#ifndef __TANK_H__
#define __TANK_H__

#include "Position.h"
#include "dev_interface/devices/video_gr.h"
#include "xpm/tank_green.xpm"

typedef struct{
    position position;
    int hp;
    int speed;
}tank;

#include "tank.c"

void destroyTank(tank *tank);
tank* createTank(int x, int y, int hp, int speed);
void drawTank();
bool canMove(int x, int y);
int moveUP(tank *tank);


#endif
