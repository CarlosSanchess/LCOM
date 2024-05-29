#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#include "Models/Tank.h"
#include "Models/arena.h"
#include "tankController.h"

void moveEnemyTank(tank* enemy, tank* player, Obstacle obstacles[], int numObstacles);

int processEnemyTank(tank* tank, Obstacle obstacles[], int numObstacles, Arena* arena);

#endif 
