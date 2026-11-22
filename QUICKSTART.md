# QUICKSTART - 3 стъпки

## 1. Инсталирай
```powershell
Set-ExecutionPolicy -Scope Process -Bypass
.uild-tauri.ps1
```
Скриптът ще инсталира Node.js, Rust, pnpm автоматично.

## 2. Build
```powershell
.uild-tauri.ps1
```
или
```powershell
.uild-tauri.ps1 build
```

## 3. Run

Portable: `release/dyrakDGram_Portable/dyrakDGram.exe`
Installer: `src-tauri/target/release/bundles/msi/dyrakDGram_*.msi`

Готово!
