#include "physics.h"
#include <stdio.h>

TileInstance *CollisionWithTile(EntityInstance entity)
{
    // check collision with tiles
    for (int i = 0; i < edgeTileCount; i++)
    {
        if (CheckCollisionRecs(GetCollider(entity), edgeTiles[i]->collider)){
            return edgeTiles[i];
        }
    }
    return NULL;
}