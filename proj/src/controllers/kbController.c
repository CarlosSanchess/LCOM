#include "kbController.h"

extern uint8_t scanCode;

int handleInterruptKBC(state gameState) {
    kbc_ih(); 
    if (scanCode == BREAK_CODE(A_KEY)) {
        return 0;
    }
    return 1;
}
