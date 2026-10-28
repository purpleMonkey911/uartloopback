/**
 * @file loopback.c
 * 
 * @brief UART loopback functinality
 * 
 * @copyright Copyright © 2026 Purple Monkey Software. All rights reserved.
 * 
 */

#include <stdbool.h>
#include "app_config.h"
#include "mhal_gpio.h"
#include "mhal_uart.h"

static Uart app_uart = 0;

void loopback_init(Uart loopback_uart) {
    app_uart = loopback_uart;
}

void loopback_check(void) {
    // check for any received data
    uint8_t byte;
    if (mHalUart_GetByte(app_uart, &byte) == MHAL_STATUS_OK) {
        // send any recevied data back
        mHalUart_SendData(app_uart, &byte, 1);
    }
}
