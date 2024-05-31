#include "bullet.h"


bullet* createBullet(position pos, int speed, uint8_t origin){
    bullet* b = (bullet*) malloc(sizeof(bullet));
    b->position = pos;
    b->speed = speed;
    b->origin = origin;
    return b;
}
bullet** removeBulletFromBullets(bullet** bullets, size_t numBullets, size_t index) {
    if (numBullets == 0 || index >= numBullets) {
        return bullets; 
    }

    bullet** temp = (bullet**)malloc((numBullets - 1) * sizeof(bullet*));
    if (!temp) {
        return NULL; 
    }

    if (index > 0) {
        memcpy(temp, bullets, index * sizeof(bullet*));
    }
    if (index < numBullets - 1) {
        memcpy(temp + index, bullets + index + 1, (numBullets - index - 1) * sizeof(bullet*));
    }

    free(bullets[index]); 
    free(bullets); 

    return temp; 
}

void freebullet(bullet* b){
    if(!b) return;
    free(b);
    b = NULL;
}


void createBulletHitbox(bullet* b, Hitbox* Hitbox){
    Hitbox->x1 = b->position.x;
    Hitbox->y1 = b->position.y;
    Hitbox->x2 = BULLET_WIDTH;
    Hitbox->y2 = BULLET_HEIGHT;
}