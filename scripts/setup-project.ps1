# ============================================
#   dyrakDGram - Windows Setup Script
#   PowerShell Installation Automation
# ============================================

# Set execution policy for current session
Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass -Force

# Enable strict mode
set-strictmode -version 2.0

# Error handling
$ErrorActionPreference = "Stop"

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  dyrakDGram - Windows Setup Script" -ForegroundColor Cyan
Write-Host "  Пълно инсталиране и настройка" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# Check if running as administrator
$isAdmin = ([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)

if (-not $isAdmin) {
    Write-Host "[INFO] Script is not running as administrator." -ForegroundColor Yellow
    Write-Host "Some operations may require elevated permissions." -ForegroundColor Yellow
    Write-Host ""
}

# Function to check and install Rust
function Install-Rust {
    param($tryWinget = $false)
    
    if (-not (Get-Command cargo -ErrorAction SilentlyContinue)) {
        if ($tryWinget) {
            Write-Host "[INFO] Attempting to install Rust with winget..."
            try {
                winget install Rust.Rust
                Write-Host "[OK] Rust installed successfully!" -ForegroundColor Green
                return $true
            } catch {
                Write-Host "[ERROR] Failed to install Rust with winget." -ForegroundColor Red
                Write-Host "Please install manually: https://rustup.rs/"
                return $false
            }
        } else {
            Write-Host "[ERROR] Rust is not installed!" -ForegroundColor Red
            Write-Host "Please install from: https://rustup.rs/"
            return $false
        }
    }
    return $true
}

# Function to check and install Node.js
function Install-Node {
    param($tryWinget = $false)
    
    if (-not (Get-Command node -ErrorAction SilentlyContinue)) {
        if ($tryWinget) {
            Write-Host "[INFO] Attempting to install Node.js with winget..."
            try {
                winget install OpenJS.NodeJS
                Write-Host "[OK] Node.js installed successfully!" -ForegroundColor Green
                return $true
            } catch {
                Write-Host "[ERROR] Failed to install Node.js with winget." -ForegroundColor Red
                Write-Host "Please install manually: https://nodejs.org/"
                return $false
            }
        } else {
            Write-Host "[ERROR] Node.js is not installed!" -ForegroundColor Red
            Write-Host "Please install from: https://nodejs.org/"
            return $false
        }
    }
    return $true
}

Write-Host "[INFO] Checking system requirements..."
Write-Host ""

# Check Rust
if (-not (Install-Rust -tryWinget $true)) {
    Write-Host "Please install Rust manually and run this script again."
    pause
    exit 1
}
Write-Host "[OK] Rust version: $((cargo --version).Trim())"
Write-Host ""

# Check Node.js
if (-not (Install-Node -tryWinget $true)) {
    Write-Host "Please install Node.js manually and run this script again."
    pause
    exit 1
}
Write-Host "[OK] Node.js version: $((node --version).Trim())"
Write-Host ""

# Install dependencies
echo "[INFO] Installing project dependencies..."
npm install
if ($LASTEXITCODE -ne 0) {
    echo "[ERROR] Failed to install npm dependencies!"
    pause
    exit 1
}

echo "[OK] Dependencies installed successfully!"
echo ""

# Build the project
echo "[INFO] Building dyrakDGram..."
cd src-tauri
cargo tauri build --release
if ($LASTEXITCODE -ne 0) {
    echo "[ERROR] Build failed!"
    pause
    exit 1
}

echo ""
echo "========================================" -ForegroundColor Green
echo "  SETUP COMPLETE!" -ForegroundColor Green
echo "========================================" -ForegroundColor Green
echo ""
echo "Application ready at:"
echo "  src-tauri/target/release/bundle/"
echo ""
echo "To launch dyrakDGram, run:"
echo "  start src-tauri\\target\\release\\dyrak-dgram.exe"
echo ""

# Optional: Launch the application
$launch = Read-Host "Do you want to launch dyrakDGram now? (y/n)"
if ($launch -eq "y" -or $launch -eq "Y") {
    & "src-tauri\\target\\release\\dyrak-dgram.exe"
    Write-Host "[INFO] dyrakDGram launched!" -ForegroundColor Green
}
