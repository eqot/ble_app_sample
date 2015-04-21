
#include <stdint.h>
#include "app_error.h"
#include "app_timer_appsh.h"
#include "bsp.h"

#include "bsp_module.h"
#include "timer.h"
#include "button.h"


/**@brief Function for initializing bsp module.
 */
void bsp_module_init(void)
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


/**@brief Function for handling a bsp event.
 *
 * @param[in]     evt                        BSP event.
 */
/* YOUR_JOB: Uncomment this function if you need to handle button events.
void bsp_event_handler(bsp_event_t evt)
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
