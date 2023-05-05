/*
 * LED_init.h
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../../Services/STD_types.h"
#include "../../Services/errorState.h"
#include "LED_config.h"
#ifndef HAL_LED_DRIVER_LED_INIT_H_
#define HAL_LED_DRIVER_LED_INIT_H_

ES_t LED_enuInit(LED_t * Copy_pStrLedConfig);
ES_t LED_enuTurnOn(LED_t * Copy_pstrLedID);
ES_t LED_enuTornOff(LED_t * Copy_pstrLedID);

#endif /* HAL_LED_DRIVER_LED_INIT_H_ */
