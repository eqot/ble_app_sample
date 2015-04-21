/* Copyright (c) 2014 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

/** @file
 *
 * @defgroup ble_sdk_app_template_main main.c
 * @{
 * @ingroup ble_sdk_app_template
 * @brief Template project main file.
 *
 * This file contains a template for creating a new application. It has the code necessary to wakeup
 * from button, advertise, get a connection restart advertising on disconnect and if no new
 * connection created go back to system-off mode.
 * It can easily be used as a starting point for creating a new application, the comments identified
 * with 'YOUR_JOB' indicates where and how you can customize.
 */

#include <stdint.h>
#include <string.h>
#include "app_scheduler.h"
#include "softdevice_handler.h"
#include "app_timer_appsh.h"
#include "bsp.h"

#include "error.h"
#include "gap.h"
#include "advertising.h"
#include "connection.h"
#include "security.h"
#include "ble_stack.h"
#include "timer.h"
#include "scheduler.h"
#include "button.h"
#include "gpiote.h"
#include "power.h"


/**@brief Function for initializing services that will be used by the application.
 */
static void services_init(void)
{
    // YOUR_JOB: Add code to initialize the services used by the application.
}


/**@brief Function for handling a bsp event.
 *
 * @param[in]     evt                        BSP event.
 */
/* YOUR_JOB: Uncomment this function if you need to handle button events.
static void bsp_event_handler(bsp_event_t evt)
{
        switch (evt)
        {
            case BSP_EVENT_KEY_0:
                // Code to handle BSP_EVENT_KEY_0
                break;

            // Handle any other event

            default:
                APP_ERROR_HANDLER(evt);
                break;
        }
    }
}
*/


/**@brief Function for initializing bsp module.
 */
static void bsp_module_init(void)
{
    uint32_t err_code;
    // Note: If the only use of buttons is to wake up, bsp_event_handler can be NULL.
    err_code = bsp_init(BSP_INIT_LED | BSP_INIT_BUTTONS, APP_TIMER_TICKS(100, APP_TIMER_PRESCALER), NULL);
    APP_ERROR_CHECK(err_code);
    // Note: If the buttons will be used to do some task, assign bsp_event_handler, as shown below.
    // err_code = bsp_init(BSP_INIT_LED | BSP_INIT_BUTTONS, APP_TIMER_TICKS(100, APP_TIMER_PRESCALER), bsp_event_handler);
    // APP_ERROR_CHECK(err_code);
    // Buttons initialization.
    buttons_init();
}


/**@brief Function for application main entry.
 */
int main(void)
{
    // Initialize
    timers_init();
    gpiote_init();
    ble_stack_init();
    bsp_module_init();
    scheduler_init();
    gap_params_init();
    advertising_init();
    services_init();
    conn_params_init();
    sec_params_init();

    // Start execution
    timers_start();
    advertising_start();

    // Enter main loop
    for (;;)
    {
        app_sched_execute();
        power_manage();
    }
}

/**
 * @}
 */
