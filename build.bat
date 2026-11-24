@echo off
echo Building dyrakDGram Windows Portable Version...
echo.

REM Check if Rust is installed
where cargo >nul 2>nul
if %errorlevel% neq 0 (
    echo Error: Rust/Cargo not found. Please install Rust from https://rustup.rs/
    pause
    exit /b 1
)

echo Setting up project structure...
if not exist "target" mkdir target

echo.
echo Building dyrakDGram for Windows...
cargo build --release --target x86_64-pc-windows-msvc

echo.
echo Creating portable version...
if exist "target\x86_64-pc-windows-msvc\release\dyrak-dgram.exe" (
    echo Copying executable to portable folder...
    if not exist "portable" mkdir portable
    copy "target\x86_64-pc-windows-msvc\release\dyrak-dgram.exe" "portable\"
    
    echo Creating Windows Portable structure...
    cd portable
    
    REM Create standard portable folder structure
    if not exist "data" mkdir data
    if not exist "plugins" mkdir plugins
    
    echo.
    echo Portable version created successfully!
    echo Location: %cd%\portable
    echo Run dyrak-dgram.exe to start the application.
    
    cd ..
) else (
    echo Error: Build failed or executable not found
    exit /b 1
)

echo.
echo Build completed successfully!
pause
