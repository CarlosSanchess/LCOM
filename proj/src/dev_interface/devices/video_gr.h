#ifndef VIDEO_GR_H_
#define VIDEO_GR_H_

#include <lcom/lcf.h>
#include "graphics_const.h"

vbe_mode_info_t vbe_mode_info;
unsigned char *video_mem;
static uint8_t *background_buffer;
static uint8_t *current_buffer;
static uint32_t buffer_size = 0;

int (video_init)(uint16_t mode);
int (vg_draw_pixel)(uint16_t x, uint16_t y, uint32_t color);
void buffer_swap();
void (buffer_to_video_mem)();
int get_width();
int get_height();
int (vg_draw_rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);
uint32_t (complete_color_dir_mode)(uint32_t color, uint32_t *new_color);
uint32_t (indexed_mode)(uint16_t col, uint16_t row, uint8_t step, uint32_t first, uint8_t n);
uint32_t (direct_mode)(uint32_t red, uint32_t green, uint32_t blueS);
uint32_t (calculate_red)(uint32_t first, uint16_t col, uint8_t step);
uint32_t (calculate_green)(uint32_t first, uint16_t row, uint8_t step);
uint32_t (calculate_blue)(uint32_t first, uint16_t row, uint16_t col, uint8_t step);
int (xpm_draw_loaded)(uint8_t * pixmap, xpm_image_t img, uint16_t x, uint16_t y);
int (xpm_draw)(xpm_map_t xpm, uint16_t x, uint16_t y);
int (vg_exit_graphics)();

#endif /* VIDEO_GR_H_ */
