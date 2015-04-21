
#ifndef BLE_STACK_H__
#define BLE_STACK_H__

void ble_stack_init(void);
void ble_evt_dispatch(ble_evt_t * p_ble_evt);
void on_ble_evt(ble_evt_t * p_ble_evt);
void sys_evt_dispatch(uint32_t sys_evt);


#endif // BLE_STACK_H__
