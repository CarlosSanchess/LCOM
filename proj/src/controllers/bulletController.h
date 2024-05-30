#ifndef __BULLET_CONTROLLER__
#define __BULLET_CONTROLLER__

#include "Models/bullet.h"
#include <lcom/lcf.h>
#include "Models/arena.h"
#include "Models/bullet.h"
#include "controllers/bulletController.h"
#include "controllers/builderController.h"

int addBulletToArena(Arena* arena);
int bulletMove(bullet* bullet);
int processBullets(Arena* arena);
int processBuilts(Arena *arena);


#endif

