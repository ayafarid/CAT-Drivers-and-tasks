/*
 * DIO_interface.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Aya farid
 */
#include "../../Services/errorState.h"
#include "../../Services/STD_types.h"
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#define NULL ((void*)(0))

#define INPUT	0
#define OUTPUT	1

#define HIGH      1
#define LOW       0
#define PULL_UP   1
#define FlOAT     0

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
ES_t DIO_enInit(void);
//Port operations
ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8Value);
ES_t DIO_enuSetPortValue(u8 Copy_u8PortID,u8 Copy_u8Value);
ES_t DIO_enutogglePort(u8 Copy_u8PortID);
ES_t DIO_enuGetPortValue(u8 Copy_u8PortID,u8 * Copy_pu8Value);
//Pin Operations
ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8BitNumber,u8 Copy_u8Value);
ES_t DIO_enuSetPinValue(u8 Copy_u8PortID,u8 Copy_u8BitNumber,u8 Copy_u8Value);
ES_t DIO_enutogglePin(u8 Copy_u8PortID,u8 Copy_u8BitNumber);
ES_t DIO_enuGetPinValue(u8 Copy_u8PortID,u8 Copy_u8BitNumber);

#endif /* DIO_INTERFACE_H_ */
