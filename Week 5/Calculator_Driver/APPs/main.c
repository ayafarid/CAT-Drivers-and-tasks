/*
 * main.c
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../Services/STD_types.h"
#include "../Services/errorState.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/keypad/keypad.h"

int main()
{
    u8 Local_u8PressedValue=0xff;
    DIO_enuInit();
    LCD_enuInit();
    key_pad_init();
    while(1)
    {
        do
        {
        	key_pad_pressed_key(&Local_u8PressedValue);
        }
        while(Local_u8PressedValue==0xff);
        LCD_enuDisplayChar(Local_u8PressedValue+'0');

    }
}

