
#ifndef SECURITY_H__
#define SECURITY_H__

extern ble_gap_sec_params_t     m_sec_params;   /**< Security requirements for this application. */

void sec_params_init(void);

#endif // SECURITY_H__
