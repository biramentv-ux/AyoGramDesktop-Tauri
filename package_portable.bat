@echo off

REM Portable packaging for Windows
set APP_NAME=AyoGramDesktop
set BUILD_DIR=Release
set OUTPUT_DIR=%APP_NAME%_Portable

if not exist %BUILD_DIR%\%APP_NAME%.exe (
echo Build not found. Run build.bat first.
exit /b 1
)

mkdir %OUTPUT_DIR%
mkdir %OUTPUT_DIR%\plugins
mkdir %OUTPUT_DIR%\translations
copy %BUILD_DIR%\%APP_NAME%.exe %OUTPUT_DIR%\
copy %BUILD_DIR%\plugins\*.dll %OUTPUT_DIR%\plugins\
copy plugins\*.json %OUTPUT_DIR%\plugins\
copy translations\* %OUTPUT_DIR%\translations\
copy ayu_settings.json %OUTPUT_DIR%\

REM Create portable config
@echo [Portable] > %OUTPUT_DIR%\portable.ini
@echo Portable=true >> %OUTPUT_DIR%\portable.ini
@echo NoInstall=true >> %OUTPUT_DIR%\portable.ini

echo Portable package created in %OUTPUT_DIR%
pause