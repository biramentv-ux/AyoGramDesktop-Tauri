# dyrakDGram - Multi-Language Documentation

## 📖 Available Languages

dyrakDGram supports the following languages:

| Language | File | Description |
|----------|------|-------------|
| **English** | `README.md` | Main documentation with all features |
| **Bulgarian** | `README_BG.md` | Complete Bulgarian guide |
| **German** | `GERMAN_README.md` | Available on request |
| **Spanish** | `SPANISH_README.md` | Available on request |
| **Russian** | `RUSSIAN_README.md` | Available on request |

## 📚 Documentation Files

### README.md (English)
- Full feature documentation
- Installation guide
- Plugin usage examples
- System requirements
- Troubleshooting section

### README_BG.md (Bulgarian)
- Complete Bulgarian user manual
- Detailed plugin descriptions
- Configuration examples
- Troubleshooting guide
- Build instructions

### ENHANCED_README.md (English)
- Comprehensive technical documentation
- Advanced features
- Developer guide
- API references
- Multi-language support structure

## 🔗 Domains

The dyrakDGram project uses multiple domains:

| Domain | Purpose | Status |
|--------|---------|--------|
| `https://dyragram.github.io/dyragram` | GitHub Pages deployment | Active |
| `https://dyrakarmy.eu` | Official mirror (alternate) | Configured |
| `https://github.com/dyrakdev/dyragram` | Primary repository | Active |
| `https://gitlab.com/biramentv-ux/AyoGramDesktop-Tauri` | GitLab mirror | Active |

## 📦 Plugin System

All plugins are fully functional and integrated:

### 1. FakePaymentInterceptor
```javascript
await handle_fake_payment_interceptor(10.50, "USD");
// Result: "Fake payment of 10.50 USD processed successfully via Stripe!"
```

### 2. MKFuckPayments
```javascript
await handle_mk_fuck_payments_plugin();
// Result: "MK_FuckPayments plugin activated - all payment barriers removed!"
```

### 3. UnlockStarsContent
```javascript
await handle_unlock_stars_content_plugin();
// Result: "Telegram Premium Stars content unlocked successfully!"
```

### 4. LocalTelegramPremium
```javascript
await handle_local_telegram_premium_plugin();
// Result: "Local Telegram Premium activated - all premium features unlocked!"
```

### 5. SpotyDown
```javascript
await handle_spotydown("track_id");
// Result: "Track downloaded from Spotify successfully!"
```

## 🚀 Quick Start

### Windows Installation
1. Download `dyrakDGram_[version]_x64.exe`
2. Extract to preferred location
3. Run executable (no installation required)

### Linux/macOS Installation
```bash
# Clone repository
git clone https://github.com/dyrakdev/dyragram.git
cd dyragram

# Build and install
npm install
npm run tauri build
```

## 🌐 Web Version

dyrakDGram web version available at:
- GitHub Pages: `https://dyragram.github.io/dyragram`
- Full functionality with plugin system
- Mobile optimized interface
- No installation required

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

## 📊 System Requirements

### Minimum
- Windows 10/11 (64-bit) or macOS 10.14+ or Linux
- 2GB RAM
- 500MB disk space
- Internet connection

### Recommended
- Windows 11 or macOS 10.14+
- 8GB+ RAM
- SSD storage
- High-speed internet

## 📝 Build Scripts

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

## 🎵 Spotify Integration (SpotyDown)

### Supported Formats
- **MP3** - Compressed, good quality audio
- **AAC** - Apple iPod format
- **WAV** - Uncompressed, best quality

### Usage
1. Copy Spotify URL from browser
2. Paste in download field
3. Select format (MP3/AAC/WAV)
4. Click "Download"

## 📚 Additional Resources

- [GitHub Repository](https://github.com/dyrakdev/dyragram)
- [GitLab Mirror](https://gitlab.com/biramentv-ux/AyoGramDesktop-Tauri)
- [Tauri Documentation](https://tauri.app/)
- [Spotify API](https://developer.spotify.com/)

---

**dyrakDGram** - Telegram Desktop Client with Premium Features and Spotify Integration

*Multi-language support: English, Bulgarian (available): German, Spanish, Russian*
