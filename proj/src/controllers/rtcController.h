/**
 * @file rtcController.h
 * @brief Declares functions for handling RTC (Real-Time Clock) operations.
 */

#ifndef __RTC_CONTROLLER__
#define __RTC_CONTROLLER__

#include <lcom/lcf.h>

#include "../dev_interface/devices/rtc.h"
#include "Models/arena.h"
#include "Models/HighScore.h"

/**
 * @brief Writes the High Score to a file or initializes.
 * 
 * @param highScore Pointer to the HighScore structure.
 */
void writeHighScoreToFile(HighScore score);

/**
 * @brief Reads the High Score from a file or initializes the high score with default values.
 * 
 * @param highScore Pointer to the HighScore structure.
 */
void readHighScoreFromFile(HighScore *highScore);


/**
 * @brief Initializes the high score with default values.
 * 
 * @param highScore Pointer to the HighScore structure.
 */
void initHighScore(HighScore *highScore);

/**
 * @brief Checks and updates the high score if the current score is higher.
 * 
 * @param arena Pointer to the Arena structure.
 * @param highScore Pointer to the HighScore structure.
 */
void checkAndUpdateHighScore(Arena *arena, HighScore *highScore);




#endif // __RTC_CONTROLLER__
