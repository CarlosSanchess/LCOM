#include "bulletController.h"

int addBulletToArena(Arena* arena){
    if(!arena) return 1;

    arena->bullets = (bullet**) realloc(arena->bullets, (arena->numBullets + 1) * sizeof(bullet*));
    if(!arena->bullets) return 1;

    position pos = {arena->tank->position.x + 10, arena->tank->position.y + 10, arena->tank->position.deg};

    arena->bullets[arena->numBullets] = createBullet(pos, 5, PLAYER);
    arena->numBullets++;

    return 0;
}

int processBullets(){

    return 0;
}

