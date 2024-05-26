#ifndef __BULLET__
#define __BULLET__

#include "Position.h"
#include "dev_interface/devices/video_gr.h"

#define BULLET_SPEED 5
#define BULLET_WIDTH 40
#define BULLET_HEIGHT 40

#define PLAYER 1
#define ENEMY 2

typedef struct{
    position position;
    int speed;
    uint8_t origin;
}bullet;


bullet* createBullet(position pos, int speed, uint8_t origin);
void freebullet(bullet* b);

#endif

