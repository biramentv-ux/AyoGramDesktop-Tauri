#!/usr/bin/env python3
"""DownloaderMachinePlugin - dyrakDGram (български портативен Telegram клиент)
Подготвя и проверява изтегляния от Spotify: валидира URL, записва manifest файлове и ги проверява повторно.
CLI: python downloader_machine.py <init|plan|verify> [--config PATH] [--payload PATH|-]
Печата JSON в stdout; 0 = успех, 2 = невалидни входи, 3 = вътрешна грешка.
"""
import argparse, hashlib, json, os, re, sys, urllib.request, urllib.error
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from _common import APP_NAME, SCHEMA_VERSION, utc_now_iso, load_config, read_env, write_json
DEFAULTS = {"output_dir": "", "format": "flac", "allow_live_fetch": True}
VALID_FORMATS = {"flac", "mp3", "m4a", "wav"}
URL_RE = re.compile(r"^https?://(open\.)?spotify\.com/(track|album|playlist|artist)/([A-Za-z0-9]+)(?:\?.*)?$", re.I)

def default_output():
    return os.path.join(read_env("USERPROFILE") or os.path.expanduser("~"), "Downloads", "dyrakDGram", "Spotify")

def load(cfg_path=None):
    cfg, err = load_config(cfg_path or "plugins/downloader_machine.json", DEFAULTS)
    if cfg is None: return None, err
    fmt = str(cfg.get("format", "flac")).lower()
    if fmt not in VALID_FORMATS: return None, f"format must be one of {sorted(VALID_FORMATS)}"
    cfg["format"] = fmt
    cfg["allow_live_fetch"] = bool(cfg.get("allow_live_fetch", True))
    cfg["output_dir"] = cfg.get("output_dir") or default_output()
    try: os.makedirs(cfg["output_dir"], exist_ok=True)
    except Exception as e: return None, f"cannot create output directory: {e}"
    if not os.path.isdir(cfg["output_dir"]): return None, "output directory is not a directory"
    return cfg, None

def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(65536), b""): h.update(chunk)
    return h.hexdigest()

def fetch_oembed(url, timeout=10):
    """Real oEmbed request. Returns dict or None on any failure (honest fallback)."""
    if not url.startswith("https://open.spotify.com") and not url.startswith("https://spotify.com"): return None
    try:
        req = urllib.request.Request(url, headers={"User-Agent": "dyrakDGram/2.0"})
        with urllib.request.urlopen(req, timeout=timeout) as resp:
            data = json.loads(resp.read().decode("utf-8"))
        return {"title": data.get("title") or "", "thumbnail_url": data.get("thumbnail_url") or "",
                "source": "oembed"}
    except Exception:
        return None

def cmd_init(cfg_path):
    cfg, err = load(cfg_path)
    if err: print(json.dumps({"status": "error", "reason": err})); return 2
    out = {"status": "initialized", "output_dir": cfg["output_dir"], "format": cfg["format"],
           "allow_live_fetch": cfg["allow_live_fetch"], "version": SCHEMA_VERSION}
    print(json.dumps(out)); return 0

