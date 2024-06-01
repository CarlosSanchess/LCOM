/**
 * @file video_gr.h
 * @brief Functions and definitions for video graphics mode.
 */

#ifndef VIDEO_GR_H_
#define VIDEO_GR_H_

#include <lcom/lcf.h>
#include "graphics_const.h"
#include "math.h"

#define GREEN_SCREEN 0x4ee44e /**< @brief Green screen color code */

vbe_mode_info_t vbe_mode_info;
unsigned char *video_mem;
static uint8_t *background_buffer;
static uint8_t *current_buffer;
static uint8_t *triple_buffer;
static uint32_t buffer_size;
static uint32_t vram_size;

/**
 * @brief Initializes the video mode.
 *
 * @param mode The video mode to set.
 * @return Returns 0 on success, 1 on failure.
 */
int (video_init)(uint16_t mode);

/**
 * @brief Draws a pixel at specified coordinates with a given color.
 *
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color of the pixel.
 * @param buffer The buffer to draw the pixel in.
 * @return Returns 0 on success.
 */
int (vg_draw_pixel)(uint16_t x, uint16_t y, uint32_t color, uint8_t *buffer);

/**
 * @brief Swaps the background and current buffers.
 */
void buffer_swap();

/**
 * @brief Copies the contents of the current buffer to the video memory.
 */
void (buffer_to_video_mem)();

/**
 * @brief Gets the screen width.
 *
 * @return The width of the screen.
 */
int get_width();

/**
 * @brief Gets the screen height.
 *
 * @return The height of the screen.
 */
int get_height();

/**
 * @brief Adjusts the color for direct color mode.
 *
 * @param color The original color.
 * @param new_color The adjusted color.
 * @return Returns 0 on success.
 */
uint32_t (complete_color_dir_mode)(uint32_t color, uint32_t *new_color);

/**
 * @brief Calculates the color for indexed mode.
 *
 * @param col The column index.
 * @param row The row index.
 * @param step The color step.
 * @param first The first color.
 * @param n The number of colors.
 * @return The calculated color.
 */
uint32_t (indexed_mode)(uint16_t col, uint16_t row, uint8_t step, uint32_t first, uint8_t n);

/**
 * @brief Calculates the color for direct color mode.
 *
 * @param red The red component.
 * @param green The green component.
 * @param blue The blue component.
 * @return The calculated color.
 */
uint32_t (direct_mode)(uint32_t red, uint32_t green, uint32_t blue);

/**
 * @brief Calculates the red component for direct color mode.
 *
 * @param first The first color.
 * @param col The column index.
 * @param step The color step.
 * @return The calculated red component.
 */
uint32_t (calculate_red)(uint32_t first, uint16_t col, uint8_t step);

/**
 * @brief Calculates the green component for direct color mode.
 *
 * @param first The first color.
 * @param row The row index.
 * @param step The color step.
 * @return The calculated green component.
 */
uint32_t (calculate_green)(uint32_t first, uint16_t row, uint8_t step);

/**
 * @brief Calculates the blue component for direct color mode.
 *
 * @param first The first color.
 * @param row The row index.
 * @param col The column index.
 * @param step The color step.
 * @return The calculated blue component.
 */
uint32_t (calculate_blue)(uint32_t first, uint16_t row, uint16_t col, uint8_t step);

/**
 * @brief Draws an XPM image as the background.
 *
 * @param xpm The XPM image to draw.
 * @param x The x-coordinate to start drawing.
 * @param y The y-coordinate to start drawing.
 * @return Returns 0 on success, 1 on failure.
 */
int (xpm_draw_Background)(xpm_map_t xpm, uint16_t x, uint16_t y);

/**
 * @brief Draws an XPM image.
 *
 * @param xpm The XPM image to draw.
 * @param x The x-coordinate to start drawing.
 * @param y The y-coordinate to start drawing.
 * @return Returns 0 on success, 1 on failure.
 */
int (xpm_draw)(xpm_map_t xpm, uint16_t x, uint16_t y);

/**
 * @brief Draws an XPM image ignoring a specified color.
 *
 * @param xpm The XPM image to draw.
 * @param x The x-coordinate to start drawing.
 * @param y The y-coordinate to start drawing.
 * @param ignoredColor The color to ignore.
 * @return Returns 0 on success, 1 on failure.
 */
int (xpm_draw_ignore)(xpm_map_t xpm, uint16_t x, uint16_t y, unsigned int ignoredColor);

/**
 * @brief Draws a rotated XPM image ignoring a specified color.
 *
 * @param xpm The XPM image to draw.
 * @param x The x-coordinate to start drawing.
 * @param y The y-coordinate to start drawing.
 * @param deg The degree of rotation.
 * @param ignoredColor The color to ignore.
 * @return Returns 0 on success, 1 on failure.
 */
int (xpm_draw_ignore_rot)(xpm_map_t xpm, uint16_t x, uint16_t y, uint16_t deg, unsigned int ignoredColor);

/**
 * @brief Draws an XPM image ignoring a specified color, with a specified block number.
 *
 * @param xpm The XPM image to draw.
 * @param x The x-coordinate to start drawing.
 * @param y The y-coordinate to start drawing.
 * @param ignoredColor The color to ignore.
 * @param number The block number.
 * @return Returns 0 on success, 1 on failure.
 */
int (xpm_draw_ignore_Block)(xpm_map_t xpm, uint16_t x, uint16_t y, unsigned int ignoredColor, int number);

/**
 * @brief Draws an XPM image ignoring a specified color, with an option to indicate build capability.
 *
 * @param xpm The XPM image to draw.
 * @param x The x-coordinate to start drawing.
 * @param y The y-coordinate to start drawing.
 * @param ignoredColor The color to ignore.
 * @param canBuild Indicates whether building is allowed.
 * @return Returns 0 on success, 1 on failure.
 */
int (xpm_draw_ignore_Hammer)(xpm_map_t xpm, uint16_t x, uint16_t y, unsigned int ignoredColor, bool canBuild);

/**
 * @brief Exits the graphics mode.
 *
 * @return Returns 0 on success, 1 on failure.
 */
int (vg_exit_graphics)();

/**
 * @brief Restores the video buffer.
 *
 * @return Returns 0 on success.
 */
int (restore_videoBuffer)();

#endif /* VIDEO_GR_H_ */
