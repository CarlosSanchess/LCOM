/**
 * @file timer.h
 * @brief Timer-related functions and definitions.
 */

#ifndef TIMERH
#define TIMERH

#include <lcom/lcf.h>
#include "i8254.h"

/**
 * @def ERROR
 * @brief Error code value.
 */
#define ERROR 1

/**
 * @brief Sets the frequency of the specified timer.
 *
 * @param timer Timer to set the frequency for (0, 1, or 2).
 * @param freq Desired frequency.
 * @return Returns 0 on success, 1 on failure.
 */
int (timer_set_frequency)(uint8_t timer, uint32_t freq);

/**
 * @brief Subscribes to timer interrupts.
 *
 * @param bit_no Address of the variable to store the interrupt bit mask.
 * @return Returns 0 on success, 1 on failure.
 */
int (timer_subscribe_int)(uint8_t *bit_no);

/**
 * @brief Unsubscribes from timer interrupts.
 *
 * @return Returns 0 on success, 1 on failure.
 */
int (timer_unsubscribe_int)();

/**
 * @brief Timer interrupt handler that increments the timer counter.
 */
void (timer_int_handler)();

/**
 * @brief Retrieves the configuration of the specified timer.
 *
 * @param timer Timer to get configuration for (0, 1, or 2).
 * @param st Address of the variable to store the configuration byte.
 * @return Returns 0 on success, 1 on failure.
 */
int (timer_get_conf)(uint8_t timer, uint8_t *st);

/**
 * @brief Displays the configuration of the specified timer.
 *
 * @param timer Timer to display configuration for (0, 1, or 2).
 * @param st Configuration byte.
 * @param field Field of the timer status to display (all, initialization mode, mode, or base).
 * @return Returns 0 on success, 1 on failure.
 */
int (timer_display_conf)(uint8_t timer, uint8_t st, enum timer_status_field field);

#endif /* TIMERH */
