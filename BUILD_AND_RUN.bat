@echo off
setlocal

REM Build и стартирай dyrakDGram

echo Build-ва се dyrakDGram...
powershell -ExecutionPolicy Bypass -Command "& '%~dp0Makefile.ps1' build"

if exist "%~dp0release\dyrakDGram_Portable\dyrakDGram.exe" (
    echo Стартирам portable версия...
    start "" "%~dp0release\dyrakDGram_Portable\dyrakDGram.exe"
) else (
    echo Build завършен, но изпълнимият файл не е намерен.
    pause
)
