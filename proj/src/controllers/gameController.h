/**
 * @file gameController.h
 * @brief Defines functions for controlling the game state.
 */

#ifndef __GAME_CONTROLLER  
#define __GAME_CONTROLLER 

#include "Models/arena.h"
#include "Models/state.h"
#include "Views/views.h"

/**
 * @brief Resets the game by reinitializing the arena.
 * 
 * @param arena Pointer to the Arena structure to be reset.
 */
void resetGame(Arena *arena);

/**
 * @brief Changes the game state to the menu.
 * 
 * @param gameState Pointer to the current game state.
 * @param arena Pointer to the Arena structure.
 * @return int Returns 0 on success, non-zero on failure.
 */
int changeToMenu(State *gameState, Arena* arena);

/**
 * @brief Changes the background of the game.
 * 
 * @return int Returns 0 on success, non-zero on failure.
 */
int changeBackground();

/**
 * @brief Changes the state and the Background to the Highscore.
 * 
 * @return int Returns 0 on success, non-zero on failure.
 */
int changeToHighScore(State* gameState, HighScore score);

/**
 * @brief Changes the state and the Background to the Menu, from the HighScores.
 * 
 * @return int Returns 0 on success, non-zero on failure.
 */
int changeToMenuFromScores(State* gameState);



#endif // __GAME_CONTROLLER
