#include "bullet.h"


bullet* createBullet(position pos, int speed, uint8_t origin){
    bullet* b = (bullet*) malloc(sizeof(bullet));
    b->position = pos;
    b->speed = speed;
    b->origin = origin;
    return b;
}

void freebullet(bullet* b){
    if(!b) return;
    free(b);
    b = NULL;
}

