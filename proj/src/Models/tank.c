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
    
    newTank->canShoot = true;
    
    newTank->direction = 0;
    return newTank;
}

void freeTank(tank *tank) {
    if (tank != NULL) {
        free(tank);
    }
}

EnemyTank* createEnemyTank(int x, int y, uint16_t deg, int hp, int speed) {
    EnemyTank *newEnemyTank = (EnemyTank*)malloc(sizeof(EnemyTank));
    if (newEnemyTank == NULL) {
        fprintf(stderr, "Failed to allocate memory for enemy tank.\n");
        return NULL;
    }
    newEnemyTank->position.x = x;
    newEnemyTank->position.y = y;
    newEnemyTank->position.deg = deg;
    newEnemyTank->speed = speed;
    newEnemyTank->direction = 0;
    newEnemyTank->currentWaypoint = 0;
    newEnemyTank->followingPlayer = false;
    newEnemyTank->canShoot = true;
    return newEnemyTank;
}


void freeEnemyTank(EnemyTank *enemyTank) {
    if (enemyTank != NULL) {
        free(enemyTank);
    }
}

void getTankHitBox(tank* tank, Hitbox *hitbox){

   hitbox->x1 = tank->position.x - TANK_WIDTH / 2;
   hitbox->x2 = tank->position.x + TANK_WIDTH / 2;
   hitbox->y1 = tank->position.y - TANK_HEIGHT / 2;
   hitbox->y2 = tank->position.y + TANK_HEIGHT / 2;
   hitbox->origin = PLAYER;
}

void getEnemyTankHitBox(EnemyTank* tank, Hitbox *hitbox){

   hitbox->x1 = tank->position.x - TANK_WIDTH / 2;
   hitbox->x2 = tank->position.x + TANK_WIDTH / 2;
   hitbox->y1 = tank->position.y - TANK_HEIGHT / 2;
   hitbox->y2 = tank->position.y + TANK_HEIGHT / 2;
   hitbox->origin = ENEMY;
}

