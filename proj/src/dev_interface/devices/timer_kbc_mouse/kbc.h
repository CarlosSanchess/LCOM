/**
 * @file kbc.h
 * @brief Constants, global variables, and function declarations for interfacing with the keyboard controller.
 */

#ifndef KBC__H
#define KBC__H

#include <lcom/lcf.h>
#include "i8042.h"

uint8_t scanCode; ///< Global variable to store the scan code from keyboard interrupts

/**
 * @brief Subscribes to keyboard interrupts.
 * 
 * @param bit_no Pointer to the bit number to be set in the mask returned upon an interrupt.
 * @return int Returns 0 upon success, non-zero otherwise.
 */
int (kbc_subscribe_int)(uint8_t *bit_no);

/**
 * @brief Unsubscribes from keyboard interrupts.
 * 
 * @return int Returns 0 upon success, non-zero otherwise.
 */
int (kbc_unsubscribe_int)();

/**
 * @brief Reads the status register.
 * 
 * @param status Pointer to store the status register value.
 * @return int Returns 0 upon success, non-zero otherwise.
 */
int (read_stat_reg)(uint8_t *status);

/**
 * @brief Reads the output buffer if the status register indicates it's ready.
 * 
 * @param status Status register value.
 * @param buffer Pointer to store the output buffer value.
 * @return int Returns 0 upon success, non-zero otherwise.
 */
int (read_output_buffer)(uint8_t status, uint8_t *buffer);

/**
 * @brief Keyboard interrupt handler.
 */
void (kbc_ih)();

/**
 * @brief Writes a command byte to the specified port.
 * 
 * @param port The port to write to.
 * @param commandByte The command byte to write.
 * @return int Returns 0 upon success, non-zero otherwise.
 */
int (write_kbc_command)(uint8_t port, uint8_t commandByte);

#endif /* KBC__H */
