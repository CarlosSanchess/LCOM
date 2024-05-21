#include "mouseController.h"

int handleInterruptMouse(State *gameState, Menu *menu){
    mouse_ih();
    mouse_packet();
    if(mouse_byte_packet.delta_x){
        menu -> selected = 0;
        if(mouse_byte_packet.lb){
            if(menu->selected == 0){
                *gameState = inGame;
            }
        }
    }
    return 0;
}
