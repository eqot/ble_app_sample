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
#include "app_scheduler.h"

#include "error.h"
#include "gap.h"
#include "advertising.h"
#include "service.h"
#include "connection.h"
#include "security.h"
#include "ble_stack.h"
#include "timer.h"
#include "scheduler.h"
#include "gpiote.h"
#include "power.h"
#include "bsp_module.h"


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
