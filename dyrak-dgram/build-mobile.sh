#!/bin/bash
# dyrakDGram Mobile Build Scripts

# Script: build-mobile.sh
# Purpose: Build dyrakDGram for Android and iOS platforms

set -e

echo "=== dyrakDGram Mobile Build System ==="
echo "Building for Android and iOS platforms..."

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Check if Rust is installed
if ! command -v rustc &> /dev/null; then
    echo -e "${RED}Rust is not installed. Please install Rust first.${NC}"
    exit 1
fi

# Check if Tauri CLI is installed
if ! command -v tauri &> /dev/null; then
    echo -e "${YELLOW}Tauri CLI not found. Installing...${NC}"
    npm install -g @tauri-apps/cli
fi

# Build Android
build_android() {
    echo -e "${GREEN}Building Android APK...${NC}"
    
    # Add Android target
    rustup target add aarch64-linux-android armv7-linux-androideabi i686-linux-android x86_64-linux-android
    
    # Build for Android
    cd android
    ./gradlew assembleDebug
    cd ..
    
    echo -e "${GREEN}Android build completed!${NC}"
}

# Build iOS
build_ios() {
    echo -e "${GREEN}Building iOS App...${NC}"
    
    # Add iOS targets
    rustup target add aarch64-apple-ios x86_64-apple-ios
    
    # Build for iOS
    tauri build --target ios
    
    echo -e "${GREEN}iOS build completed!${NC}"
}

# Build Web (for personal domain)
build_web() {
    echo -e "${GREEN}Building Web Application...${NC}"
    
    # Build web assets
    cd web
    npm run build
    cd ..
    
    echo -e "${GREEN}Web build completed!${NC}"
}

# Run all builds
case "$1" in
    android)
        build_android
        ;;
    ios)
        build_ios
        ;;
    web)
        build_web
        ;;
    all|*)
        build_android
        build_ios
        build_web
        ;;
esac

echo -e "${GREEN}All builds completed successfully!${NC}"
