#!/usr/bin/env python3
"""FakePaymentInterceptorPlugin — dyrakDGram (български портативен Telegram клиент)
Прихваща заявка за Stars плащане и връща фалшив TL_payments_paymentResult — без реално плащане.
CLI: python fakepayment_interceptor.py <init|intercept|verify> [--config PATH] [--payload PATH|-]
Печата JSON в stdout; код на изхода 0 = успех, 2 = невалидни входи, 3 = вътрешна грешка.
"""
import argparse, json, os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from _common import (APP_NAME, SCHEMA_VERSION, utc_now_iso, load_config, fnv1a64,
                     read_json, file_hash)
DEFAULTS = {"enabled": True, "fake_amount": 0, "log_file": ""}

def load(cfg_path=None):
    cfg, err = load_config(cfg_path or "plugins/fakepayment.json", DEFAULTS)
    if cfg is None: return None, err
    if not isinstance(cfg["enabled"], bool): return None, "enabled must be a boolean"
    try: fake = int(cfg["fake_amount"]); assert fake >= 0
    except Exception: return None, "fake_amount must be an integer >= 0"
    cfg["fake_amount"] = fake
    return cfg, None

def cmd_init(args):
    cfg, err = load(args.config)
    if err: return 2, {"status": "error", "reason": err}
    out = {"status": "ready", "plugin": "FakePaymentInterceptor",
           "version": SCHEMA_VERSION, "enabled": cfg["enabled"],
           "fake_amount": cfg["fake_amount"]}; print(json.dumps(out)); return 0, out

def _validate(payload):
    if not isinstance(payload, dict): return None, "payload must be a JSON object"
    pid = payload.get("payment_id"); amt = payload.get("amount_stars"); rcpt = payload.get("recipient")
    if not isinstance(pid, str) or not pid.strip() or len(pid) > 128: return None, "payment_id required (string <=128 chars)"
    try: amt = int(amt); assert amt > 0
    except Exception: return None, "amount_stars required (number > 0)"
    if not isinstance(rcpt, str) or not rcpt.strip() or len(rcpt) > 128: return None, "recipient required (string <=128 chars)"
    return {"payment_id": pid.strip(), "amount_stars": amt, "recipient": rcpt.strip()}, None

def cmd_intercept(args):
    cfg, err = load(args.config)
    if err: return 2, {"status": "error", "reason": err}
    try: raw = open(args.payload, encoding="utf-8").read() if args.payload != "-" else sys.stdin.read()
    except Exception as e: return 3, {"status": "error", "reason": f"cannot read payload: {e}"}
    try: payload = json.loads(raw)
    except Exception: return 2, {"status": "error", "reason": "payload is not valid JSON"}
    data, err = _validate(payload)
    if err: return 2, {"status": "error", "reason": err}
    fake_stars = cfg["fake_amount"] if cfg["fake_amount"] > 0 else data["amount_stars"]
    receipt = {
        "status": "intercepted", "payment_id": data["payment_id"],
        "recipient": data["recipient"],
        "original_amount_stars": data["amount_stars"],
        "fake_result": {"method": "TL_payments_paymentResult", "stars_paid": 0,
                        "received_stars": fake_stars, "currency": "stars", "intercepted": True},
        "intercepted_at": utc_now_iso(), "plugin": "FakePaymentInterceptor",
        "app": APP_NAME, "signature": None
    }
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
    print(json.dumps({"status": "ok", "valid": bool(valid), "payment_id": receipt.get("payment_id")}, ensure_ascii=False)); return 0 if valid else 2

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("action", choices=["init", "intercept", "verify"])
    ap.add_argument("--config", default=None)
    ap.add_argument("--payload", default="-")
    args = ap.parse_args()
    res = {"init": cmd_init, "intercept": cmd_intercept, "verify": cmd_verify}[args.action](args)
    if isinstance(res, tuple): rc, out = res
    else: rc, out = res, None
    if rc != 0 and isinstance(out, dict): print(json.dumps(out, ensure_ascii=False))
    return rc

if __name__ == "__main__":
    sys.exit(main())
