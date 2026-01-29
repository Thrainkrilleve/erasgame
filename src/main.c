/*******************************************************************************************
*
*   Erasgame - Main Entry Point
*   A 2D open-world sandbox game with chunk generation
*
********************************************************************************************/

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

// Constants
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define TILE_SIZE 32
#define CHUNK_SIZE 20
#define TILES_PER_CHUNK (CHUNK_SIZE * CHUNK_SIZE)

// Structures
typedef struct {
    int x;
    int y;
    int type;  // 0 = air, 1 = grass, 2 = dirt, 3 = stone, etc.
} Tile;

typedef struct {
    int chunkX;
    int chunkY;
    Tile tiles[TILES_PER_CHUNK];
    bool isGenerated;
    bool isModified;
} Chunk;

typedef struct {
    Vector2 position;
    Vector2 velocity;
    float speed;
} Player;

// Function declarations
void InitGame(void);
void UpdateGame(void);
void DrawGame(void);
void GenerateChunk(Chunk* chunk, int chunkX, int chunkY);
void DrawChunk(Chunk* chunk);
Color GetTileColor(int tileType);

// Global variables
Player player = {0};
Chunk testChunk = {0};  // Start with one chunk for testing

int main(void)
{
    // Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Erasgame - Development Build");
    SetTargetFPS(60);
    
    InitGame();
    
    // Main game loop
    while (!WindowShouldClose())
    {
        UpdateGame();
        
        BeginDrawing();
        ClearBackground(SKYBLUE);
        DrawGame();
        
        // Debug info
        DrawText(TextFormat("FPS: %d", GetFPS()), 10, 10, 20, DARKGRAY);
        DrawText(TextFormat("Player: (%.0f, %.0f)", player.position.x, player.position.y), 10, 35, 20, DARKGRAY);
        DrawText("WASD to move | ESC to exit", 10, 60, 20, DARKGRAY);
        
        EndDrawing();
    }
    
    // Cleanup
    CloseWindow();
    
    return 0;
}

void InitGame(void)
{
    // Initialize player
    player.position = (Vector2){ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
    player.velocity = (Vector2){ 0, 0 };
    player.speed = 200.0f;
    
    // Generate test chunk
    GenerateChunk(&testChunk, 0, 0);
    
    printf("Game initialized!\n");
}

void UpdateGame(void)
{
    float deltaTime = GetFrameTime();
    
    // Player movement
    player.velocity = (Vector2){ 0, 0 };
    
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) player.velocity.y = -1;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) player.velocity.y = 1;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) player.velocity.x = -1;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) player.velocity.x = 1;
    
    // Normalize diagonal movement
    if (player.velocity.x != 0 && player.velocity.y != 0) {
        player.velocity.x *= 0.707f;
        player.velocity.y *= 0.707f;
    }
    
    // Apply movement
    player.position.x += player.velocity.x * player.speed * deltaTime;
    player.position.y += player.velocity.y * player.speed * deltaTime;
}

void DrawGame(void)
{
    // Draw chunk
    DrawChunk(&testChunk);
    
    // Draw player (simple circle for now)
    DrawCircleV(player.position, 16, RED);
}

void GenerateChunk(Chunk* chunk, int chunkX, int chunkY)
{
    chunk->chunkX = chunkX;
    chunk->chunkY = chunkY;
    
    // Simple generation: create a basic pattern
    for (int y = 0; y < CHUNK_SIZE; y++) {
        for (int x = 0; x < CHUNK_SIZE; x++) {
            int index = y * CHUNK_SIZE + x;
            
            // Simple terrain: grass on top, dirt below
            if (y < 5) {
                chunk->tiles[index].type = 0;  // Air
            } else if (y < 8) {
                chunk->tiles[index].type = 1;  // Grass
            } else {
                chunk->tiles[index].type = 2;  // Dirt
            }
            
            chunk->tiles[index].x = x;
            chunk->tiles[index].y = y;
        }
    }
    
    chunk->isGenerated = true;
    chunk->isModified = false;
    
    printf("Generated chunk at (%d, %d)\n", chunkX, chunkY);
}

void DrawChunk(Chunk* chunk)
{
    if (!chunk->isGenerated) return;
    
    int screenOffsetX = (SCREEN_WIDTH - (CHUNK_SIZE * TILE_SIZE)) / 2;
    int screenOffsetY = (SCREEN_HEIGHT - (CHUNK_SIZE * TILE_SIZE)) / 2;
    
    for (int i = 0; i < TILES_PER_CHUNK; i++) {
        Tile tile = chunk->tiles[i];
        
        if (tile.type == 0) continue;  // Skip air tiles
        
        Rectangle tileRect = {
            screenOffsetX + tile.x * TILE_SIZE,
            screenOffsetY + tile.y * TILE_SIZE,
            TILE_SIZE,
            TILE_SIZE
        };
        
        Color tileColor = GetTileColor(tile.type);
        DrawRectangleRec(tileRect, tileColor);
        DrawRectangleLinesEx(tileRect, 1, ColorAlpha(BLACK, 0.1f));
    }
}

Color GetTileColor(int tileType)
{
    switch (tileType) {
        case 0: return BLANK;           // Air
        case 1: return GREEN;           // Grass
        case 2: return BROWN;           // Dirt
        case 3: return GRAY;            // Stone
        default: return PINK;           // Unknown
    }
}
