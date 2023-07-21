/*
 * keypad.c
 *
 *  Created on: Jul 11, 2023
 *      Author: Aya farid
 */
#include "../../Services/STD_types.h"
#include "../../Services/errorState.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "../../HAL/KEYPAD/keypad.h"
#include "../../HAL/KEYPAD/keypad_cong.h"
#include "../../HAL/KEYPAD/keypad_priv.h"
#include "util/delay.h"
u8 getKeyPressed(u8* Copy_u8Key)
{
    ES_t Local_Error=ES_NOK;
    if(Copy_u8Key!=NULL)
    {
    	DIO_enuSetPortValue(DIO_PORTB,0xff);
        u8 pinState;
        u8 Array[ROW_NUM][CLM_NUM]={{'7','8','9','/'},
                                {'4','5','6','x'},
                  {'1','2','3','-'},
                  {'c','0','=','+'}
        };
        DIO_enuSetPinValue(C0_PORT,C0_PIN,LOW);
        DIO_enuGetPinValue(R0_PORT,R0_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R0_PORT,R0_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[0][0];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuGetPinValue(R1_PORT,R1_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R1_PORT,R1_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[1][0];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuGetPinValue(R2_PORT,R2_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R2_PORT,R2_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[2][0];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuGetPinValue(R3_PORT,R3_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R3_PORT,R3_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[3][0];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuSetPinValue(C0_PORT,C0_PIN,HIGH);

        DIO_enuSetPinValue(C1_PORT,C1_PIN,LOW);
        DIO_enuGetPinValue(R0_PORT,R0_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R0_PORT,R0_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[0][1];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuGetPinValue(R1_PORT,R1_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R1_PORT,R1_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[1][1];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuGetPinValue(R2_PORT,R2_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R2_PORT,R2_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[2][1];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuGetPinValue(R3_PORT,R3_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R3_PORT,R3_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[3][1];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuSetPinValue(C1_PORT,C1_PIN,HIGH);

DIO_enuSetPinValue(C2_PORT,C2_PIN,LOW);
        DIO_enuGetPinValue(R0_PORT,R0_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R0_PORT,R0_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[0][2];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuGetPinValue(R1_PORT,R1_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R1_PORT,R1_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[1][2];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuGetPinValue(R2_PORT,R2_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R2_PORT,R2_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[2][2];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuGetPinValue(R3_PORT,R3_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R3_PORT,R3_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[3][2];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuSetPinValue(C2_PORT,C2_PIN,HIGH);

        DIO_enuSetPinValue(C3_PORT,C3_PIN,LOW);
        DIO_enuGetPinValue(R0_PORT,R0_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R0_PORT,R0_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[0][3];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuGetPinValue(R1_PORT,R1_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R1_PORT,R1_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[1][3];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuGetPinValue(R2_PORT,R2_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R2_PORT,R2_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[2][3];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuGetPinValue(R3_PORT,R3_PIN,&pinState);
        if(pinState==LOW){
          while(pinState==LOW){
            DIO_enuGetPinValue(R3_PORT,R3_PIN,&pinState);
          }
          _delay_ms(10);
          *Copy_u8Key=Array[3][3];
          Local_Error=ES_OK;
          return Local_Error;
        }
        DIO_enuSetPinValue(C3_PORT,C3_PIN,HIGH);
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