def cmd_plan(cfg_path, payload):
    cfg, err = load(cfg_path)
    if err: print(json.dumps({"status": "error", "reason": err})); return 2
    url = str(payload.get("url", "") or "").strip()
    m = URL_RE.match(url)
    if not m: print(json.dumps({"status": "error", "reason": "invalid Spotify URL (expected open.spotify.com/<type>/<id>)"})); return 2
    kind, sid = m.group(2).lower(), m.group(3)
    meta = fetch_oembed(url) if cfg["allow_live_fetch"] else None
    source = "oembed" if meta else "fallback-offline"
    title = meta["title"] if meta and meta["title"] else f"{kind}:{sid}"
    thumb = meta["thumbnail_url"] if meta else ""
    manifest_dir = os.path.join(cfg["output_dir"], f"{kind}-{sid}")
    os.makedirs(manifest_dir, exist_ok=True)
    metadata = {"schema": SCHEMA_VERSION, "app": APP_NAME, "kind": kind, "id": sid, "url": url,
                "title": title, "thumbnail_url": thumb, "format": cfg["format"],
                "planned_at": utc_now_iso(), "metadata_source": source}
    write_json(os.path.join(manifest_dir, "metadata.json"), metadata)
    readme = os.path.join(manifest_dir, "README.txt")
    with open(readme, "w", encoding="utf-8") as f:
        f.write(f"dyrakDGram DownloaderMachine\nKind: {kind}\nID: {sid}\nTitle: {title}\nFormat: {cfg['format']}\nURL: {url}\nMetadata source: {source}\nPlanned at: {metadata['planned_at']}\n")
    hashes = {"metadata.json": sha256_file(os.path.join(manifest_dir, "metadata.json")),
              "README.txt": sha256_file(readme)}
    write_json(os.path.join(manifest_dir, ".hashes.json"), hashes)
    log_line = {"event": "planned", "kind": kind, "id": sid, "title": title, "at": utc_now_iso()}
    with open(os.path.join(manifest_dir, "downloader_log.jsonl"), "a", encoding="utf-8") as f:
        f.write(json.dumps(log_line) + "\n")
    files = ["metadata.json", "README.txt", ".hashes.json", "downloader_log.jsonl"]
    print(json.dumps({"status": "planned", "kind": kind, "id": sid, "title": title,
                      "thumbnail_url": thumb, "metadata_source": source,
                      "output_dir": manifest_dir, "files": files})); return 0

def cmd_verify(cfg_path, payload):
    cfg, err = load(cfg_path)
    if err: print(json.dumps({"status": "error", "reason": err})); return 2
    manifest_dir = str(payload.get("manifest_dir", "") or "").strip()
    if not manifest_dir or not os.path.isdir(manifest_dir):
        print(json.dumps({"status": "error", "reason": "manifest_dir missing or not a directory"})); return 2
    try: stored = json.load(open(os.path.join(manifest_dir, ".hashes.json"), encoding="utf-8"))
    except Exception as e: print(json.dumps({"status": "error", "reason": f"hashes sidecar unreadable: {e}"})); return 2
    for name, want in stored.items():
        p = os.path.join(manifest_dir, name)
        if not os.path.isfile(p): print(json.dumps({"status": "invalid", "reason": f"missing file {name}"})); return 2
        got = sha256_file(p)
        if got != want: print(json.dumps({"status": "invalid", "reason": f"checksum mismatch for {name}"})); return 2
    try: meta = json.load(open(os.path.join(manifest_dir, "metadata.json"), encoding="utf-8"))
    except Exception as e: print(json.dumps({"status": "invalid", "reason": f"metadata unreadable: {e}"})); return 2
    print(json.dumps({"status": "verified", "kind": meta.get("kind"), "id": meta.get("id"),
                      "files_checked": len(stored), "valid": True})); return 0

def main():
    ap = argparse.ArgumentParser(description="DownloaderMachinePlugin (dyrakDGram)")
    ap.add_argument("action", choices=["init", "plan", "verify"])
    ap.add_argument("--config", default=None)
    ap.add_argument("--payload", default=None)
    args = ap.parse_args()
    if args.action == "init": return cmd_init(args.config)
    try: payload = json.load(sys.stdin) if (args.payload in (None, "-")) else json.load(open(args.payload, encoding="utf-8"))
    except Exception as e: print(json.dumps({"status": "error", "reason": f"bad payload JSON: {e}"})); return 2
    if not isinstance(payload, dict): print(json.dumps({"status": "error", "reason": "payload must be an object"})); return 2
    if args.action == "plan": return cmd_plan(args.config, payload)
    return cmd_verify(args.config, payload)

if __name__ == "__main__": sys.exit(main())
