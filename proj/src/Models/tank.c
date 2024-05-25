#include "Tank.h"

tank* createTank(int x, int y,uint16_t deg, int hp, int speed) {
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
    newTank->direction = 0;
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
        tank->wantToMove += tank->speed * 10;
        tank->direction = UP;
        return 0;
    }
    return 1;
}
int moveRight(tank *tank) {
    if (canMove(tank->position.x + 1, tank->position.y)) {
        tank->wantToRotate += 10;
        tank->direction = RIGHT;
        return 0;
    }
    return 1;
}

int moveLeft(tank *tank) {
    if (canMove(tank->position.x - 1, tank->position.y)) {
        tank->wantToRotate -= 10;
        tank->direction = LEFT;
        return 0;
    }
    return 1;
}


int moveDown(tank *tank) {
    if (canMove(tank->position.x, tank->position.y - 1)) {
        tank->wantToMove += tank->speed * 10;
        tank->direction = DOWN;
        return 0;
    }
    return 1;
}

void drawTank(tank *tank) {
    if(tank->wantToMove >= tank->speed || tank->wantToRotate >= 10){
        tank->wantToMove -= 2;
        switch (tank->direction)
        {
        case LEFT:
            tank->position.deg -= 10;
            break;
        case RIGHT:
            tank->position.deg += 10;
            break;
        case UP:
            tank->position.y -= 2;
            tank->wantToMove -= 2;

            break;
        case DOWN:
            tank->position.y += 2;
            tank->wantToMove -= 2;
            break;        
        default:
            break;
        }
    }
    xpm_draw_tank_ignore_rot(tank_green, tank->position.x, tank->position.y, tank->position->deg, GREEN_SCREEN);  
}
