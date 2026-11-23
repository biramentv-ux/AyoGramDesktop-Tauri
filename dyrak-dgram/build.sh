#!/bin/bash
# Build script for dyrakDGram Mobile
# Supports Android, iOS, and Web platforms

set -e  # Exit on any error

echo "🚀 Starting dyrakDGram mobile build process..."

# Check if Rust is installed
if ! command -v rustc &> /dev/null; then
    echo "❌ Rust не е инсталиран. Моля, инсталирайте Rust от https://rustup.rs"
    exit 1
fi

# Check if Tauri CLI is installed
if ! command -v tauri &> /dev/null; then
    echo "⚠️ Tauri CLI не е инсталиран. Инсталиране с npm..."
    npm install -g @tauri-apps/cli
fi

# Function to build Android app
build_android() {
    echo "📱 Building Android APK..."
    
    # Add Android targets if not already present
    rustup target add aarch64-linux-android
    rustup target add armv7-linux-androideabi
    rustup target add x86_64-linux-android
    rustup target add i686-linux-android
    
    # Build the Android app
    cd src-tauri
    cargo tauri android build --release
    cd ..
    
    echo "✅ Android APK builds successfully!"
    echo "📁 APK файловете са в: src-tauri/target/"
}

# Function to build iOS app
build_ios() {
    echo "🍎 Building iOS App..."
    
    # Check if building on macOS
    if [[ "$(uname -s)" != "Darwin" ]]; then
        echo "⚠️ iOS сграждането изисква macOS. Използвайте виртуална машина или CI/CD."
        exit 1
    fi
    
    # Add iOS targets
    rustup target add aarch64-apple-ios
    rustup target add x86_64-apple-ios
    
    # Build the iOS app
    cd src-tauri
    cargo tauri ios build --release
    cd ..
    
    echo "✅ iOS App builds successfully!"
    echo "📁 iOS артефактите са в: src-tauri/target/ios/"
}

# Function to build web app
build_web() {
    echo "🌐 Building Web App..."
    
    # Install Node.js dependencies if needed
    if [ ! -d "web/node_modules" ]; then
        cd web
        npm install
        cd ..
    fi
    
    # Build the web app
    cd web
    npm run build
    cd ..
    
    echo "✅ Web App builds successfully!"
    echo "📁 Уеб артефактите са в: web/dist/"
}

# Function to create portable Windows version
build_windows_portable() {
    echo "💻 Building Windows Portable..."
    
    # Build desktop version
    cargo tauri build --release
    
    echo "✅ Windows Portable builds successfully!"
    echo "📁 Уверете се, че всички DLL файлове са включени."
}

# Main build function
main() {
    echo "========================================"
    echo "  dyrakDGram Mobile Build Script"
    echo "========================================"
    echo ""
    
    # Check for platform and prompt for build type
    if [[ "$1" == "android" ]]; then
        build_android
    elif [[ "$1" == "ios" ]]; then
        build_ios
    elif [[ "$1" == "web" ]]; then
        build_web
    elif [[ "$1" == "windows" ]]; then
        build_windows_portable
    else
        echo "Изберете платформа за сграждане:"
        echo "  android   - Build Android APK"
        echo "  ios       - Build iOS App (macOS required)"
        echo "  web       - Build Web version"
        echo "  windows   - Build Windows Portable"
        echo ""
        echo "Примери:"
        echo "  ./build.sh android"
        echo "  ./build.sh web"
    fi
}

# Run main function with arguments
main "$@"
