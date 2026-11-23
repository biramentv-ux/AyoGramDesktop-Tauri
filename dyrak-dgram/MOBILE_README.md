# 📱 dyrakDGram Mobile - Android & iOS

> **Пълнофункционален Telegram клиент за мобилни устройства**
>
> *Изграден с Tauri Mobile - бърз, лек и сигурен*

---

## 🚀 Features

- ✅ Пълен Telegram протокол
- ✅ Български превод
- ✅ Ghost Mode (скрит режим)
- ✅ Stream Mode (гледане на съдържание)
- ✅ Звукови съобщения
- ✅ Групови чатове
- ✅ Cloud storage (5GB free)
- ✅ End-to-end encryption

---

## 📲 Install

### Android
- **APK**: [Download dyrakDGram APK](https://github.com/dyragram/dyrakDGram/releases)
- **Requirements**: Android 7.0+ (ARM64-v8a, x86_64)

### iOS  
- **App Store**: Coming soon
- **TestFlight**: [Join TestFlight](https://testflight.apple.com/dyragram)
- **Requirements**: iOS 14.0+ (iPhone/iPad)

---

## 🛠️ Build from Source

### Android
```bash
# Install Rust and Tauri CLI
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
source $HOME/.cargo/env
npm install -g @tauri-apps/cli

# Build Android app
cd dyrak-dgram
cargo tauri android build --release
```

### iOS
```bash
# Install Xcode and dependencies
xcode-select --install
npm install -g @tauri-apps/cli

# Build iOS app
cd dyrak-dgram
cargo tauri ios build --release
```

---

## 📁 Project Structure

```
dyrak-dgram/
├── src-tauri/          # Rust backend (Tauri)
├── web/               # Web frontend (React + Tailwind)
├── android/           # Android specific code
│   ├── app/           # App resources
│   └── build.gradle   # Build configuration
├── ios/               # iOS specific code
│   ├── Resources/     # Assets and configs
│   └── Info.plist     # App configuration
└── README.md          # This file
```

---

## 🌐 Web Version

Visit our web app: [https://web.dyragram.app](https://web.dyragram.app)

- **Light/Dark mode**: Automatic switching
- **Responsive design**: Works on all devices
- **Instant sync**: Real-time updates

---

## 🤝 Contributing

We welcome contributions! Here's how you can help:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'feat: add some amazing feature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📄 License

Distributed under MIT License. See `LICENSE` for details.

---

## 💬 Support

- Telegram group: [@dyrakDGramChat](https://t.me/dyrakDGramChat)
- GitHub issues: [Report a bug](https://github.com/dyragram/dyrakDGram/issues)

---

*dyrakDGram is not affiliated with Telegram or Telegram FZ LLC*

---

<div align="center">
  <img src="https://img.shields.io/github/license/dyragram/dyrakDGram?style=flat-square">
  <img src="https://img.shields.io/github/v/release/dyragram/dyrakDGram?style=flat-square">
  <img src="https://img.shields.io/github/stars/dyragram/dyrakDGram?style=flat-square">
</div>
