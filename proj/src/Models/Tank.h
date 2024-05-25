#ifndef __TANK_H__
#define __TANK_H__

#include "Position.h"
#include "dev_interface/devices/video_gr.h"
#include "xpm/tank_green.xpm"

#define LEFT -2
#define RIGHT 2
#define UP 1
#define DOWN -1

#define TANK_WIDTH 42
#define TANK_HEIGHT 46

#define NUM_OBSTACLES 12

typedef struct{
    position position;
    int hp;
    int speed;
    int wantToMove;
    uint16_t wantToRotate;

    int direction; // 1 UP -1 DOWN 2 RIGHT -2 LEFT
} tank;

typedef struct {
    int x1, x2;
    int y1, y2;
} Obstacle;

extern Obstacle obstacles[NUM_OBSTACLES];

#include "tank.c"

<<<<<<< HEAD
void destroyTank(tank *tank);
tank* createTank(int x, int y,uint16_t deg, int hp, int speed);
void drawTank();
=======
tank* createTank(int x, int y, int hp, int speed);
void destroyTank(tank *tank);
void freeTank(tank *tank);
void drawTank(tank *tank);
>>>>>>> 579e33ca665290381744c229251a839beb878933
bool canMove(int x, int y);
int moveUP(tank *tank);
int moveDown(tank *tank);
int moveLeft(tank *tank);
int moveRight(tank *tank);

#endif
