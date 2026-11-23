# 🚀 dyrakDGram Mobile & Web

> **Съвременен Telegram клиент с мобилни версии и уеб приложение.**

[![Windows](https://img.shields.io/badge/platform-Windows_10/11-blue?style=flat-square)](https://windows.com)
[![Android](https://img.shields.io/badge/platform-Android-green?style=flat-square)](https://android.com)
[![iOS](https://img.shields.io/badge/platform-iOS-blue?style=flat-square)](https://ios.com)
[![Web](https://img.shields.io/badge/web-React_JS-orange?style=flat-square)](https://react.dev)

---

## 📱 Мобилни Версии

### Android
- **Изтегли:** [dyrakDGram APK](https://github.com/dyrakDGram/dyrakDGram/releases)
- **Min SDK:** Android 7.0 (Nougat)
- **Размер:** ~25 MB
- **Формат:** Standalone APK (не е нужен Google Play)

### iOS
- **Итегли:** [dyrakDGram IPA](https://github.com/dyrakDGram/dyrakDGram/releases)
- **Min SDK:** iOS 14.0
- **Размер:** ~30 MB
- **Формат:** Standalone IPA (не е нужен App Store)

---

## 🌐 Уеб Версия

### Личен Домейн
dyrakDGram уеб версията може да се разположи на личен домейн за напълно функционален достъп.

**Примерна конфигурация:**
```nginx
server {
    listen 80;
    server_name your-domain.com;
    root /path/to/dyrak-dgram/web/dist;
    index index.html;
    
    location / {
        try_files $uri $uri/ /index.html;
    }
}
```

### Функции:
- ✅ Telegram API интеграция
- ✅ Реално време съобщения
- ✅ Групови чатове
- ✅ Файлове и мултимедия
- ✅ Персонализируем интерфейс

---

## 🔧 Технологии

### Desktop (Tauri)
- ⚡️ Tauri 2.x + Rust
- 🎨 Tailwind CSS
- 🔐 Secure protocol handling

### Mobile (React Native/Flutter alternative)
- 📱 React for web-first approach
- 🎯 Cross-platform compatibility
- 🔄 Real-time data sync

### Web (React)
- ⚛️ React 18.x
- 🎨 Tailwind CSS
- 📡 Vite bundler

---

## 🛠 Installation

### Desktop
```bash
# Clone the repository
git clone https://github.com/dyrakDGram/dyrakDGram.git
cd dyrak-dgram

# Build for Windows
cargo tauri build --target x86_64-pc-windows-msvc

# Build portable version
cargo tauri build --target x86_64-pc-windows-msvc --features portable
```

### Mobile (Android)
```bash
# Setup Android environment
export ANDROID_SDK_PATH=/path/to/android/sdk
export ANDROID_NDK_PATH=/path/to/android/ndk

# Build APK
cargo tauri android build
```

### Mobile (iOS)
```bash
# Setup iOS environment
# Install Xcode and command line tools

# Build IPA
cargo tauri ios build
```

### Web
```bash
cd web
npm install
npm run dev
npm run build
```

---

## 📂 Project Structure

```
dyrak-dgram/
├── src-tauri/          # Tauri backend (Rust)
│   ├── src/
│   │   ├── main.rs    # Application entry point
│   │   ├── lib.rs     # Library with plugin system
│   │   └── plugins/   # Plugin modules
│   ├── Cargo.toml     # Rust dependencies
│   └── tauri.conf.json # Tauri configuration
├── web/               # Web frontend (React)
│   ├── src/
│   │   ├── App.jsx    # Main React component
│   │   ├── index.js   # Entry point
│   │   └── index.css  # Global styles
│   ├── package.json   # NPM dependencies
│   └── vite.config.js # Vite configuration
├── build/             # Build artifacts
└── README.md         # This file
```

---

## 🌟 Features

### Desktop Features
- ⚡️ Бърз и ефективен
- 🎨 Съвременен дизайн
- 🔐 Приватност и сигурност
- 📁 Файлови трансфер
- 🎧 Stream режим за музика

### Mobile Features
- 📱 Оптимизиран за мобилни устройства
- 🔔 Push notifications
- 💬 Групови чатове
- 📸 Камера интеграция
- 🎵 Музикален плейър

### Web Features
- 🌐 Достъп от всички устройства
- 🔄 Синхронизация в реално време
- 🎨 Теми и цветове
- 🔍 Търсене и филтри

---

## 📄 License

MIT License - See full license in [LICENSE](LICENSE) file.

---

## 👥 Authors

- **dyrakDGram** - [GitHub](https://github.com/dyrakDGram)

---

## 🙏 Acknowledgments

- Based on Telegram API
- Inspired by AyoGram Desktop
- Built with Tauri framework

---

## 📞 Support

Need help? Join our:
- [Telegram Channel](https://t.me/dyrakDGram)
- [GitHub Discussions](https://github.com/dyrakDGram/dyrakDGram/discussions)
- [Issue Tracker](https://github.com/dyrakDGram/dyrakDGram/issues)

---

**dyrakDGram** - Telegram, but your way. 🚀
