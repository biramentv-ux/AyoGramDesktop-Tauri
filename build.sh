#!/bin/bash

echo "Building dyrakDGram Application"

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
cd ..