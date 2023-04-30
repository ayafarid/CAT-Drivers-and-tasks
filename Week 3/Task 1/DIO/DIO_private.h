/*
 * DIO_init.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Aya farid
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
#define NULL ((void*)(0))
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7
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

#define INPUT	0
#define OUTPUT	1

#define HIGH      1
#define LOW       0
#define PULL_UP   1
#define FlOAT     0

#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0
#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)



#endif /* DIO_PRIVATE_H_ */
