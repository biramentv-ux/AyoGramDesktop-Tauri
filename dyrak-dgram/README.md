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

### Running in Development
```bash
# Install dependencies
npm install

# Run development server
cargo tauri dev

# Build production version
cargo tauri build

# Build for specific platform
cargo tauri build --target aarch64-linux-android  # Android
cargo tauri build --target aarch64-apple-ios      # iOS
```

### Building Mobile Versions
```bash
# Install mobile targets
rustup target add aarch64-linux-android
rustup target add aarch64-apple-ios

# Build Android APK
cargo tauri android-libsqlite sys/sqlite3

# Build iOS app
cargo tauri build --target aarch64-apple-ios
```

---

## 🔌 Plugin Architecture

### Creating Custom Plugins
```rust
// Example plugin structure
pub struct MyPlugin {
    name: String,
    version: String,
}

impl MyPlugin {
    pub fn new() -> Self {
        Self {
            name: "MyPlugin".to_string(),
            version: "1.0.0".to_string(),
        }
    }

    pub fn execute(&self) -> Result<String, String> {
        Ok("Plugin executed successfully!".to_string())
    }
}
```

### Plugin API
All plugins implement the `TelegramPlugin` trait with methods:
- `name()` - Returns plugin name
- `version()` - Returns plugin version  
- `execute()` - Executes plugin functionality
- `settings()` - Returns plugin configuration

---

## 🌐 Web Deployment

### Personal Domain Setup
1. Fork this repository
2. Update `CNAME` file with your domain
3. Enable GitHub Pages in repository settings
4. Deploy to production

### Custom Build
```bash
# Build web assets
npm run build

# Deploy to personal server
rsync -av dist/ user@server:/var/www/dyrakdgram.com/
```

---

## 📊 Analytics & Metrics

- **Total Downloads**: [![Downloads](https://img.shields.io/github/downloads/dyrak-dgram/dyrak-dgram/total.svg?style=flat-square)](https://github.com/dyrak-dgram/dyrak-dgram/releases)
- **Active Users**: [![Users](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fapi.t.me%2Fstats%2Fchannel%3Fslug%3Ddyrakdgram&query=%24.stats.visitors&name=Active%20Users)](https://t.me/dyrakdgram)
- **GitHub Stars**: [![Stars](https://img.shields.io/github/stars/dyrak-dgram/dyrak-dgram?style=social)](https://github.com/dyrak-dgram/dyrak-dgram/stargazers)

---

## 📝 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgements

- [Telegram Desktop](https://telegram.org/) for the base architecture
- [Tauri Framework](https://tauri.app/) for cross-platform desktop development
- All plugin authors and contributors
- The open-source community

---

## 📞 Support & Community

| Platform | Link |
|----------|------|
| GitHub Issues | [Report bugs](https://github.com/dyrak-dgram/dyrak-dgram/issues) |
| Telegram Channel | [Join chat](https://t.me/dyrakdgram) |
| Documentation | [Read docs](https://dyrak-dgram.github.io/docs) |

---

**Made with ❤️ by the dyrakDGram Team**
