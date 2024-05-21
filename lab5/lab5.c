// IMPORTANT: you must include the following line in all your C files
#include <lcom/lcf.h>

#include <lcom/lab5.h>

#include "video_gr.h"
#include "timer.c"
#include "kbc.c"

#include <stdint.h>
#include <stdio.h>

extern vbe_mode_info_t mode_info;
extern uint8_t scanCode;
extern unsigned int timer_counter;
// Any header files included below this line should have been created by you

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab5/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab5/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

int(video_test_init)(uint16_t mode, uint8_t delay) {
  if(video_init(mode) != OK){
    return 1;
  }

  sleep(delay);

  if(vg_exit_graphics() != OK){
    return 1;
  }
  return 0;
}

int(video_test_rectangle)(uint16_t mode, uint16_t x, uint16_t y,
                          uint16_t width, uint16_t height, uint32_t color) {
  
  if(video_init(mode) != OK){
    return 1;
  }
  
  if(video_init(mode) != OK){
    return 1;
  }

  uint32_t new_color;
  if(complete_color_dir_mode(color,&new_color) != OK){
    return 1;
  }
  
  if(vg_draw_rectangle(x,y,width,height,new_color) != OK){
    return 1;
  }
  buffer_to_video_mem();
  if(waiting_ESC_key() != 0){
    return 1;
  }
  if(vg_exit_graphics() != OK){
    return 1;
  }
  return 0;
}

int(video_test_pattern)(uint16_t mode, uint8_t no_rectangles, uint32_t first, uint8_t step) {

  if (video_init(mode) != 0) return 1;

  int vertical = vbe_mode_info.YResolution / no_rectangles;
  int horizontal = vbe_mode_info.XResolution / no_rectangles;

  for (int i = 0 ; i < no_rectangles ; i++) {
    for (int j = 0 ; j < no_rectangles ; j++) {

      uint32_t color;

      if (vbe_mode_info.MemoryModel == 0x06) {
        uint32_t R = calculate_red(j, step, first);
        uint32_t G = calculate_green(i, step, first);
        uint32_t B = calculate_blue(j, i, step, first);
        color = direct_mode(R, G, B);

      } else {
        color = indexed_mode(j, i, step, first, no_rectangles);
      }

      if (vg_draw_rectangle(j * horizontal, i * vertical, horizontal, vertical, color)) return 1;
      buffer_to_video_mem();
    }
  }
  
  if (waiting_ESC_key()) return 1;

  if (vg_exit_graphics() != 0) return 1;

  return 0;
}


int(video_test_xpm)(xpm_map_t xpm, uint16_t x, uint16_t y) {
  if(video_init(0x105) != OK){
    return 1;
  }
  if(xpm_draw(xpm,x,y) != OK){
    return 1;
  }
  buffer_to_video_mem();
  if(waiting_ESC_key() != 0){
    return 1;
  }
  if(vg_exit_graphics() != OK){
    return 1;
  }
  return 0;
}

int(video_test_move)(xpm_map_t xpm, uint16_t xi, uint16_t yi, uint16_t xf, uint16_t yf,
                     int16_t speed, uint8_t fr_rate) {
  /* To be completed */
  printf("%s(): under construction\n", __func__);

  return 1;
}

int(video_test_controller)() {
  /* To be completed */
  printf("%s(): under construction\n", __func__);

  return 1;
}
