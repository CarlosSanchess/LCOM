#include "arena.h"


Arena* createArena(int width, int height, MouseInfo *mouseInfo) {
    Arena *newArena = (Arena*)malloc(sizeof(Arena));
    if (newArena == NULL) {
        fprintf(stderr, "Failed to allocate memory for arena.\n");
        return NULL;
    }

    newArena->tank = createTank(145, 410, 0, 1, 3);
    newArena->enemyTank = createEnemyTank(970, 410, 0, 1, 3);
    newArena->crosshair = mouseInfo;
    newArena->width = width;
    newArena->height = height;
    newArena->curr_score = 0;
    newArena->endGame = false;
    newArena->bomba = (bomb){{-1, -1, 0}, false};

    
    Obstacle initialObstacles[NUM_OBSTACLES] = {
        {108, 320, 165, 227, -1, false},
        {265, 320, 227, 345, -1, false},
        {108, 320, 633, 694, -1, false},
        {265, 320, 519, 633, -1, false},
        {422, 634, 280, 342, -1, false},
        {422, 478, 341, 460, -1, false},
        {517, 727, 521, 581, -1, false},
        {673, 727, 404, 521, -1, false},
        {830, 1043, 166, 227, -1, false},
        {830, 887, 227, 342, -1, false},
        {830, 1042, 634, 694, -1, false},
        {830, 887, 517, 634, -1, false}
    };
    memcpy(newArena->obstacles, initialObstacles, sizeof(initialObstacles));

    if (!newArena->tank || !newArena->enemyTank) {
        destroyArena(newArena);
        return NULL;
    }

    return newArena;
}

void destroyArena(Arena *arena) {
    if (arena != NULL) {
        freeTank(arena->tank);
        free(arena);
    }
}

