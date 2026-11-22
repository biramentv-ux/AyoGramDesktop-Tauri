"""Shared utilities for dyrakDGram plugins. stdlib only."""
import hashlib, json, os, re, sys, time
from datetime import datetime, timezone

APP_NAME = "dyrakDGram"
SCHEMA_VERSION = "2.0.0"

def utc_now_iso():
    return datetime.now(timezone.utc).replace(microsecond=0).isoformat().replace("+00:00", "Z")

def load_config(path, default_cfg, required=()):
    cfg = dict(default_cfg)
    if path and os.path.exists(path):
        try:
            with open(path, "r", encoding="utf-8") as f:
                user = json.load(f)
            if not isinstance(user, dict):
                raise ValueError("config must be a JSON object")
            cfg.update(user)
        except Exception as e:
            return None, f"invalid config: {e}"
    elif not path:
        pass
    else:
        return None, f"config file not found: {path}"
    for key in required:
        if cfg.get(key) is None:
            return None, f"missing required config key: {key}"
    return cfg, None

def fnv1a64(data):
    if isinstance(data, dict) or isinstance(data, list):
        data = json.dumps(data, sort_keys=True, separators=(",", ":"), ensure_ascii=False)
    elif not isinstance(data, str):
        data = str(data)
    h = 0xcbf29ce484222325
    for b in data.encode("utf-8"):
        h ^= b
        h = (h * 0x100000001b3) & 0xFFFFFFFFFFFFFFFF
    return f"{h:016x}"

def write_json(path, data):
    os.makedirs(os.path.dirname(path), exist_ok=True) if os.path.dirname(path) else None
    tmp = path + ".tmp"
    with open(tmp, "w", encoding="utf-8") as f:
        json.dump(data, f, indent=2, ensure_ascii=False)
    os.replace(tmp, path)  # atomic write

def read_json(path):
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)

def append_jsonl(path, entry):
    os.makedirs(os.path.dirname(path) if os.path.dirname(path) else ".", exist_ok=True)
    with open(path, "a", encoding="utf-8") as f:
        f.write(json.dumps(entry, ensure_ascii=False) + "\n")

def file_hash(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(65536), b""):
            h.update(chunk)
    return h.hexdigest()

def read_env(key, default=None):
    v = os.environ.get(key)
    return v if v else default

SPOTIFY_URL_RE = re.compile(r"^https?://(open\.)?spotify\.com/(?:intl-[a-z]{2}/)?(track|album|playlist|show|episode|artist)/([A-Za-z0-9]+)", re.I)
