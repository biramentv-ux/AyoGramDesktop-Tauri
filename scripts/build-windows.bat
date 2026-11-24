@echo off
echo ========================================
echo   dyrakDGram - Windows Build Script
echo   Търговска версия за изграждане
echo ========================================
echo.

echo [INFO] Building dyrakDGram for Windows...
echo.

REM Check Rust
cargo --version >nul 2>&nul
if %errorlevel% neq 0 (
    echo [ERROR] Rust is not installed!
    echo Please install from: https://rustup.rs/
    pause
    exit /b 1
)

echo [INFO] Rust is installed.
cargo --version
echo.

REM Check Node.js
node --version >nul 2>&nul
if %errorlevel% neq 0 (
    echo [ERROR] Node.js is not installed!
    pause
    exit /b 1
)

echo [INFO] Node.js is installed.
node --version
echo.

REM Install dependencies
echo [INFO] Installing npm dependencies...
npm install
if %errorlevel% neq 0 (
    echo [ERROR] Failed to install dependencies!
    pause
    exit /b 1
)

echo [OK] Dependencies installed successfully.
echo.

REM Clean previous build
echo [INFO] Cleaning previous builds...
cd src-tauri
cargo clean >nul 2>&nul
echo [OK] Previous builds cleaned.
echo.

REM Build release version
echo [INFO] Building release version...
echo This may take a few minutes on first build.
echo.

cargo tauri build --release --target x86_64-pc-windows-msvc
if %errorlevel% neq 0 (
    echo [ERROR] Build failed!
    pause
    exit /b 1
)

echo.
echo ========================================
echo   BUILD SUCCESSFUL!
echo ========================================
echo.
echo Output location:
echo   src-tauri/target/release/bundle/
echo.
echo Executable:
echo   dyrakDGram.exe
echo.
echo Installer:
echo   dyrakDGram_[version]_x64_setup.exe
echo.

REM Show files
echo [INFO] Files in bundle directory:
cd src-tauri/target/release/bundle/ntx 2>nul || cd src-tauri/target/release/bundle 2>nul
if exist *.exe (
    echo Found executable files:
    dir /b *.exe
) else (
    echo Executable not found in bundle directory.
)
echo.

REM Launch
echo [INFO] Launching dyrakDGram...
cd src-tauri/target/release
start "dyrakDGram" dyrak-dgram.exe
echo.
echo [OK] dyrakDGram has been launched!
pause