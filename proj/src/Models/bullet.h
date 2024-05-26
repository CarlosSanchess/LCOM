#ifndef __BULLET__
#define __BULLET__

#include "Models/Position.h"
#include "dev_interface/devices/video_gr.h"
#include "xpm/bullet.xpm"


typedef struct{
    position position;
    int speed;
}bullet;


int drawBullet(bullet mouse);

#endif
