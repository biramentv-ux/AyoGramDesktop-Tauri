# Плъгини - AyoGram Desktop Hybrid

## Готови плъгини

Всички плъгини използват `PluginInterface` и се компилират като отделни Qt6 DLL-и.

### 1. Ghost Mode
- Файлове: `plugins/ghostmodeplugin.h/.cpp/.json`
- Описание: Скрит режим, без известия, анти-рекол
- DLL: `ghostmodeplugin.dll`

### 2. Stream Mode
- Файлове: `plugins/streammodeplugin.h/.cpp/.json`
- Описание: Режим на стриймър, оптимизиран без изскачащи прозорци
- DLL: `streammodeplugin.dll`

### 3. Local Premium
- Файлове: `plugins/localpremiumplugin.h/.cpp/.json`
- Описание: Локален Premium без абонамент
- DLL: `localpremiumplugin.dll`

### 4. Translator
- Файлове: `plugins/translatorplugin.h/.cpp/.json`
- Описание: Автоматичен превод на съобщения
- DLL: `translatorplugin.dll`

### 5. Filters
- Файлове: `plugins/filtersplugin.h/.cpp/.json`
- Описание: Филтри за съобщения и медия
- DLL: `filtersplugin.dll`

### 6. Media Preview
- Файлове: `plugins/mediapreviewplugin.h/.cpp/.json`
- Описание: Предварителен преглед на медия
- DLL: `mediapreviewplugin.dll`

## Build

CMake автоматично ще изгради всички плъгини:

```bash
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release .
mingw32-make
```

Плъгините се копират в `plugins/` папка при portable packaging.
