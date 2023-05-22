#include "physics.h"
#include <stdio.h>

TileInstance *CollisionWithTile(EntityInstance entity)
{
    Rectangle entityCol = {entity.position.x, entity.position.y, entity.type.size.x, entity.type.size.y};
    // check collision with tiles
    for (int i = 0; i < edgeTileCount; i++)
    {
        if (CheckCollisionRecs(entityCol, edgeTiles[i]->collider)){
            return edgeTiles[i];
        }
    }
    return NULL;
}