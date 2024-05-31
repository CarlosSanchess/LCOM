#ifndef __RTC_CONTROLLER__
#define __RTC_CONTROLLER__

#include "../dev_interface/devices/rtc.h"
#include "Models/arena.h"

typedef struct {
    int score;
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
} HighScore;

void initHighScore(HighScore *highScore);

void checkAndUpdateHighScore(Arena *arena, HighScore *highScore);

#endif 
