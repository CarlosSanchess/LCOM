#ifndef __MOUSE__
#define __MOUSE__

#include "Models/Position.h"
#include "dev_interface/devices/video_gr.h"
#include "xpm/cursor.xpm"


typedef struct{
    position mousePosition;
    //bool crossHair;
}MouseInfo;

#include "mouse.c"

int drawMouse(MouseInfo mouse);

#endif
