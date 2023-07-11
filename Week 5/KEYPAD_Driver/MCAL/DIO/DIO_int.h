/*
 * DIO_interface.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Aya farid
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3

#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7

#define HIGH		1
#define LOW		0

#define DIO_u8INPUT		0
#define DIO_u8OUTPUT	1

#define DIO_u8FLOAT		0
#define DIO_u8PULL_UP	1

ES_t DIO_enuInit(void);

ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8Value);

ES_t DIO_enuSetPortValue(u8 Copy_u8PortID , u8 Copy_u8Value);

ES_t DIO_enuTogPortValue(u8 Copy_u8PortID);

ES_t DIO_enuGetPortValue(u8 Copy_u8PortID , u8 * Copy_pu8Value);

ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID ,u8 Copy_u8PinID , u8 Copy_u8Value);

ES_t DIO_enuSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value);

ES_t DIO_enuTogPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID );

ES_t DIO_enuGetPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID , u8 * Copy_pu8Value);

#endif /* DIO_INT_H_ */
