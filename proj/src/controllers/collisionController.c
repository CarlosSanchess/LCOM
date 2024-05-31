#include "collisionController.h"

bool checkCollision(Hitbox a, Hitbox b) {
    return (a->x < b->x + b->width && a->x + a->width > b->x &&
            a->y < b->y + b->height && a->y + a->height > b->y);
}

void processCollisions(bullet *bullet, Hitbox tankHB, Hitbox enemyTankHB,Hitbox bulletHB) {
   
    createBulletHitbox(bullet, &bulletHB);

    if (checkCollision(bulletHB, tankHB)) {
        arena->bullets = removeBulletFromBullets(arena->bullets, arena->numBullets, i);
        arena->numBullets--;
        continue;
    }

    if (checkCollision(bulletHB, enemyTankHB)) {
        arena->bullets = removeBulletFromBullets(arena->bullets, arena->numBullets, i);
        arena->numBullets--;
        continue;
    }
}