# Technical Design Document

## Chunk System Design

### Chunk Specifications
- **Size**: 20x20 tiles
- **Tile Size**: 32x32 pixels
- **Total Pixels per Chunk**: 640x640 pixels
- **Tiles per Chunk**: 400

### Loading System
```
Player Position -> Calculate Visible Chunks (9-12) -> Load/Generate -> Cache in Memory
```

### Optimization Strategy
1. **Pregeneration**: Generate chunks around spawn point during game load
2. **Caching**: Keep loaded chunks in memory for quick access
3. **Async Loading**: Load chunks on separate thread to prevent frame drops
4. **Unload Distance**: Unload chunks beyond render distance

### Data Structure Proposal
```
Chunk {
  position: (x, y)
  tiles: [400 elements]
  entities: []
  modified: boolean
  lastAccessed: timestamp
}
```

## Physics System

### Rigid Body Implementation
- Use existing physics library (e.g., Box2D, Chipmunk)
- Each destructible object as separate rigid body
- Progressive damage system tracking hit points

### Tree Chopping Example
1. Player hits tree -> decrement HP
2. HP reaches threshold -> trigger falling animation
3. Tree becomes dynamic rigid body
4. Falls with realistic physics
5. Settles and becomes static/collectible

## File Format Specification

### Chunk Data (.ini format)
```ini
[chunk_x_y]
generated=true
seed=12345
modified=false

[tiles]
0_0=grass,1
0_1=grass,1
...

[entities]
tree_0=oak,x,y,hp
rock_0=boulder,x,y,hp
```

## Performance Targets
- **FPS**: 60 fps stable
- **Chunk Load Time**: < 16ms per chunk
- **Memory**: < 500MB for 9 chunks loaded
