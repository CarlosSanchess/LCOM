#include "arenaController.h"

int processArena(Arena* arena){
    if(processTank(arena->tank) != 0){return 1;} //Process the move of it 
    if(processBullets(arena)){return 1;}

    return 0;
}
