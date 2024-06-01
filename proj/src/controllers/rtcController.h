#ifndef __RTC_CONTROLLER__
#define __RTC_CONTROLLER__

#include "../dev_interface/devices/rtc.h"
#include "Models/arena.h"
#include "Models/HighScore.h"

void initHighScore(HighScore *highScore);

void checkAndUpdateHighScore(Arena *arena, HighScore *highScore);

#endif 
