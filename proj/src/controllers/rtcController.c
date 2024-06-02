#include "rtcController.h"

char *filename = "/home/lcom/labs/g4/proj/src/highscore.txt";

void readHighScoreFromFile(HighScore *highScore) {
    char buffer[20];
    int i = 0;
    FILE *file = fopen(filename, "r");

     fgets(buffer, 80, file);
     char *token = strtok(buffer, ",");
     while (token) { 
        if(i == 0){highScore->score = (int)atoi(token);}
        if(i == 1){highScore->hours = (uint8_t)atoi(token);}
        if(i == 2){highScore->minutes = (uint8_t)atoi(token);}
        if(i == 3){highScore->seconds = (uint8_t)atoi(token);}
        
        i++;
         token = strtok(NULL, ",");
     }


    fclose(file);
}
void writeHighScoreToFile(HighScore score){
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }
    
    fprintf(file, "%d,%d,%d,%d\n", score.score, score.hours, score.minutes, score.seconds);
    
    fclose(file);
}

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



