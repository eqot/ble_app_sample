
#include <stdint.h>
#include "app_error.h"
#include "app_gpiote.h"

#include "gpiote.h"


#define APP_GPIOTE_MAX_USERS    1   /**< Maximum number of users of the GPIOTE handler. */


/**@brief Function for initializing the GPIOTE handler module.
 */
void gpiote_init(void)
{
    APP_GPIOTE_INIT(APP_GPIOTE_MAX_USERS);
}
