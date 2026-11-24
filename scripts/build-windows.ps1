# ============================================
#   dyrakDGram - Windows Build Script
#   Tauri Release Build Automation
# ============================================

# Set execution policy for current session
Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass -Force

# Error handling
$ErrorActionPreference = "Stop"

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  dyrakDGram - Windows Build Script" -ForegroundColor Cyan
Write-Host "  Търговска версия за изграждане" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# Check Rust
Write-Host "[INFO] Checking Rust installation..."
if (-not (Get-Command cargo -ErrorAction SilentlyContinue)) {
    Write-Host "[ERROR] Rust is not installed!" -ForegroundColor Red
    Write-Host "Please install from: https://rustup.rs/"
    Write-Host "Or run: winget install Rust.Rust"
    exit 1
}
Write-Host "[OK] Rust: $((cargo --version).Trim())"
Write-Host ""

# Check Node.js
Write-Host "[INFO] Checking Node.js installation..."
if (-not (Get-Command node -ErrorAction SilentlyContinue)) {
    Write-Host "[ERROR] Node.js is not installed!" -ForegroundColor Red
    Write-Host "Please install from: https://nodejs.org/"
    exit 1
}
Write-Host "[OK] Node.js: $((node --version).Trim())"
Write-Host ""

# Install dependencies
echo "[INFO] Installing npm dependencies..."
npm install
if ($LASTEXITCODE -ne 0) {
    echo "[ERROR] Failed to install dependencies!"
    exit 1
}
echo "[OK] Dependencies installed."
echo ""

# Clean previous build
echo "[INFO] Cleaning previous builds..."
cd src-tauri
cargo clean | Out-Null
echo "[OK] Previous builds cleaned."
echo ""

# Build release version
echo "[INFO] Building release version..."
echo "This may take a few minutes on first build."
echo ""

$BUILD_RESULT = cargo tauri build --release --target x86_64-pc-windows-msvc
if ($LASTEXITCODE -ne 0) {
    echo "[ERROR] Build failed!"
    exit 1
}

echo ""
echo "========================================" -ForegroundColor Green
echo "  BUILD SUCCESSFUL!" -ForegroundColor Green
echo "========================================" -ForegroundColor Green
echo ""
echo "Output location:"
echo "  src-tauri/target/release/bundle/"
echo ""
echo "Executable:"
echo "  dyrakDGram.exe"
echo ""
echo "Installer:"
echo "  dyrakDGram_[version]_x64_setup.exe"
echo ""

# Show output
echo "[INFO] Files in bundle directory:"
if (Test-Path "src-tauri/target/release/bundle/ntx") {
    echo "Executable files:"
    Get-ChildItem "src-tauri/target/release/bundle/ntx" -Filter "*.exe" | ForEach-Object { Write-Host "  - $($_.Name)" }
} else {
    echo "Bundle directory not found."
}
echo ""

# Launch the application
echo "[INFO] Launching dyrakDGram..."
if (Test-Path "src-tauri/target/release/dyrak-dgram.exe") {
    & "src-tauri/target/release/dyrak-dgram.exe"
    echo "[OK] dyrakDGram has been launched!" -ForegroundColor Green
} else {
    echo "[INFO] Executable not found at expected location."
    echo "Check: src-tauri/target/release/bundle/"
}
echo ""
