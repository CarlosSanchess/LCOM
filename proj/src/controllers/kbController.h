#ifndef __KBController__
#define __KBController__

#include "../dev_interface/devices/timer_kbc_mouse/kbc.h"
#include "Models/state.h"
#include "Models/menu.h"
#include "Models/arena.h"
#include "controllers/tankController.h"
#include "controllers/bulletController.h"

extern uint8_t scanCode;

int handleInterruptKBC(State *gameState, Menu *menu, Arena *arena);
int handleMenu(State *gameState ,Menu *menu, Arena* arena);
<<<<<<< HEAD
int handleTank(tank* tank, Obstacle Obstacles[], int numObstacles);

#include "kbController.c"
=======
int handleTank(tank* tank);
int handleArena(Arena* arena);
>>>>>>> bullet


#endif 

