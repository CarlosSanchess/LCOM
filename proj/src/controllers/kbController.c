#include "kbController.h"
extern uint8_t scanCode;

int handleInterruptKBC(State *gameState, Menu *menuInfo, Arena *arena){
    kbc_ih(); 
    if (scanCode == BREAK_CODE(ESC_KEY)) {
        if (*gameState == inGame) {
            *gameState = inMenu;
            resetGame(arena);
            drawMenuBackGround();
            return 0;
        } else if (*gameState == inMenu) {
            return 1;
        }
    }
    if(*gameState == inMenu){
        if(handleMenu(gameState, menuInfo, arena)){
        return 1;
        }
    }
    if(*gameState == inGame){
        handleTank(arena);
        handleArena(arena);
    }
    return 0;
}

int handleArena(Arena* arena){
    if(scanCode == BREAK_CODE(SPACE_KEY) && arena->tank->canShoot){
        if(addBulletToArena(arena,GREEN_TANK) != 0 ){return 1;}
        arena->tank->canShoot = false;
    }
    return 0;
}
int handleTank(Arena* arena){
    if(scanCode == BREAK_CODE(W_KEY)){
        moveUP(arena->tank,arena->obstacles, NUM_OBSTACLES, arena->builts, arena->numBuilts);
    }
    if(scanCode == BREAK_CODE(A_KEY)){
        moveLeft(arena->tank);
    }
    if(scanCode == BREAK_CODE(S_KEY)){
        moveDown(arena->tank,arena->obstacles, NUM_OBSTACLES, arena->builts, arena->numBuilts);
    }
    if(scanCode == BREAK_CODE(D_KEY)){
        moveRight(arena->tank);
    }
    return 0;
}
int handleMenu(State *gameState ,Menu *menu, Arena* arena){
    if(scanCode == BREAK_CODE(S_KEY)){
        menu->selected = ((menu->selected + 1) % 2);
    }
    if(scanCode == BREAK_CODE(W_KEY)){
        menu->selected = ((menu->selected + 1) % 2);
    }
    
    if(scanCode == BREAK_CODE(ENTER_KEY)){
        if(!menu->selected){
            *gameState = inGame;
            arena->crosshair->crossHair = 1;
        }
        if(menu->selected){
            return 1;
        }
    }
    return 0;
}
