/*
 * sevSeg_config.c
 *
 *  Created on: May 5, 2023
 *      Author: Aya farid
 */
#include "../../MCAL/DIO/DIO_interface.h"
#include "sevSeg_config.h"
SEV_SEG_t SEVSEG_AstrSegConfig[SEVEN_SEG]={
		{.Seven_Seg_APIN=DIO_PIN0,.Seven_Seg_APORT=DIO_PORTA,
		 .Seven_Seg_BPIN=DIO_PIN1,.Seven_Seg_BPORT=DIO_PORTA,
		 .Seven_Seg_CPIN=DIO_PIN2,.Seven_Seg_CPORT=DIO_PORTA,
		 .Seven_Seg_DPIN=DIO_PIN3,.Seven_Seg_DPORT=DIO_PORTA,
		 .Seven_Seg_EPIN=DIO_PIN4,.Seven_Seg_EPORT=DIO_PORTA,
		 .Seven_Seg_FPIN=DIO_PIN5,.Seven_Seg_FPORT=DIO_PORTA,
		 .Seven_Seg_GPIN=DIO_PIN6,.Seven_Seg_GPORT=DIO_PORTA,
		 .Seven_Seg_CMN_PIN=DIO_PIN0,.Seven_Seg_CMN_PORT=DIO_PORTB,
		 .Seven_Seg_DOT_PIN=DIO_PIN7,.Seven_Seg_DOT_PORT=DIO_PORTA,
		 .Seven_Seg_type=COMMON_CATHOD}
};

