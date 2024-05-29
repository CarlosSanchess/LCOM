#ifndef __VIEWS__
#define __VIEWS__

#include "Models/arena.h"
#include "Models/menu.h"
#include "Models/Tank.h"
#include "Models/mouse.h"
#include "Models/bullet.h"
#include "dev_interface/devices/video_gr.h"
#include "../xpm/bullet_xpm.xpm"
#include "../xpm/tank_green.xpm"


int drawMenu(Menu menu);
int drawArena(Arena arena);
int drawTank(tank *tank);
int drawEnemyTank(EnemyTank *tank);
int drawMouse(MouseInfo mouse);
int drawBullet(bullet b);
int drawBullets(Arena arena);

#endif

