#!/bin/bash

echo "Building dyrakDGram..."
echo ""

# Check if Rust is installed
if ! command -v cargo &> /dev/null; then
    echo "Error: Rust/Cargo not found. Please install Rust from https://rustup.rs/"
    exit 1
fi

# Create target directory if it doesn't exist
mkdir -p target

echo "Building dyrakDGram for current platform..."

# Build for release
cargo build --release

echo ""
echo "Creating portable version..."
mkdir -p portable

# Copy executable to portable folder
if [ -f "target/release/dyrak-dgram" ]; then
    cp target/release/dyrak-dgram portable/
    
    # Create portable structure
    mkdir -p portable/data
    mkdir -p portable/plugins
    
    echo "Portable version created successfully!"
    echo "Location: $(pwd)/portable"
    echo "Run ./portable/dyrak-dgram to start the application."
else
    echo "Error: Build failed or executable not found"
    exit 1
fi

echo ""
echo "Build completed successfully!"
