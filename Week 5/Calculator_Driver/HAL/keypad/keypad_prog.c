/*
 * keypad.c
 *
 *  Created on: Jul 11, 2023
 *      Author: Aya farid
 */
#include "../../Services/STD_types.h"
#include "../../Services/errorState.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "../../HAL/KEYPAD/keypad_cong.h"
#include "../../HAL/KEYPAD/keypad_priv.h"
#include "util/delay.h"

#include "keypad_int.h"
ES_t Keypad_enuInit(void)
{
	ES_t Local_enuErrorState =ES_NOK;

	DIO_enuSetPinDirection(C1_PORT,C1_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(C2_PORT,C2_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(C3_PORT,C3_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(C0_PORT,C0_PIN, DIO_u8OUTPUT);

	DIO_enuSetPinDirection(R1_PORT,R1_PIN, DIO_u8INPUT);
	DIO_enuSetPinDirection(R2_PORT,R2_PIN, DIO_u8INPUT);
	DIO_enuSetPinDirection(R3_PORT,R3_PIN, DIO_u8INPUT);
	DIO_enuSetPinDirection(R0_PORT,R0_PIN, DIO_u8INPUT);

	DIO_enuSetPinValue(C1_PORT,C1_PIN, HIGH);
	DIO_enuSetPinValue(C2_PORT,C2_PIN, HIGH);
	DIO_enuSetPinValue(C3_PORT,C3_PIN, HIGH);
	DIO_enuSetPinValue(C0_PORT,C0_PIN, HIGH);

	DIO_enuSetPinValue(R1_PORT,R1_PIN, DIO_u8PULL_UP);
	DIO_enuSetPinValue(R2_PORT,R2_PIN, DIO_u8PULL_UP);
	DIO_enuSetPinValue(R3_PORT,R3_PIN, DIO_u8PULL_UP);
	DIO_enuSetPinValue(R0_PORT,R0_PIN, DIO_u8PULL_UP);

	Local_enuErrorState =ES_OK;

	return Local_enuErrorState;
}
u8 getKeyPressed(u8* Copy_u8Key)
{
    ES_t Local_Error=ES_NOK;
    if(Copy_u8Key!=NULL)
    {
        DIO_enuSetPortValue(DIO_PORTB,0xff);
        u8 pinState;
        u8 Array[ROW_NUM][CLM_NUM]= {{'7','8','9','/'},
                                     {'4','5','6','x'},
                                     {'1','2','3','-'},
                                     {'c','0','=','+'}
        };
		u8 Local_Au8RowPins [ROW_NUM] = {R0_PIN, R1_PIN , R2_PIN , R3_PIN  };
		u8 Local_Au8ColPins [CLM_NUM] = { C0_PIN, C1_PIN , C2_PIN , C3_PIN  };
		u8 Local_Au8RowPorts[ROW_NUM] = {C0_PORT, R1_PORT , R2_PORT , R3_PORT };
		u8 Local_Au8ColPorts[CLM_NUM] = {C0_PORT, C1_PORT , C2_PORT , C3_PORT };
		for (int i =0; i < CLM_NUM ; i ++){
			DIO_enuSetPinValue(Local_Au8ColPorts[i],Local_Au8ColPins[i],LOW);
			for(int j=0;j<ROW_NUM;j++){
				DIO_enuGetPinValue(Local_Au8RowPorts[j],Local_Au8RowPins[j],&pinState);
		        if(pinState==LOW)
		        {
		            while(pinState==LOW)
		            {
		            	DIO_enuGetPinValue(Local_Au8RowPorts[j],Local_Au8RowPins[j],&pinState);
		            }
		            _delay_ms(10);
		            *Copy_u8Key=Array[j][i];
		            Local_Error=ES_OK;
		            return Local_Error;
		        }
			}
			DIO_enuSetPinValue(Local_Au8ColPorts[i],Local_Au8ColPins[i],HIGH);
		}
    }
    else
    {
        *Copy_u8Key=0xff;
        Local_Error=ES_NULL_POINTER;
        return Local_Error;
    }
    *Copy_u8Key=0xff;
    return Local_Error;
}
