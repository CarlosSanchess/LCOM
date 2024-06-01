/**
 * @file kbController.h
 * @brief Declares functions for handling keyboard interrupts and controlling game states.
 */

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

/**
 * @brief Handles keyboard interrupts and processes game state changes.
 * 
 * @param gameState Pointer to the current game state.
 * @param menu Pointer to the Menu structure.
 * @param arena Pointer to the Arena structure.
 * @return int Returns 0 on success, 1 if the game should exit.
 */
int handleInterruptKBC(State *gameState, Menu *menu, Arena *arena);

/**
 * @brief Processes the menu interactions based on keyboard input.
 * 
 * @param gameState Pointer to the current game state.
 * @param menu Pointer to the Menu structure.
 * @param arena Pointer to the Arena structure.
 * @return int Returns 0 on success, 1 if the game should exit.
 */
int handleMenu(State *gameState, Menu *menu, Arena *arena);

/**
 * @brief Handles tank movements based on keyboard input.
 * 
 * @param arena Pointer to the Arena structure.
 * @return int Returns 0 on success.
 */
int handleTank(Arena *arena);

/**
 * @brief Handles arena interactions based on keyboard input.
 * 
 * @param arena Pointer to the Arena structure.
 * @return int Returns 0 on success.
 */
int handleArena(Arena *arena);

#endif // __KBController__
