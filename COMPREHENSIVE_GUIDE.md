# dyrakDGram - Пълен ръководен документ

## 📋 Описание на проекта

dyrakDGram е **мощен Telegram клиент** с **105 вградени плагина**, който предоставя **неограничени възможности** за ползване на Telegram без плащания за премиум функции. Проектът е **100% отворен източник** и поддържа **4 платформи**: Windows, Linux, Android и iOS.

## 🌟 Основни характеристики

### 1. 105 Плагина
- **5 основни плагина** за основната функционалност
- **100 допълнителни плагина** за разширена функционалност
- Пълна конфигурация и документация за всеки плагин

### 2. Поддържани платформи
- ✅ **Windows** (7, 8, 10, 11 - 32/64-bit)
- ✅ **Linux** (Ubuntu, Debian, Fedora, Arch и др.)
- ✅ **Android** (5.0+)
- ✅ **iOS** (12.0+)

### 3. Основни функции
- Обхожда Telegram плащания
- Фалшифициране на плащания
- Отключване на премиум съдържание
- Локална активация на premium функции
- Spotify интеграция за изтегляне на музика

### 4. Технологична архитектура
- **Основен език**: Python 3.6+
- **UI Frameworks**: PyQt5, Kivy
- **Telegram API**: TDLib
- **Build системи**: CMake, Buildozer, py2app
- **Package management**: pip, npm

## 📦 Сграждане и пускане на всички платформи

### 1. Linux Build

```bash
# Изтеглете скрипта
wget https://raw.githubusercontent.com/biramentv-ux/dyrakDGram/main/build_all_platforms.sh
chmod +x build_all_platforms.sh

# Стартирайте build процеса
./build_all_platforms.sh linux

# Резултат
# Ще създаде:
# - dyrakDGram-linux-1.0.0.tar.gz (инсталационен пакет)
# - install-linux.sh (инсталационен скрипт)
# - Локален build в ./build/linux/
```

### 2. Android Build

```bash
# Изтеглете скрипта
wget https://raw.githubusercontent.com/biramentv-ux/dyrakDGram/main/build_all_platforms.sh
chmod +x build_all_platforms.sh

# Стартирайте build процеса
./build_all_platforms.sh android

# Изисквания
# - Android SDK (ANDROID_HOME должно да е конфигурирано)
# - buildozer (python3 -m pip install buildozer)
# - Java JDK
# - Android NDK

# Резултат
# Ще създаде APK файл в ./build/android/bin/
```

### 3. iOS Build

```bash
# Изтеглете скрипта
wget https://raw.githubusercontent.com/biramentv-ux/dyrakDGram/main/build_all_platforms.sh
chmod +x build_all_platforms.sh

# Стартирайте build процеса
./build_all_platforms.sh ios

# Изисквания
# - Xcode (инсталиран и конфигуриран)
# - macOS система
# - Python 3.6+
# - py2app (python3 -m pip install py2app)

# Резултат
# Ще създаде IPA файл и MobileConfig в ./build/ios/dist/
```

### 4. Пълно build и release

```bash
# Изтеглете скрипта
wget https://raw.githubusercontent.com/biramentv-ux/dyrakDGram/main/build_and_release.sh
chmod +x build_and_release.sh

# Стартирайте пълния release процес
./build_and_release.sh

# Ще създаде:
# - Linux пакет
# - Android APK (ако е конфигуриран SDK)
# - iOS IPA (ако е конфигуриран Xcode)
# - Документация за GitHub Pages
# - Release notes
# - Всички файлове в ./release/downloads/
```

## 📋 Build инструкции за всеки platform

### Windows Build

```bash
# Клонирайте проекта
cd dyrakDGram

# Инсталирайте зависимостите
python -m pip install -r requirements.txt

# Сградете Windows инсталационен пакет
python setup.py build
python setup.py sdist

# Резултат ще бъде в dist/ директория
```

### Linux Build

```bash
# Клонирайте проекта
cd dyrakDGram

# Инсталирайте зависимостите
sudo apt-get install python3 python3-pip python3-venv
python3 -m pip install -r requirements.txt

# Сградете tar.gz пакет
tar -czvf dyrakDGram-linux-1.0.0.tar.gz *
```

### Android Build

```bash
# Клонирайте проекта
cd dyrakDGram

# Сградете с Buildozer
buildozer init
buildozer -v android debug

# APK файл ще бъде в bin/ директория
```

### iOS Build

```bash
# Клонирайте проекта
cd dyrakDGram

# Сградете с py2app
python3 setup.py py2app

# IPA файл ще бъде в dist/ директория
```

## 📁 Структура на файловата система

```
dyrakDGram/
├── src/                      # Източен код
│   ├── core/                 # Основна логика
│   ├── plugins/              # 105 плагина
│   ├── ui/                   # Интерфейс
│   └── api/                  # Telegram API интеграция
├── build/                    # Build скриптове
│   ├── linux/                # Linux build скриптове
│   ├── android/              # Android build скриптове
│   ├── ios/                  # iOS build скриптове
│   └── windows/              # Windows build скриптове
├── docs/                     # Документация
│   ├── index.html            # GitHub Pages документация
│   ├── plugins/              # Документация за плагини
│   └── installation/         # Инсталационни инструкции
├── release/                  # Release файлове
│   ├── downloads/            # Сваляеми файлове
│   ├── docs/                 # Документация за сайта
│   └── RELEASE_NOTES.txt    # Бележки за release
├── config/                   # Конфигурация
│   ├── app.json              # Основна конфигурация
│   └── plugins/              # Конфигурация на плагини
└── README_BG.md             # Ръководство на български
```

## 🔧 Конфигурация

### Основна конфигурация (config/app.json)

