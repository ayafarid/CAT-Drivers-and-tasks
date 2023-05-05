/*
 * sevSeg_program.c
 *
 *  Created on: May 5, 2023
 *      Author: Aya farid
 */
#include "../../Services/STD_types.h"
#include "../../Services/errorState.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "sevSeg_config.h"
#include "sevSeg_Private.h"
extern SEV_SEG_t SEVSEG_AstrSegConfig[SEVEN_SEG];
ES_t _7Seg_enuInit(SEV_SEG_t * Copy_PStrASeg){
	ES_t Local_errorState=ES_OK;
	for(int i=0 ; i<SEVEN_SEG;i++){
		DIO_enuSetPinDirection(Copy_PStrASeg[i].Seven_Seg_APORT,Copy_PStrASeg[i].Seven_Seg_APIN,OUTPUT);
		DIO_enuSetPinDirection(Copy_PStrASeg[i].Seven_Seg_BPORT,Copy_PStrASeg[i].Seven_Seg_BPIN,OUTPUT);
		DIO_enuSetPinDirection(Copy_PStrASeg[i].Seven_Seg_CPORT,Copy_PStrASeg[i].Seven_Seg_CPIN,OUTPUT);
		DIO_enuSetPinDirection(Copy_PStrASeg[i].Seven_Seg_DPORT,Copy_PStrASeg[i].Seven_Seg_DPIN,OUTPUT);
		DIO_enuSetPinDirection(Copy_PStrASeg[i].Seven_Seg_EPORT,Copy_PStrASeg[i].Seven_Seg_EPIN,OUTPUT);
		DIO_enuSetPinDirection(Copy_PStrASeg[i].Seven_Seg_FPORT,Copy_PStrASeg[i].Seven_Seg_FPIN,OUTPUT);
		DIO_enuSetPinDirection(Copy_PStrASeg[i].Seven_Seg_GPORT,Copy_PStrASeg[i].Seven_Seg_GPIN,OUTPUT);
		if(Copy_PStrASeg[i].Seven_Seg_CMN_PIN<=DIO_PIN7 && Copy_PStrASeg[i].Seven_Seg_CMN_PORT<=DIO_PORTD){
			DIO_enuSetPinDirection(Copy_PStrASeg[i].Seven_Seg_CMN_PORT,Copy_PStrASeg[i].Seven_Seg_CMN_PIN,OUTPUT);
		}
		if(Copy_PStrASeg[i].Seven_Seg_DOT_PIN<= DIO_PIN7 && Copy_PStrASeg[i].Seven_Seg_DOT_PORT<=DIO_PORTD){
			DIO_enuSetPinDirection(Copy_PStrASeg[i].Seven_Seg_DOT_PORT,Copy_PStrASeg[i].Seven_Seg_DOT_PIN,OUTPUT);
		}
	}
	return Local_errorState;
}
ES_t _7Seg_enuDispayNumber(u8 Copy_u8SegID,u8 Copy_u8Num){
	ES_t Local_errorState=ES_OK;
	if(Copy_u8SegID<SEVEN_SEG&&Copy_u8Num<10){
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_type==COMMON_CATHOD){
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_APORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_APIN,(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>0)&1);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_BPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_BPIN,(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>1)&1);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CPIN,(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>2)&1);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DPIN,(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>3)&1);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_EPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_EPIN,(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>4)&1);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_FPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_FPIN,(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>5)&1);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_GPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_GPIN,(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>6)&1);
		}else{
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_APORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_APIN,!(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>0)&1);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_BPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_BPIN,!(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>1)&1);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CPIN,!(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>2)&1);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DPIN,!(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>3)&1);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_EPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_EPIN,!(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>4)&1);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_FPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_FPIN,!(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>5)&1);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_GPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_GPIN,!(_7Seg_Au8sevenSegNumber[Copy_u8Num]>>6)&1);
		}
	}
	return Local_errorState;
}
ES_t _7Seg_enuClearNumber(u8 Copy_u8SegID){
	ES_t Local_errorState=ES_OK;
	if(Copy_u8SegID<SEVEN_SEG){
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_type==COMMON_CATHOD){
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_APORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_APIN,LOW);
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_BPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_BPIN,LOW);
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CPIN,LOW);
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DPIN,LOW);
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_EPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_EPIN,LOW);
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_FPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_FPIN,LOW);
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_GPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_GPIN,LOW);
			}else{
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_APORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_APIN,HIGH);
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_BPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_BPIN,HIGH);
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CPIN,HIGH);
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DPIN,HIGH);
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_EPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_EPIN,HIGH);
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_FPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_FPIN,HIGH);
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_GPORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_GPIN,HIGH);
			}
	}
	return Local_errorState;
}
ES_t _7Seg_enuSetDot(u8 Copy_u8SegID){
	ES_t Local_errorState=ES_OK;
	if(Copy_u8SegID<SEVEN_SEG){
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DOT_PIN!=NOT_CONNECTED && SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DOT_PORT!=NOT_CONNECTED){
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_type==COMMON_CATHOD)
				Local_errorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DOT_PORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DOT_PIN,HIGH);
			else
				Local_errorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DOT_PORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DOT_PIN,LOW);
		}else{
			Local_errorState=ES_OUT_OF_RANGE;
		}
	}
	return Local_errorState;
}
ES_t _7Seg_enuClearDot(u8 Copy_u8SegID){
	ES_t Local_errorState=ES_OK;
	if(Copy_u8SegID<SEVEN_SEG){
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DOT_PIN!=NOT_CONNECTED && SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DOT_PORT!=NOT_CONNECTED){
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_type==COMMON_CATHOD)
				Local_errorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DOT_PORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DOT_PIN,LOW);
			else
				Local_errorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DOT_PORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_DOT_PIN,HIGH);
		}else{
			Local_errorState=ES_OUT_OF_RANGE;
		}
	}
	return Local_errorState;
}
ES_t _7Seg_enuEnableCommon(u8 Copy_u8SegID){
	ES_t Local_errorState=ES_OK;
	if(Copy_u8SegID<SEVEN_SEG){
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CMN_PIN!=NOT_CONNECTED && SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CMN_PORT!=NOT_CONNECTED){
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_type==COMMON_CATHOD)
				Local_errorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CMN_PORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CMN_PIN,HIGH);
			else
				Local_errorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CMN_PORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CMN_PIN,LOW);
		}else{
			Local_errorState=ES_OUT_OF_RANGE;
		}
	}
	return Local_errorState;
}
ES_t _7Seg_enuDisableCommon(u8 Copy_u8SegID){
	ES_t Local_errorState=ES_OK;
	if(Copy_u8SegID<SEVEN_SEG){
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CMN_PIN!=NOT_CONNECTED && SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CMN_PORT!=NOT_CONNECTED){
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_type==COMMON_CATHOD)
				Local_errorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CMN_PORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CMN_PIN,LOW);
			else
				Local_errorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CMN_PORT,SEVSEG_AstrSegConfig[Copy_u8SegID].Seven_Seg_CMN_PIN,HIGH);
		}else{
			Local_errorState=ES_OUT_OF_RANGE;
		}
	}
	return Local_errorState;
}

