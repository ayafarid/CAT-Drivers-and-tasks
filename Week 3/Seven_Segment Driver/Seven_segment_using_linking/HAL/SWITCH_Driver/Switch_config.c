/*
 * Switch_config.c
 *
 *  Created on: May 3, 2023
 *      Author: Aya farid
 */
#include "../../Services/errorState.h"
#include "Switch_config.h"
#include "../../MCAL/DIO/DIO_interface.h"

SW_t switch_arrayOfSruct[SW_NUM]={{DIO_PORTA,DIO_PIN0,FlOAT},{DIO_PORTA,DIO_PIN1,PULL_UP}};
