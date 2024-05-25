#include "Tank.h"

tank* createTank(int x, int y, int hp, int speed) {
    tank *newTank = (tank*)malloc(sizeof(tank));
    if (newTank == NULL) {
        fprintf(stderr, "Failed to allocate memory for tank.\n");
        return NULL;
    }
    newTank->position.x = x;
    newTank->position.y = y;
    newTank->hp = hp;
    newTank->speed = speed;
    return newTank;
}

void freeTank(tank *tank) {
    if (tank != NULL) {
        free(tank);
    }
}
bool canMove(int x, int y){ //TODO
    if((x < 1000 && x > 0) && (y > 0 && y < 1000)){
        return true;
    }
    return false;
}
int moveUP(tank *tank){
    if(canMove(tank->position.x, tank->position.y + 1)){
        tank->position.y -= tank->speed * 5;
        return 0;
    }
    return 1;
}
int moveRight(tank *tank) {
    if (canMove(tank->position.x + 1, tank->position.y)) {
        tank->position.x += tank->speed * 5;
        return 0;
    }
    return 1;
}

int moveLeft(tank *tank) {
    if (canMove(tank->position.x - 1, tank->position.y)) {
        tank->position.x -= tank->speed * 5;
        return 0;
    }
    return 1;
}


int moveDown(tank *tank) {
    if (canMove(tank->position.x, tank->position.y - 1)) {
        tank->position.y += tank->speed * 5;
        return 0;
    }
    return 1;
}

void drawTank(tank *tank) {
    xpm_draw_ignore(tank_green, tank->position.x, tank->position.y, GREEN_SCREEN);  
}
