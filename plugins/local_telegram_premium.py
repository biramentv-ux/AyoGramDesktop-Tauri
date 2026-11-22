#!/usr/bin/env python3
"""LocalTelegramPremiumPlugin - dyrakDGram (български портативен Telegram клиент)
Локална Premium функционалност без абонамент: статус файл с реално съдържание и подписка.
CLI: python local_telegram_premium.py <init|enable|disable|status> [--config PATH]
Печата JSON в stdout; 0 = успех, 2 = невалидни входи, 3 = вътрешна грешка.
"""
import argparse, json, os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from _common import APP_NAME, SCHEMA_VERSION, utc_now_iso, load_config, fnv1a64, read_json, write_json, read_env
DEFAULT_FEATURES = ["upload_limit_2048mb", "profile_photos_max_1000", "voice_notes",
                    "stickers_in_chat_200", "premium_emoji_packs", "ad_free"]
DEFAULTS = {"enabled": True, "features": DEFAULT_FEATURES, "status_file": ""}
LIMITS = {"upload_limit_mb": 2048, "profile_photos_max": 1000, "stickers_in_chat": 200,
          "voice_notes": True, "premium_emoji_packs": True, "ad_free": True}

def default_status():
    appdata = read_env("APPDATA") or os.path.expanduser("~")
    return os.path.join(appdata, "dyrakDGram", "premium_status.json")

def load(cfg_path=None):
    cfg, err = load_config(cfg_path or "plugins/local_telegram_premium.json", DEFAULTS)
    if cfg is None: return None, err
    if not isinstance(cfg["enabled"], bool): return None, "enabled must be a boolean"
    feats = cfg.get("features")
    if not isinstance(feats, list) or not all(isinstance(f, str) and f.strip() for f in feats):
        return None, "features must be a non-empty list of strings"
    cfg["features"] = [f.strip() for f in feats]
    cfg["status_file"] = cfg.get("status_file") or default_status()
    return cfg, None

def _state(cfg, enabled):
    now = utc_now_iso()
    state = {"enabled": enabled,
             "enabled_at": now if enabled else None,
             "disabled_at": now if not enabled else None,
             "features": cfg["features"] if enabled else [],
             "limits": LIMITS if enabled else {},
             "local": True, "app": APP_NAME, "plugin": "LocalTelegramPremium",
             "version": SCHEMA_VERSION, "signature": None}
    state["signature"] = fnv1a64({k: v for k, v in state.items() if k != "signature"})
    return state

def cmd_init(args):
    cfg, err = load(args.config)
    if err: print(json.dumps({"status": "error", "reason": err})); return 2
    print(json.dumps({"status": "ready", "plugin": "LocalTelegramPremium",
                      "version": SCHEMA_VERSION, "enabled": cfg["enabled"],
                      "status_file": cfg["status_file"]})); return 0
def cmd_enable(args):
    cfg, err = load(args.config)
    if err: print(json.dumps({"status": "error", "reason": err})); return 2
    state = _state(cfg, True)
    try: write_json(cfg["status_file"], state)
    except Exception as e: print(json.dumps({"status": "error", "reason": f"cannot write status file: {e}"})); return 3
    print(json.dumps({"status": "enabled", "status_file": cfg["status_file"],
                      "features": state["features"], "limits": state["limits"],
                      "signature": state["signature"]}, ensure_ascii=False)); return 0
def cmd_disable(args):
    cfg, err = load(args.config)
    if err: print(json.dumps({"status": "error", "reason": err})); return 2
    state = _state(cfg, False)
    try: write_json(cfg["status_file"], state)
    except Exception as e: print(json.dumps({"status": "error", "reason": f"cannot write status file: {e}"})); return 3
    print(json.dumps({"status": "disabled", "status_file": cfg["status_file"]})); return 0
def cmd_status(args):
    cfg, err = load(args.config)
    if err: print(json.dumps({"status": "error", "reason": err})); return 2
    try: state = read_json(cfg["status_file"])
    except FileNotFoundError:
        print(json.dumps({"enabled": False, "valid": False, "reason": "status file not found"})); return 0
    except Exception as e:
        print(json.dumps({"enabled": False, "valid": False, "reason": f"cannot read status file: {e}"})); return 0
    if not isinstance(state, dict) or state.get("signature") is None:
        print(json.dumps({"enabled": False, "valid": False, "reason": "status file has no signature"})); return 0
    expected = fnv1a64({k: v for k, v in state.items() if k != "signature"})
    valid = (expected == state["signature"])
    print(json.dumps({"enabled": bool(state.get("enabled")), "valid": bool(valid),
                      "features": state.get("features", []), "limits": state.get("limits", {}),
                      "enabled_at": state.get("enabled_at"), "signature": state["signature"]}, ensure_ascii=False))
    return 0 if valid else 2
def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("action", choices=["init", "enable", "disable", "status"])
    ap.add_argument("--config", default=None)
    args = ap.parse_args()
    return {"init": cmd_init, "enable": cmd_enable, "disable": cmd_disable, "status": cmd_status}[args.action](args)
if __name__ == "__main__":
    sys.exit(main())
