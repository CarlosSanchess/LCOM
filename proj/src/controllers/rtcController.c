#include "rtcController.h"

int readHighScore(const char *filename, int *score, uint8_t *hours, uint8_t *minutes, uint8_t *seconds) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }

    if (fscanf(file, "%d %hhu %hhu %hhu", score, hours, minutes, seconds) != 4) {
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

int writeHighScore(const char *filename, int score, uint8_t hours, uint8_t minutes, uint8_t seconds) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        return -1;
    }

    fprintf(file, "%d %hhu %hhu %hhu", score, hours, minutes, seconds);
    fclose(file);
    return 0;
}

void checkAndUpdateHighScore(Arena *arena, int *highScore, uint8_t *highScoreHours, uint8_t *highScoreMinutes, uint8_t *highScoreSeconds, const char *highscoreFile) {
    if (arena->curr_score > *highScore) {
        *highScore = arena->curr_score;
        update_rtc_time(highScoreSeconds, highScoreMinutes, highScoreHours);
        writeHighScore(highscoreFile, *highScore, *highScoreHours, *highScoreMinutes, *highScoreSeconds);
    }
}
