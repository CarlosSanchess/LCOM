/**
 * @file mouseController.h
 * @brief Declares functions for handling mouse interrupts and controlling game states based on mouse lb clicks.
 */

#ifndef __MouseController__
#define __MouseController__

#include "../dev_interface/devices/timer_kbc_mouse/mouse.h"
#include "Models/state.h"
#include "Models/menu.h"
#include "Models/mouse.h"
#include "Models/obstacle.h"
#include "Models/arena.h"
#include "controllers/builderController.h"
#include "controllers/gameController.h"

#define MOUSE_SCALING_FACTOR 0.5
#define SCREEN_WIDTH 1152
#define SCREEN_WIDTH_RIGHT 5
#define HAMMER_TOP 18
#define HAMMER_LOW 795
#define HAMMER_LEFT 5
#define HAMMER_RIGHT 1085
#define SCREEN_HEIGHT_LOW 795
#define CURSOR_WIDTH 50
#define CURSOR_HEIGHT 50

extern struct packet mouse_byte_packet;
extern int mouse_errorHandling;

/**
 * @brief Handles mouse interrupts and processes game state changes.
 * 
 * @param gameState Pointer to the current game state.
 * @param menu Pointer to the Menu structure.
 * @param arena Pointer to the Arena structure.
 * @param mouseInfo Pointer to the MouseInfo structure.
 * @param score Value of the current HighScore.
 * @return int Returns 0 on success, 1 if the game should exit.
 */
int handleInterruptMouse(State *gameState, Menu *menu, Arena *arena, MouseInfo *mouseInfo, HighScore score);

/**
 * @brief Updates the mouse position based on input.
 * 
 * @param mouseInfo Pointer to the MouseInfo structure.
 */
void getPositionMouse(MouseInfo *mouseInfo);

/**
 * @brief Processes the menu interactions based on mouse input.
 * 
 * @param gameState Pointer to the current game state.
 * @param menu Pointer to the Menu structure.
 * @param mouseInfo Pointer to the MouseInfo structure.
 * @param score Value of the current HighScore.
 * @return int Returns 0 on success, non-zero on failure.
 */
int processMenu(State *gameState, Menu *menu, MouseInfo *mouseInfo, HighScore score);

/**
 * @brief Processes the build actions in the arena based on mouse input.
 * 
 * @param arena Pointer to the Arena structure.
 * @param mouseInfo Pointer to the MouseInfo structure.
 * @return int Returns 0 on success.
 */
int processBuild(Arena *arena, MouseInfo *mouseInfo);

#endif // __MouseController__
