#include "views.h"

int drawArena(Arena arena){
    drawBullets(arena);
    drawTank(arena.tank);
    drawEnemyTank(arena.enemyTank);
    drawBuilds(arena.builts, arena.numBuilts);

    return 0;
}

int drawTank(tank *tank) {
    xpm_draw_ignore_rot(tank_green, tank->position.x, tank->position.y, tank->position.deg, GREEN_SCREEN);
    return 0;
}

int drawEnemyTank(EnemyTank *tank) {
    xpm_draw_ignore_rot(tank_red, tank->position.x, tank->position.y, tank->position.deg, GREEN_SCREEN);
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
             if(xpm_draw_ignore(martelo, mouse.mousePosition.x, mouse.mousePosition.y, GREEN_SCREEN) != 0){
                return 1;
            }
        }
    }
    return 0;
}
int drawBullets(Arena arena){
    for(size_t i = 0; i < arena.numBullets; i++){
        drawBullet(*(arena.bullets[i]));
    }
    return 0;
}
int drawBullet(bullet b){
    xpm_draw_ignore_rot(bullet_xpm, b.position.x, b.position.y, b.position.deg, GREEN_SCREEN);
    return 0;
}

int drawBuilds(Obstacle** builds, size_t numBuilts){
    // for(size_t i = 0; i < numBuilts; i++){
        //xpm_draw_ignore(block,50, 50, GREEN_SCREEN);
    // }
    for(size_t i = 0; i < numBuilts; i++){ // TODO
        xpm_draw_ignore_Block(block, builds[i]->x1, builds[i]->y1, GREEN_SCREEN, builds[i]->time);
    }
    return 0;
}
