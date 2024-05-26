#include "Tank.h"


tank* createTank(int x, int y, uint16_t deg, int hp, int speed) {
    tank *newTank = (tank*)malloc(sizeof(tank));
    if (newTank == NULL) {
        fprintf(stderr, "Failed to allocate memory for tank.\n");
        return NULL;
    }
    newTank->position.x = x;
    newTank->position.y = y;

    newTank->position.deg = deg;
    newTank->hp = hp;
    newTank->speed = speed;

    newTank->wantToMove = 0;
    newTank->wantToRotate = 0;
    
    newTank->direction = 0;
    return newTank;
}

void freeTank(tank *tank) {
    if (tank != NULL) {
        free(tank);
    }
}
