
#ifndef TIMER_H__
#define TIMER_H__

#define APP_TIMER_PRESCALER     0   /**< Value of the RTC1 PRESCALER register. */

void timers_init(void);
void timers_start(void);

#endif // TIMER_H__
