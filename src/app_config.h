/**
 * @file app_config.h
 * @brief Application parameters
 *
 * Copyright © 2026 Purple Monkey Software. All rights reserved.
 *
 */

#ifndef __APP_CONFIG_H__
#define __APP_CONFIG_H__

#include "mhal_gpio.h"
#include "mhal_uart.h"

// UART GPIO pin assignments (UART3)
#define UART_PORT                    GPIO_PORT_C
#define UART_TX_PIN                  GPIO_PIN10
#define UART_RX_PIN                  GPIO_PIN11
#define UART_BAUD                    UART_BAUD_115200
#define UART_DATA_BITS               UART_DATA_BITS_8
#define UART_STOP_BITS               UART_STOP_BITS_1
#define UART_PARITY                  UART_PARITY_BITS_NONE
#define UART_RING_BUFFER_SIZE_BYTES  128
#define UART_INDEX                   UART_INDEX_3

// debug LED
#define LED_GPIO_PORT          GPIO_PORT_A
#define LED_GPIO_PIN           GPIO_PIN5

#endif // __APP_CONFIG_H__
