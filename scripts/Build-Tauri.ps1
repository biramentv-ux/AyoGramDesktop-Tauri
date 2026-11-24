# ============================================
#   dyrakDGram - Tauri Build Script
#   Windows PowerShell Automation
# ============================================

# Enable strict mode
set-strictmode -version 2.0

# Error handling
$ErrorActionPreference = "Stop"

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  dyrakDGram Tauri Build Script" -ForegroundColor Cyan
Write-Host "  Telegram Desktop with Premium Features" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# Check for required tools
function Check-RequiredTool {
    param($toolName, $installationUrl)
    
    if (-not (Get-Command $toolName -ErrorAction SilentlyContinue)) {
        Write-Host "[ERROR] $toolName is not installed!" -ForegroundColor Red
        Write-Host "Please install from: $installationUrl" -ForegroundColor Yellow
        exit 1
    }
}

Write-Host "[INFO] Checking required tools..."
Check-RequiredTool "cargo" "https://rustup.rs/"
Check-RequiredTool "node" "https://nodejs.org/"
Check-RequiredTool "npm" "https://nodejs.org/"

# Display versions
Write-Host "[INFO] Tool versions:"
Write-Host "  Rust: $((cargo --version).Trim())"
Write-Host "  Node: $((node --version).Trim())"
Write-Host "  NPM:  $((npm --version).Trim())"
Write-Host ""

# Build configuration
$BUILD_CONFIG = "release"
if ($args.Count -gt 0 -and $args[0] -eq "--dev") {
    $BUILD_CONFIG = "debug"
}

# Check if Tauri is installed
echo "Checking Tauri installation..."
if (-not (Get-Command "tauri" -ErrorAction SilentlyContinue)) {
    Write-Host "[INFO] Tauri CLI not found. Installing..."
    npm install --save-dev @tauri-apps/cli
}

Write-Host "[INFO] Building in $BUILD_CONFIG mode..."
Write-Host ""

# Navigate to Tauri directory
cd src-tauri

# Full build with all features
echo "Running: cargo tauri build --$BUILD_CONFIG --release"
cargo tauri build --$BUILD_CONFIG --release

if ($LASTEXITCODE -ne 0) {
    Write-Host "[ERROR] Build failed!" -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "========================================" -ForegroundColor Green
Write-Host "  BUILD SUCCESSFUL!" -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Green
Write-Host ""
Write-Host "Application location:"
Write-Host "  src-tauri/target/release/bundle/"
Write-Host ""
Write-Host "Available formats:"
Write-Host "  - Windows Portable: .exe (MSIX, NSIS)"
Write-Host "  - macOS: .dmg, .app"
Write-Host "  - Linux: .deb, .AppImage, .rpm"
Write-Host ""
Write-Host "Open the bundle folder to find your build files."
