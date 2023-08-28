/*
 * LCD_config.h
 *
 *  Created on: Jun 19, 2023
 *      Author: Aya farid
 */
#include "../../MCAL/DIO/DIO_int.h"
#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

/* LCD MODE */
#define LCD_MODE  _8_BIT
/* Control Pins */
#define RS_PORT DIO_PORTA
#define RS_PIN DIO_PIN0

#define RW_PORT DIO_PORTA
#define RW_PIN DIO_PIN1

#define EN_PORT DIO_PORTA
#define EN_PIN DIO_PIN2
/* Data Pins */
#define D7_PORT DIO_PORTA
#define D7_PIN DIO_PIN3

#define D6_PORT DIO_PORTA
#define D6_PIN DIO_PIN4

#define D5_PORT DIO_PORTA
#define D5_PIN DIO_PIN5

#define D4_PORT DIO_PORTA
#define D4_PIN DIO_PIN6

#define D3_PORT DIO_PORTA
#define D3_PIN DIO_PIN7

#define D2_PORT DIO_PORTC
#define D2_PIN DIO_PIN0

#define D1_PORT DIO_PORTC
#define D1_PIN DIO_PIN1

#define D0_PORT DIO_PORTC
#define D0_PIN DIO_PIN2

#define Direction             Direction_Increment
#define Direction_Increment   0
#define Direction_Decrement   1
#endif /* HAL_LCD_LCD_CONFIG_H_ */
