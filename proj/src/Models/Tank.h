#ifndef __TANK_H__
#define __TANK_H__

#include "Position.h"
#include "dev_interface/devices/video_gr.h"
#include "xpm/tank_green.xpm"

#define LEFT -2
#define RIGHT 2
#define UP 1
#define DOWN -1

typedef struct{
    position position;
    int hp;
    int speed;
    int wantToMove;
    uint16_t wantToRotate;

    int direction; // 1 UP -1 DOWN 2 RIGHT -2 LEFT
}tank;

#include "tank.c"

void destroyTank(tank *tank);
tank* createTank(int x, int y,uint16_t deg, int hp, int speed);
void drawTank();
bool canMove(int x, int y);
int moveUP(tank *tank);



#endif
