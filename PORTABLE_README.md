# dyrakDGram - Portable Version

## Характеристики

- **Хибрид между dyrakDGram и exDekstop**
- **Без Android emulator** - директен desktop Windows клиент
- **Portable версия** - работи от USB без инсталация
- **Готови плъгини**: Ghost Mode, Stream Mode
- **Български език** по подразбиране

## Плъгини

### Ghost Mode (Скрит режим)
- Скрит режим на съобщения
- Без известия
- Анти-рекол

### Stream Mode (Режим на стриймър)
- Оптимизиран за стрийм
- Спряни известия
- Специални настройки

## Стартиране

1. Разопаковай архива
2. Стартирай `dyrakDGramHybrid.exe`
3. Приложението е готово за работа

## Структура

```
dyrakDGramHybrid_Portable/
├── dyrakDGramHybrid.exe
├── plugins/
│   ├── ghostmodeplugin.dll
│   └── streammodeplugin.dll
├── translations/
│   └── ayu_bg.qm
├── portable.ini
└── ayu_settings.json
```

## Настройки

Всички настройки се запазват в `ayu_settings.json` в същата папка.

## Компилация

```bash
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release .
mingw32-make
```
