/*
 * LED_program.c
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../../Services/STD_types.h"
#include "../../Services/errorState.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LED_private.h"
#include "LED_config.h"
ES_t LED_enuInit(LED_t * Copy_pStrLedConfig){
	ES_t Local_enuErrorState=ES_OK;
	if(Copy_pStrLedConfig!=NULL){
		for(int i=0;i<LED_NUM;i++){
			DIO_enuSetPinDirection(Copy_pStrLedConfig[i].LED_u8PortID,Copy_pStrLedConfig[i].LED_u8PinID,OUTPUT);
			if(Copy_pStrLedConfig[i].LED_u8Connection==LED_SINK){
				if(Copy_pStrLedConfig[i].LED_u8State==LED_ON)
					  DIO_enuSetPinValue(Copy_pStrLedConfig[i].LED_u8PortID,Copy_pStrLedConfig[i].LED_u8PinID,LOW);
				else
					DIO_enuSetPinValue(Copy_pStrLedConfig[i].LED_u8PortID,Copy_pStrLedConfig[i].LED_u8PinID,HIGH);
			}else if(Copy_pStrLedConfig[i].LED_u8Connection==LED_SOURCE){
				if(Copy_pStrLedConfig[i].LED_u8State==LED_ON)
					  DIO_enuSetPinValue(Copy_pStrLedConfig[i].LED_u8PortID,Copy_pStrLedConfig[i].LED_u8PinID,HIGH);
				else
					DIO_enuSetPinValue(Copy_pStrLedConfig[i].LED_u8PortID,Copy_pStrLedConfig[i].LED_u8PinID,LOW);
			}else{
				Local_enuErrorState=ES_OUT_OF_RANGE;
			}
		}
	}else{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
ES_t LED_enuTurnOn(LED_t * Copy_pstrLedID){
	ES_t Local_enuErrorState=ES_OK;
	if(Copy_pstrLedID!=NULL){
		if(Copy_pstrLedID->LED_u8Connection==LED_SINK){
			DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,LOW);
		}else if(Copy_pstrLedID->LED_u8Connection==LED_SOURCE){
			DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,HIGH);
		}else{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}
	}else{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
ES_t LED_enuTornOff(LED_t * Copy_pstrLedID){
	ES_t Local_enuErrorState=ES_OK;
	if(Copy_pstrLedID!=NULL){
		if(Copy_pstrLedID->LED_u8Connection==LED_SINK){
			DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,HIGH);
		}else if(Copy_pstrLedID->LED_u8Connection==LED_SOURCE){
			DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,LOW);
		}else{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}
	}else{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

