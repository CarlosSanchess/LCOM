#include <lcom/lcf.h>
#include "video_gr.h"

// vg_exit() sai do graphics mode
        
int (video_init)(uint16_t mode){

    reg86_t reg86;

    uint8_t *reg_ptr = (uint8_t *)&reg86; // apontador para o início da struct
    for (size_t i = 0; i < sizeof(reg86); ++i) {
      *(reg_ptr + i) = 0;
    }
    
    uint8_t *ptr = (uint8_t *)&vbe_mode_info; // Pointer to the start of the struct
    for (size_t i = 0; i < sizeof(vbe_mode_info); ++i) {
        *(ptr + i) = 0;
    }

    if(vbe_get_mode_info(mode, &vbe_mode_info) != OK){
        fprintf(stderr,"vbe_get_mode_info() failed \n");
        return ERROR;
    }

    struct minix_mem_range mr;
    unsigned int vram_base = vbe_mode_info.PhysBasePtr;  
    unsigned int bits_per_pixel = vbe_mode_info.BitsPerPixel;
    unsigned int bytes_per_pixel = (bits_per_pixel + 7) >> 3; // mudar para >>arredonda para o bit mais próximo
    unsigned int vram_size = vbe_mode_info.XResolution * vbe_mode_info.YResolution * bytes_per_pixel;
    buffer_size = vram_size;
    int r;

    mr.mr_base = (phys_bytes) vram_base;  
    mr.mr_limit = mr.mr_base + vram_size;  

    if( OK != (r = sys_privctl(SELF, SYS_PRIV_ADD_MEM, &mr))){
        fprintf(stderr,"sys_privctl (ADD_MEM) failed: %d\n", r);
        return ERROR;
    }

    video_mem = vm_map_phys(SELF, (void *)mr.mr_base, vram_size);

    if(video_mem == MAP_FAILED){
        fprintf(stderr,"couldn't map video memory");
        return ERROR;
    }

    reg86.ax = VBE_MODE;
    reg86.bx = VBE_LINEAR_FRAMEBUFFER | mode; 
    reg86.intno = BIOS_VIDEO_SERVICES;
    if(sys_int86(&reg86) != OK ) {
      fprintf(stderr,"sys_int86() failed \n");
      return ERROR;
    }

    background_buffer = malloc(vram_size);
    current_buffer = malloc(vram_size);
    if (background_buffer == NULL | current_buffer == NULL) {
        return ERROR;
    }

    return OK;
}

int get_width() {
    return vbe_mode_info.XResolution;
}

int get_height() {
    return vbe_mode_info.YResolution;
}

int (vg_draw_pixel)(uint16_t x, uint16_t y, uint32_t color) {
    uintptr_t pixel_address = (uintptr_t)current_buffer + (y * get_width() + x) * ((vbe_mode_info.BitsPerPixel + 7) >> 3);
    *((uint32_t *)pixel_address) = color;
    return OK;
}

void (buffer_to_video_mem)() {
    memcpy(video_mem, current_buffer, vbe_mode_info.XResolution * vbe_mode_info.YResolution * ((vbe_mode_info.BitsPerPixel + 7) >> 3));
}

void buffer_swap() {
    uint8_t *temp = background_buffer;
    background_buffer = current_buffer;
    current_buffer = temp;
}

int (vg_draw_rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color) {
    for (unsigned i = 0; i < height; ++i) {
        for (unsigned j = 0; j < width; ++j) {
            vg_draw_pixel(x + j, y + i, color);
        }
    }
    return OK;
}

int (vg_exit_graphics)(){
  free(current_buffer);
  free(background_buffer);
  if(vg_exit() != OK){
    return ERROR;
  };
  return OK;
}


uint32_t (complete_color_dir_mode)(uint32_t color, uint32_t *new_color) {
  switch(vbe_mode_info.ModeAttributes) {
    case 0x105: // 1024x768 Indexed 8
      if (color > 255) {
        return ERROR; // return error if color is larger than 255
      }
      *new_color = color;
      break;
    case 0x110: // 640x480 Direct color 15 (1:5:5:5)
      *new_color = color & 0x7FFF; // consider only the 15 least significant bits
      break;
    case 0x115: // 800x600 Direct color 24 (8:8:8)
      *new_color = color & 0xFFFFFF; // consider only the 24 least significant bits
      break;
    case 0x11A: // 1280x1024 Direct color 16 (5:6:5)
      *new_color = color & 0xFFFF; // consider only the 16 least significant bits
      break;
    case 0x14C: // 1152x864 Direct color 32 (8:8:8:8)
      *new_color = color; // all bits are considered
      break;
    default:
    {
        uint32_t mask = 0xFFFFFFFF; // Initialize mask with all bits set to 1
        
        mask >>= (32 - vbe_mode_info.BitsPerPixel);
        
        *new_color = color & mask;
    }
      break;
  }
  return 0;
}

uint32_t (indexed_mode)(uint16_t col, uint16_t row, uint8_t step, uint32_t first, uint8_t n){
  return (first + (row * n + col) * step) % (1 << vbe_mode_info.BitsPerPixel);
}

uint32_t (direct_mode)(uint32_t red, uint32_t green, uint32_t blue) {
    return (red << vbe_mode_info.RedMaskSize) |
           (green << vbe_mode_info.GreenMaskSize) |
           (blue << vbe_mode_info.BlueMaskSize);
}

uint32_t (calculate_red)(uint32_t first, uint16_t col, uint8_t step) {
  return (R(first) + col * step) % (1 << vbe_mode_info.RedMaskSize);
}

uint32_t (calculate_green)(uint32_t first, uint16_t row, uint8_t step) {
  return (G(first) + row * step) % (1 << vbe_mode_info.GreenMaskSize);
}

uint32_t (calculate_blue)(uint32_t first, uint16_t row, uint16_t col, uint8_t step) {
  return (B(first) + (col + row) * step) % (1 << vbe_mode_info.BlueMaskSize);
}

int (xpm_draw)(xpm_map_t xpm, uint16_t x, uint16_t y) {
  xpm_image_t img;
  if (xpm_load(xpm, XPM_INDEXED, &img) == NULL) {
    return ERROR;
  }
  return xpm_draw_loaded(img, x, y);
}

int (xpm_draw_loaded)(xpm_image_t img, uint16_t x, uint16_t y) {
  for (unsigned i = 0; i < img.height; ++i) {
    for (unsigned j = 0; j < img.width; ++j) {
      uint32_t color;
      if (complete_color_dir_mode(img.bytes[i * img.width + j], &color) != OK) {
        return ERROR;
      }
      vg_draw_pixel(x + j, y + i, color);
    }
  }
  return OK;
}

int is_direct_color() {
  return vbe_mode_info.MemoryModel == 0x06;
}

int is_indexed_color() {
  return vbe_mode_info.MemoryModel == 0x04;
}

int is_text_mode() {
  return vbe_mode_info.MemoryModel == 0x07;
}
