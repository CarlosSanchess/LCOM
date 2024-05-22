#include <lcom/lcf.h>

#include "sprite.h"

Sprite *create_sprite(char *pic[], char *base) {
    Sprite *sprite = (Sprite *)malloc(sizeof(Sprite));
    if (sprite == NULL) {
        return NULL; 
    }

    sprite->x = 0; 
    sprite->y = 0; 
    sprite->width = 0; 
    sprite->height = 0; 
    sprite->xspeed = 0; 
    sprite->yspeed = 0; 
    sprite->map = read_xpm(pic, &sprite->width, &sprite->height); 
    if (sprite->map == NULL) {
        free(sprite);
        return NULL; 
    }

    return sprite;
}

void destroy_sprite(Sprite *fig, char *base) {
    if (fig == NULL) {
        return;
    }
    if (fig->map != NULL) {
        free(fig->map); 
    }
    free(fig);
}

int draw_sprite(Sprite *fig, char *base) {
    if (fig == NULL || base == NULL) {
        return ERROR; 
    }

    for (int y = 0; y < fig->height; y++) {
        for (int x = 0; x < fig->width; x++) {
            int base_x = fig->x + x;
            int base_y = fig->y + y;
            
            if (base_x >= 0 && base_x < get_width() && base_y >= 0 && base_y < get_height()) {
                uint32_t color = fig->map[y * fig->width + x];
                
                vg_draw_pixel(base_x, base_y, color, current_buffer);
            }
        }
    }

    return OK;
}

char *read_xpm(char *map[], int *wd, int *ht)
{
    int width, height, colors;
    char sym[256];
    int  col;
    int i, j;
    char *pix, *pixtmp, *tmp, *line;
    char symbol;

    if (sscanf(map[0],"%d %d %d", &width, &height, &colors) != 3) {
        printf("read_xpm: incorrect width, height, colors\n");
        return NULL;
    }
    if (width > get_width() || height > get_height() || colors > 256) {
        printf("read_xpm: incorrect width, height, colors\n");
        return NULL;
    }

    *wd = width;
    *ht = height;

    for (i=0; i<256; i++)
        sym[i] = 0;

    for (i=0; i<colors; i++) {
        if (sscanf(map[i+1], "%c %d", &symbol, &col) != 2) {
            printf("read_xpm: incorrect symbol, color at line %d\n", i+1);
            return NULL;
        }
        if (col > 256) {
            printf("read_xpm: incorrect color at line %d\n", i+1);
            return NULL;
        }
        sym[col] = symbol;
    }
    
    pix = pixtmp = malloc(width*height);

    for (i=0; i<height; i++) {
        line = map[colors+1+i];
        for (j=0; j<width; j++) {
            tmp = memchr(sym, line[j], 256);  
            if (tmp == NULL) {
        	  printf("read_xpm: incorrect symbol at line %d, col %d\n", colors+i+1, j);
        	  return NULL;
            }
            *pixtmp++ = tmp - sym; 
        }
    }

    return pix;
}

int load_game_UI() {
    return OK;
}

int destroy_game_UI() {
    return OK;
}
