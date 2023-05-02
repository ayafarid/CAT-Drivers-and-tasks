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
#include "STD_MATH.h"
u8 sevenSegNumber[]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6f};
int main()
{
    DIO_enInit();
    DIO_enuSetPortDirection(DIO_PORTA,0x00);
    DIO_enuSetPortDirection(DIO_PORTC,0xff);
    DIO_enuSetPortDirection(DIO_PORTD,0x00);
    DIO_enuSetPortValue(DIO_PORTA,0x03);
    DIO_enuSetPortValue(DIO_PORTC,~sevenSegNumber[0]);
    DIO_enuSetPortValue(DIO_PORTD,0x03);
    DIO_enuSetPortValue(DIO_PORTD,0x1);
    DIO_enuSetPortValue(DIO_PORTC,~sevenSegNumber[0]);
    u8 b0=0,b1=0,count=50;
    while(1)
    {
        b0=DIO_enuGetPinValue(DIO_PORTA,DIO_PIN0);
        b1=DIO_enuGetPinValue(DIO_PORTA,DIO_PIN1);
        if(b0==0)
        {
            count++;
            while((b0=DIO_enuGetPinValue(DIO_PORTA,DIO_PIN0))==0);
        }
        else if(b1==0)
        {
            if(count>=1)
                count--;
            while((b1=DIO_enuGetPinValue(DIO_PORTA,DIO_PIN1))==0);
        }
        for(int i=0; i<10; i++)
        {
            DIO_enuSetPortValue(DIO_PORTD,0x1);
            DIO_enuSetPortValue(DIO_PORTC,~sevenSegNumber[count/10]);
            _delay_ms(10);
            DIO_enuSetPortValue(DIO_PORTD,0x2);
            DIO_enuSetPortValue(DIO_PORTC,~sevenSegNumber[count%10]);
            _delay_ms(10);
        }

    }

}

