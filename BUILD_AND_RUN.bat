@echo off
setlocal

REM Build и стартирай AyoGramDesktop

echo Build-ва се AyoGramDesktop...
powershell -ExecutionPolicy Bypass -Command "& '%~dp0Makefile.ps1' build"

if exist "%~dp0release\AyoGramDesktop_Portable\AyoGramDesktop.exe" (
    echo Стартирам portable версия...
    start "" "%~dp0release\AyoGramDesktop_Portable\AyoGramDesktop.exe"
) else (
    echo Build завършен, но изпълнимият файл не е намерен.
    pause
)
