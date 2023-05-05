/*
 * Switch_config.h
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../../Services/STD_types.h"
#ifndef HAL_SWITCH_DRIVER_SWITCH_CONFIG_H_
#define HAL_SWITCH_DRIVER_SWITCH_CONFIG_H_
#define SW_NUM  2
typedef struct {
	u8 SW_portID;
	u8 SW_pinID;
	u8 SW_status;
}SW_t;

#endif /* HAL_SWITCH_DRIVER_SWITCH_CONFIG_H_ */
