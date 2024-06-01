#include "collisionController.h"

bool checkCollision(Hitbox a, Hitbox b) {
    if (a.origin == b.origin) {
        return false;
    }

    bool collisionX = (a.x1 < b.x2 && a.x2 > b.x1);
    bool collisionY = (a.y1 < b.y2 && a.y2 > b.y1);

    return collisionX && collisionY;
}

int processCollisions(Arena* arena,size_t index, Hitbox tankHB, Hitbox enemyTankHB,Hitbox bulletHB) {

    for (size_t j = 0; j < NUM_OBSTACLES; j++) {
        Obstacle *obstacle = &arena->obstacles[j];
        if (arena->bullets[index]->position.x >= obstacle->x1 - 10 &&  arena->bullets[index]->position.x <= obstacle->x2 + 5 &&
            arena->bullets[index]->position.y >= obstacle->y1 &&  arena->bullets[index]->position.y <= obstacle->y2) 
        {
            arena->bullets = removeBulletFromBullets(arena->bullets, arena->numBullets, index);
            arena->numBullets--;
            return 2;
        }
    }

    for(size_t k = 0; k < arena->numBuilts; k++){
        if (arena->bullets[index]->position.x >= arena->builts[k]->x1 &&  arena->bullets[index]->position.x <= arena->builts[k]->x2 &&
        arena->bullets[index]->position.y >= arena->builts[k]->y1 &&  arena->bullets[index]->position.y <= arena->builts[k]->y2){
            arena->bullets = removeBulletFromBullets(arena->bullets, arena->numBullets, index);
            arena->numBullets--;
            return 2;
        }
    }

    if (checkCollision(bulletHB, tankHB)) {
        arena->bullets = removeBulletFromBullets(arena->bullets, arena->numBullets, index);
        arena->numBullets--;
        arena->curr_score = 0;
        arena->bomba.pos.y = tankHB.y1;
        arena->bomba.pos.x = tankHB.x1;
        arena->bomba.active = true;
        return 2;
    }

    if (checkCollision(bulletHB, enemyTankHB)) {
        arena->bullets = removeBulletFromBullets(arena->bullets, arena->numBullets, index);
        arena->numBullets--;
        arena->curr_score++;
        arena->bomba.pos.y = enemyTankHB.y1;
        arena->bomba.pos.x = enemyTankHB.x1;

        arena->bomba.active = true;
        return 2;
    }
  
    return 0;
}

