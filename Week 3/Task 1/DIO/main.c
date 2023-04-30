/*
 * main.c
 *
 *  Created on: Apr 29, 2023
 *      Author: Aya farid
 */
#include "DIO_interface.h"
#include "DIO_config.h"
#include "STD_types.h"
#include "util/delay.h"
#include "DIO_private.h"
#include "STD_MATH.h"
int main()
{
    DIO_enInit();
    DIO_enuSetPortDirection(DIO_PORTA,0xff);
    DIO_enuSetPortDirection(DIO_PORTB,0x00);
    DIO_enuSetPortValue(DIO_PORTA,0x00);
    DIO_enuSetPortValue(DIO_PORTB,0xff);
    u8 b0,b1,b2;
    while(1)
    {
        b0=DIO_enuGetPinValue(DIO_PORTB,DIO_PIN0);
        b1=DIO_enuGetPinValue(DIO_PORTB,DIO_PIN1);
        b2=DIO_enuGetPinValue(DIO_PORTB,DIO_PIN2);
        if(b0==0)
        {
            DIO_enuSetPinValue(DIO_PORTA,DIO_PIN0,HIGH);
            while((b0=DIO_enuGetPinValue(DIO_PORTB,DIO_PIN0))==0);

        }
        else if(b1==0)
        {
        	DIO_enuSetPinValue(DIO_PORTA,DIO_PIN1,HIGH);
            while((b1=DIO_enuGetPinValue(DIO_PORTB,DIO_PIN1))==0);
        }
        else if(b2==0)
        {
            DIO_enuSetPinValue(DIO_PORTA,DIO_PIN1,HIGH);
            DIO_enuSetPinValue(DIO_PORTA,DIO_PIN0,HIGH);
            while((b2=DIO_enuGetPinValue(DIO_PORTB,DIO_PIN2))==0);
        }
        DIO_enuSetPinValue(DIO_PORTA,DIO_PIN1,LOW);
        DIO_enuSetPinValue(DIO_PORTA,DIO_PIN0,LOW);

    }

}

