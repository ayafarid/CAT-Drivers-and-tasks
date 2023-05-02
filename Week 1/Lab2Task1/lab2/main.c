/*
 * main.c
 *
 *  Created on: Dec 10, 2022
 *      Author: Aya farid
 */
#include <util/delay.h>
#include "STD_MATH.h"
typedef unsigned char u8;
// PORT A
#define DDRA  *((volatile u8*)0X3A)
#define PORTA *((volatile u8*)0x3B)
#define PINA  *((volatile u8*)0x39)
// PORT B
#define PORTB *((volatile u8*)0x38)
#define DDRB  *((volatile u8*)0X37)
#define PINB  *((volatile u8*)0x36)
// PORT C
#define PORTC *((volatile u8*)0x35)
#define DDRC  *((volatile u8*)0X34)
#define PINC  *((volatile u8*)0x33)
// PORT D
#define PORTD *((volatile u8*)0x32)
#define DDRD  *((volatile u8*)0X31)
#define PIND  *((volatile u8*)0x30)
#define delayPeriod 100
int main(){
	//pin 4 output
	SET_BIT(DDRA,0); //set bit 4 in DDRA and make it as an output pin
	//make all pin of port A , B , C and D as output
	for(int i=0 ; i<8 ; i++){
		SET_BIT(DDRA,i); //set bit i in DDRA and make it as an output pin
		SET_BIT(DDRB,i); //set bit i in DDRB and make it as an output pin
		SET_BIT(DDRC,i); //set bit i in DDRC and make it as an output pin
		SET_BIT(DDRD,i); //set bit i in DDRD and make it as an output pin
	}
	while(1)
	{
		for(int i=0 ; i<8 ; i++){
			SET_BIT(PORTA,i); //set bit 4 in PORTA and make it as on led
			_delay_ms(delayPeriod);
			CLEAR_BIT(PORTA,i); //set bit 4 in PORTA and make it as off led
		}
		for(int i=0 ; i<8 ; i++){
			SET_BIT(PORTB,i); //set bit 4 in PORTA and make it as on led
			_delay_ms(delayPeriod);
			CLEAR_BIT(PORTB,i); //set bit 4 in PORTA and make it as off led
		}
		for(int i=0 ; i<8 ; i++){
			SET_BIT(PORTC,i); //set bit 4 in PORTA and make it as on led
			_delay_ms(delayPeriod);
		}
		for(int i=0 ; i<8 ; i++){
			SET_BIT(PORTD,i); //set bit 4 in PORTA and make it as on led
			_delay_ms(delayPeriod);
		}
		for(int i=7 ; i>=0 ; i--){
			CLEAR_BIT(PORTD,i); //set bit 4 in PORTA and make it as off led
			_delay_ms(delayPeriod);
		}
		for(int i=7 ; i>=0 ; i--){
			CLEAR_BIT(PORTC,i); //set bit 4 in PORTA and make it as off led
			_delay_ms(delayPeriod);
		}
	}
	return 0;
}

