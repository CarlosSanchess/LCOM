#ifndef __ARENA__
#define __ARENA__

#include "Tank.h"
#include "mouse.h"


typedef struct{
    tank* tank;
    MouseInfo* crosshair;
    int width;
    int height;


}Arena;

Arena* createArena(int width, int height, MouseInfo *mouseInfo);
void destroyArena(Arena *arena);

#endif
