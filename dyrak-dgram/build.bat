@echo off
rem Build script for dyrakDGram Mobile
rem Supports Android, iOS, and Web platforms

echo ============================
echo   dyrakDGram Build Script
echo ============================
echo.

rem Check if Rust is installed
where rustc >nul 2>nul
if %errorlevel% neq 0 (
    echo ERROR: Rust is not installed.
    echo Please install Rust from https://rustup.rs
    exit /b 1
)

rem Check if Tauri CLI is installed
where tauri >nul 2>nul
if %errorlevel% neq 0 (
    echo WARNING: Tauri CLI not found. Installing with npm...
    call npm install -g @tauri-apps/cli
)

rem Function to build web app
call :build_web
goto :eof

:build_web
echo Building Web App...
cd web
if not exist node_modules (
    npm install
)
npm run build
cd ..
echo Build completed!
echo Open web/dist/ in your browser.
exit /b 0

rem Function to build desktop version
call :build_desktop
goto :eof

:build_desktop
echo Building Windows Portable...
cargo tauri build --release
echo Desktop build completed!
echo Find executable in src-tauri/target/release/
exit /b 0
