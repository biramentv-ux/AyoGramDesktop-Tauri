#!/usr/bin/env python3
"""UnlockStarsContentPlugin — dyrakDGram (български портативен Telegram клиент)
Отключва съдържание, изискващо Stars: валидира заявката и връща receipt с валидна подписка — без реално плащане.
CLI: python unlock_stars_content.py <init|unlock|verify> [--config PATH] [--payload PATH|-]
Печата JSON в stdout; код на изхода 0 = успех, 2 = невалидни входи, 3 = вътрешна грешка.
"""
import argparse, json, os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from _common import (APP_NAME, SCHEMA_VERSION, utc_now_iso, load_config, fnv1a64)
DEFAULTS = {"enabled": True, "auto_unlock": True, "log_file": ""}
VALID_TYPES = {"channel", "media", "sticker", "gif", "other"}

def load(cfg_path=None):
    cfg, err = load_config(cfg_path or "plugins/unlock_stars.json", DEFAULTS)
    if cfg is None: return None, err
    if not isinstance(cfg["enabled"], bool): return None, "enabled must be a boolean"
    if not isinstance(cfg["auto_unlock"], bool): return None, "auto_unlock must be a boolean"
    return cfg, None

def cmd_init(args):
    cfg, err = load(args.config)
    if err: return 2, {"status": "error", "reason": err}
    out = {"status": "ready", "plugin": "UnlockStarsContent",
           "version": SCHEMA_VERSION, "enabled": cfg["enabled"],
           "auto_unlock": cfg["auto_unlock"]}; print(json.dumps(out)); return 0, out

def cmd_unlock(args):
    cfg, err = load(args.config)
    if err: return 2, {"status": "error", "reason": err}
    try: raw = open(args.payload, encoding="utf-8").read() if args.payload != "-" else sys.stdin.read()
    except Exception as e: return 3, {"status": "error", "reason": f"cannot read payload: {e}"}
    try: payload = json.loads(raw)
    except Exception: return 2, {"status": "error", "reason": "payload is not valid JSON"}
    if not isinstance(payload, dict): return 2, {"status": "error", "reason": "payload must be a JSON object"}
    cid = payload.get("content_id"); stypes = payload.get("type", "other")
    try: stars = int(payload.get("stars_required", 0)); assert stars >= 0
    except Exception: return 2, {"status": "error", "reason": "stars_required must be an integer >= 0"}
    if not isinstance(cid, str) or not cid.strip() or len(cid) > 256:
        return 2, {"status": "error", "reason": "content_id required (string <=256 chars)"}
    if not isinstance(stypes, str) or stypes.lower() not in VALID_TYPES: stypes = "other"
    receipt = {"status": "unlocked", "content_id": cid.strip(), "type": stypes.lower(),
               "stars_charged": 0, "stars_required": stars,
               "unlocked_at": utc_now_iso(), "auto_unlock": cfg["auto_unlock"],
               "plugin": "UnlockStarsContent", "app": APP_NAME, "signature": None}
    receipt["signature"] = fnv1a64({k: v for k, v in receipt.items() if k != "signature"})
    print(json.dumps(receipt, ensure_ascii=False)); return 0

def cmd_verify(args):
    try: raw = open(args.payload, encoding="utf-8").read() if args.payload != "-" else sys.stdin.read()
    except Exception as e: return 3, {"status": "error", "reason": f"cannot read receipt: {e}"}
    try: receipt = json.loads(raw)
    except Exception: return 2, {"status": "error", "reason": "receipt is not valid JSON"}
    if not isinstance(receipt, dict) or receipt.get("signature") is None:
        return 2, {"status": "error", "reason": "receipt missing signature"}
    expected = fnv1a64({k: v for k, v in receipt.items() if k != "signature"})
    valid = (expected == receipt["signature"])
    print(json.dumps({"status": "ok", "valid": bool(valid), "content_id": receipt.get("content_id")}, ensure_ascii=False)); return 0 if valid else 2

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("action", choices=["init", "unlock", "verify"])
    ap.add_argument("--config", default=None)
    ap.add_argument("--payload", default="-")
    args = ap.parse_args()
    res = {"init": cmd_init, "unlock": cmd_unlock, "verify": cmd_verify}[args.action](args)
    if isinstance(res, tuple): rc, out = res
    else: rc, out = res, None
    if rc != 0 and isinstance(out, dict): print(json.dumps(out, ensure_ascii=False))
    return rc

if __name__ == "__main__":
    sys.exit(main())
