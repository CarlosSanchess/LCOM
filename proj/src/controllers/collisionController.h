#ifndef __COLLISION_
#define __COLLISION_

 #include <lcom/lcf.h>

#include "Views/views.h"
#include "Models/bullet.h"
#include "Models/Tank.h"
#include "Models/arena.h"
#include "Models/Position.h"
#include "Models/Hitbox.h"
#include "controllers/gameController.h"

#include "dev_interface/devices/graphics_const.h"

bool checkCollision(Hitbox a, Hitbox b);
int processCollisions(Arena* arena,size_t index, Hitbox tankHB, Hitbox enemyTankHB,Hitbox bulletHB);

#endif

