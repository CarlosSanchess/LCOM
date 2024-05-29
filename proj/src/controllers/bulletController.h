#ifndef __BULLET_CONTROLLER__
#define __BULLET_CONTROLLER__

#include "Models/bullet.h"
#include <lcom/lcf.h>
#include "Models/arena.h"
#include "Models/bullet.h"
#include "controllers/bulletController.h"

int addBulletToArena(Arena* arena);
int bulletMove(bullet* bullet);
int handleBullet(bullet* bullet, size_t *numBullets, int width, int height);
int processBullets(bullet** bullets, size_t *numBullets, int width, int height);


#endif

