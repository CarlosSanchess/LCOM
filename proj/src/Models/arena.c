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
    
    newArena->builts = create_obstacle_array();
    newArena->numBuilts = 0;

    Obstacle initialObstacles[NUM_OBSTACLES] = {
        {108, 320, 165, 227},
        {265, 320, 227, 345},
        {108, 320, 633, 694},
        {265, 320, 519, 633},
        {422, 634, 280, 342},
        {422, 478, 341, 460},
        {517, 727, 521, 581},
        {673, 727, 404, 521},
        {830, 1043, 166, 227},
        {830, 887, 227, 342},
        {830, 1042, 634, 694},
        {830, 887, 517, 634}
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

