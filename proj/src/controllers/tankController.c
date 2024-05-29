#include "Models/Tank.h"

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

bool canMove(int x, int y) {
    if ((x < 0 || x + TANK_WIDTH > MAP_WIDTH) || (y < 0 || y + TANK_HEIGHT > MAP_HEIGHT)) {
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
    int newX = tank->position.x + (int)(tank->speed * 6 * cos(radians));
    int newY = tank->position.y + (int)(tank->speed * 6 * sin(radians));

    if (canMove(newX, newY)) {
        tank->wantToMove = 6;
        tank->direction = DOWN;
        return 0;
    }
    return 1;
}

int moveUP(tank *tank) {
    double radians = (tank->position.deg - 90) * (M_PI / 180.0);
    int newX = tank->position.x - (int)(tank->speed * 6 * cos(radians));
    int newY = tank->position.y - (int)(tank->speed * 6 * sin(radians));

    if (canMove(newX, newY)) {
        tank->wantToMove = 6;
        tank->direction = UP;
        return 0;
    }
    return 1;
}

int moveRight(tank *tank) {
    tank->wantToRotate += 10;
    tank->direction = RIGHT;
    return 0;
}

int moveLeft(tank *tank) {
    tank->wantToRotate += 10;
    tank->direction = LEFT;
    return 0;
}

int processTank(tank* tank){
    int newY, newX;
    double radians;

    if(tank->wantToRotate >= 5){
        switch (tank->direction)
        {
         case LEFT:
            tank->position.deg -= 10;
            tank->wantToRotate -= 5;

            if (tank->position.deg < 0) {
                tank->position.deg += 360;
            }
            break;
        case RIGHT:
            tank->position.deg += 10;
            tank->wantToRotate -= 5;

            if (tank->position.deg >= 360) {
                tank->position.deg -= 360;
            }
            break;
        default:
            break;
        }
    }

    if(tank->wantToMove >= 2){
        radians = (tank->position.deg - 90) * (M_PI / 180.0);

        switch (tank->direction)
        {
         case UP:
            newX = tank->position.x - (int)(tank->speed * 2 * cos(radians));
            newY = tank->position.y - (int)(tank->speed * 2 * sin(radians));

            tank->position.x = newX;
            tank->position.y = newY;
            tank->wantToMove -= 2;
            break;
        case DOWN:

            newX = tank->position.x + (int)(tank->speed * 2 * cos(radians));
            newY = tank->position.y + (int)(tank->speed * 2 * sin(radians));

            tank->position.x = newX;
            tank->position.y = newY;
            tank->wantToMove -= 2;
            break;
        default:
            break;
        }
    }
    return 0;

}

