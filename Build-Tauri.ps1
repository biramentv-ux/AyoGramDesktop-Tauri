# Build-Tauri.ps1 - Пълен инсталиращ и build-ващ Tauri хибрид за AyoGramDesktop
# Windows portable + installer, един клик

param(
    [string]$ProjectName = "AyoGramDesktop",
    [string]$ReleaseDir  = "$PSScriptRoot\release"
)

Write-Host "=== Tauri Build-All ===" -ForegroundColor Green
Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

# 1. Node.js + pnpm
if (-not (Get-Command node -ErrorAction SilentlyContinue)) {
    Write-Host "Инсталирам Node.js LTS..." -ForegroundColor Yellow
    winget install -e --id OpenJS.NodeJS.LTS --accept-package-agreements --accept-source-agreements
}
if (-not (Get-Command pnpm -ErrorAction SilentlyContinue)) {
    Write-Host "Инсталирам pnpm..." -ForegroundColor Yellow
    npm install -g pnpm
}

# 2. Rust + Tauri CLI
if (-not (Get-Command cargo -ErrorAction SilentlyContinue)) {
    Write-Host "Инсталирам Rust MSVC..." -ForegroundColor Yellow
    winget install -e --id Rustlang.Rust.MSVC --accept-package-agreements --accept-source-agreements
}

# 3. Създай структура ако липсва
if (-not (Test-Path "$PSScriptRoot\package.json")) {
    Write-Host "Инициализирам frontend..." -ForegroundColor Cyan
    Copy-Item "$PSScriptRoot\package.json" . -ErrorAction SilentlyContinue
}
if (-not (Test-Path "$PSScriptRoot\src-tauri\Cargo.toml")) {
    Write-Host "Инициализирам Tauri backend..." -ForegroundColor Cyan
    New-Item -ItemType Directory -Force "src-tauri\src" | Out-Null
    New-Item -ItemType Directory -Force "icons" | Out-Null
    # placeholders
    @("icon.ico","128x128.png","icon.icns","tray.png") | ForEach-Object { New-Item -ItemType File -Path "icons\$_" -Force | Out-Null }
}

# 4. Инсталирай зависимости
Write-Host "pnpm install..." -ForegroundColor Cyan
pnpm install

# 5. Build frontend
Write-Host "pnpm build frontend..." -ForegroundColor Cyan
pnpm build

# 6. Release build Tauri
Write-Host "cargo tauri build --release..." -ForegroundColor Cyan
Push-Location "$PSScriptRoot\src-tauri"
& "$env:CARGO_BIN\tauri" build --release
Pop-Location

# 7. Portable пакет
$Portable = "$ReleaseDir\${ProjectName}_Portable"
Remove-Item $Portable -Recurse -Force -ErrorAction SilentlyContinue
mkdir $Portable -Force | Out-Null
$Bin = "$PSScriptRoot\src-tauri\target\release\${ProjectName}.exe"
if (Test-Path $Bin) { Copy-Item $Bin $Portable }
Get-ChildItem "$PSScriptRoot\src-tauri\target\release\bundles\msi\*.msi" -ErrorAction SilentlyContinue | Copy-Item -Destination $Portable
Copy-Item "$PSScriptRoot\icons" $Portable -Recurse -Force

Write-Host "Готово! Portable: $Portable" -ForegroundColor Green
Write-Host "Installer MSI е копиран в Portable папката" -ForegroundColor Yellow
Write-Host "За стартиране: $Portable\${ProjectName}.exe" -ForegroundColor Cyan
