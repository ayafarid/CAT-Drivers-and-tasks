/*
 * main.c
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../Services/STD_types.h"
#include "../Services/errorState.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "util/delay.h"

int main(){
	DIO_enuInit();
	LCD_enuInit();
	u8 keyPressed=0xff;
	while(1){
		do{
			getKeyPressed(&keyPressed);
		}while(keyPressed==0xff);
		_delay_ms(10);
		LCD_enuDisplayChar(keyPressed+'0');
		keyPressed=0xff;
	}
}

