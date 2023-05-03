/*
 * Switch_program.c
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_config.h"
#include "Switch_config.h"
ES_t Switch_enuInit(SW_t * Copy_AstrSwitchs){
	ES_t Local_enuErrorState=ES_OK;
	if(Copy_AstrSwitchs!=NULL){
		for(int i=0;i<SW_NUM;i++){
			Local_enuErrorState=DIO_enuSetPinDirection(Copy_AstrSwitchs[i].SW_portID,Copy_AstrSwitchs[i].SW_pinID,INPUT);
			Local_enuErrorState=DIO_enuSetPinValue(Copy_AstrSwitchs[i].SW_portID,Copy_AstrSwitchs[i].SW_pinID,Copy_AstrSwitchs[i].SW_status);
		}
	}else{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
u8 Switch_enuGetState(SW_t * Copy_AstrSwitchs,u8 * Copy_u8SwitchState){
	ES_t Local_enuErrorState=ES_OK;
	u8 local=0;
	if(Copy_AstrSwitchs!=NULL){
		*Copy_u8SwitchState=DIO_enuGetPinValue(Copy_AstrSwitchs->SW_portID,Copy_AstrSwitchs->SW_pinID);
	}else{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return local;
}

