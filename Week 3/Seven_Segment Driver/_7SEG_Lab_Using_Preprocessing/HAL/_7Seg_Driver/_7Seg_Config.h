/*
 * _7Seg_Config.h
 *
 *  Created on: May 4, 2023
 *      Author: Aya farid
 */
#include "../../MCAL/DIO/DIO_interface.h"
#include "_7Seg_init.h"
#ifndef HAL__7SEG_DRIVER__7SEG_CONFIG_H_
#define HAL__7SEG_DRIVER__7SEG_CONFIG_H_

#define _7Seg_APIN     DIO_PIN0
#define _7Seg_APORT    DIO_PORTA

#define _7Seg_BPIN     DIO_PIN1
#define _7Seg_BPORT    DIO_PORTA

#define _7Seg_CPIN     DIO_PIN2
#define _7Seg_CPORT    DIO_PORTA

#define _7Seg_DPIN     DIO_PIN3
#define _7Seg_DPORT    DIO_PORTA

#define _7Seg_EPIN     DIO_PIN4
#define _7Seg_EPORT    DIO_PORTA

#define _7Seg_FPIN     DIO_PIN5
#define _7Seg_FPORT    DIO_PORTA

#define _7Seg_GPIN     DIO_PIN6
#define _7Seg_GPORT    DIO_PORTA

#define _7Seg_CMN      DIO_PIN0
#define _7Seg_CMN_PORT DIO_PORTB

#define _7Seg_DOt      DIO_PIN7
#define _7Seg_DOT_PORT DIO_PORTA
#define _7Seg_TYpe     COMMON_CATHOD
#endif /* HAL__7SEG_DRIVER__7SEG_CONFIG_H_ */
