# 🚀 dyrakDGram - Cross-Platform Telegram Client

> **Telegram, но по твой начин.** Хибриден клиент с Ghost Mode и Stream Mode за Windows, macOS, Android и iOS.

<div align="center">
  <img src="https://img.shields.io/badge/platform-Windows%2010/11-blue?style=flat-square" alt="Platform"> 
  <img src="https://img.shields.io/badge/platform-macOS-green?style=flat-square" alt="macOS">
  <img src="https://img.shields.io/badge/platform-Android-purple?style=flat-square" alt="Android">
  <img src="https://img.shields.io/badge/platform-iOS-orange?style=flat-square" alt="iOS">
  <img src="https://img.shields.io/badge/framework-Tauri%202-red?style=flat-square" alt="Tauri"> 
  <img src="https://img.shields.io/badge/language-Rust-orange?style=flat-square" alt="Rust"> 
</div>

<div align="center">
  <img src="https://img.shields.io/github/license/dyrak-dgram/dyrak-dgram?style=flat-square" alt="License">
  <img src="https://img.shields.io/github/stars/dyrak-dgram/dyrak-dgram?style=flat-square" alt="Stars">
  <img src="https://img.shields.io/github/actions/workflow/status/dyrak-dgram/dyrak-dgram/deploy.yml?style=flat-square" alt="CI/CD">
</div>

---

## 🌐 Web Version & Personal Domain

dyrakDGram е достъпен и като уеб приложение, което може да се разположи на персонален домейн:

- **Web URL**: [https://dyrakdgram.com](https://dyrakdgram.com)
- **GitHub Pages**: [https://dyrak-dgram.github.io/dyrak-dgram](https://dyrak-dgram.github.io/dyrak-dgram)
- **PWA Support**: Full Progressive Web App с offline mode

---

## ✨ Features

### Desktop Features
- 🎨 **Modern Interface** - Clean design with Bulgarian language support
- 🔌 **Plugin Architecture** - Full support for custom plugins
- 💾 **Local File Storage** - Direct file downloads without cloud
- ⚡ **Fast Performance** - Optimized for speed and minimal memory footprint

### Mobile Features  
- 📱 **Android Support** - Native Android app with Tauri mobile
- 🍎 **iOS Support** - Native iOS app with full features
- 👆 **Touch Interface** - Optimized for mobile touch controls
- 🔔 **Push Notifications** - Real-time notifications

### Plugin Ecosystem
| Plugin | Description | Status |
|--------|-------------|--------|
| Fake Payment Interceptor | Simulates payment transactions | ✅ Active |
| MK_FuckPayments | Bypasses payment systems | ✅ Active |
| Unlock Stars Content | Unlocks premium content | ✅ Active |
| Local Telegram Premium | Enables premium features | ✅ Active |
| SpotyDown | Direct music downloading | ✅ Active |

---

## 📥 Installation

### Windows & macOS
Download the latest version from our [GitHub Releases](https://github.com/dyrak-dgram/dyrak-dgram/releases).

```bash
# Portable Windows build
./dyrakDGram-portable.exe

# macOS installer
open dyrakDGram-macos.dmg
```

### Android
[<img src="https://img.shields.io/badge/Google_Play-4140?style=for-the-badge&logo=google-play&logoColor=white" alt="Google Play">](https://play.google.com/store/apps/details?id=com.dyrakdgram)
[<img src="https://img.shields.io/badge/apkware-4140?style=for-the-badge&logo=apkpure&logoColor=white" alt="APK Ware">](https://www.apkware.com/store/com.dyrakdgram)

### iOS
[<img src="https://img.shields.io/badge/App_Store-4140?style=for-the-badge&logo=app-store&logoColor=white" alt="App Store">](https://apps.apple.com/app/dyrakdgram)
[<img src="https://img.shields.io/badge/TestFlight-4140?style=for-the-badge&logo=test-flight&logoColor=white" alt="TestFlight">](https://testflight.apple.com/apps/dyrakdgram)

### Web Version
Visit our [Web Application](https://dyrakdgram.com) directly from any browser.

---

## 🛠 Development

### Project Structure
```
dyrak-dgram/
├── src-tauri/          # Tauri backend (Rust)
│   ├── src/
│   │   ├── plugins/    # All plugin implementations
│   │   ├── main.rs     # Application entry point
│   │   └── lib.rs      # Library functions
│   └── tauri.conf.json # Tauri configuration
├── web/                # Web frontend (HTML/CSS/JS)
│   ├── index.html      # Main HTML file
│   ├── manifest.json   # PWA manifest
│   └── assets/         # Static assets
└── .github/workflows/  # CI/CD pipeline
```

---

## 🔌 Plugins

All plugins are integrated directly into the application:

- **fake_payment_interceptor**: Simulates payment transactions with custom logic
- **mk_fuck_payments**: Bypasses standard payment systems
- **unlock_stars_content**: Unlocks premium Telegram features
- **local_telegram_premium**: Enables premium features locally
- **spotydown**: Direct music downloading with no limits

---

## 🚀 Building from Source

### Desktop Builds
```bash
# Install Rust and Tauri CLI
cargo install tauri-cli

# Build desktop application
cd src-tauri
cargo build --release
npm run tauri build
```

### Mobile Builds (Android/iOS)
```bash
# Setup mobile development environment
npm run tauri add android
npm run tauri add ios

# Build mobile applications
npm run tauri build --target aarch64-linux-android
npm run tauri build --target aarch64-apple-ios
```

---

## 📁 Project Structure

### Backend (src-tauri/)
- **plugins/**: All custom plugin implementations
  - `fake_payment_interceptor/`
  - `mk_fuck_payments/`
  - `unlock_stars_content/`
  - `local_telegram_premium/`
  - `spotydown/`

### Frontend (web/)
- **index.html**: Main application entry point
- **manifest.json**: PWA configuration for Android/iOS
- **styles.css**: Mobile-optimized styles

---

## 🌐 Web Deployment

The web version is automatically deployed to GitHub Pages and can be hosted on a personal domain:

1. Update `web/manifest.json` with your domain info
2. Set up GitHub Pages in repository settings
3. Configure custom domain in repository settings
4. Deploy via CI/CD pipeline

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🙌 Acknowledgments

- Based on Telegram Desktop architecture
- Built with Tauri 2 for cross-platform development
- Custom plugins designed for enhanced functionality
