# dyrakDGram Windows Portable Version

Complete guide for the Windows portable version of dyrakDGram.

## 📥 Download & Installation

### Portable Version
- **File**: `dyrakDGram_[version]_x64.exe`
- **Size**: ~50MB
- **Installation**: Extract and run (no installation required)

### Installer Version  
- **File**: `dyrakDGram_[version]_x64_setup.exe`
- **Installation**: Standard Windows installer

## 🚀 Quick Start

### First Launch
1. Extract the portable version to your desired location
2. Run `dyrakDGram.exe`
3. Allow any firewall prompts
4. Configure your preferences

### Configuration
The app automatically creates a config directory:
```
%APPDATA%\dyrakDGram\
├── config.json
├── plugins/
│   └── spotydown_config.json
└── logs/
    └── app.log
```

## 🔌 Plugins Overview

### All Plugins Enabled
- ✓ Fake Payment Interceptor - Simulated payment processing
- ✓ MK Fuck Payments - Payment system bypass
- ✓ Unlock Stars Content - Telegram Stars premium content
- ✓ Local Telegram Premium - Premium features without subscription
- ✓ SpotyDown - Spotify music downloader

## ⚙️ Advanced Settings

### Custom Paths
```json
{
  "download_directory": "C:\Users\Public\Music\Spotify",
  "cache_directory": "%APPDATA%\dyrakDGram\cache"
}
```

### Keyboard Shortcuts
| Shortcut | Action |
|----------|--------|
| Ctrl+Shift+P | Toggle Premium Mode |
| Ctrl+Shift+S | Spotify Download |
| Ctrl+R | Refresh Plugin Status |
| F5 | Reload Application |

## 🎵 SpotyDown Integration

### Music Download
1. Copy Spotify track URL
2. Paste in the download field
3. Select format (MP3/AAC/WAV)
4. Click "Download"

### Batch Downloads
- Import playlist URLs
- Queue multiple tracks
- Download all at once

## 🔐 Troubleshooting

### Common Issues

**"Plugin not found" error**
```bash
# Reset plugin cache
rm -rf %APPDATA%\dyrakDGram\plugins\
```

**Spotify download failed**
- Check internet connection
- Verify Spotify URL format
- Try different track

**Audio playback issues**
- Install LAV Filters
- Update audio drivers
- Check file permissions

## 📊 System Requirements

### Minimum
- Windows 10/11 (64-bit)
- 2GB RAM
- 500MB disk space
- Internet connection

### Recommended
- Windows 11
- 8GB+ RAM  
- SSD storage
- High-speed internet

## 🔧 Update & Maintenance

### Automatic Updates
```bash
# Check for updates
.\dyrakDGram.exe --check-updates

# Manual update
curl -L https://github.com/dyrakdev/dyragram/releases/latest -o dyrakDGram_setup.exe
```

### Uninstall
1. Close all instances
2. Delete program folder
3. Remove config: `%APPDATA%\dyrakDGram\`
4. Clear cache: `%LOCALAPPDATA%\dyrakDGram\`

## 📝 Build Instructions

### Create Portable Version
```bash
# Using build script
.\build-win.bat --portable

# Or manually
npm run tauri build -- --target x86_64-pc-windows-msvc
```

### Custom Builds
```bash
# With specific features
cargo build --release --features webview2
```

---

*For technical support, see [BUILD_README.md](./BUILD_README.md)*
