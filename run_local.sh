#!/bin/bash
# Quick script to build and run Erasgame

set -e

echo "🎮 Building and Running Erasgame..."
echo ""

# Build the project
echo "📦 Building..."
cmake -B build -S .
cmake --build build

echo ""
echo "✅ Build complete!"
echo ""
echo "🚀 Starting game..."
echo ""

# Run the game
./build/erasgame
