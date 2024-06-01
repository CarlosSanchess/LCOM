/**
 * @file rtc.h
 * @brief RTC-related functions and definitions.
 */

#ifndef RTC_H_
#define RTC_H_

#include <lcom/lcf.h>

/**
 * @def ERROR
 * @brief Error code value.
 */
#define ERROR 1

/**
 * @def RTC_IRQ
 * @brief RTC IRQ line.
 */
#define RTC_IRQ 8

/**
 * @def RTC_ADDR_REG
 * @brief RTC address register.
 */
#define RTC_ADDR_REG 0x70

/**
 * @def RTC_DATA_REG
 * @brief RTC data register.
 */
#define RTC_DATA_REG 0x71

/**
 * @def RTC_UPDATE
 * @brief RTC update in progress register.
 */
#define RTC_UPDATE 0x0A

/**
 * @def RTC_BINARY
 * @brief RTC binary mode register.
 */
#define RTC_BINARY 0x0B

/**
 * @def RTC_SECONDS
 * @brief RTC seconds register.
 */
#define RTC_SECONDS 0x00

/**
 * @def RTC_MINUTES
 * @brief RTC minutes register.
 */
#define RTC_MINUTES 0x02

/**
 * @def RTC_HOURS
 * @brief RTC hours register.
 */
#define RTC_HOURS 0x04

/**
 * @brief Subscribes to RTC interrupts.
 *
 * @param bit_no Address of the variable to store the interrupt bit mask.
 * @return Returns 0 on success, 1 on failure.
 */
int (rtc_subscribe_int)(uint8_t *bit_no);

/**
 * @brief Unsubscribes from RTC interrupts.
 *
 * @return Returns 0 on success, 1 on failure.
 */
int (rtc_unsubscribe_int)();

/**
 * @brief Reads a value from a specified RTC register.
 *
 * @param reg Register to read from.
 * @param data Address of the variable to store the register value.
 * @return Returns 0 on success, 1 on failure.
 */
int (rtc_read_reg)(uint8_t reg, uint8_t *data);

/**
 * @brief Checks if an RTC update is in progress.
 *
 * @return Returns true if an update is in progress, false otherwise.
 */
bool (rtc_update_in_progress)();

/**
 * @brief Checks if the RTC is in binary mode.
 *
 * @return Returns true if in binary mode, false otherwise.
 */
bool (is_rtc_binary)();

/**
 * @brief Converts a BCD value to binary.
 *
 * @param bcd Address of the BCD value to convert (modifies in place).
 * @return Returns 0 on success.
 */
int (bcd_to_binary)(uint8_t *bcd);

/**
 * @brief Updates the provided variables with the current RTC time.
 *
 * @param seconds Address of the variable to store the current seconds.
 * @param minutes Address of the variable to store the current minutes.
 * @param hours Address of the variable to store the current hours.
 */
void (update_rtc_time)(uint8_t *seconds, uint8_t *minutes, uint8_t *hours);

#endif /* RTC_H_ */
