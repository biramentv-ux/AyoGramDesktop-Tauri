# Старт на разработка - dyrakDGram

## Създаден проект

Проектът е хибрид между dyrakDGram и exDekstop с:
- Desktop Windows клиент
- Portable версия (без инсталация)
- Без Android emulator
- Готови плъгини: Ghost Mode, Stream Mode
- Поддръжка на български език

## Файлове създадени

### Core
- main.cpp
- mainwindow.h / mainwindow.cpp
- CMakeLists.txt
- build.bat
- package_portable.bat

### Настройки
- ayu_settings.h / ayu_settings.cpp
- ayu_translator.h / ayu_translator.cpp

### Плъгини
- plugins/plugininterface.h
- plugins/ghostmodeplugin.h / ghostmodeplugin.cpp
- plugins/streammodeplugin.h / streammodeplugin.cpp
- pluginmanager.h / pluginmanager.cpp

### Превода
- translations/ayu_bg.ts

## Следващи стъпки

1. Компилирай с CMake + MinGW
2. Тествай плъгините
3. Добави още плъгини: Local Premium, Translator, Filters
4. Създай portable пакет с package_portable.bat

## Portable структура

dyrakDGramHybrid_Portable/
├── exe
├── plugins/
├── translations/
└── settings.json
