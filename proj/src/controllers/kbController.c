#include "kbController.h"

extern uint8_t scanCode;

int handleInterruptKBC(State *gameState, Menu *menu) {
    kbc_ih(); 
    if (scanCode == BREAK_CODE(ESC_KEY)) {
        return 1;
    }
    if(scanCode == BREAK_CODE(S_KEY)){
        menu->selected = (menu->selected + 1) % 2;
    }
    if(scanCode == BREAK_CODE(W_KEY)){
        menu->selected = (menu->selected - 1) % 2;
    }
    
    if(scanCode == BREAK_CODE(ENTER_KEY)){
        if(!menu->selected){
            *gameState = inGame;
        }
    }
    return 0;
}
