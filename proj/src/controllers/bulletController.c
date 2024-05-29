
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
int bulletMove(bullet* bullet){
    if(!bullet) return 1;
    double radians = (bullet->position.deg - 90) * (M_PI / 180.0);

    bullet->position.x -= bullet->speed * cos(radians);
    bullet->position.y -= bullet->speed * sin(radians);

    return 0;

}

int processBullets(Arena* arena){
    size_t aux = arena->numBullets;
    for(size_t i = 0; i < aux; i++){
        print_double(arena->bullets[i]->position.x);
        print_double(arena->bullets[i]->position.y);
        if(arena->bullets[i]->position.x < 0 || arena->bullets[i]->position.x > arena->width || arena->bullets[i]->position.y < 0 || arena->bullets[i]->position.y > arena->height){
            //arena->bullets = removeBulletFromBullets(arena->bullets, arena->numBullets, i);
            arena->numBullets--;
        }
        bulletMove(arena->bullets[i]);
    }
    return 0;
}
