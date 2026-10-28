/**
 * @file loopback.c
 * 
 * @brief UART loopback module
 * 
 * @copyright Copyright © 2026 Purple Monkey Software. All rights reserved.
 * 
 */

#ifndef __LOOPBACK_H__
#define __LOOPBACK_H__

#include "mhal_uart.h"

/**
 * @brief initialize loopback module
 * 
 * @param loopback_uart Uart to be used for the loopback module
 * 
 * @note It is expected that Uart is already declared and allocated properly
 */ 
extern void loopback_init(Uart loopback_uart);

/**
 * @brief check for loopback data
 */ 
extern void loopback_check(void);

#endif  // __LOOPBACK_H__