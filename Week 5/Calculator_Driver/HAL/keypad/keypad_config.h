//
// Created by kareem on 2/22/23.
//

#ifndef CLIONAVRTEST_KEYPAD_CONFIG_H
#define CLIONAVRTEST_KEYPAD_CONFIG_H

#define C1_PORT    DIO_PORTB
#define C1_PIN     DIO_PIN0
#define C2_PORT    DIO_PORTB
#define C2_PIN     DIO_PIN1
#define C3_PORT    DIO_PORTB
#define C3_PIN     DIO_PIN2
#define C4_PORT    DIO_PORTB
#define C4_PIN     DIO_PIN3

#define R1_PORT    DIO_PORTB
#define R1_PIN     DIO_PIN4
#define R2_PORT    DIO_PORTB
#define R2_PIN     DIO_PIN5
#define R3_PORT    DIO_PORTB
#define R3_PIN      DIO_PIN6
#define R4_PORT    DIO_PORTB
#define R4_PIN      DIO_PIN7

#define COLOMS_NUMBER 4

#define ROWS_NUMBER 4

u8 key_values[ROWS_NUMBER][COLOMS_NUMBER] = {{'7', '8', '9', '/'},
									{'4', '5', '6', 'X'},
									{'1', '2', '3', '-'},
									{'c', '0', '=', '+'}};






#endif //CLIONAVRTEST_KEYPAD_CONFIG_H
