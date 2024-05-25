#ifndef __MouseController__
#define __MouseController__

#include "../dev_interface/devices/timer_kbc_mouse/mouse.h"
#include "Models/state.h"
#include "Models/menu.h"
#include "Models/mouse.h"

extern struct packet mouse_byte_packet;
extern int mouse_errorHandling;

int handleInterruptMouse(State *gameState, Menu *menu, MouseInfo *mouseInfo);
void getPositionMouse(MouseInfo *mouseInfo);
void processMenu(State *gameState, Menu *menu, MouseInfo *mouseInfo);

#include "mouseController.c"

#endif
