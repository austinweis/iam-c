#ifndef TILE
#define TILE

#define TILE_SIZE 8
#define tile_id uint16_t

#include <raylib.h>
#include <inttypes.h>
#include <stdlib.h>


typedef enum PhysicalState
{
    Gas,
    Liquid,
    Solid
} PhysicalState;

typedef struct TileType
{
    uint16_t id;
    const char *name;
    Texture2D sprite;

    PhysicalState state;
    uint16_t maxDensity;
    float bounce;
    float friction;
} TileType;

typedef struct TileInstance
{
    tile_id type;

    Rectangle collider;
    uint16_t damage;

    tile_id surroundingTiles[4]; // top, right, bottom, left
} TileInstance;

extern int tileCount;
extern uint16_t typeCount;
extern uint16_t edgeTileCount;
extern TileInstance **tiles;
extern TileType *tileTypes;
extern TileInstance **edgeTiles;
extern uint16_t worldSizeX;
extern uint16_t worldSizeY;


void CreateTileType(const char *name, Texture2D sprite, PhysicalState state, uint16_t density, float bounce, float friction);
void SetTile(uint16_t x, uint16_t y, uint16_t typeId);
void DrawTiles(bool colliders, Rectangle cameraBounds);
void GenerateWorld(int seed, uint16_t x_size, uint16_t y_size);
void RefreshEdgeBuffer();

#endif