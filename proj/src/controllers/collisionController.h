#ifndef __COLLISION_
#define __COLLISION_

#include "Models/bullet.h"
#include "Models/Tank.h"
#include "Models/arena.h"
#include "Models/Position.h"

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Hitbox;

bool checkCollision(Hitbox *a, Hitbox *b);

#endif
