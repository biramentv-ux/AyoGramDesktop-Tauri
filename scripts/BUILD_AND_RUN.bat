@echo off
echo ========================================
echo   dyrakDGram - Build & Run Script
echo   Telegram Desktop with Premium Features
echo ========================================
echo.

REM Check if Rust is installed
where cargo >nul 2>nul
if %errorlevel% neq 0 (
    echo [ERROR] Rust is not installed!
    echo Please install Rust from: https://rustup.rs/
    pause
    exit /b 1
)

echo [INFO] Checking Rust installation...
echo Rust version:
cargo --version
echo.

REM Check if Node.js is installed
where node >nul 2>nul
if %errorlevel% neq 0 (
    echo [ERROR] Node.js is not installed!
    pause
    exit /b 1
)

echo [INFO] Checking Node.js installation...
echo Node version:
node --version
echo NPM version:
npm --version
echo.

echo [INFO] Installing project dependencies...
cd /d "%~dp0"
npm install
if %errorlevel% neq 0 (
    echo [ERROR] Failed to install dependencies!
    pause
    exit /b 1
)

echo [INFO] Building dyrakDGram...
echo.
cd src-tauri
cargo tauri build --release
if %errorlevel% neq 0 (
    echo [ERROR] Failed to build dyrakDGram!
    pause
    exit /b 1
)

echo.
echo ========================================
echo   BUILD SUCCESSFUL!
echo ========================================
echo.
echo Application location:
echo   src-tauri/target/release/bundle/
echo.
echo Starting dyrakDGram...
cd /d "%~dp0"
cd src-tauri/target/release
start "dyrakDGram" dyrak-dgram.exe
echo.
echo [INFO] dyrakDGram has been launched!
echo ========================================
echo   Build Files Location
echo ========================================
echo Windows Portable: src-tauri\target\release\bundle\ntx\
echo   - dyrakDGram_[version]_x64.exe (Portable)
echo   - dyrakDGram_[version]_x64_setup.exe (Installer)
echo.
echo macOS: src-tauri\target\release\bundle\macos\
echo   - dyrakDGram_[version]_aarch64.dmg
echo   - dyrakDGram_[version]_x64.dmg
echo.
echo Linux: src-tauri\target\release\bundle\deb\
echo   - dyrakDGram_[version]_amd64.deb
echo.
pause