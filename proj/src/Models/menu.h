#ifndef __MENU__
#define __MENU__

#include "xpm/grenade.xpm"
#include "dev_interface/devices/video_gr.h"

typedef struct{
    int selected;
    bool InGame;
    int coord[3][2]; //Coodenadas para desenhar a granada
}Menu;



#endif

