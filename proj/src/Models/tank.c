#include "Tank.h"

Obstacle obstacles[NUM_OBSTACLES] = {
    {108, 320, 165, 227},
    {265, 320, 227, 345},
    {108, 320, 633, 694},
    {265, 320, 519, 633},
    {422, 634, 280, 342},
    {422, 478, 341, 460},
    {517, 727, 521, 581},
    {673, 727, 404, 521},
    {830, 1043, 166, 227},
    {830, 887, 227, 342},
    {830, 1042, 634, 694},
    {830, 887, 517, 634}
};

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
    newTank->wantToMove = 0;
    newTank->direction = 0;
    return newTank;
}

void freeTank(tank *tank) {
    if (tank != NULL) {
        free(tank);
    }
}

void destroyTank(tank *tank) {
    if (tank != NULL) {
        free(tank);
    }
}

bool canMove(int x, int y) {
    if ((x < 0 || x + TANK_WIDTH > 1000) || (y < 0 || y + TANK_HEIGHT > 1000)) {
        return false;
    }

    for (int i = 0; i < NUM_OBSTACLES; i++) {
        if ((x < obstacles[i].x2 && x + TANK_WIDTH > obstacles[i].x1) &&
            (y < obstacles[i].y2 && y + TANK_HEIGHT > obstacles[i].y1)) {
            return false;
        }
    }

    return true;
}

int moveUP(tank *tank) {
    int newY = tank->position.y - tank->speed * 5;
    if (canMove(tank->position.x, newY)) {
        tank->position.y = newY;
        return 0;
    }
    return 1;
}

int moveDown(tank *tank) {
    int newY = tank->position.y + tank->speed * 5;
    if (canMove(tank->position.x, newY)) {
        tank->position.y = newY;
        return 0;
    }
    return 1;
}

int moveLeft(tank *tank) {
    int newX = tank->position.x - tank->speed * 5;
    if (canMove(newX, tank->position.y)) {
        tank->position.x = newX;
        return 0;
    }
    return 1;
}

int moveRight(tank *tank) {
    int newX = tank->position.x + tank->speed * 5;
    if (canMove(newX, tank->position.y)) {
        tank->position.x = newX;
        return 0;
    }
    return 1;
}

void drawTank(tank *tank) {
    if (tank->wantToMove > 2) {
        tank->wantToMove -= 2;
        tank->position.y += 2;
    }
    xpm_draw_ignore(tank_green, tank->position.x, tank->position.y, GREEN_SCREEN);
}
