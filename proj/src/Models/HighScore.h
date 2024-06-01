/**
 * @file HighScore.h
 * @brief Defines the HighScore structure used to store high score details.
 */

#ifndef __HIGH_SCORE__
#define __HIGH_SCORE__

#include <stdint.h>

/**
 * @brief Structure to store high score details.
 * 
 * This structure holds the score and the time (in hours, minutes, and seconds)
 * associated with the score.
 */
typedef struct {
    int score;        /**< The score value */
    uint8_t hours;    /**< Hours component of the time */
    uint8_t minutes;  /**< Minutes component of the time */
    uint8_t seconds;  /**< Seconds component of the time */
} HighScore;

#endif // __HIGH_SCORE__
