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
git clone https://github.com/dyragram/dyragram.git
cd dyragram
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
build.bat

# Windows (PowerShell)
.\Build-Tauri.ps1
```

### Linux/macOS Build
```bash
./build.sh
```

### Build Output Structure
```
src-tauri/target/release/bundle/
├── Windows Portable (x64)
│   ├── dyrakDGram_[version]_x64.exe
│   └── dyrakDGram_[version]_x64_setup.exe
├── macOS
│   ├── dyrakDGram_[version]_aarch64.dmg
│   └── dyrakDGram_[version]_x64.dmg
└── Linux
    ├── dyrakDGram_[version]_amd64.deb
    ├── dyrakDGram_[version]_arm64.AppImage
    └── dyrakDGram_[version]_x86_64.rpm
```

## 📦 Windows Portable Version

### Create Portable Version Manually
```bash
cargo build --release
mkdir dist\dyrakDGram
copy target\release\dyrakDGram.exe dist\dyrakDGram\
echo { "portable": true } > dist\dyrakDGram\config.json
```

### Portable Directory Structure
```
dist/dyrakDGram/
├── dyrakDGram.exe     # Main executable
├── config/            # Configuration files
│   └── app.json       # App settings
├── plugins/           # Plugin directory
└── start.bat          # Quick start script
```

## 🚀 Deployment

### Push to GitHub
```bash
git add -A
git commit -m "feat: update to version X.Y.Z"
git push origin main
```

### Automated CI/CD
The project uses GitHub Actions for automated builds:
- `.github/workflows/ci.yml` - Continuous integration
- Automatic releases on tag creation

## 🔍 Troubleshooting

### Common Issues

**Rust not found**
```bash
# Verify installation
cargo --version
# If not found, reinstall from https://rustup.rs/
```

**Build errors on Windows**
```bash
# Install Visual Studio Build Tools
# Download from: https://visualstudio.microsoft.com/downloads/
```

**Node module issues**
```bash
# Clean install
rm -rf node_modules package-lock.json
npm install
```

### Verification Commands
```bash
# Check Rust installation
cargo --version
rustc --version

# Check Tauri installation
cargo tauri --version

# Check Node.js installation
node --version
npm --version
```

## 📝 Build Scripts Reference

### build.bat (Windows)
- Cleans previous builds
- Builds release version
- Creates portable directory structure
- Copies all necessary files

### build.sh (Linux/macOS)
- Same functionality as build.bat
- Cross-platform compatibility
- Unix-style path handling

### deploy.sh
- Pushes changes to GitHub
- Syncs with GitLab mirror
- Updates documentation

## 🎯 Customization

### Modify Build Configuration
Edit `src-tauri/tauri.conf.json`:
```json
{
  "bundle": {
    "windows": {
      "signCommand": "signtool.exe sign /fd SHA256 /t https://timestamp.digicert.com",
      "length": 20
    }
  }
}
```

### Add New Plugins
1. Create plugin in `src-tauri/src/plugins/`
2. Update `mod.rs` with new plugin exports
3. Update Cargo.toml dependencies
4. Rebuild application

## 🤝 Contributing

1. Fork the repository
2. Create your branch: `git checkout -b feature/AmazingFeature`
3. Commit your changes: `git commit -m 'feat: add amazing feature'`
4. Push to branch: `git push origin feature/AmazingFeature`
5. Open a Pull Request

---

**Built with Tauri and Rust 🦀**
