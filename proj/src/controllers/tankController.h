#ifndef TANKCONTROLLER_H
#define TANKCONTROLLER_H

#include "Models/Tank.h"
#include "Models/arena.h"

bool canMove(int x, int y, Obstacle obstacles[], int numObstacles);
int moveDown(tank *tank, Obstacle obstacles[], int numObstacles);
int moveUP(tank *tank, Obstacle obstacles[], int numObstacles);
int moveRight(tank *tank);
int moveLeft(tank *tank);
int processTank(tank* tank, Obstacle obstacles[], int numObstacles);

#endif 
