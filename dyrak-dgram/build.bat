@echo off
cd /d %~dp0

echo === dyrakDGram Build Script for Windows ===

:: Check if Rust is installed
where cargo >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo Error: Rust is not installed. Please install from https://rustup.rs
    exit /b 1
)

:: Check if Tauri CLI is installed
where tauri >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo Installing Tauri CLI...
    npm install -g @tauri-apps/cli
)

echo.
echo === Building dyrakDGram ===

:: Build development version
echo [1/4] Building debug version...
cargo build --manifest-path src-tauri/Cargo.toml --lib
if %ERRORLEVEL% NEQ 0 (
    echo Error: Debug build failed
    exit /b 1
)

:: Build release version
echo [2/4] Building release version...
cargo build --manifest-path src-tauri/Cargo.toml --release --lib
if %ERRORLEVEL% NEQ 0 (
    echo Error: Release build failed
    exit /b 1
)

:: Tauri build
echo [3/4] Running Tauri build...
npm run tauri build
if %ERRORLEVEL% NEQ 0 (
    echo Error: Tauri build failed
    exit /b 1
)

:: Create portable Windows version
echo [4/4] Creating portable Windows version...
mkdir target\portable
copy src-tauri\target\release\dyrak-dgram.exe target\portable\
echo Portable version created in: target\portable

echo.
echo === Build Complete ===
echo Application location: target/portable/dyrak-dgram.exe
echo Installer location: src-tauri/target/release/bundle/
echo.
