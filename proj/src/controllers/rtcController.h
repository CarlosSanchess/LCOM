#ifndef __RTC_CONTROLLER__
#define __RTC_CONTROLLER__

#include "../dev_interface/devices/rtc.h"
#include "Models/arena.h"

int readHighScore(const char *filename, int *score, uint8_t *hours, uint8_t *minutes, uint8_t *seconds);

int writeHighScore(const char *filename, int score, uint8_t hours, uint8_t minutes, uint8_t seconds);

void checkAndUpdateHighScore(Arena *arena, int *highScore, uint8_t *highScoreHours, uint8_t *highScoreMinutes, uint8_t *highScoreSeconds, const char *highscoreFile);

#endif 
