
#include "bulletController.h"

int addBulletToArena(Arena* arena){
    if(!arena) return 1;
    arena->bullets = (bullet**) realloc(arena->bullets, (arena->numBullets + 1) * sizeof(bullet*));
    if(!arena->bullets) return 1;

    double radians = (arena->tank->position.deg - 90) * (M_PI / 180.0);

    position pos = {arena->tank->position.x - 5 * cos(radians), arena->tank->position.y - 5 * sin(radians), arena->tank->position.deg};

    arena->bullets[arena->numBullets] = createBullet(pos, 5, PLAYER);
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
    while (i < arena->numBullets) {
        if (arena->bullets[i]->position.x < 0 || arena->bullets[i]->position.x > arena->width - ARENA_BORDER || arena->bullets[i]->position.y < 0 || arena->bullets[i]->position.y > arena->height - ARENA_BORDER) {
            arena->bullets = removeBulletFromBullets(arena->bullets, arena->numBullets, i);
            arena->numBullets--;
        } else {
            bulletMove(arena->bullets[i]);
            i++;
        }
    }
    return 0;
}
