#ifndef TANKCONTROLLER_H
#define TANKCONTROLLER_H

#include "Models/Tank.h"
#include "Models/arena.h"

bool canMove(int x, int y, Obstacle obstacles[], int numObstacles, Obstacle** builds, size_t numBuilds);
int moveDown(tank *tank, Obstacle obstacles[], int numObstacles, Obstacle** builds, size_t numBuilds);
int moveUP(tank *tank, Obstacle obstacles[], int numObstacles, Obstacle** builds, size_t numBuilds);
int moveRight(tank *tank);
int moveLeft(tank *tank);
int processTank(tank* tank, Obstacle obstacles[], int numObstacles);

#endif 
