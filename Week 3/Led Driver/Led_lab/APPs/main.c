/*
 * main.c
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../Services/STD_types.h"
#include "../Services/errorState.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../HAL/LED_Driver/LED_init.h"
#include "util/delay.h"

extern LED_t LED_AstrLedConfig[LED_NUM];
int main(){
	//DIO_enInit();
	LED_enuInit(LED_AstrLedConfig);
	while(1){
		LED_enuTurnOn(&LED_AstrLedConfig[0]);
		LED_enuTurnOn(&LED_AstrLedConfig[1]);
		_delay_ms(1000);
		LED_enuTornOff(&LED_AstrLedConfig[0]);
		LED_enuTornOff(&LED_AstrLedConfig[1]);
		_delay_ms(1000);
	}
}

