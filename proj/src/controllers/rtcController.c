#include "rtcController.h"

void initHighScore(HighScore *highScore) {
    highScore->score = 0;
    highScore->hours = 0;
    highScore->minutes = 0;
    highScore->seconds = 0;
}

void checkAndUpdateHighScore(Arena *arena, HighScore *highScore) {
    if (arena->curr_score > highScore->score) {
        highScore->score = arena->curr_score;
        update_rtc_time(&highScore->seconds, &highScore->minutes, &highScore->hours);
    }
}
