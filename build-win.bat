@echo off
title dyrakDGram - Windows Portable Build
color 0A

echo === dyrakDGram Windows Portable Build ===
echo.

REM Check if Rust is installed
where cargo >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Rust not found. Please install Rust from https://rustup.rs
    pause
    exit /B 1
)

echo [1/5] Checking Rust installation...
cargo --version

echo.
echo [2/5] Cleaning previous builds...
cargo clean

echo.
echo [3/5] Building debug version...
cargo build --release

echo.
echo [4/5] Setting up portable directory structure...
if exist "dist" rmdir /S /Q dist
mkdir dist
mkdir dist\dyrakDGram
mkdir dist\dyrakDGram\plugins
mkdir dist\dyrakDGram\config

echo.
echo [5/5] Copying build artifacts and resources...

REM Copy the executable
copy /Y "target\release\dyrakDGram.exe" "dist\dyrakDGram\" 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo WARNING: Executable not found at target\release\dyrakDGram.exe
    echo Trying alternative path...
    for %%F in (target\release\*.exe) do copy /Y "%%F" "dist\dyrakDGram\" 2>nul
)

REM Copy plugins
copy /Y "src-tauri\src\plugins\*.rs" "dist\dyrakDGram\plugins\" 2>nul

REM Create portable configuration
echo {
echo     "app_name": "dyrakDGram",
echo     "version": "1.0.0",
echo     "portable_mode": true,
echo     "plugins": [
echo         "fake_payment_interceptor",
echo         "mk_fuck_payments", 
echo         "unlock_stars_content",
echo         "local_telegram_premium",
echo         "spotydown"
echo     ]
echo } > dist\dyrakDGram\config\app.json

REM Create startup script
echo @echo off > dist\dyrakDGram\start.bat
echo cd /d "%~dp0" >> dist\dyrakDGram\start.bat
echo start dyrakDGram.exe >> dist\dyrakDGram\start.bat
echo echo dyrakDGram started! >> dist\dyrakDGram\start.bat

echo.
echo Build complete!
echo Portable version located at: dist\dyrakDGram\
echo.
echo To run: double-click dist\dyrakDGram\start.bat
echo.
pause
