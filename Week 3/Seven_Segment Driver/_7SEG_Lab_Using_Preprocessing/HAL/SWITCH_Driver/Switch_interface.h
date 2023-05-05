/*
 * Switch_interface.h
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../../Services/STD_types.h"
#include "../../Services/errorState.h"
#ifndef HAL_SWITCH_DRIVER_SWITCH_INTERFACE_H_
#define HAL_SWITCH_DRIVER_SWITCH_INTERFACE_H_

ES_t Switch_enuInit(SW_t * Copy_AstrSwitchs);
ES_t Switch_enuGetState(SW_t * Copy_AstrSwitchs,u8 * Copy_u8SwitchState);

#endif /* HAL_SWITCH_DRIVER_SWITCH_INTERFACE_H_ */
