#ifndef _LCOM_GRAPHICS_CONST_H_
#define _LCOM_GRAPHICS_CONST_H_

#include <lcom/lcf.h>
#include "video_gr.h"

/** @defgroup i8254 i8254
 * @{
 *
 * Constants for programming the graphics card.
 */

#define ERROR 1

#define VBE_MODE 0x4F02
#define VBE_LINEAR_FRAMEBUFFER BIT(14)
#define BIOS_VIDEO_SERVICES 0x10
#define INDEXED_COLOR_MODE 0x105
#define DIRECT_COLOR_MODE 0x06

#define R(color) ((color >> vbe_mode_info.RedFieldPosition) & ((1 << vbe_mode_info.RedMaskSize) - 1))
#define G(color) ((color >> vbe_mode_info.GreenFieldPosition) & ((1 << vbe_mode_info.GreenMaskSize) - 1))
#define B(color) ((color >> vbe_mode_info.BlueFieldPosition) & ((1 << vbe_mode_info.BlueMaskSize) - 1))

#endif /* _LCOM_GRAPHICS_CONST_H_*/
