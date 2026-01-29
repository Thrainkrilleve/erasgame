# Getting Started Guide

## Decision Points

Before you begin coding, you and your friend need to decide on:

### 1. Game Engine/Framework
Choose one based on your experience and needs:

#### Option A: Game Engines (Easiest)
- **Godot** (Recommended for 2D)
  - Free and open source
  - Excellent 2D support
  - Built-in physics
  - GDScript (Python-like) or C#
  
- **Unity**
  - Industry standard
  - Great asset store
  - C# programming
  - More 3D-focused but 2D capable

#### Option B: Frameworks (More Control)
- **pygame** (Python)
  - Simple to learn
  - Good for prototyping
  - Need to implement many systems yourself

- **LÖVE** (Lua)
  - Lightweight
  - Good 2D performance
  - Simple API

- **LibGDX** (Java)
  - Cross-platform
  - Powerful but steeper learning curve

#### Option C: From Scratch
- Choose a language (C++, Rust, etc.)
- Use graphics library (SDL2, SFML, raylib)
- Most work, most control

### 2. Development Roles

Split the work between you and your friend:

**Developer 1: Core Systems**
- Chunk generation system
- World persistence (save/load)
- Data structures

**Developer 2: Gameplay & Physics**
- Player controller
- Physics integration
- Interaction system

**Shared:**
- Asset creation
- Testing
- Design decisions

### 3. Version Control Setup

```bash
# Initialize git (if not done)
git init

# Create .gitignore
# Add build files, IDE configs, etc.

# Commit initial structure
git add .
git commit -m "Initial project structure"

# Set up branches for features
git checkout -b feature/chunk-system
git checkout -b feature/player-controller
```

## Next Steps

1. **Choose your engine** (discuss with your friend)
2. **Set up development environment**
3. **Create a minimal prototype**
   - Single non-generated chunk
   - Basic player movement
   - Simple collision
4. **Iterate** - Add features one at a time

## Minimal Viable Product (MVP)

Start with the smallest playable version:
- ✅ Player can move (WASD/Arrow keys)
- ✅ World has 1 static chunk with tiles
- ✅ Player collides with solid tiles
- ✅ One interactive object (tree)

Then expand from there!
