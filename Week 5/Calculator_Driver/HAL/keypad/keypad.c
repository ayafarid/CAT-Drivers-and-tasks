//
// Created by kareem on 2/22/23.
//

#include <stddef.h>
#include "../../Services/STD_types.h"
#include "../../Services/errorState.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "keypad.h"
#include "keypad_config.h"
#include "keypad_private.h"

ES_t  key_pad_init()
{
    ES_t local_error = ES_NOK;
    DIO_enuSetPinDirection(C1_PORT,C1_PIN,DIO_u8OUTPUT);
    DIO_enuSetPinDirection(C2_PORT,C2_PIN,DIO_u8OUTPUT);
    DIO_enuSetPinDirection(C3_PORT,C3_PIN,DIO_u8OUTPUT);
    DIO_enuSetPinDirection(C4_PORT,C4_PIN,DIO_u8OUTPUT);

    DIO_enuSetPinDirection(R1_PORT,R1_PIN,DIO_u8INPUT);
    DIO_enuSetPinDirection(R2_PORT,R2_PIN,DIO_u8INPUT);
    DIO_enuSetPinDirection(R3_PORT,R3_PIN,DIO_u8INPUT);
    DIO_enuSetPinDirection(R4_PORT,R4_PIN,DIO_u8INPUT);

    DIO_enuSetPinValue(C1_PORT,C1_PIN,HIGH);
    DIO_enuSetPinValue(C2_PORT,C2_PIN,HIGH);
    DIO_enuSetPinValue(C3_PORT,C3_PIN,HIGH);
    DIO_enuSetPinValue(C4_PORT,C4_PIN,HIGH);

    DIO_enuSetPinValue(R1_PORT,R1_PIN,DIO_u8PULL_UP);
    DIO_enuSetPinValue(R2_PORT,R2_PIN,DIO_u8PULL_UP);
    DIO_enuSetPinValue(R3_PORT,R3_PIN,DIO_u8PULL_UP);
    DIO_enuSetPinValue(R4_PORT,R4_PIN,DIO_u8PULL_UP);

    local_error =ES_OK;
    return local_error;
}

ES_t key_pad_pressed_key(u8 *pressed_key)
{
    ES_t local_error = ES_NOK;
    if(pressed_key != NULL)
    {
        u8 row_pins [ROWS_NUMBER] = { R1_PIN , R2_PIN , R3_PIN , R4_PIN };
        u8 col_pins [COLOMS_NUMBER] = { C1_PIN , C2_PIN , C3_PIN , C4_PIN };
        u8 row_ports[ROWS_NUMBER] = { R1_PORT , R2_PORT , R3_PORT , R4_PORT };
        u8 col_ports[COLOMS_NUMBER] = { C1_PORT , C2_PORT , C3_PORT , C4_PORT };
        u8 local_value = KEY_NOT_PRESSED;
        for (int i = 0; i < COLOMS_NUMBER ; i++)
        {
        	DIO_enuSetPinValue(col_ports[i],col_pins[i],LOW);
            for (int j = 0; j <ROWS_NUMBER ; j++)
            {
                DIO_enuGetPinValue(row_ports[j],row_pins[j],&local_value);
                if(LOW == local_value)
                {

                    //indicator

                    do{

                        DIO_enuGetPinValue(row_ports[j],row_pins[j],&local_value);

                    } while (LOW == local_value);

                    *pressed_key = key_values[j][i];
                    local_error = ES_OK;
                    return local_error;
                }
            }

            DIO_enuSetPinValue(col_ports[i],col_pins[i], HIGH);
        }

    } else
    {
        local_error = ES_NULL_POINTER;
        return local_error;
    }

    return local_error;

}
