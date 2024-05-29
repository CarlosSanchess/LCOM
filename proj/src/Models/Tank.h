#ifndef __TANK_H__
#define __TANK_H__

#include <lcom/lcf.h>
#include "Position.h"
#include "xpm/tank_green.xpm"
#include "xpm/tank_red.xpm"
#include "utils/utilsFunctions.h"

#define LEFT -2
#define RIGHT 2
#define UP 1
#define DOWN -1

#define TANK_WIDTH 42
#define TANK_HEIGHT 46

#define MAP_WIDTH 1152
#define MAP_HEIGHT 864

typedef struct{
    position position;
    int hp;
    int speed;
    int wantToMove;
    uint16_t wantToRotate;   
     
    int direction; // 1 UP -1 DOWN 2 RIGHT -2 LEFT
} tank;

tank* createTank(int x, int y,uint16_t deg, int hp, int speed);
void freeTank(tank *tank);
tank* createEnemyTank(int x, int y, uint16_t deg, int hp, int speed);
void freeEnemyTank(tank *enemyTank);

#endif
