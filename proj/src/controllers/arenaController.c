#include "arenaController.h"

int processArena(Arena* arena) {
    if (processTank(arena->tank,arena->obstacles,NUM_OBSTACLES) != 0) {
        return 1;
    }
    moveEnemyTank(arena->enemyTank, arena->tank, arena->obstacles, NUM_OBSTACLES);
    if (processEnemyTank(arena->enemyTank,arena->obstacles,NUM_OBSTACLES,arena) != 0) {
        return 1;
    }
    return 0;
}
