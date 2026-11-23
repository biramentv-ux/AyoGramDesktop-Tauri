# dyrakDGram - Telegram Desktop Fork with Advanced Plugins

![dyrakDGram Logo](https://img.shields.io/github/v/release/dyrakdev/dyrakDGram)
![License](https://img.shields.io/github/license/dyrakdev/dyrakDGram)
![Downloads](https://img.shields.io/github/downloads/dyrakdev/dyrakDGram/latest/total)

## Overview

dyrakDGram is a custom Telegram Desktop fork with advanced plugins and features:

- **MK Fuck Payments**: Removes payment limitations in Telegram
- **Fake Payment Interceptor**: Bypasses payment requirements
- **Unlock Stars Content**: Access to premium stars content
- **Local Telegram Premium**: Local premium service implementation
- **SpotyDown**: Spotify integration for music streaming

## Features

### 🎵 SpotyDown Plugin
- Stream music directly from Spotify
- Download tracks in MP3 format
- High-quality audio (320kbps)
- Cross-platform support

### 💸 Payment Plugins
- Automatic payment detection and bypass
- Fake payment methods integration
- Enhanced user experience

## Installation

### Windows (Portable)
1. Download the latest release
2. Extract ZIP file
3. Run `dyrakDGram.exe`
4. No installation required!

### macOS
1. Download `.app` package
2. Drag to Applications folder
3. Launch and enjoy

### Linux
1. Download `.deb` package
2. Install with `sudo dpkg -i dyrakDGram.deb`
3. Launch from menu

## Build Instructions

```bash
# Clone repository
git clone https://github.com/dyrakdev/dyrakDGram.git
cd dyrakDGram/src-tauri

# Install dependencies
npm install
cargo build --release

# Build application
cargo tauri build

# Run development version
cargo tauri dev
```

## Plugins

### SpotyDown
```json
{
  "enabled": true,
  "config": {
    "outputFormat": "mp3",
    "bitrate": "320",
    "downloadPath": "~/Music/SpotyDown"
  }
}
```

### MK Fuck Payments
- Removes payment barriers
- Free access to premium features

### Fake Payment Interceptor
- Automatic payment detection
- Seamless integration

## Contributing

We welcome contributions! Here's how you can help:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License.

## Acknowledgments

- Telegram for the amazing desktop application
- All plugin contributors
- Community feedback and support

---

**Note**: This is a community-driven project. Please use responsibly and respect copyright laws.
