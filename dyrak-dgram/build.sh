#!/bin/bash

echo "=== dyrakDGram Build Script for Linux/macOS ==="

# Check if Rust is installed
if ! command -v cargo &> /dev/null; then
    echo "Error: Rust is not installed. Please install from https://rustup.rs"
    exit 1
fi

# Check if Tauri CLI is installed
if ! command -v tauri &> /dev/null; then
    echo "Installing Tauri CLI..."
    npm install -g @tauri-apps/cli
fi

echo ""
echo "=== Building dyrakDGram ==="

# Build development version
echo "[1/4] Building debug version..."
cargo build --manifest-path src-tauri/Cargo.toml --lib
if [ $? -ne 0 ]; then
    echo "Error: Debug build failed"
    exit 1
fi

# Build release version
echo "[2/4] Building release version..."
cargo build --manifest-path src-tauri/Cargo.toml --release --lib
if [ $? -ne 0 ]; then
    echo "Error: Release build failed"
    exit 1
fi

# Tauri build
echo "[3/4] Running Tauri build..."
npm run tauri build
if [ $? -ne 0 ]; then
    echo "Error: Tauri build failed"
    exit 1
fi

# Create portable version (Linux)
echo "[4/4] Creating portable Linux version..."
mkdir -p target/portable
cp src-tauri/target/release/dyrak-dgram target/portable/
echo "Portable version created in: target/portable"

echo ""
echo "=== Build Complete ==="
echo "Application location: target/portable/dyrak-dgram"
echo "Installer location: src-tauri/target/release/bundle/"
