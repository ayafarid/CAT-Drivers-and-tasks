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

ES_t getKeyPressed(u8* Copy_u8Key)
{
    ES_t Local_Error=ES_NOK;
    if(Copy_u8Key!=NULL)
    {
        u8 Local_clmIterator,Local_rowsIterator,pinState;
        u8 Array[ROW_NUM][CLM_NUM]={{7,8,9,11},
        		                    {4,5,6,12},
									{1,2,3,13},
									{14,0,15,16}
        };
        u8 ColumnsPins[CLM_NUM]=
        {
            C0_PIN,
            C1_PIN,
            C2_PIN,
            C3_PIN
        };
        u8 RowsPins[ROW_NUM]=
        {
            R0_PIN,
            R1_PIN,
            R2_PIN,
            R3_PIN
        };
        u8 ColumnsPorts[CLM_NUM]=
        {
            C0_PORT,
            C1_PORT,
            C2_PORT,
            C3_PORt
        };
        u8 RowsPorts[ROW_NUM]=
        {
            R0_PORT,
            R1_PORT,
            R2_PORT,
            R3_PORT
        };
        for(Local_clmIterator=0; Local_clmIterator<CLM_NUM; Local_clmIterator++)
        {
            DIO_enuSetPinValue(ColumnsPorts[Local_clmIterator],ColumnsPins[Local_clmIterator],LOW);
            for(Local_rowsIterator=0; Local_rowsIterator<ROW_NUM; Local_rowsIterator++)
            {
                DIO_enuGetPinValue(RowsPorts[Local_rowsIterator],RowsPins[Local_rowsIterator],&pinState);
                if(pinState==LOW)
                {
                    while(pinState==LOW)
                    {
                        DIO_enuGetPinValue(RowsPorts[Local_rowsIterator],RowsPins[Local_rowsIterator],&pinState);
                    }
                    _delay_ms(10);
                    *Copy_u8Key=Array[Local_rowsIterator][Local_clmIterator];
                    Local_Error=ES_OK;
                    return Local_Error;
                }
            }
            DIO_enuSetPinValue(ColumnsPorts[Local_clmIterator],ColumnsPins[Local_clmIterator],LOW);
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
