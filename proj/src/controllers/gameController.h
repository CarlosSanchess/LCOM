#ifndef __GAME_CONTROLLER  
#define __GAME_CONTROLLER 


#include "Models/arena.h"
#include "Models/state.h"
#include "Views/views.h"

void resetGame(Arena *arena);
int changeToMenu(State *gameState, Arena* arena);

#endif

