/*
 * LED_config.c
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../../Services/errorState.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LED_config.h"

LED_t LED_AstrLedConfig[LED_NUM]={
		{.LED_u8Connection=LED_SOURCE,.LED_u8PinID=DIO_PORTA,.LED_u8PinID=DIO_PIN0,.LED_u8State=LED_OFF},
		{.LED_u8Connection=LED_SINK,.LED_u8PinID=DIO_PORTA,.LED_u8PinID=DIO_PIN1,.LED_u8State=LED_ON}
};
