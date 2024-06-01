#ifndef __VIEWS__
#define __VIEWS__

#include "Models/arena.h"
#include "Models/menu.h"
#include "Models/Tank.h"
#include "Models/mouse.h"
#include "Models/bullet.h"
#include "Models/HighScore.h"
#include "dev_interface/devices/video_gr.h"
#include "../xpm/bullet.xpm"
#include "../xpm/tank_green.xpm"
#include "../xpm/tank_red.xpm"
#include "../xpm/bomb.xpm"
#include "../xpm/highscore.xpm"
#include "../xpm/menuScore.xpm"
#include "../xpm/blocks/block1.xpm"
#include "../xpm/blocks/block2.xpm"
#include "../xpm/blocks/block3.xpm"
#include "../xpm/blocks/block4.xpm"
#include "../xpm/blocks/block5.xpm"
#include "../xpm/blocks/block6.xpm"
#include "../xpm/blocks/block7.xpm"
#include "../xpm/blocks/block8.xpm"
#include "../xpm/blocks/block9.xpm"
#include "../xpm/blocks/block10.xpm"
#include "../xpm/martelo.xpm"
#include "../xpm/menu.xpm"
#include "../xpm/mapa1.xpm"

int drawMenu(Menu menu, HighScore score);
int drawArena(Arena arena);
int drawTank(tank *tank);
int drawEnemyTank(EnemyTank *tank);
int drawMouse(MouseInfo mouse);
int drawBullet(bullet b);
int drawBullets(Arena arena);
int drawBuilds(Obstacle** builds, size_t numBuilts);
int drawBomb(int x, int y);
int drawHighScore(HighScore score);
int drawMenuBackGround();
int drawGameBackGround();
int drawScoreBackGround();

#endif

