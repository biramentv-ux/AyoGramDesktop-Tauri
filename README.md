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

## 🚀 Installation

### Windows Portable Version
1. Download the latest Windows portable release
2. Extract to your preferred location
3. Run `dyrak-dgram.exe` - no installation required!

### Web Version
Visit [dyragram.github.io/dyragram](https://dyragram.github.io/dyragram) for the web version.

### From Source
```bash
# Clone the repository
git clone https://github.com/dyragram/dyragram.git
cd dyragram

# Build Tauri application
cd src-tauri
cargo build --release
cargo tauri build
```

## 📁 Project Structure

```
dyrak-dgram/
├── src-tauri/          # Tauri backend with plugins
│   └── src/plugins/    # Plugin implementations
├── web/               # Web frontend (GitHub Pages)
└── .github/workflows/ # CI/CD configuration
```

## 🛠️ Development

### Build Scripts
- `build.bat` - Windows build script
- `build.sh` - Linux/macOS build script

### Commands
```bash
# Install dependencies
npm install

# Run development version
npm run tauri dev

# Build production version
npm run tauri build
```

## 🤝 Contributing

Contributions are welcome! Please read our [contributing guidelines](CONTRIBUTING.md) first.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'feat: add some amazing feature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- Telegram for the amazing messaging platform
- Tauri team for the cross-platform framework
- All contributors and users of dyrakDGram

---

**Made with ❤️ by the dyrakDGram community**
