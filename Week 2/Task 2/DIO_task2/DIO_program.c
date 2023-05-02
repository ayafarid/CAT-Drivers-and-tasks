/*
 * DIO_prog.c
 *
 *  Created on: Apr 29, 2023
 *      Author: Aya farid
 */

#ifndef DIO_PROG_C_
#define DIO_PROG_C_
#include "DIO_errorstae.h"
#include "STD_types.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "STD_MATH.h"
//Port operations
ES_t DIO_enInit(void)
{
    ES_t Local_enuErrorState=ES_OK;
    DDRA = Conc(PA_PIN7_DIR,PA_PIN6_DIR,PA_PIN5_DIR,PA_PIN4_DIR,PA_PIN3_DIR,PA_PIN2_DIR,PA_PIN1_DIR,PA_PIN0_DIR);
    DDRB = Conc(PB_PIN7_DIR,PB_PIN6_DIR,PB_PIN5_DIR,PB_PIN4_DIR,PB_PIN3_DIR,PB_PIN2_DIR,PB_PIN1_DIR,PB_PIN0_DIR);
    DDRC = Conc(PC_PIN7_DIR,PC_PIN6_DIR,PC_PIN5_DIR,PC_PIN4_DIR,PC_PIN3_DIR,PC_PIN2_DIR,PC_PIN1_DIR,PC_PIN0_DIR);
    DDRD = Conc(PD_PIN7_DIR,PD_PIN6_DIR,PD_PIN5_DIR,PD_PIN4_DIR,PD_PIN3_DIR,PD_PIN2_DIR,PD_PIN1_DIR,PD_PIN0_DIR);
    PORTA = Conc(PA_PIN7_VALUE,PA_PIN6_VALUE,PA_PIN5_VALUE,PA_PIN4_VALUE,PA_PIN3_VALUE,PA_PIN2_VALUE,PA_PIN1_VALUE,PA_PIN0_VALUE);
    PORTB = Conc(PB_PIN7_VALUE,PB_PIN6_VALUE,PB_PIN5_VALUE,PB_PIN4_VALUE,PB_PIN3_VALUE,PB_PIN2_VALUE,PB_PIN1_VALUE,PB_PIN0_VALUE);
    PORTC = Conc(PC_PIN7_VALUE,PC_PIN6_VALUE,PC_PIN5_VALUE,PC_PIN4_VALUE,PC_PIN3_VALUE,PC_PIN2_VALUE,PC_PIN1_VALUE,PC_PIN0_VALUE);
    PORTB = Conc(PB_PIN7_VALUE,PB_PIN6_VALUE,PB_PIN5_VALUE,PB_PIN4_VALUE,PB_PIN3_VALUE,PB_PIN2_VALUE,PB_PIN1_VALUE,PB_PIN0_VALUE);

    return Local_enuErrorState;
}
ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8Value)
{
    ES_t Local_enuErrorState=ES_OK;
    switch(Copy_u8PortID)
    {
    case DIO_PORTA:
        DDRA=Copy_u8Value;
        break;
    case DIO_PORTB:
        DDRB=Copy_u8Value;
        break;
    case DIO_PORTC:
        DDRC=Copy_u8Value;
        break;
    case DIO_PORTD:
        DDRD=Copy_u8Value;
        break;
    default:
        Local_enuErrorState=ES_OUT_OF_RANGE;
    }
    return Local_enuErrorState;
}
ES_t DIO_enuSetPortValue(u8 Copy_u8PortID,u8 Copy_u8Value)
{
    ES_t Local_enuErrorState=ES_OK;
    switch(Copy_u8PortID)
    {
    case DIO_PORTA:
        PORTA=Copy_u8Value;
        break;
    case DIO_PORTB:
        PORTB=Copy_u8Value;
        break;
    case DIO_PORTC:
        PORTC=Copy_u8Value;
        break;
    case DIO_PORTD:
        PORTD=Copy_u8Value;
        break;
    default:
        Local_enuErrorState=ES_OUT_OF_RANGE;
    }
    return Local_enuErrorState;
}
ES_t DIO_enutogglePort(u8 Copy_u8PortID)
{
    ES_t Local_enuErrorState=ES_OK;
    switch(Copy_u8PortID)
    {
    case DIO_PORTA:
        PORTA=~PORTA;
        break;
    case DIO_PORTB:
        PORTB=~PORTB;
        break;
    case DIO_PORTC:
        PORTC=~PORTC;
        break;
    case DIO_PORTD:
        PORTD=~PORTD;
        break;
    default:
        Local_enuErrorState=ES_OUT_OF_RANGE;
    }
    return Local_enuErrorState;
}
ES_t DIO_enuGetPortValue(u8 Copy_u8PortID,u8 * Copy_pu8Value)
{
    ES_t Local_enuErrorState=ES_OK;
    if(Copy_pu8Value!=NULL)
    {
        switch(Copy_u8PortID)
        {
        case DIO_PORTA:
            *Copy_pu8Value=PINA;
            break;
        case DIO_PORTB:
            *Copy_pu8Value=PINB;
            break;
        case DIO_PORTC:
            *Copy_pu8Value=PINC;
            break;
        case DIO_PORTD:
            *Copy_pu8Value=PIND;
            break;
        default:
            Local_enuErrorState=ES_OUT_OF_RANGE;
        }
    }
    else
    {
        Local_enuErrorState=ES_NULL_POINTER;
    }
    return Local_enuErrorState;
}
//Pin Operations
ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8BitNumber,u8 Copy_u8Value)
{
    ES_t Local_enuErrorState=ES_OK;
    // To unuse if and else use that code
    /*
     * DDRA&=~(1<<Copy_u8BitNumber);
     * DDRB|=(1<<Copy_u8BitNumber);
     */
    if(Copy_u8Value==OUTPUT)
    {
        switch(Copy_u8PortID)
        {
        case DIO_PORTA:
            SET_BIT(DDRA,Copy_u8BitNumber);
            break;
        case DIO_PORTB:
            SET_BIT(DDRB,Copy_u8BitNumber);
            break;
        case DIO_PORTC:
            SET_BIT(DDRC,Copy_u8BitNumber);
            break;
        case DIO_PORTD:
            SET_BIT(DDRD,Copy_u8BitNumber);
            break;
        }
    }
    else if(Copy_u8Value==OUTPUT)
    {
        switch(Copy_u8PortID)
        {
        case DIO_PORTA:
            CLEAR_BIT(DDRA,Copy_u8BitNumber);
            break;
        case DIO_PORTB:
            CLEAR_BIT(DDRB,Copy_u8BitNumber);
            break;
        case DIO_PORTC:
            CLEAR_BIT(DDRC,Copy_u8BitNumber);
            break;
        case DIO_PORTD:
            CLEAR_BIT(DDRD,Copy_u8BitNumber);
            break;
        }
    }
    else
    {
        Local_enuErrorState=ES_OUT_OF_RANGE;
    }
    return Local_enuErrorState;
}
ES_t DIO_enuSetPinValue(u8 Copy_u8PortID,u8 Copy_u8BitNumber,u8 Copy_u8Value)
{
    ES_t Local_enuErrorState=ES_OK;
    if(Copy_u8PortID<=PORTD&&Copy_u8BitNumber<=DIO_PIN7)
    {
        if(Copy_u8Value==HIGH)
        {
            switch(Copy_u8PortID)
            {
            case DIO_PORTA:
                SET_BIT(PORTA,Copy_u8BitNumber);
                break;
            case DIO_PORTB:
                SET_BIT(PORTB,Copy_u8BitNumber);
                break;
            case DIO_PORTC:
                SET_BIT(PORTC,Copy_u8BitNumber);
                break;
            case DIO_PORTD:
                SET_BIT(PORTD,Copy_u8BitNumber);
                break;
            }
        }
        else
        {
            switch(Copy_u8PortID)
            {
            case DIO_PORTA:
                CLEAR_BIT(PORTA,Copy_u8BitNumber);
                break;
            case DIO_PORTB:
                CLEAR_BIT(PORTB,Copy_u8BitNumber);
                break;
            case DIO_PORTC:
                CLEAR_BIT(PORTC,Copy_u8BitNumber);
                break;
            case DIO_PORTD:
                CLEAR_BIT(PORTD,Copy_u8BitNumber);
                break;
            }
        }
    }
    else
    {
        Local_enuErrorState=ES_OUT_OF_RANGE;
    }
    return Local_enuErrorState;
}
ES_t DIO_enutogglePinr(u8 Copy_u8PortID,u8 Copy_u8BitNumber)
{
    ES_t Local_enuErrorState=ES_OK;
    if(Copy_u8PortID<=PORTD&&Copy_u8BitNumber<=DIO_PIN7)
    {
        switch(Copy_u8PortID)
        {
        case DIO_PORTA:
            PORTA^=(1<<Copy_u8BitNumber);
            break;
        case DIO_PORTB:
            PORTB^=(1<<Copy_u8BitNumber);
            break;
        case DIO_PORTC:
            PORTC^=(1<<Copy_u8BitNumber);
            break;
        case DIO_PORTD:
            PORTD^=(1<<Copy_u8BitNumber);
            break;
        }
    }
    else
    {
        Local_enuErrorState=ES_OUT_OF_RANGE;
    }
    return Local_enuErrorState;
}
u8 DIO_enuGetPinValue(u8 Copy_u8PortID,u8 Copy_u8BitNumber)
{
    u8 b=0;
    switch(Copy_u8PortID)
    {
    case DIO_PORTA:
        b= GET_BIT(PINA,Copy_u8BitNumber);
        break;
    case DIO_PORTB:
        b= GET_BIT(PINB,Copy_u8BitNumber);
        break;
    case DIO_PORTC:
        b= GET_BIT(PINC,Copy_u8BitNumber);
        break;
    case DIO_PORTD:
        b= GET_BIT(PIND,Copy_u8BitNumber);
        break;
    }
    return b;
}
#endif /* DIO_PROG_C_ */
