#include "views.h"

int drawArena(Arena arena){
    drawTank(arena.tank);

    return 0;
}

int drawTank(tank *tank) {
    xpm_draw_tank_ignore_rot(tank_green, tank->position.x, tank->position.y, tank->position.deg, GREEN_SCREEN);
    return 0;
}

int drawMenu(Menu menu){ 
    if(menu.selected == 0){
        xpm_draw_ignore(granade, menu.coord[0][0], menu.coord[0][1], GREEN_SCREEN);  
    }
    if(menu.selected == 1){
        xpm_draw_ignore(granade, menu.coord[1][0], menu.coord[1][1], GREEN_SCREEN);  
    }
    return 0;
}

int drawMouse(MouseInfo mouse){
    if((mouse.mousePosition.x > 0 && mouse.mousePosition.x < 1152) && (mouse.mousePosition.y > 0 && mouse.mousePosition.y < 864)){
        if(mouse.crossHair == 0){
            if(xpm_draw_ignore(cursor, mouse.mousePosition.x, mouse.mousePosition.y, GREEN_SCREEN) != 0){
                return 1;
            }
        }else{
             if(xpm_draw_ignore(crosshair, mouse.mousePosition.x, mouse.mousePosition.y, GREEN_SCREEN) != 0){
                return 1;
            }
        }
    }
    return 0;
}
