# dyrakDGram - Enhanced Documentation

## 📖 Introduction

dyrakDGram is a modern Telegram desktop client with enhanced functionality through custom plugins. Built with Tauri for cross-platform performance, it provides native desktop experience with full Windows portable support.

## 🌟 Features

- 🎵 **Spotify Integration** - Direct music downloading with SpotyDown plugin
- 💰 **Smart Payments** - Fake payment interceptor and payment bypass system  
- ⭐ **Premium Content** - Telegram Stars content unlocker
- 🛡️ **Local Premium** - Local premium features activation without subscription
- 🌍 **Multi-Language Support** - Full interface in multiple languages
- 🪟 **Windows Portable** - Ready-to-use portable version for Windows
- 🌐 **Web Version** - GitHub Pages deployment with full functionality
- 🔗 **Domain**: [dyrakarmy.eu](https://dyrakarmy.eu)

## 📦 Plugins

### 1. FakePaymentInterceptor
Intercepts payment flows and creates fake successful payments for testing purposes.

**Usage:**
```javascript
await handle_fake_payment_interceptor(10.50, "USD");
// Result: "Fake payment of 10.50 USD processed successfully via Stripe!"
```

### 2. MKFuckPayments  
Bypasses payment systems and activates premium features automatically.

**Usage:**
```javascript
await handle_mk_fuck_payments_plugin();
// Result: "MK_FuckPayments plugin activated - all payment barriers removed!"
```

### 3. UnlockStarsContent
Unlocks all Telegram Stars premium content without subscription.

**Usage:**
```javascript
await handle_unlock_stars_content_plugin();
// Result: "Telegram Premium Stars content unlocked successfully!"
```

### 4. LocalTelegramPremium
Activates local premium features with 100% working implementation.

**Usage:**
```javascript
await handle_local_telegram_premium_plugin();
// Result: "Local Telegram Premium activated - all premium features unlocked!"
```

### 5. SpotyDown
Spotify integration plugin for music downloading with MP3/AAC/WAV format support.

**Usage:**
```javascript
await handle_spotydown("track_id");
// Result: "Track downloaded from Spotify successfully!"
```

## 🚀 Installation

### Windows Portable Version
1. Download the latest Windows portable release
2. Extract to your preferred location
3. Run `dyrakDGram.exe` - no installation required!

### Web Version
Visit [dyragram.github.io/dyragram](https://dyragram.github.io/dyragram) for the web version.

### From Source
```bash
# Clone the repository
git clone https://github.com/dyrakdev/dyragram.git
cd dyragram

# Build Tauri application
cd src-tauri
cargo build --release
cargo tauri build
```

## 📁 Project Structure

```
dyrakDGram/
├── src-tauri/          # Tauri backend with plugins
│   └── src/plugins/    # Plugin implementations
├── web/               # Web frontend (GitHub Pages)
└── .github/workflows/ # CI/CD configuration
```

## 🛠️ Development

### Build Scripts
- `build.bat` - Windows build script
- `build.sh` - Linux/macOS build script
- `build-win.bat` - Windows portable version

### Commands
```bash
# Install dependencies
npm install

# Run development version
npm run tauri dev

# Build production version
npm run tauri build

# Create portable version
.\build-win.bat
```

## 🌐 Multi-Language Support

dyrakDGram supports multiple languages:

| Language | Code | Documentation |
|----------|------|---------------|
| English | `en` | [README.md](README.md) |
| Bulgarian | `bg` | [README_BG.md](README_BG.md) |
| Deutsch | `de` | Available on request |
| Español | `es` | Available on request |
| Русский | `ru` | Available on request |

## 📊 System Requirements

### Minimum
- Windows 10/11 (64-bit)
- 2GB RAM
- 500MB disk space
- Internet connection

### Recommended
- Windows 11 or macOS 10.14+
- 8GB+ RAM
- SSD storage
- High-speed internet

## 🔄 Updates & Maintenance

### Automatic Updates
The application checks for updates on startup and downloads them automatically.

### Manual Update
```bash
# Check for updates
./dyrakDGram.exe --check-updates

# Install latest version
curl -L https://github.com/dyrakdev/dyragram/releases/latest -o dyrakDGram_setup.exe
```

## 🔧 Configuration

### Config File Location
```
%APPDATA%\dyrakDGram\config.json
```

### Recommended Settings
```json
{
  "theme": "dark",
  "language": "bg",
  "download_directory": "C:\Users\Public\Music\Spotify",
  "cache_directory": "%APPDATA%\dyrakDGram\cache",
  "plugins_enabled": true,
  "auto_update": true
}
```

## 🐛 Troubleshooting

### Common Issues

**Problem:** Plugin not found  
**Solution:** Clear plugin cache and restart application

**Problem:** Spotify download not working  
**Solution:** Check internet connection and verify Spotify URL format

**Problem:** Audio player not functioning  
**Solution:** Install LAV Filters and update audio drivers

## 📝 Build Commands

### Windows Build
```bash
.\build-win.bat
```

### Linux/macOS Build
```bash
# Install dependencies first
sudo apt install libgtk-3-dev libwebkit2gtk-4.0-dev \
    pkg-config libasound2-dev

# Then build
npm run tauri build
```

## 🌐 Web Version

dyrakDGram is also available as a web application:
- GitHub Pages: `https://dyragram.github.io/dyragram`
- Full functionality
- Fast loading
- Mobile optimized

## 📚 Additional Resources

- [GitHub Repository](https://github.com/dyrakdev/dyragram)
- [GitLab Mirror](https://gitlab.com/biramentv-ux/AyoGramDesktop-Tauri)
- [Tauri Documentation](https://tauri.app/)
- [Spotify API](https://developer.spotify.com/)

---

**Made with ❤️ by the dyrakDGram community**

*dyrakarmy.eu - Official Mirror*
