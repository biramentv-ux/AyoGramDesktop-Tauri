# dyrakDGram Build Instructions

Complete guide for building dyrakDGram across all platforms.

## 📋 Prerequisites

### Required Tools
- **Rust**: [Install from rustup.rs](https://rustup.rs/)
- **Node.js**: Version 16+ required
- **npm**: Usually comes with Node.js
- **Tauri CLI**: `npm install -g @tauri-apps/cli`
- **Git**: For version control

### Windows-Specific
- Visual Studio Build Tools (Windows only)
- WSL2 recommended for development

## 🔧 Development Build

### Clone Repository
```bash
git clone https://github.com/dyrakdev/dyragram.git
cd dyrakDGram
```

### Install Dependencies
```bash
npm install
```

### Development Mode
```bash
npm run tauri dev
```

## 🏗️ Production Builds

### Windows Build
```bash
# Windows (Command Prompt)
.\build-win.bat

# Or using PowerShell
.\Build-Tauri.ps1 --release

# Development build
.\Build-Tauri.ps1 --dev
```

### Linux/macOS Build
```bash
# Install dependencies first
sudo apt install libgtk-3-dev libwebkit2gtk-4.0-dev \
    pkg-config libasound2-dev libxcb-composite0-dev \
    libxcomposite1 libxcomposite-dev libxcursor1 \
    libxcursor-dev libxdamage1 libxdamage-dev \
    libxi-dev libxinerama1 libxinerama-dev \
    libxkbcommon-dev libxrandr-dev libxrender-dev \
    libxtst-dev

# Build for production
npm run tauri build
```

## 📦 Output Structure

After building, you'll find:

```
src-tauri/target/release/bundle/
├── Windows Portable (x64)
│   ├── dyrakDGram_[version]_x64.exe (Portable)
│   └── dyrakDGram_[version]_x64_setup.exe (Installer)
├── macOS
│   ├── dyrakDGram_[version]_aarch64.dmg
│   └── dyrakDGram_[version]_x64.dmg
└── Linux
    ├── dyrakDGram_[version]_amd64.deb
    ├── dyrakDGram_[version]_arm64.AppImage
    └── dyrakDGram_[version]_x86_64.rpm
```

## 🔌 Plugin Commands

### Web Frontend Integration
The web frontend includes all plugin integrations:
- Fake Payment Interceptor
- MK Fuck Payments
- Unlock Stars Content  
- Local Telegram Premium
- SpotyDown

## 🐛 Troubleshooting

### Common Build Issues
1. **WebView2 not found**: Install [Microsoft Edge WebView2](https://developer.microsoft.com/en-us/microsoft-edge/webview2/)
2. **Build failed**: Run `cargo clean && npm run tauri build`
3. **Dependency errors**: Update Rust: `rustup update`

## 🚀 Deployment

### GitHub Actions
The project uses CI/CD for automated builds:
- Push to `main` → Automated deployment
- Pull requests → Build verification

### Manual Deployment
```bash
# Push changes to GitHub
git add .
git commit -m "Your commit message"
git push origin main

# Push to GitLab (backup)
git push gitlab main
```

## 📝 Build Scripts

### Available Scripts
- `build.bat` - Windows build script
- `build.sh` - Linux/macOS build script  
- `BUILD_AND_RUN.bat` - Build and run on Windows
- `Build-Tauri.ps1` - PowerShell build script

## 🔍 Verification

After building, verify the installation:
```bash
# Check build output
ls src-tauri/target/release/bundle/

# Verify executable
./target/release/dyrak-dgram --version
```

---

*For more information, see [README.md](./README.md) and [CHANGELOG.md](./CHANGELOG.md)*
