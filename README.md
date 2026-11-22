# AyoGramDesktop Hybrid - Tauri Edition

Хибриден Telegram desktop клиент с Ghost Mode и Stream Mode. Построен с Tauri + Rust + Vite/Tailwind.

## Бърз старт

```powershell
Set-ExecutionPolicy -Scope Process -Bypass
.uild-tauri.ps1
```

Това ще инсталира Node.js, Rust, pnpm, build-не frontend и Rust backend и ще създаде portable папка в `release/AyoGramDesktop_Portable/`.

## Структура

```
AyoGramDesktop/
├─ src-tauri/
│  ├─ src/main.rs          # Tauri entry, system-tray, commands
│  ├─ Cargo.toml
│  └─ icons/
├─ ghost_mode/
│  ├─ Cargo.toml
│  └─ src/lib.rs           # Ghost Mode логика
├─ stream_mode/
│  ├─ Cargo.toml
│  └─ src/lib.rs           # Stream Mode логика
├─ package.json
├─ vite.config.ts
├─ tauri.conf.json
└─ src/index.html
```

## Добавяне на нов плъгин

1. Създай нова Rust crate в корена, напр. `local_premium`:
   ```
   mkdir local_premium
   # Cargo.toml + src/lib.rs
   ```
2. Добави в `src-tauri/Cargo.toml`:
   ```toml
   local_premium = { path = "../local_premium" }
   ```
3. Експортирай command в `src-tauri/src/main.rs`:
   ```rust
   #[tauri::command]
   fn get_local_premium() -> ...
   ```
4. В UI повикай `window.__TAURI__.invoke('get_local_premium')`.

## Auto-updater тест локално

1. Смени `pubkey` в `tauri.conf.json` с реален Ed25519 ключ.
2. Стартирай локален сървър:
   ```powershell
   python -m http.server 8000
   ```
3. Смени `endpoints` на `http://localhost:8000/releases/{{version}}`.
4. Пусни `cargo tauri dev` и тествай.

## Portable build

Резултатът е в `release/AyoGramDesktop_Portable/`:
- `AyoGramDesktop.exe` - portable
- `*.msi` - инсталатор

## Изисквания

- Windows 10/11
- PowerShell 5+
- Интернет за първо сваляне на Node/Rust