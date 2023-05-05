/*
 * main.c
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../Services/STD_types.h"
#include "../Services/errorState.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/Seven_Segment_Driver/sevSeg_init.h"
#include "../HAL/Seven_Segment_Driver/sevSeg_config.h"
#include "util/delay.h"
extern SEV_SEG_t SEVSEG_AstrSegConfig[SEVEN_SEG];
int main(){
	_7Seg_enuInit(SEVSEG_AstrSegConfig);
	while(1){
		_7Seg_enuSetDot(0);
		for(int i=0;i<10;i++){
			_7Seg_enuDispayNumber(0,i);
			_delay_ms(1000);
		}
	}
}

