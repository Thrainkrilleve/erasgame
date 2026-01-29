# Erasgame

A 2D indie-style open-world sandbox game with procedural terrain generation and dynamic world interaction.

## 🎮 Game Overview

Erasgame is an open-world sandbox adventure featuring:
- **2D Indie Style**: Pixel art aesthetic with modern gameplay mechanics
- **Earth-like Terrain**: Realistic biomes and natural environments
- **Dynamic World Interaction**: Physics-based interactions with the environment

## ✨ Core Features

### Chunk Generation System
- **Grid System**: 20x20 chunk grid (Minecraft-inspired)
- **Tile Resolution**: 32x32 pixel items
- **Tiles per Chunk**: 400 tiles (20x20 grid)
- **Loading Range**: 9-12 chunks around the player (position-dependent)
- **Data Persistence**: Chunks saved to `.ini` files
- **Generation Strategy**: 
  - Generated once per chunk
  - Pregenerated around character spawn on game load
  - Dynamically loaded/unloaded on player movement
  - Optimization needed to reduce CPU load

### World Interaction
- **Physics System**: Rigid body assets with realistic physics
- **Resource Gathering**: Interactive elements (e.g., trees)
- **Dynamic Destruction**: Objects fall and break based on damage
  - Example: Trees fall when chopped, with progressive damage system

## 🛠️ Technical Architecture

### Data Management
- **Storage Format**: INI configuration files
- **Memory Structure**: Efficient data structures for chunk loading
- **Optimization Goals**:
  - Reduce CPU load during chunk generation
  - Implement chunk pregenerating on game load
  - Optimize chunk reloading on player movement

### Planned Systems
- [ ] Chunk generation and management
- [ ] World persistence (save/load)
- [ ] Physics engine integration
- [ ] Player movement and controls
- [ ] Resource gathering mechanics
- [ ] Inventory system
- [ ] Crafting system (future)

## 🚀 Getting Started

### Prerequisites
- [To be determined based on chosen game engine]

### Installation
```bash
# Clone the repository
git clone https://github.com/Thrainkrilleve/erasgame.git
cd erasgame

# Setup instructions to be added
```

### Running the Game

**In the dev container (for development):**
```bash
# Build the project
cmake -B build -S .
cmake --build build

# The executable is created at: build/erasgame
```

**To run with graphics (on your local machine):**
```bash
# If cloning to your local machine
./build/erasgame
```

**Note:** The dev container doesn't have display support configured. To test the game with graphics:
- Clone the repo to your local Linux/Mac machine, or
- Use Windows with WSL2 (with WSLg for graphics), or
- Configure X11 forwarding in your dev container

## 📁 Project Structure
```
erasgame/
├── src/            # Source code
├── assets/         # Game assets (sprites, sounds, etc.)
├── data/           # Game data files (.ini chunk data)
├── docs/           # Documentation
└── tests/          # Unit tests
```

## 🗺️ Development Roadmap

### Phase 1: Core Systems (Current)
- [ ] Choose game engine/framework
- [ ] Set up development environment
- [ ] Implement basic chunk generation
- [ ] Create player movement system
- [ ] Develop chunk loading/unloading system

### Phase 2: World Generation
- [ ] Procedural terrain generation
- [ ] Biome system
- [ ] Resource placement
- [ ] Save/load system for chunks

### Phase 3: Interaction & Physics
- [ ] Physics engine integration
- [ ] Resource gathering mechanics
- [ ] Destruction system
- [ ] Animation system

### Phase 4: Polish & Features
- [ ] Inventory system
- [ ] UI/UX improvements
- [ ] Performance optimization
- [ ] Audio integration

## 🤝 Contributing

This is a collaborative project. Feel free to contribute!

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

[License to be determined]

## 👥 Team

- [Add team members]

## 📞 Contact

Project Link: [https://github.com/Thrainkrilleve/erasgame](https://github.com/Thrainkrilleve/erasgame)



