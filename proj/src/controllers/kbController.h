#ifndef __KBController__
#define __KBController__

#include "../dev_interface/devices/timer_kbc_mouse/kbc.h"
#include "Models/state.h"
#include "Models/menu.h"
#include "Models/arena.h"
#include "controllers/tankController.h"
#include "controllers/bulletController.h"
#include "controllers/gameController.h"


extern uint8_t scanCode;

int handleInterruptKBC(State *gameState, Menu *menu, Arena *arena);
int handleMenu(State *gameState ,Menu *menu, Arena* arena);
int handleTank(Arena* arena);
int handleArena(Arena* arena);


#endif 

