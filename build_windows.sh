#!/bin/bash

# Windows Portable Build Script for dyrakDGram

set -e

echo "Starting Windows portable build..."

# Install Rust if not installed
if ! command -v rustup &> /dev/null; then
    echo "Installing Rust..."
    curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
    source $HOME/.cargo/env
fi

# Install Tauri CLI
echo "Installing Tauri CLI..."
npm install -g @tauri-apps/cli

# Build Windows portable version
echo "Building Windows portable version..."
cd src-tauri
tauri build --target x86_64-pc-windows-msvc --release

# Create portable version (ZIP file)
echo "Creating portable version..."
mkdir -p dist/portable
cp target/release/dyrak-dgram.exe dist/portable/
cp -r web/* dist/portable/

# Create installer
echo "Creating Windows installer..."
cargo install tauri-cli
tauri build --target x86_64-pc-windows-msvc --release

# Output files
echo "Build complete!"
echo "Portable version: dist/portable/"
echo "Installer: src-tauri/target/release/"
