#ifndef __BULLET_CONTROLLER__
#define __BULLET_CONTROLLER__

#include "Models/bullet.h"
#include <lcom/lcf.h>
#include "Models/arena.h"
#include "Models/bullet.h"
#include "controllers/bulletController.h"
#include "controllers/builderController.h"
#include "controllers/collisionController.h"

#define GREEN_TANK 1
#define RED_TANK 2

int addBulletToArena(Arena* arena, int tankColor);
int bulletMove(bullet* bullet);
int processBullets(Arena* arena);
int processBuilts(Arena *arena);


#endif

