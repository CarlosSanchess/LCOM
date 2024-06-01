/**
 * @file mouse.h
 * @brief Constants, global variables, and function declarations for interfacing with the mouse.
 */

#ifndef MOUSEH 
#define MOUSEH

#include <lcom/lcf.h>
#include "i8042.h"

struct packet mouse_byte_packet; ///< Global variable to store the mouse packet
int mouse_errorHandling; ///< Global variable to handle mouse errors

/**
 * @brief Writes a command byte to the mouse.
 * 
 * @param command_byte The command byte to write.
 * @return int Returns 0 upon success, non-zero otherwise.
 */
int (write_mouse)(uint8_t command_byte);

/**
 * @brief Mouse interrupt handler.
 */
void (mouse_ih)();

/**
 * @brief Processes the mouse packet.
 */
void (mouse_packet)();

/**
 * @brief Subscribes to mouse interrupts.
 * 
 * @param bit_no Pointer to the bit number to be set in the mask returned upon an interrupt.
 * @return int Returns 0 upon success, non-zero otherwise.
 */
int (mouse_subscribe_int)(uint8_t *bit_no);

/**
 * @brief Unsubscribes from mouse interrupts.
 * 
 * @return int Returns 0 upon success, non-zero otherwise.
 */
int (mouse_unsubscribe_int)();

#endif /* MOUSEH */
