
#include <stdint.h>
#include "app_error.h"
#include "bsp.h"

#include "button.h"


#define BUTTON_DETECTION_DELAY      APP_TIMER_TICKS(50, APP_TIMER_PRESCALER)    /**< Delay from a GPIOTE event until a button is reported as pushed (in number of timer ticks). */


/**@brief Function for initializing the button handler module.
 */
void buttons_init(void)
{
    uint32_t err_code;
    // Note: Before start using buttons, assign events to buttons, as shown below.
    //      err_code = bsp_event_to_button_assign(BUTTON_0_ID, BSP_EVENT_KEY_0);
    //      APP_ERROR_CHECK(err_code);
    // Note: Enable buttons which you want to use.
    //      err_code = bsp_buttons_enable((1 << WAKEUP_BUTTON_ID) | (1 << BUTTON_0_ID));
    //      APP_ERROR_CHECK(err_code);
    // Note: If the only use of buttons is to wake up, the bsp module can be omitted, and
    // the wakeup button can be configured by
    err_code = bsp_buttons_enable(1 << WAKEUP_BUTTON_ID);
    APP_ERROR_CHECK(err_code);
}
