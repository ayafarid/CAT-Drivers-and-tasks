/*
 * main.c
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../Services/STD_types.h"
#include "../Services/errorState.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/_7Seg_Driver/_7Seg_init.h"
#include "util/delay.h"
int main(){
	ES_t errorState=_7Seg_enuInit();
	while(1){
		if(errorState==ES_OK){
			_7Seg_enuSetDot();
		    for(int i=0;i<10;i++){
			     _7Seg_enuDispayNumber(i);
			     _delay_ms(1000);
		    }
		}
	}
}

