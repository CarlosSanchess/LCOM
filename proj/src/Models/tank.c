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
    newTank->direction = 0;
    return newTank;
}

void freeTank(tank *tank) {
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

int moveDown(tank *tank) {
    double radians = (tank->position.deg - 90) * (M_PI / 180.0);
    int newX = tank->position.x + (int)(tank->speed * 5 * cos(radians));
    int newY = tank->position.y + (int)(tank->speed * 5 * sin(radians));

    if (canMove(newX, newY)) {
        tank->position.x = newX;
        tank->position.y = newY;
        tank->direction = UP;
        return 0;
    }
    return 1;
}

int moveUP(tank *tank) {
    double radians = (tank->position.deg - 90) * (M_PI / 180.0);
    int newX = tank->position.x - (int)(tank->speed * 5 * cos(radians));
    int newY = tank->position.y - (int)(tank->speed * 5 * sin(radians));

    if (canMove(newX, newY)) {
        tank->position.x = newX;
        tank->position.y = newY;
        tank->direction = DOWN;
        return 0;
    }
    return 1;
}

int moveRight(tank *tank) {
    tank->position.deg += 10;
    if (tank->position.deg >= 360) {
        tank->position.deg -= 360;
    }
    tank->direction = RIGHT;
    return 0;
}

int moveLeft(tank *tank) {
    tank->position.deg -= 10;
    if (tank->position.deg < 0) {
        tank->position.deg += 360;
    }
    tank->direction = LEFT;
    return 0;
}

void drawTank(tank *tank) {
    xpm_draw_tank_ignore_rot(tank_green, tank->position.x, tank->position.y, tank->position.deg, GREEN_SCREEN);
}
