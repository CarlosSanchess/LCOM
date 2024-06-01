/**
 * @file graphics_const.h
 * @brief Constants and macros for programming the graphics card.
 */

#ifndef _LCOM_GRAPHICS_CONST_H_
#define _LCOM_GRAPHICS_CONST_H_

#include <lcom/lcf.h>
#include "video_gr.h"

#define ERROR 1 /**< @brief Error code value */

#define VBE_MODE 0x4F02 /**< @brief VBE mode set function */
#define VBE_LINEAR_FRAMEBUFFER BIT(14) /**< @brief Linear framebuffer bit */
#define BIOS_VIDEO_SERVICES 0x10 /**< @brief BIOS video services interrupt */
#define INDEXED_COLOR_MODE 0x105 /**< @brief Indexed color mode */
#define DIRECT_COLOR_MODE 0x06 /**< @brief Direct color mode */

/**
 * @brief Extracts the red component from a color.
 * @param color The color value.
 * @return The red component.
 */
#define R(color) ((color >> vbe_mode_info.RedFieldPosition) & ((1 << vbe_mode_info.RedMaskSize) - 1))

/**
 * @brief Extracts the green component from a color.
 * @param color The color value.
 * @return The green component.
 */
#define G(color) ((color >> vbe_mode_info.GreenFieldPosition) & ((1 << vbe_mode_info.GreenMaskSize) - 1))

/**
 * @brief Extracts the blue component from a color.
 * @param color The color value.
 * @return The blue component.
 */
#define B(color) ((color >> vbe_mode_info.BlueFieldPosition) & ((1 << vbe_mode_info.BlueMaskSize) - 1))

#endif /* _LCOM_GRAPHICS_CONST_H_ */
