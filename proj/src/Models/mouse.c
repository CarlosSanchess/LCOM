#include "mouse.h"

int drawMouse(MouseInfo mouse){
    if(mouse.mousePosition.x != -1 && mouse.mousePosition.y != -1){
        if(xpm_draw_ignore(cursor, mouse.mousePosition.x, mouse.mousePosition.y, GREEN_SCREEN) != 0){
            return 1;
        }
    }
    return 0;
}