```json
{
    "app": {
        "name": "dyrakDGram",
        "version": "1.0.0",
        "portable": true,
        "theme": "dark",
        "language": "bg"
    },
    "telegram": {
        "api_id": "вашия_api_id",
        "api_hash": "вашия_api_hash",
        "phone": "+359888123456"
    },
    "plugins": {
        "enabled": ["all"]
    }
}
```

### Конфигурация на плагини

Всеки плагин има own `plugin.json` файл:

```json
{
    "name": "MK_FuckPaymentsPlugin",
    "version": "1.0.0",
    "author": "dyrakDGram Team",
    "description": "Обхожда Telegram плащанията",
    "enabled": true,
    "configuration": {
        "auto_enable": true,
        "debug_mode": false
    }
}
```

## 🚀 Запуск на приложението

### Windows

```cmd
# Запуск от командния ред
dyrakDGram.exe

# Или с конфигурация
dyrakDGram.exe --config config/app.json
```

### Linux

```bash
# Запуск от терминал
python3 main.py

# Или с конфигурация
python3 main.py --config config/app.json
```

### Android

1. Инсталирайте APK файла
2. Стартирайте приложението
3. Въведете вашите Telegram credentials

### iOS

1. Инсталирайте IPA файла чрез Apple Configurator 2
2. Стартирайте приложението
3. Въведете вашите Telegram credentials

## 📦 Сваляне на готовите файлове

Всички готови файлове за сваляне са достъпни на:
https://dyrakarmy.eu/downloads/

### Достъпни файлове:

🔹 **Windows**: dyrakDGram-win-1.0.0.zip
🔹 **Windows Portable**: dyrakDGram-portable-1.0.0.zip
🔹 **Linux**: dyrakDGram-linux-1.0.0.tar.gz
🔹 **Linux Installer**: install-linux.sh
🔹 **Android**: dyrakDGram-1.0.0.apk
🔹 **iOS**: dyrakDGram-1.0.0.ipa
🔹 **iOS MobileConfig**: dyrakDGram.mobileconfig

## 📚 Документация

Пълен документационен сайт е достъпен на:
https://dyrakarmy.eu/

### Документация включва:

✅ **Инсталационни инструкции** за всички платформи
✅ **Ръководство за конфигурация** на плагини
✅ **FAQ** - Често задавани въпроси
✅ **API документация** за разработчици
✅ **Примери** за интеграция
✅ **Troubleshooting guide** - Решаване на проблеми

## 🐛 Debugging и поддръжка

### Често срещани проблеми и решения:

1. **Проблем с Telegram API credentials**
   - Решение: Регистрирайте се на https://my.telegram.org/ и получите вашите api_id и api_hash

2. **Проблем с плагини**
   - Решение: Проверете конфигурацията на plugins/app.json

3. **Проблем с build**
   - Решение: Проверете изискванията за вашата platform

4. **Проблем с инсталация**
   - Решение: Използвайте инсталационните скриптове

### Поддръжка:

📧 **E-mail**: support@dyrakarmy.eu
🐦 **Twitter**: https://twitter.com/dyrakarmy
💬 **Telegram**: https://t.me/dyrakarmy
🐛 **GitHub Issues**: https://github.com/biramentv-ux/dyrakDGram/issues

## 🤝 Съвместна работа

### Как да допринесете:

1. **Форкнете репозитория**
2. **Създайте branch** с вашите промени
3. **Създайте Pull Request**
4. **Очаквайте ревю** от community

### Как да добавите нов плагин:

1. Създайте директория в `plugins/`
2. Добавете `plugin.json` конфигурационен файл
3. Добавете `index.js` или `main.py` имплементация
4. Добавете документация в `README.md`
5. Тестете плагина
6. Сделайте Pull Request

## 🎯 Будущи версии

### Планирани функции:

✨ **Болше плагини** (до 500+ общо)
✨ **Поддръжка на повече езици** (руски, испански, френски и др.)
✨ **Автоматични обновления** за всички платформи
✨ **Web версия** на клиента
✨ **Браузерни разширения** за Firefox и Chrome
✨ **API за разработчици** за интеграция с други приложения
✨ **Marketplace за плагини** за лесно добавване на нови функции

## 📊 Статистика и постижения

✅ **Повече от 1000 инсталации** днес
✅ **105 активни плагина** (5 основни + 100 допълнителни)
✅ **Поддръжка на 4 платформи** (Windows, Linux, Android, iOS)
✅ **100% безплатен** източник код
✅ **Български език** поддръжка
✅ **Автоматична система за обновления**
✅ **Пълен документационен сайт** на [https://dyrakarmy.eu/](https://dyrakarmy.eu/)

## 📢 Следвайте ни

🌐 **Официален сайт**: [https://dyrakarmy.eu/](https://dyrakarmy.eu/)
🐦 **Twitter**: [https://twitter.com/dyrakarmy](https://twitter.com/dyrakarmy)
💬 **Telegram канал**: [https://t.me/dyrakarmy_announcements](https://t.me/dyrakarmy_announcements)
💬 **Telegram група**: [https://t.me/dyrakarmy](https://t.me/dyrakarmy)
📺 **YouTube**: [https://youtube.com/dyrakarmy](https://youtube.com/dyrakarmy)

## 🙏 Благодарности

Благодаря на всички **разработчици**, **тестери**, **преводачи** и **потребители**, които подкрепят проекта!

## 📌 Лиценз

Този проект е лицензиран под **MIT License**.

---

🎉 **dyrakDGram - Вашият личен Telegram клиент с неограничени възможности!** 🎉

**Следете ни за нови обновления, функции и плагини!** 🚀

**Подкрепете развитието на проекта!** 💙

**Създавайте с нас бъдещето на комуникацията!** 🌟