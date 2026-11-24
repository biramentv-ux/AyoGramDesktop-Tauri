@echo off
echo ========================================
echo   dyrakDGram - Project Setup Script
echo   Пълно инсталиране и настройка
echo ========================================
echo.

echo [INFO] Checking system requirements...
echo.

REM Check Rust
echoChecking Rust installation...
where cargo >nul 2>nul
if %errorlevel% neq 0 (
    echo [ERROR] Rust is not installed!
    echo.
    echo Please install Rust:
    echo   - Download: https://rustup.rs/
    echo   - Or run: winget install Rust.Rust
    echo.
    set /p INSTALL_RUST="Do you want to try to install Rust with winget? (y/n): "
    if /i "%INSTALL_RUST%"=="y" (
        echo [INFO] Installing Rust...
        winget install Rust.Rust
    ) else (
        echo [INFO] Please install Rust manually and run this script again.
        pause
        exit /b 1
    )
) else (
    echo [OK] Rust is installed.
    cargo --version
echo.
)

REM Check Node.js
echoChecking Node.js installation...
where node >nul 2>nul
if %errorlevel% neq 0 (
    echo [ERROR] Node.js is not installed!
    echo.
    echo Please install Node.js:
    echo   - Download: https://nodejs.org/
    echo   - Or run: winget install OpenJS.NodeJS
    pause
    exit /b 1
) else (
    echo [OK] Node.js is installed.
    node --version
echo.
)

echo [INFO] Installing project dependencies...
echo.
npm install
if %errorlevel% neq 0 (
    echo [ERROR] Failed to install npm dependencies!
    pause
    exit /b 1
)

echo.
echo [INFO] Building Tauri application...
echo.
cd src-tauri
cargo tauri build --release
if %errorlevel% neq 0 (
    echo [ERROR] Failed to build!
    pause
    exit /b 1
)

echo.
echo ========================================
echo   SETUP COMPLETE!
echo ========================================
echo.
echo Application ready at:
echo   src-tauri/target/release/bundle/
echo.
echo Launch dyrakDGram:
echo   start src-tauri\target\release\dyrak-dgram.exe
echo.
pause