#!/usr/bin/env python3
"""MK_FuckPaymentsPlugin — dyrakDGram (български портативен Telegram клиент)
fake_stars: премахва плащанията и показва фалшиви звезди, като логира всеки събитие в логов файл.
CLI: python mk_fuckpayments.py <init|process|summary> [--config PATH] [--payload PATH|-]
Печата JSON в stdout; код на изхода 0 = успех, 2 = невалидни входи, 3 = вътрешна грешка.
"""
import argparse, json, os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from _common import (APP_NAME, SCHEMA_VERSION, utc_now_iso, load_config, fnv1a64,
                     read_json, append_jsonl, file_hash, read_env)
DEFAULTS = {"enabled": True, "fake_balance": 999, "log_file": ""}

def default_log():
    appdata = read_env("APPDATA") or os.path.expanduser("~")
    return os.path.join(appdata, "dyrakDGram", "payments.jsonl")

def load(cfg_path=None):
    cfg, err = load_config(cfg_path or "plugins/mk_fuckpayments.json", DEFAULTS)
    if cfg is None: return None, err
    if not isinstance(cfg["enabled"], bool): return None, "enabled must be a boolean"
    try: bal = int(cfg["fake_balance"]); assert bal >= 0
    except Exception: return None, "fake_balance must be an integer >= 0"
    cfg["fake_balance"] = bal
    cfg["log_file"] = cfg.get("log_file") or default_log()
    return cfg, None

def cmd_init(args):
    cfg, err = load(args.config)
    if err: return 2, {"status": "error", "reason": err}
    out = {"status": "ready", "plugin": "MK_FuckPayments",
           "version": SCHEMA_VERSION, "enabled": cfg["enabled"],
           "fake_balance": cfg["fake_balance"], "log_file": cfg["log_file"]}; print(json.dumps(out)); return 0, out

def cmd_process(args):
    cfg, err = load(args.config)
    if err: return 2, {"status": "error", "reason": err}
    try: raw = open(args.payload, encoding="utf-8").read() if args.payload != "-" else sys.stdin.read()
    except Exception as e: return 3, {"status": "error", "reason": f"cannot read payload: {e}"}
    try: payload = json.loads(raw)
    except Exception: return 2, {"status": "error", "reason": "payload is not valid JSON"}
    if not isinstance(payload, dict): return 2, {"status": "error", "reason": "payload must be a JSON object"}
    pid = payload.get("payment_id"); cost = payload.get("stars_cost")
    if not isinstance(pid, str) or not pid.strip() or len(pid) > 128:
        return 2, {"status": "error", "reason": "payment_id required (string <=128 chars)"}
    try: cost = int(cost); assert cost > 0
    except Exception: return 2, {"status": "error", "reason": "stars_cost required (number > 0)"}
    event = {"type": "stars_payment", "payment_id": pid.strip(), "stars_cost": cost,
             "sanitized": True, "fake_balance_shown": cfg["fake_balance"],
             "logged_at": utc_now_iso(), "plugin": "MK_FuckPayments"}
    event["event_id"] = fnv1a64(event)
    try:
        append_jsonl(cfg["log_file"], event)
    except Exception as e: return 3, {"status": "error", "reason": f"cannot write log file: {e}"}
    print(json.dumps({"status": "sanitized", "payment_id": event["payment_id"],
                      "fake_balance_shown": cfg["fake_balance"], "stars_cost": cost,
                      "event_id": event["event_id"], "logged_to": cfg["log_file"]}, ensure_ascii=False)); return 0

def cmd_summary(args):
    cfg, err = load(args.config)
    if err: return 2, {"status": "error", "reason": err}
    entries = []
    try:
        with open(cfg["log_file"], encoding="utf-8") as f:
            for line in f:
                line = line.strip()
                if not line: continue
                try: entries.append(json.loads(line))
                except Exception: pass
    except FileNotFoundError:
        print(json.dumps({"status": "ok", "log_file": cfg["log_file"], "count": 0, "last_entry": None})); return 0
    except Exception as e: return 3, {"status": "error", "reason": f"cannot read log file: {e}"}
    print(json.dumps({"status": "ok", "log_file": cfg["log_file"], "count": len(entries),
                      "last_entry": entries[-1] if entries else None}, ensure_ascii=False)); return 0

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("action", choices=["init", "process", "summary"])
    ap.add_argument("--config", default=None)
    ap.add_argument("--payload", default="-")
    args = ap.parse_args()
    res = {"init": cmd_init, "process": cmd_process, "summary": cmd_summary}[args.action](args)
    if isinstance(res, tuple): rc, out = res
    else: rc, out = res, None
    if rc != 0 and isinstance(out, dict): print(json.dumps(out, ensure_ascii=False))
    return rc

if __name__ == "__main__":
    sys.exit(main())
