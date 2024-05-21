#ifndef MOUSE__H 
#define MOUSE__H
#include "i8042.h"

int (write_mouse)(uint8_t command_byte);
void (mouse_ih)();
void (mouse_packet)();
int (mouse_subscribe_int)(uint8_t *bit_no);
int (mouse_unsubscribe_int)();


#endif
