#ifndef __ARENA__
#define __ARENA__

#include "Tank.h"
#include "mouse.h"

#define ARENA_BORDER 50
typedef struct{
    tank* tank;
    MouseInfo* crosshair;
    int width;
    int height;
    bullet** bullets;
    size_t numBullets;

}Arena;

Arena* createArena(int width, int height, MouseInfo *mouseInfo);
void destroyArena(Arena *arena);

#endif
