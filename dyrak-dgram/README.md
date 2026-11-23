# 🚀 dyrakDGram - Mobile Ready Edition

> **Telegram, но по твой начин.** Хибриден клиент с Ghost Mode и Stream Mode за desktop и мобилни устройства.

[![Platform](https://img.shields.io/badge/platform-Windows%2010/11-blue?style=flat-square)](https://windows.microsoft.com)
[![Tauri](https://img.shields.io/badge/framework-Tauri%202-red?style=flat-square)](https://tauri.app)
[![Rust](https://img.shields.io/badge/language-Rust-orange?style=flat-square)](https://rust-lang.org)
[![License](https://img.shields.io/github/license/Dyragram/Project)](LICENSE)

---

## 📱 Features

### Desktop
- ⚡️ Tauri + Rust + Vite/Tailwind за максимална скорост
- 🎨 Minimal memory footprint
- 🔌 Истинска плагин архитектура
- 💻 Windows portable build
- 🌐 Web UI

### Mobile (Android & iOS)
- 📱 Native mobile support
- 🔄 Full Telegram integration
- ⚡️ Lightning fast performance
- 💾 Local storage optimization
- 🔒 End-to-end encryption

## 🛠 Installation

### Desktop
1. Clone the repository:
```bash
git clone https://github.com/Dyragram/Project.git
cd Project/dyrak-dgram
```

2. Install dependencies:
```bash
npm install
```

3. Run in development mode:
```bash
npm run tauri dev
```

4. Build release:
```bash
npm run tauri build
```

### Mobile

#### Android
1. Setup Android SDK and NDK
2. Build APK:
```bash
cargo tauri build --target aarch64-linux-android --release
```
3. Install on device:
```bash
adb install target/aarch64-linux-android/release/apk/
```

#### iOS
1. Setup Xcode and iOS toolchain
2. Build IPA:
```bash
cargo tauri build --target aarch64-apple-ios --release
```
3. Install via Xcode or TestFlight

## 📦 Plugins

| Plugin | Description |
|--------|-------------|
| MK Fuck Payments | Advanced payment system replacement |
| Fake Payment Interceptor | Intercept and process payments |
| Unlock Stars Content | Access premium content without subscription |
| Local Telegram Premium | Local premium features implementation |
| SpotyDown | Audio processing and download management |

## 🚀 Web Frontend

The web version runs on your personal domain:
- React + Vite for fast development
- Tailwind CSS for styling
- Responsive design for mobile devices
- Full feature parity with desktop app

## 🔧 Configuration

### Mobile Configuration
```json
{
  "android": {
    "buildType": "release",
    "signing": {
      "storeFile": "./keystores/release.keystore",
      "storePassword": "android",
      "keyAlias": "dyragram",
      "keyPassword": "android"
    },
    "arm64": true,
    "x86_64": true,
    "appCompat": true
  },
  "ios": {
    "developmentTeam": "DYRAGRAM_TEAM",
    "bundleIdentifier": "com.dyragram.mobile",
    "deploymentTarget": "12.0",
    "sdkVersion": "15.0"
  }
}
```

### Personal Domain Setup
1. Deploy web frontend to your domain
2. Configure DNS records
3. Set up SSL certificate
4. Update `tauri.config.json` with your domain

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👥 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'feat: add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 🙌 Acknowledgments

- Built with [Tauri](https://tauri.app)
- Inspired by Telegram design principles
- Mobile support powered by Tauri 2.0

---

**dyrakDGram** - Make it yours! 🎨
