#define FNL_IMPL

#include "tile.h"
#include "extern/FastNoiseLite.h"
#include <stdlib.h>
#include <stdio.h>

int tileCount = 0;
uint16_t typeCount = 0;
uint16_t worldSizeX = 0;
uint16_t worldSizeY = 0;
uint16_t edgeTileCount = 0;
TileInstance **tiles; // tile/world matrix
TileType *tileTypes;
TileInstance **edgeTiles; // list of pointers

void CreateTileType(const char *name, Texture2D sprite, PhysicalState state, uint16_t density, float bounce, float friction)
{
    typeCount++;
    tileTypes = realloc(tileTypes, sizeof(TileType) * (typeCount));
    tileTypes[typeCount - 1] = (TileType){typeCount - 1, name, sprite, state, density, bounce, friction};
}

void SetTile(uint16_t x, uint16_t y, uint16_t typeId)
{
    tileCount += (bool)typeId;
    tiles[x][y] = (TileInstance){
        typeId,
        (tileTypes[typeId].state == Solid) ? ((Rectangle){x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE}) : ((Rectangle){0}),
        0,
        // add adjacent tiles
        {y == 0 ? 0 : tiles[x][y - 1].type,
         x == worldSizeX - 1 ? 0 : tiles[x + 1][y].type,
         y == worldSizeY - 1 ? 0 : tiles[x][y + 1].type,
         x == 0 ? 0 : tiles[x - 1][y].type}};

    // add this new tile to adjacent tiles' data
    if (y > 0)
    {
        tiles[x][y - 1].surroundingTiles[2] = typeId;
    }
    if (x < worldSizeX - 1)
    {
        tiles[x + 1][y].surroundingTiles[3] = typeId;
    }
    if (y < worldSizeY - 1)
    {
        tiles[x][y + 1].surroundingTiles[0] = typeId;
    }
    if (x > 0)
    {
        tiles[x - 1][y].surroundingTiles[1] = typeId;
    }
}

void DrawTiles(bool colliders, Rectangle cameraBounds)
{
    for (int x = 0; x < worldSizeX; x++)
    {
        for (int y = 0; y < worldSizeY; y++)
        {
            // skip if can not be seen
            if ((x + 1) * TILE_SIZE < cameraBounds.x || x * TILE_SIZE > cameraBounds.x + cameraBounds.width || (y + 1) * TILE_SIZE < cameraBounds.y || y * TILE_SIZE > cameraBounds.y + cameraBounds.height)
            {
                continue;
            }
            // draw
            if (&tiles[x][y] != NULL)
            {
                DrawTexture(tileTypes[(tiles[x][y]).type].sprite, x * TILE_SIZE, y * TILE_SIZE, WHITE);
                if (colliders)
                {
                    DrawRectangleLinesEx(tiles[x][y].collider, 1, GREEN);
                }
            }
        }
    }
}

void GenerateWorld(uint16_t x_size, uint16_t y_size)
{
    // generation settings
    worldSizeX = x_size;
    worldSizeY = y_size;
    fnl_state noiseState = fnlCreateState();
    noiseState.seed = GetRandomValue(0, RAND_MAX);
    noiseState.frequency = 0.001f;
    noiseState.gain = 0.1f;
    noiseState.octaves = 4;
    noiseState.noise_type = FNL_NOISE_OPENSIMPLEX2;
    unsigned int scale = 100;

    // get noise data
    int *noiseData = malloc(x_size * sizeof(int));
    for (int i = 0; i < x_size; i++)
    {
        noiseData[i] = (int)floorf(((fnlGetNoise2D(&noiseState, i, 0.0f) + 1.0f) / 2.0f) * scale);
    }

    // allocate space for tile buffer
    tiles = (TileInstance **)malloc(sizeof(TileInstance *) * x_size);
    for (int i = 0; i < x_size; i++)
    {
        tiles[i] = (TileInstance *)malloc(sizeof(TileInstance) * y_size);
    }

    // fill tile buffer according to 1d noise data
    for (int x = 0; x < x_size; x++)
    {
        for (int y = 0; y < y_size; y++)
        {
            SetTile(x, y, 0);
        }
    }
    for (int x = 0; x < x_size; x++)
    {
        for (int y = y_size - 1; y > noiseData[x]; y--)
        {
            SetTile(x, y, 1);
        }
    }
    RefreshEdgeBuffer();

    free(noiseData);
}

void RefreshEdgeBuffer()
{
    // TODO: optimize
    // allocate buffer
    int edgeNumber = 0;
    for (int x = 0; x < worldSizeX; x++)
    {
        for (int y = 0; y < worldSizeY; y++)
        {
            TileInstance context = tiles[x][y];
            if (context.type != 0)
            {
                if (context.surroundingTiles[0] == 0 ||
                    context.surroundingTiles[1] == 0 ||
                    context.surroundingTiles[2] == 0 ||
                    context.surroundingTiles[3] == 0)
                {
                    edgeNumber++;
                }
            }
        }
    }
    free(edgeTiles);
    edgeTiles = (TileInstance **)malloc(sizeof(TileInstance *) * edgeNumber);
    edgeTileCount = edgeNumber;

    // fill buffer
    for (int x = 0; x < worldSizeX; x++)
    {
        for (int y = 0; y < worldSizeY; y++)
        {
            TileInstance *context = &tiles[x][y];
            if (context->type != 0)
            {
                if (context->surroundingTiles[0] == 0 ||
                    context->surroundingTiles[1] == 0 ||
                    context->surroundingTiles[2] == 0 ||
                    context->surroundingTiles[3] == 0)
                {
                    edgeTiles[edgeNumber - 1] = context;
                    edgeNumber--;
                }
            }
        }
    }
}