@echo off
setlocal

REM Търси AyoGramDesktop.exe в типичните места
set "EXE_PATH="

if exist "%~dp0release\AyoGramDesktop_Portable\AyoGramDesktop.exe" (
    set "EXE_PATH=%~dp0release\AyoGramDesktop_Portable\AyoGramDesktop.exe"
) else if exist "%~dp0src-tauri\target\release\AyoGramDesktop.exe" (
    set "EXE_PATH=%~dp0src-tauri\target\release\AyoGramDesktop.exe"
) else if exist "%~dp0src-tauri\target\debug\AyoGramDesktop.exe" (
    set "EXE_PATH=%~dp0src-tauri\target\debug\AyoGramDesktop.exe"
)

if defined EXE_PATH (
    echo Стартирам: %EXE_PATH%
    start "" "%EXE_PATH%"
) else (
    echo AyoGramDesktop.exe не е намерен.
    echo Пусни първо: .uild-tauri.ps1
    pause
)
