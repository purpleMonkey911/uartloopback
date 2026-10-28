/**
 * @file           : main.c
 * @brief          : Entry point for uartloopback application
 * 
 * @copyright Copyright © 2026 Purple Monkey Software. All rights reserved.
 * 
 */

#include "app_config.h"
#include "loopback.h"
#include "mhal_gpio.h"
#include "mhal_interrupt.h"
#include "mhal_timer.h"
#include "system_init.h"
#include "uart_inst.h"

#define LED_TOGGLE_INTERVAL_US   1000000

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
    system_init();
    mHalTimer_SystemTimerInit();

    // Clear and enable interrupts
    mHalIntr_Clear();
    mHalIntr_Enable();

// setup debug LED
    GpioConfig led_config = {
        .mode = GPIO_MODE_OUT_PP,
        .pull = GPIO_PULL_NONE,
        .speed = GPIO_SPEED_LO,
        .alt_func = GPIO_AF_0_NONE,
    };
    Gpio led_gpio = {
        .port = LED_GPIO_PORT,
        .pin = LED_GPIO_PIN,
    };
    mHalGpio_Init(led_gpio, &led_config);
    mHalGpio_Write(led_gpio, GPIO_STATE_LOW);
    mHalTimerObj led_timer = {0};
    mHalTimer_StartTimerObj(&led_timer);

    // create and init Uart instance
    // create and init loopback 
    Uart_Init();
    loopback_init(Uart_GetInstance());
    

    while (1)
    {
        if (mHalTimer_TimerObjElapsed(&led_timer, LED_TOGGLE_INTERVAL_US)) {
            mHalGpio_Toggle(led_gpio);
            mHalTimer_StartTimerObj(&led_timer);
        }

        // exercise state machines
        if (mHalUart_StateMachine(Uart_GetInstance()) < MHAL_STATUS_OK) {
            // set off howling alarm!
        }

        // check loopback
        loopback_check();
    }

    // we should never get here!
    return 0;
}
