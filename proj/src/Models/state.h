/**
 * @file state.h
 * @brief Defines the State enumeration used to represent different game states.
 */

#ifndef __STATE__
#define __STATE__

/**
 * @brief Enumeration to represent different game states.
 * 
 * This enumeration holds the possible states of the game, such as in the menu,
 * in-game, multiplayer mode, and score display.
 */
typedef enum {
    inMenu,   /**< State representing the menu screen */
    inGame,   /**< State representing the gameplay */
    Multi,    /**< State representing multiplayer mode */
    Score     /**< State representing the score display */
} State;

#endif // __STATE__
