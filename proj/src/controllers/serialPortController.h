/**
 * @file serialPortController.h
 * @brief Header file for serial port state management and interrupt handling.
 */

#ifndef __SERIAL_PORT__
#define __SERIAL_PORT__

#include "dev_interface/devices/serial_port.h"

/**
 * @brief Enumeration representing the different states of the serial port.
 */
typedef enum {
    INIT,       /**< Initial state */
    WAITING,    /**< Waiting state */
    CONNECTED   /**< Connected state */
} MSTATE;

/**
 * @brief Handles the serial port interrupt.
 *
 * This function should be called when a serial port interrupt is generated.
 * It processes the interrupt and performs necessary actions based on the 
 * current state and received data.
 *
 * @return 0 upon success, non-zero otherwise.
 */
int handleSPInterrupt();

#endif /* __SERIAL_PORT__ */
