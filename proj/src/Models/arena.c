#include "arena.h"


Arena* createArena(int width, int height, MouseInfo *mouseInfo) {
    Arena *newArena = (Arena*)malloc(sizeof(Arena));
    if (newArena == NULL) {
        fprintf(stderr, "Failed to allocate memory for arena.\n");
        return NULL;
    }

    newArena->tank = createTank(10, 10, 0, 1, 3);
    newArena->enemyTank = createEnemyTank(100, 100, 0, 1, 3);
    newArena->crosshair = mouseInfo;
    newArena->width = width;
    newArena->height = height;

    
    Obstacle initialObstacles[NUM_OBSTACLES] = {
        {108, 320, 165, 227, -1},
        {265, 320, 227, 345, -1},
        {108, 320, 633, 694, -1},
        {265, 320, 519, 633, -1},
        {422, 634, 280, 342, -1},
        {422, 478, 341, 460, -1},
        {517, 727, 521, 581, -1},
        {673, 727, 404, 521, -1},
        {830, 1043, 166, 227, -1},
        {830, 887, 227, 342, -1},
        {830, 1042, 634, 694, -1},
        {830, 887, 517, 634, -1}
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

