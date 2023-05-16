#ifndef ENTITY
#define ENTITY

#include <raylib.h>
#include <inttypes.h>
#include "tile.h"

typedef struct EntityType
{
    uint16_t id;
    const char* name;
    float SPD_MOD;
    float JMP_MOD;

    Texture2D sprite;
    Vector2 size; // collider size
} EntityType;

typedef struct EntityInstance
{
    EntityType type;

    uint8_t lvl;
    Vector2 acceleration;
    Vector2 velocity;
    Vector2 position;
    TileInstance *verticallyAdjacentTile;
    TileInstance *horizontallyAdjacentTile;
} EntityInstance;

void UpdateEntity(EntityInstance* entity, float deltaTime);
void DrawEntity(EntityInstance entity, bool collider);
Rectangle GetCollider(EntityInstance entity);

#endif