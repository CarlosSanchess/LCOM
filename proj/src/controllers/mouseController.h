#ifndef __MouseController__
#define __MouseController__

#include "../dev_interface/devices/timer_kbc_mouse/mouse.h"
#include "Models/state.h"
#include "Models/menu.h"
#include "Models/mouse.h"
#include "mouseController.c"

extern struct packet mouse_byte_packet;

int handleInterruptMouse(State *gameState, Menu *menu, MouseInfo *mouseInfo);

#endif
