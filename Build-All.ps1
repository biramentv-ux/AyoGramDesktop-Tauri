# Build-All.ps1 - Пълен автоматичен build за dyrakDGram хибрид
# Qt 6 + TDLib, portable Windows клиент, с aqtinstall

param(
    [string]$QtVersion = "6.7.2",
    [string]$QtArch    = "win64_msvc2022_64",
    [string]$QtDir     = "C:\Qt",
    [string]$ProjectDir = "$PSScriptRoot",
    [string]$BuildType  = "Release",
    [string]$BuildDir   = "$ProjectDir\build"
)

Write-Host "=== dyrakDGram Build-All ===" -ForegroundColor Green
Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

# 1. Python
if (-not (Get-Command python -ErrorAction SilentlyContinue)) {
    Write-Host "Python не е намерен, инсталирам..." -ForegroundColor Yellow
    winget install -e --id Python.Python.3.11
}

# 2. aqtinstall
pip install -q aqtinstall

# 3. Qt
$QtPath = Join-Path $QtDir "$QtVersion\$QtArch"
if (-not (Test-Path "$QtPath\bin\qmake.exe")) {
    Write-Host "Qt $QtVersion липсва, свалям с aqt..." -ForegroundColor Cyan
    # Проверка на налични архитекттури
    python -m aqt list-qt windows desktop --arch $QtVersion | Write-Host
    python -m aqt install-qt windows desktop $QtVersion $QtArch -O $QtDir -m qtbase qttools
    if (-not (Test-Path "$QtPath\bin\qmake.exe")) {
        Write-Error "Qt не е инсталиран в $QtPath"
        exit 1
    }
} else {
    Write-Host "Qt намерен: $QtPath" -ForegroundColor Green
}

# 4. CMake
if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    Write-Host "CMake не е намерен, инсталирам..." -ForegroundColor Yellow
    winget install -e --id Kitware.CMake
}

# 5. Git
if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
    winget install -e --id Git.Git
}

# 6. TDLib
$TdLibDir = "$ProjectDir\tdlib"
if (-not (Test-Path $TdLibDir)) {
    Write-Host "Сваляне на TDLib..." -ForegroundColor Cyan
    git clone https://github.com/tdlib/td.git $TdLibDir
}
$TdBuild = "$TdLibDir\build"
if (-not (Test-Path "$TdBuild\tdlibrary.lib")) {
    Write-Host "Компилация на TDLib..." -ForegroundColor Cyan
    mkdir $TdBuild -Force
    Push-Location $TdBuild
    cmake "$TdLibDir" -DCMAKE_BUILD_TYPE=$BuildType -DBUILD_SHARED_LIBS=OFF
    cmake --build . --config $BuildType -- /m
    Pop-Location
}

# 7. Build проекта
mkdir $BuildDir -Force
Push-Location $BuildDir
Write-Host "Конфигурация на проекта с Qt..." -ForegroundColor Cyan
cmake "$ProjectDir" -DCMAKE_PREFIX_PATH="$QtPath" -DCMAKE_BUILD_TYPE=$BuildType -DTD_LIBRARY_DIR="$TdBuild"
if ($LASTEXITCODE -ne 0) { Write-Error "CMake конфигурация неуспешна"; exit 1 }

Write-Host "Компилация..." -ForegroundColor Cyan
cmake --build . --config $BuildType -- /m
if ($LASTEXITCODE -ne 0) { Write-Error "Build неуспешен"; exit 1 }

Pop-Location

# 8. Portable пакет
$PortableDir = "$ProjectDir\dyrakDGram_Portable"
if (Test-Path $PortableDir) { Remove-Item $PortableDir -Recurse -Force }
mkdir $PortableDir | Out-Null
Copy-Item "$BuildDir\$BuildType\dyrakDGram.exe" $PortableDir
Copy-Item "$ProjectDir\translations" $PortableDir -Recurse
Copy-Item "$ProjectDir\plugins" $PortableDir -Recurse
Copy-Item "$ProjectDir\ayu_settings.json" $PortableDir -ErrorAction SilentlyContinue

# копирай Qt плъгини DLL ако съществуват
if (Test-Path "$QtPath\plugins") {
    Copy-Item "$QtPath\plugins\platforms\qwindows.dll" "$PortableDir\plugins\platforms" -ErrorAction SilentlyContinue
}

Write-Host "Готово! Изпълним файл: $BuildDir\$BuildType\dyrakDGram.exe" -ForegroundColor Green
Write-Host "Portable пакет: $PortableDir" -ForegroundColor Green
