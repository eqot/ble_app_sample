
#include <stdint.h>
#include "app_error.h"
#include "ble.h"

#include "security.h"

#define SEC_PARAM_BOND              1                       /**< Perform bonding. */
#define SEC_PARAM_MITM              0                       /**< Man In The Middle protection not required. */
#define SEC_PARAM_IO_CAPABILITIES   BLE_GAP_IO_CAPS_NONE    /**< No I/O capabilities. */
#define SEC_PARAM_OOB               0                       /**< Out Of Band data not available. */
#define SEC_PARAM_MIN_KEY_SIZE      7                       /**< Minimum encryption key size. */
#define SEC_PARAM_MAX_KEY_SIZE      16                      /**< Maximum encryption key size. */


static ble_gap_sec_params_t         m_sec_params;           /**< Security requirements for this application. */


/**@brief Function for initializing security parameters.
 */
void sec_params_init(void)
{
    m_sec_params.bond         = SEC_PARAM_BOND;
    m_sec_params.mitm         = SEC_PARAM_MITM;
    m_sec_params.io_caps      = SEC_PARAM_IO_CAPABILITIES;
    m_sec_params.oob          = SEC_PARAM_OOB;
    m_sec_params.min_key_size = SEC_PARAM_MIN_KEY_SIZE;
    m_sec_params.max_key_size = SEC_PARAM_MAX_KEY_SIZE;
}
