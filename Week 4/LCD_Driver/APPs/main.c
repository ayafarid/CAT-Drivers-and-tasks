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
	LCD_enuInit();
	DIO_enuInit();
	while(1){
		LCD_enuDisplayChar('A');
		LCD_enuDisplayChar('y');
		LCD_enuDisplayChar('a');
		LCD_enuDisplayChar(' ');
		LCD_enuDisplayChar(':');
		LCD_enuDisplayChar(')');
		_delay_ms(3000);
		LCD_enuSendCommand(0x01);
	}
}

