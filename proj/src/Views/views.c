#include "views.h"

int drawArena(Arena arena){
    drawBullets(arena);
    drawTank(arena.tank);
    drawEnemyTank(arena.enemyTank);
    drawBuilds(arena.builts, arena.numBuilts);
    drawBomb(arena.bomba);

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


int drawMenu(Menu menu, HighScore score){
    drawHighScore(score); 
    if(menu.selected == 0){
        xpm_draw_ignore(granade, menu.coord[0][0], menu.coord[0][1], GREEN_SCREEN);  
    }
    if(menu.selected == 1){
        xpm_draw_ignore(granade, menu.coord[1][0], menu.coord[1][1], GREEN_SCREEN);  
    }
    if(menu.selected == 2){
        xpm_draw_ignore(granade, menu.coord[2][0], menu.coord[2][1], GREEN_SCREEN);  
    }
    return 0;
}
int drawMenuBackGround(){
    xpm_draw_Background(menuXPM, 0, 0);
    return 0;
}

int drawHighScore(HighScore score){
    if(score.score > 0){
      xpm_draw_ignore(highscore,730, 35, GREEN_SCREEN);
    }
    return 0;
}

int drawScore(HighScore score){
    
    char scoreString[20]; 
    sprintf(scoreString, "%d", score.score);

    int digitWidth = 20;

    int startX = 610;
    int startY = 275;

    for (size_t i = 0; i < strlen(scoreString); ++i) {
        int digit = scoreString[i] - '0';

        int xPos = startX + i * digitWidth;

        switch (digit) {
            case 0: xpm_draw_ignore(number0, xPos, startY, GREEN_SCREEN); break;
            case 1: xpm_draw_ignore(number1, xPos, startY, GREEN_SCREEN); break;
            case 2: xpm_draw_ignore(number2, xPos, startY, GREEN_SCREEN); break;
            case 3: xpm_draw_ignore(number3, xPos, startY, GREEN_SCREEN); break;
            case 4: xpm_draw_ignore(number4, xPos, startY, GREEN_SCREEN); break;
            case 5: xpm_draw_ignore(number5, xPos, startY, GREEN_SCREEN); break;
            case 6: xpm_draw_ignore(number6, xPos, startY, GREEN_SCREEN); break;
            case 7: xpm_draw_ignore(number7, xPos, startY, GREEN_SCREEN); break;
            case 8: xpm_draw_ignore(number8, xPos, startY, GREEN_SCREEN); break;
            case 9: xpm_draw_ignore(number9, xPos, startY, GREEN_SCREEN); break;
        }
    }

    return 0;
}

int drawChrono(HighScore score){
    
    char timeString[9]; 
    sprintf(timeString, "%02d%02d%02d", score.hours, score.minutes, score.seconds);

    // int digitWidth = 15;

    int startX[] = {498, 523, 600, 625, 704, 729};
    int startY[] = {379, 380, 383, 383, 383, 383};

    for (size_t i = 0; i < strlen(timeString); ++i) {
        int digit = timeString[i] - '0';
        
        int xPos = startX[i];
        int yPos = startY[i];

        switch (digit) {
            case 0: xpm_draw_ignore(number0, xPos, yPos, GREEN_SCREEN); break;
            case 1: xpm_draw_ignore(number1, xPos, yPos, GREEN_SCREEN); break;
            case 2: xpm_draw_ignore(number2, xPos, yPos, GREEN_SCREEN); break;
            case 3: xpm_draw_ignore(number3, xPos, yPos, GREEN_SCREEN); break;
            case 4: xpm_draw_ignore(number4, xPos, yPos, GREEN_SCREEN); break;
            case 5: xpm_draw_ignore(number5, xPos, yPos, GREEN_SCREEN); break;
            case 6: xpm_draw_ignore(number6, xPos, yPos, GREEN_SCREEN); break;
            case 7: xpm_draw_ignore(number7, xPos, yPos, GREEN_SCREEN); break;
            case 8: xpm_draw_ignore(number8, xPos, yPos, GREEN_SCREEN); break;
            case 9: xpm_draw_ignore(number9, xPos, yPos, GREEN_SCREEN); break;
        }
    }

    return 0;
}

int drawScoreBackGround(){
    xpm_draw_Background(scoreXPM, 0, 0);
    return 0;
}

int drawMouse(MouseInfo mouse){
    if((mouse.mousePosition.x > 0 && mouse.mousePosition.x < 1152) && (mouse.mousePosition.y > 0 && mouse.mousePosition.y < 864)){
        if(mouse.crossHair == 0){
            if(xpm_draw_ignore(cursor, mouse.mousePosition.x, mouse.mousePosition.y, GREEN_SCREEN) != 0){
                return 1;
            }
        }else{
             if(xpm_draw_ignore_Hammer(martelo, mouse.mousePosition.x, mouse.mousePosition.y, GREEN_SCREEN, mouse.canBuild) != 0){
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
    for(size_t i = 0; i < numBuilts; i++){ 
        if(builds[i]->draw && builds[i]->time == 10){xpm_draw_ignore(block10, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 9) {xpm_draw_ignore(block9, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 8) {xpm_draw_ignore(block8, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 7) {xpm_draw_ignore(block7, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 6) {xpm_draw_ignore(block6, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 5) {xpm_draw_ignore(block5, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 4) {xpm_draw_ignore(block4, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 3) {xpm_draw_ignore(block3, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 2) {xpm_draw_ignore(block2, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 1) {xpm_draw_ignore(block1, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}                
    }
    return 0;
}

int drawGameBackGround(){
    xpm_draw_Background(mapa, 0, 0);
    return 0;
}

int drawBomb(bomb bomb){
    if(bomb.active){
    xpm_draw_ignore(bomba, bomb.pos.x, bomb.pos.y, GREEN_SCREEN);        
    }
    return 0;
}



