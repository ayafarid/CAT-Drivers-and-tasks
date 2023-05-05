/*
 * LED_config.h
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */

#ifndef HAL_LED_DRIVER_LED_CONFIG_H_
#define HAL_LED_DRIVER_LED_CONFIG_H_
typedef struct{
	u8 LED_u8State;
	u8 LED_u8PortID;
	u8 LED_u8PinID;
	u8 LED_u8Connection;
}LED_t;
#define LED_NUM 2
#define LED_SINK   0
#define LED_SOURCE 1
#define LED_OFF    0
#define LED_ON     1
#endif /* HAL_LED_DRIVER_LED_CONFIG_H_ */
