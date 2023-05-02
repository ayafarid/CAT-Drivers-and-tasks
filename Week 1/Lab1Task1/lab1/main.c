/*
 * main.c
 *
 *  Created on: Dec 10, 2022
 *      Author: Aya farid
 */
#include <util/delay.h>
#include "STD_MATH.h"
typedef unsigned char u8;
#define DDRA  *((volatile u8*)0X3A)
#define PORTA *((volatile u8*)0x3B)
#define PINA  *((volatile u8*)0x39)
int main(){
	//pin 4 output
	SET_BIT(DDRA,0); //set bit 4 in DDRA and make it as an output pin

	while(1)
	{
		SET_BIT(PORTA,0); //set bit 4 in PORTA and make it as on led
		_delay_ms(1000);
		CLEAR_BIT(PORTA,0);
		_delay_ms(1000);
	}
	return 0;
}


