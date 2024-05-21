#ifndef MouseController
#define MouseController

#include "../dev_interface/devices/timer_kbc_mouse/mouse.h"
#include "Models/state.h"
#include "Models/menu.h"
#include "mouseController.c"

extern struct packet mouse_byte_packet;

int handleInterruptMouse(State *gameState, Menu *menu);

#endif
