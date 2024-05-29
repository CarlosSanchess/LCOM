#ifndef __VIEWS__
#define __VIEWS__

#include "Models/arena.h"
#include "Models/menu.h"
#include "Models/Tank.h"
#include "Models/mouse.h"
#include "dev_interface/devices/video_gr.h"


int drawMenu(Menu menu);
int drawArena(Arena arena);
int drawTank(tank *tank);
int drawEnemyTank(tank *tank);
int drawMouse(MouseInfo mouse);

#endif

