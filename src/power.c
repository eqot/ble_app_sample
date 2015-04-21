
#include <stdint.h>
#include "app_error.h"
#include "softdevice_handler.h"

#include "power.h"

/**@brief Function for the Power manager.
 */
void power_manage(void)
{
    uint32_t err_code = sd_app_evt_wait();
    APP_ERROR_CHECK(err_code);
}
