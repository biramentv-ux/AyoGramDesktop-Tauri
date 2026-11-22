@echo off

echo Building dyrakDGram Application

cd /d "%~dp0"

cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release .
mingw32-make

if exist Release\plugins mkdir Release\plugins 2>nul
copy plugins\*.dll Release\plugins\ 2>nul
copy plugins\*.json Release\plugins\ 2>nul

echo Build completed successfully!
echo Plugins ready in Release\plugins