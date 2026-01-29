# raylib Setup Guide

## What is raylib?

raylib is a simple and easy-to-use library to learn videogames programming. It's perfect for your 2D sandbox game because it's:
- Fast and lightweight
- Has everything you need built-in
- Cross-platform
- Easy to learn

## Quick Start

### 1. Install Dependencies (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install build-essential cmake git
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev \
                 libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev \
                 libxinerama-dev
```

### 2. Build the Project

```bash
# From the erasgame directory
cmake -B build -S .
cmake --build build
```

**Build output:** The executable will be created at `build/erasgame`

### 3. Run the Game

**On Local Machine (with display):**
```bash
./build/erasgame
```

**In Dev Container:**
The dev container doesn't have display configured by default. The project builds successfully, but to run the game you need:
- Copy to your local machine, or
- Use WSL2 with WSLg on Windows, or
- Configure X11 forwarding

Or use VS Code tasks:
- Press `Ctrl+Shift+B` to build
- Press `Ctrl+Shift+P` → "Tasks: Run Test Task" to run

## VS Code Integration

I've set up VS Code tasks for you:

- **Build Erasgame**: Configure CMake
- **Compile Erasgame** (default): Build the executable
- **Run Erasgame**: Build and run the game
- **Clean Build**: Remove build files

Use:
- `Ctrl+Shift+B` - Quick build
- `F5` - Debug mode
- Terminal commands for more control

## Project Structure

```
erasgame/
├── src/
│   └── main.c           # Main game code
├── build/               # Build output (generated)
├── CMakeLists.txt       # Build configuration
└── .vscode/
    ├── tasks.json       # Build tasks
    └── launch.json      # Debug configuration
```

## What's Implemented

The starter code includes:
- ✅ Window creation (1280x720)
- ✅ Basic player movement (WASD)
- ✅ Single chunk generation
- ✅ Simple tile rendering
- ✅ FPS counter and debug info

## Next Steps for Development

### 1. Expand Chunk System
- Add multiple chunks
- Implement chunk loading/unloading
- Add world coordinates

### 2. Add File I/O
- Save chunks to .ini files
- Load chunks from disk
- Track modified chunks

### 3. Implement Physics
- Add collision detection
- Integrate Box2D or use raylib's built-in physics
- Make player collide with solid tiles

### 4. Add Interactions
- Click to destroy tiles
- Place tiles
- Add entities (trees, rocks)

## Learning Resources

- **raylib cheatsheet**: https://www.raylib.com/cheatsheet/cheatsheet.html
- **raylib examples**: https://www.raylib.com/examples.html
- **C programming**: https://www.learn-c.org/

## Troubleshooting

### Build fails with missing libraries
```bash
# Make sure you installed all dependencies
sudo apt install build-essential cmake
```

### Game window doesn't appear
Check your graphics drivers are working:
```bash
glxinfo | grep "OpenGL version"
```

### Performance issues
- Check FPS counter (should be 60)
- Profile with `gprof` if needed
- Optimize chunk generation

## Working Together

Split the work:

**Person 1: Core Systems**
- `src/chunk.c` - Chunk management
- `src/world.c` - World generation
- `src/save.c` - File I/O

**Person 2: Gameplay**
- `src/player.c` - Player controller
- `src/physics.c` - Physics/collision
- `src/entities.c` - Game objects

Both can work in VS Code simultaneously using git branches!
