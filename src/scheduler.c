
#include <stdint.h>
#include "app_error.h"
#include "app_scheduler.h"
#include "app_timer_appsh.h"

#include "scheduler.h"


// YOUR_JOB: Modify these according to requirements (e.g. if other event types are to pass through
//           the scheduler).
#define SCHED_MAX_EVENT_DATA_SIZE   sizeof(app_timer_event_t)   /**< Maximum size of scheduler events. Note that scheduler BLE stack events do not contain any data, as the events are being pulled from the stack in the event handler. */
#define SCHED_QUEUE_SIZE            10                          /**< Maximum number of events in the scheduler queue. */

/**@brief Function for the Event Scheduler initialization.
 */
void scheduler_init(void)
{
    APP_SCHED_INIT(SCHED_MAX_EVENT_DATA_SIZE, SCHED_QUEUE_SIZE);
}
