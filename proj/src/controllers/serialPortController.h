#ifndef __SERIAL_PORT__
#define __SERIAL_PORT__

#include "dev_interface/devices/serial_port.h"


typedef enum{
    INIT,
    WAITING,
    CONNECTED
}MSTATE;

int handleSPInterrupt();

#endif

