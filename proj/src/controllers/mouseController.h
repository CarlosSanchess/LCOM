#ifndef __MouseController__
#define __MouseController__

#include "../dev_interface/devices/timer_kbc_mouse/mouse.h"
#include "Models/state.h"
#include "Models/menu.h"
#include "Models/mouse.h"

#define MOUSE_SCALING_FACTOR 0.92
#define SCREEN_WIDTH 1152
#define SCREEN_HEIGHT 864
#define CURSOR_WIDTH 50
#define CURSOR_HEIGHT 50

extern struct packet mouse_byte_packet;
extern int mouse_errorHandling;

int handleInterruptMouse(State *gameState, Menu *menu, MouseInfo *mouseInfo);
void getPositionMouse(MouseInfo *mouseInfo);
void processMenu(State *gameState, Menu *menu, MouseInfo *mouseInfo);


#endif
