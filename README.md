# dyrakDGram

**dyrakDGram** is a modern Telegram desktop client with enhanced functionality through custom plugins. Built with Tauri for cross-platform performance, it provides a native desktop experience with full Windows portable support.

## 🌟 Features

- 🎵 **Spotify Integration** - Direct music downloading with SpotyDown plugin
- 💰 **Smart Payments** - Fake payment interceptor and payment bypass system  
- ⭐ **Premium Content** - Telegram Stars content unlocker
- 🛡️ **Local Premium** - Local premium features activation without subscription
- 🌍 **Bulgarian Interface** - Full Bulgarian language support
- 🪟 **Windows Portable** - Ready-to-use portable version for Windows
- 🌐 **Web Version** - GitHub Pages deployment with full functionality
- 🔗 **dyrakarmy.eu Mirror** - Alternate access domain

## 📦 Plugins

### 1. FakePaymentInterceptor
Intercepts payment flows and creates fake successful payments for testing purposes.

### 2. MKFuckPayments  
Bypasses payment systems and activates premium features automatically.

### 3. UnlockStarsContent
Unlocks all Telegram Stars premium content without subscription.

### 4. LocalTelegramPremium
Activates local premium features with 100% working implementation.

### 5. SpotyDown
Spotify integration plugin for music downloading with MP3/AAC/WAV format support.

## 🚀 Quick Start

### Prerequisites
- Node.js 16+ 
- Rust (install from [rustup.rs](https://rustup.rs))
- Tauri CLI: `npm install -g @tauri-apps/cli`

### Installation
```bash
# Clone the repository
git clone https://github.com/dyrakdev/dyragram.git
cd dyrakDGram

# Install dependencies
npm install

# Start development mode
npm run tauri dev
```

## 📖 Documentation

- **[BUILD_README.md](./BUILD_README.md)** - Complete build instructions for all platforms
- **[CHANGELOG.md](./CHANGELOG.md)** - Version history and changes
- **[WINDOWS_PORTABLE_README.md](./WINDOWS_PORTABLE_README.md)** - Windows portable version guide
- **[БУЛГАРСКА_ДОКУМЕНТАЦИЯ.md](./БУЛГАРСКА_ДОКУМЕНТАЦИЯ.md)** - Full Bulgarian user manual

## 💻 Supported Platforms

- ✅ Windows (Portable + Installer)
- ✅ macOS (Universal: Intel + Apple Silicon)
- ✅ Linux (Debian, RPM, AppImage)
- 🌐 Web (GitHub Pages)
- 🔗 Mirror: [dyrakarmy.eu](https://dyrakarmy.eu)

## 🔧 Development

### Build Commands
```bash
# Development build
npm run tauri dev

# Production build
npm run tauri build

# Windows portable build
./build-win.bat
```

### Project Structure
```
dyrakDGram/
├── src-tauri/          # Tauri backend with plugins
├── web/                # Web frontend
├── .github/           # CI/CD workflows
└── scripts/           # Build and deployment scripts
```

## 📄 License

This project is licensed under the MIT License.

## 👥 Author

**Dyrak** - GitHub: [@dyrakdev](https://github.com/dyrakdev)

---

*dyrakDGram: Premium Telegram Desktop Client with Enhanced Features*
