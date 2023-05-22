#include "entity.h"
#include "physics.h"
#include "tile.h"
#include <stdio.h>

#include <raymath.h>

void UpdateEntity(EntityInstance *entity, float deltaTime)
{
    // Update velocity
    entity->velocity = Vector2Add(entity->velocity, Vector2Scale(entity->acceleration, deltaTime));
    entity->velocity = Vector2Scale(entity->velocity, 1.0f - (DRAG * deltaTime));
    if (entity->verticallyAdjacentTile != NULL && entity->acceleration.x == 0) // if on ground and not accelerating
    {
        entity->velocity.x *= (1.0f - (tileTypes[entity->verticallyAdjacentTile->type].friction * deltaTime)); // apply friction
    }

    // update position and process collisions
    entity->position.x += entity->velocity.x * deltaTime;
    TileInstance *colTile = CollisionWithTile(*entity);
    entity->horizontallyAdjacentTile = colTile;
    if (colTile != NULL)
    {
        entity->position.x = (entity->velocity.x > 0) ? (entity->position.x = colTile->collider.x - entity->type.size.x) : (entity->position.x = colTile->collider.x + colTile->collider.width);
        entity->velocity.x *= -tileTypes[-(*colTile).type].bounce;
    }

    entity->position.y += entity->velocity.y * deltaTime;
    colTile = CollisionWithTile(*entity);
    entity->verticallyAdjacentTile = colTile;
    if (colTile != NULL)
    {
        entity->position.y = (entity->velocity.y > 0) ? (entity->position.y = colTile->collider.y - entity->type.size.y) : (entity->position.y = colTile->collider.y + colTile->collider.height);
        entity->velocity.y *= -tileTypes[(*colTile).type].bounce;
    }
}
void DrawEntity(EntityInstance entity, bool collider)
{
    DrawTexture(entity.type.sprite, entity.position.x, entity.position.y, WHITE);
    if (collider)
    {
        DrawRectangleLinesEx(GetCollider(entity), 1, GREEN);
    }
}
Rectangle GetCollider(EntityInstance entity)
{
    return (Rectangle){
        entity.position.x,
        entity.position.y,
        entity.type.size.x,
        entity.type.size.y};
}