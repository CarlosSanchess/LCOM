#include "arena.h"


Arena* createArena(int width, int height, MouseInfo *mouseInfo) {
    Arena *newArena = (Arena*)malloc(sizeof(Arena));
    if (newArena == NULL) {
        fprintf(stderr, "Failed to allocate memory for arena.\n");
        return NULL;
    }
    newArena->tank = createTank(10,10,0,1,2);


    newArena->width = width;
    newArena->height = height;
    return newArena;
}

void destroyArena(Arena *arena) {
    if (arena != NULL) {
        freeTank(arena->tank);
        free(arena);
    }
}

