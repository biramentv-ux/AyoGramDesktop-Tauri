# Deployment Guide for dyrakDGram Mobile

## Android Deployment

### Build APK
```bash
cd android
./gradlew assembleDebug
```

### Install on Device
```bash
adb install app/build/outputs/apk/debug/app-debug.apk
```

### Generate Signed APK
1. Open Android Studio
2. Go to Build > Generate Signed Bundle / APK
3. Select APK and click Next
4. Create or select your keystore
5. Complete the signing process

## iOS Deployment

### Build for Simulator
```bash
tauri build --target ios
```

### Build for Device (Ad Hoc)
1. Open Xcode
2. Select your development team
3. Build for device

### Archive and Distribute
1. Go to Window > Organizer
2. Archive the project
3. Distribute to TestFlight or distribute ad hoc

## Web Deployment (Personal Domain)

### Configure Domain
1. Update `personal-domain-config.js` with your domain
2. Set up DNS records for your domain
3. Configure SSL/TLS certificate

### Deploy to Personal Server
```bash
# Build the web app
npm run build

# Copy files to your server
cp -r dist/* /var/www/yourdomain.com/
```

### GitHub Pages Deployment
```bash
# Configure package.json
"homepage": "https://yourusername.github.io/dyrakDGram"

# Deploy
npm run deploy
```

## Continuous Integration

### GitHub Actions Workflow
The project includes a CI/CD workflow for automated builds:
- Android: Builds APK on push to main
- iOS: Builds IPA on tag creation
- Web: Deploys to GitHub Pages on release

### Custom Build Pipeline
```bash
# Build all platforms
./build-mobile.sh all

# Build specific platform
./build-mobile.sh android
./build-mobile.sh ios
./build-mobile.sh web
```

## Troubleshooting

### Android Issues
- Ensure Android SDK is installed
- Check ANDROID_HOME environment variable
- Verify Java version (17 recommended)

### iOS Issues
- Ensure Xcode is installed
- Check development team in Xcode project
- Verify provisioning profiles

### Web Issues
- Ensure Node.js 18+ is installed
- Check npm dependencies
- Verify build configuration

## Support

For mobile-specific issues, please check:
- Android: [developer.android.com](https://developer.android.com)
- iOS: [developer.apple.com](https://developer.apple.com)
- Tauri Mobile: [tauri.app/mobile](https://tauri.app/mobile)
