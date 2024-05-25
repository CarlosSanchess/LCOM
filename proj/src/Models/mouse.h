#ifndef __MOUSE__
#define __MOUSE__

#include "Models/Position.h"
#include "dev_interface/devices/video_gr.h"
#include "xpm/cursor.xpm"
#include"xpm/crosshair.xpm"


typedef struct{
    position mousePosition;
    uint8_t crossHair;
}MouseInfo;

#include "mouse.c"

int drawMouse(MouseInfo mouse);

#endif
