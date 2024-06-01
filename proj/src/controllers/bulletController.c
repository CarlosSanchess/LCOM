
#include "bulletController.h"

int addBulletToArena(Arena *arena, int tankColor){
    if(!arena) return 1;
    arena->bullets = (bullet**) realloc(arena->bullets, (arena->numBullets + 1) * sizeof(bullet*));
    if(!arena->bullets) return 1;

    double radians;
    position pos;

    if (tankColor == GREEN_TANK) {
        radians = (arena->tank->position.deg - 90) * (M_PI / 180.0);
        pos.x = arena->tank->position.x - 5 * cos(radians);
        pos.y = arena->tank->position.y - 5 * sin(radians);
        pos.deg = arena->tank->position.deg;
        arena->bullets[arena->numBullets] = createBullet(pos, 5, PLAYER);
    } else if (tankColor == RED_TANK) {
        radians = (arena->enemyTank->position.deg - 90) * (M_PI / 180.0);
        pos.x = arena->enemyTank->position.x - 5 * cos(radians);
        pos.y = arena->enemyTank->position.y - 5 * sin(radians);
        pos.deg = arena->enemyTank->position.deg;
        arena->bullets[arena->numBullets] = createBullet(pos, 5, ENEMY);
    }
    arena->numBullets++;

    return 0;
}

int bulletMove(bullet* bullet){
    if(!bullet) return 1;
    double radians = (bullet->position.deg - 90) * (M_PI / 180.0);

    bullet->position.x -= (bullet->speed * cos(radians));
    bullet->position.y -= (bullet->speed * sin(radians));

    return 0;

}

int processBullets(Arena* arena) {
    size_t i = 0;
    Hitbox bulletHB, tankHB, enemyTankHB; 



    while (i < arena->numBullets) {

        bullet *bullet = arena->bullets[i];
        createBulletHitbox(bullet,&bulletHB);
        getTankHitBox(arena->tank, &tankHB);
        getEnemyTankHitBox(arena->enemyTank, &enemyTankHB);

        if (arena->bullets[i]->position.x < 0 || arena->bullets[i]->position.x > arena->width - ARENA_BORDER || arena->bullets[i]->position.y < 0 || arena->bullets[i]->position.y > arena->height - ARENA_BORDER){
            arena->bullets = removeBulletFromBullets(arena->bullets, arena->numBullets, i);
            arena->numBullets--;
            continue;
        }

        if (processCollisions(arena, i, tankHB, enemyTankHB, bulletHB) != 2) {
            bulletMove(bullet);
            i++;
        }
    }

    return 0;
}
