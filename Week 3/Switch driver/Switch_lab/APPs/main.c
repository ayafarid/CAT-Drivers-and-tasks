/*
 * main.c
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../HAL/SWITCH_Driver/Switch_config.h"
#include "../HAL/SWITCH_Driver/Switch_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_config.h"
#include "util/delay.h"
extern SW_t switch_arrayOfSruct[SW_NUM];
int main(){
	u8  switchState;
	Switch_enuInit(switch_arrayOfSruct);
	while(1){
		Switch_enuGetState(&switch_arrayOfSruct[1],&switchState);
		if(switchState==0){
			DIO_enuSetPinValue(DIO_PORTA,DIO_PIN0,HIGH);
			_delay_ms(100);
		}else{
			DIO_enuSetPinValue(DIO_PORTA,DIO_PIN0,LOW);
			_delay_ms(100);
		}
	}
}

