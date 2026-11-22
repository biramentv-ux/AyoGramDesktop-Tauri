@echo off
setlocal

REM Търси dyrakDGram.exe в типичните места
set "EXE_PATH="

if exist "%~dp0release\dyrakDGram_Portable\dyrakDGram.exe" (
    set "EXE_PATH=%~dp0release\dyrakDGram_Portable\dyrakDGram.exe"
) else if exist "%~dp0src-tauri\target\release\dyrakDGram.exe" (
    set "EXE_PATH=%~dp0src-tauri\target\release\dyrakDGram.exe"
) else if exist "%~dp0src-tauri\target\debug\dyrakDGram.exe" (
    set "EXE_PATH=%~dp0src-tauri\target\debug\dyrakDGram.exe"
)

if defined EXE_PATH (
    echo Стартирам: %EXE_PATH%
    start "" "%EXE_PATH%"
) else (
    echo dyrakDGram.exe не е намерен.
    echo Пусни първо: .uild-tauri.ps1
    pause
)
