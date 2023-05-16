#ifndef PHYSICS
#define PHYSICS

#define GRAVITY 9.82f * 60.0f
#define DRAG 1.0f

#include <raylib.h>
#include "entity.h"
#include "tile.h"

TileInstance *CollisionWithTile(EntityInstance entity);

#endif