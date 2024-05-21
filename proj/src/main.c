#include <lcom/lcf.h>
#include "dev_interface/devices/video_gr.h"
#include "dev_interface/devices/timer_kbc_mouse/mouse.h"
#include"xpm/menu.xpm"
#include "dev_interface/sprites/sprite.h"


int test(){
  video_init(0x14C);

  xpm_draw(menu, 0, 0);

  buffer_to_video_mem();

  return 0;
}

int main(int argc, char *argv[]) {

  lcf_set_language("EN-US");
  if (lcf_start(argc, argv)) return 1;
  lcf_cleanup();

  return 0;
}

int(proj_main_loop)(int argc, char *argv[]) {
    

  test();  

  return 0;
}
