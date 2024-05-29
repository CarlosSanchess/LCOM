#ifndef __ARENA__
#define __ARENA__

#include "Tank.h"
#include "mouse.h"

#define NUM_OBSTACLES 12

typedef struct {
    int x1, x2;
    int y1, y2;
} Obstacle;

typedef struct{
    tank* tank;
    EnemyTank* enemyTank;
    MouseInfo* crosshair;
    int width;
    int height;
    Obstacle obstacles[NUM_OBSTACLES];


}Arena;

Arena* createArena(int width, int height, MouseInfo *mouseInfo);
void destroyArena(Arena *arena);

#endif
