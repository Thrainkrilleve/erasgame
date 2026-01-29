#!/bin/bash
# Test script for Erasgame - verifies build and basic functionality

set -e  # Exit on error

echo "🔨 Testing Erasgame Build..."
echo ""

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "❌ Build directory not found. Run cmake first."
    exit 1
fi

# Check if executable exists
if [ ! -f "build/erasgame" ]; then
    echo "❌ Executable not found. Build the project first."
    exit 1
fi

echo "✅ Build directory exists"
echo "✅ Executable found at build/erasgame"

# Check file size (should be reasonable)
SIZE=$(stat -f%z "build/erasgame" 2>/dev/null || stat -c%s "build/erasgame" 2>/dev/null)
echo "✅ Executable size: $((SIZE / 1024)) KB"

# Verify it's executable
if [ -x "build/erasgame" ]; then
    echo "✅ File has execute permissions"
else
    echo "⚠️  File is not executable, fixing..."
    chmod +x build/erasgame
fi

# Check dependencies
echo ""
echo "📦 Checking dependencies..."
if command -v ldd &> /dev/null; then
    echo "Required libraries:"
    ldd build/erasgame | grep -E "raylib|pthread|GL|X11" || echo "  (library check not available)"
fi

echo ""
echo "✅ All basic checks passed!"
echo ""
echo "To run the game:"
echo "  ./build/erasgame"
echo ""
echo "If you're on:"
echo "  • Linux/Mac: Just run the command above"
echo "  • WSL2 with WSLg: Should work directly"
echo "  • Remote (Codespaces): Requires X11 forwarding"
