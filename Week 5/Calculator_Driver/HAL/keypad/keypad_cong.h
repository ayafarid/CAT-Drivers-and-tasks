/*
 * keypad_cong.h
 *
 *  Created on: Jul 11, 2023
 *      Author: Aya farid
 */

#ifndef HAL_KEYPAD_KEYPAD_CONG_H_
#define HAL_KEYPAD_KEYPAD_CONG_H_

#define CLM_NUM  4
#define ROW_NUM  4

#define R0_PORT     DIO_PORTB
#define R1_PORT     DIO_PORTB
#define R2_PORT     DIO_PORTB
#define R3_PORT     DIO_PORTB
#define C0_PORT     DIO_PORTB
#define C1_PORT     DIO_PORTB
#define C2_PORT     DIO_PORTB
#define C3_PORT     DIO_PORTB

#define R0_PIN      DIO_PIN4
#define R1_PIN      DIO_PIN5
#define R2_PIN      DIO_PIN6
#define R3_PIN      DIO_PIN7
#define C0_PIN      DIO_PIN0
#define C1_PIN      DIO_PIN1
#define C2_PIN      DIO_PIN2
#define C3_PIN      DIO_PIN3

#define COL_START					0
#define COL_FIN						4
#define ROW_START					4
#define ROW_FIN						8

#define PRESSED						0
#endif /* HAL_KEYPAD_KEYPAD_CONG_H_ */
