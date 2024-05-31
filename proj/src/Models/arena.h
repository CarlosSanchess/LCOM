#ifndef __ARENA__
#define __ARENA__

#include "Tank.h"
#include "mouse.h"
#include "obstacle.h"

#define NUM_OBSTACLES 12
#define ARENA_BORDER 50


typedef struct{
    tank* tank;
    EnemyTank* enemyTank;
    MouseInfo* crosshair;
    int width;
    int height;
    Obstacle obstacles[NUM_OBSTACLES];

    Obstacle** builts;
    size_t numBuilts;

    bullet** bullets;
    size_t numBullets;

    int curr_score;

}Arena;

Arena* createArena(int width, int height, MouseInfo *mouseInfo);
void destroyArena(Arena *arena);
void resetGame(Arena *arena);

#endif
