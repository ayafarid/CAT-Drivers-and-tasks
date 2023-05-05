/*
 * _7Seg_Program.c
 *
 *  Created on: May 4, 2023
 *      Author: Aya farid
 */
#include "_7Seg_Config.h"
#include "_7Seg_pivate.h"
#include "../../MCAL/DIO/DIO_interface.h"
ES_t _7Seg_enuInit(){
	ES_t Local_errorState=ES_OK;
	u32 Local_u32Chek;
	Local_u32Chek |= ( DIO_enuSetPinDirection(_7Seg_APORT,_7Seg_APIN,OUTPUT) << 0 );
	Local_u32Chek |= ( DIO_enuSetPinDirection(_7Seg_BPORT,_7Seg_BPIN,OUTPUT) << 3 );
	Local_u32Chek |= ( DIO_enuSetPinDirection(_7Seg_CPORT,_7Seg_CPIN,OUTPUT) << 6 );
	Local_u32Chek |= ( DIO_enuSetPinDirection(_7Seg_DPORT,_7Seg_DPIN,OUTPUT) << 9 );
	Local_u32Chek |= ( DIO_enuSetPinDirection(_7Seg_EPORT,_7Seg_EPIN,OUTPUT) << 12);
	Local_u32Chek |= ( DIO_enuSetPinDirection(_7Seg_FPORT,_7Seg_FPIN,OUTPUT) << 15);
	Local_u32Chek |= ( (DIO_enuSetPinDirection(_7Seg_GPORT,_7Seg_GPIN,OUTPUT) << 9)<<9);
#if _7Seg_CMN<=DIO_PIN7 && _7Seg_CMN_PORT<=DIO_PORTD
	DIO_enuSetPinDirection(_7Seg_CMN_PORT,_7Seg_CMN,OUTPUT);
#elif _7Seg_CMN==NOT_CONNECTED

#else
#error "Common pin value or Common port value not valid"
#endif

#if _7Seg_DOt<=DIO_PIN7 && _7Seg_DOT_PORT<=DIO_PORTD
	DIO_enuSetPinDirection(_7Seg_DOT_PORT,_7Seg_DOt,OUTPUT);
#elif _7Seg_DOt==NOT_CONNECTED || _7Seg_DOT_PORT==NOT_CONNECTED

#else
#error "Common pin value or Common port value not valid"
#endif
	u8 local_u8Iterator;
	for(local_u8Iterator=0;local_u8Iterator<sizeof(Local_u32Chek)*8;local_u8Iterator+=3){
		if((((Local_u32Chek)>>local_u8Iterator)&7)!=ES_OK){
			return Local_errorState=ES_NOK;
		}
	}
	return Local_errorState;
}
ES_t _7Seg_enuDispayNumber(u8 Copy_u8PNummber){
	ES_t Local_errorState=ES_OK;
#if _7Seg_TYpe == COMMON_CATHOD
	DIO_enuSetPinValue(_7Seg_APORT,_7Seg_APIN,((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>0)&1));
	DIO_enuSetPinValue(_7Seg_BPORT,_7Seg_BPIN,((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>1)&1));
	DIO_enuSetPinValue(_7Seg_CPORT,_7Seg_CPIN,((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>2)&1));
	DIO_enuSetPinValue(_7Seg_DPORT,_7Seg_DPIN,((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>3)&1));
	DIO_enuSetPinValue(_7Seg_EPORT,_7Seg_EPIN,((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>4)&1));
	DIO_enuSetPinValue(_7Seg_FPORT,_7Seg_FPIN,((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>5)&1));
	DIO_enuSetPinValue(_7Seg_FPORT,_7Seg_GPIN,((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>6)&1));
#elif _7Seg_TYpe==COMMON_ANODE
	DIO_enuSetPinValue(_7Seg_APORT,_7Seg_APIN,!((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>0)&1));
	DIO_enuSetPinValue(_7Seg_BPORT,_7Seg_BPIN,!((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>1)&1));
	DIO_enuSetPinValue(_7Seg_CPORT,_7Seg_CPIN,!((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>2)&1));
	DIO_enuSetPinValue(_7Seg_DPORT,_7Seg_DPIN,!((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>3)&1));
	DIO_enuSetPinValue(_7Seg_EPORT,_7Seg_EPIN,!((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>4)&1));
	DIO_enuSetPinValue(_7Seg_FPORT,_7Seg_FPIN,!((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>5)&1));
	DIO_enuSetPinValue(_7Seg_GPORT,_7Seg_GPIN,!((_7Seg_Au8sevenSegNumber[Copy_u8PNummber]>>6)&1));
#else
#error "Wrong 7seg type"
#endif
	return Local_errorState;
}
ES_t _7Seg_enuClearNumber(u8 Copy_u8PNummber){
	ES_t Local_errorState=ES_OK;
#if _7Seg_TYpe == COMMON_CATHOD
	DIO_enuSetPinValue(_7Seg_APORT,_7Seg_APIN,LOW);
	DIO_enuSetPinValue(_7Seg_BPORT,_7Seg_BPIN,LOW);
	DIO_enuSetPinValue(_7Seg_CPORT,_7Seg_CPIN,LOW);
	DIO_enuSetPinValue(_7Seg_DPORT,_7Seg_DPIN,LOW);
	DIO_enuSetPinValue(_7Seg_EPORT,_7Seg_EPIN,LOW);
	DIO_enuSetPinValue(_7Seg_FPORT,_7Seg_FPIN,LOW);
	DIO_enuSetPinValue(_7Seg_FPORT,_7Seg_GPIN,LOW);
#elif _7Seg_TYpe==COMMON_ANODE
	DIO_enuSetPinValue(_7Seg_APORT,_7Seg_APIN,HIGH);
	DIO_enuSetPinValue(_7Seg_BPORT,_7Seg_BPIN,HIGH);
	DIO_enuSetPinValue(_7Seg_CPORT,_7Seg_CPIN,HIGH);
	DIO_enuSetPinValue(_7Seg_DPORT,_7Seg_DPIN,HIGH);
	DIO_enuSetPinValue(_7Seg_EPORT,_7Seg_EPIN,HIGH);
	DIO_enuSetPinValue(_7Seg_FPORT,_7Seg_FPIN,HIGH);
	DIO_enuSetPinValue(_7Seg_GPORT,_7Seg_GPIN,HIGH);
#else
#error "Wrong 7seg type"
#endif
	return Local_errorState;
}
ES_t _7Seg_enuSetDot(){
	ES_t Local_errorState=ES_OK;
#if _7Seg_DOT_PORT<=DIO_PORTD && _7Seg_DOt<=DIO_PIN7
    #if _7Seg_TYpe==COMMON_CATHOD
	     DIO_enuSetPinValue(_7Seg_DOT_PORT,_7Seg_DOt,HIGH);
    #elif _7Seg_TYpe==COMMON_ANODE
	     DIO_enuSetPinValue(_7Seg_DOT_PORT,_7Seg_DOt,LOW);
    #else
    #error "7 Segment type value is invalid"
    #endif
#else
#error "DOT port or pin value is invalid"
#endif
	return Local_errorState;
}
ES_t _7Seg_enuClearDot(){
	ES_t Local_errorState=ES_OK;
#if _7Seg_DOT_PORT<=DIO_PORTD && _7Seg_DOt<=DIO_PIN7
    #if _7Seg_TYpe==COMMON_CATHOD
	     DIO_enuSetPinValue(_7Seg_DOT_PORT,_7Seg_DOt,LOW);
    #elif _7Seg_TYpe==COMMON_ANODE
	     DIO_enuSetPinValue(_7Seg_DOT_PORT,_7Seg_DOt,HIGH);
    #else
    #error "7 Segment type value is invalid"
    #endif
#else
#error "DOT port or pin value is invalid"
#endif
	return Local_errorState;
}
ES_t _7Seg_enuEnableCommon(){
	ES_t Local_errorState=ES_OK;
#if _7Seg_CMN_PORT<=DIO_PORTD && _7Seg_CMN<=DIO_PIN7
    #if _7Seg_TYpe==COMMON_CATHOD
	     DIO_enuSetPinValue(_7Seg_CMN_PORT,_7Seg_CMN,HIGH);
    #elif _7Seg_TYpe==COMMON_ANODE
	     DIO_enuSetPinValue(_7Seg_CMN_PORT,_7Seg_CMN,LOW);
    #else
    #error "7 Segment type value is invalid"
    #endif
#else
#error "DOT port or pin value is invalid"
#endif
	return Local_errorState;
}
ES_t _7Seg_enuDisableCommon(){
	ES_t Local_errorState=ES_OK;
#if _7Seg_CMN_PORT<=DIO_PORTD && _7Seg_CMN<=DIO_PIN7
    #if _7Seg_TYpe==COMMON_CATHOD
	     DIO_enuSetPinValue(_7Seg_CMN_PORT,_7Seg_CMN,LOW);
    #elif _7Seg_TYpe==COMMON_ANODE
	     DIO_enuSetPinValue(_7Seg_CMN_PORT,_7Seg_CMN,HIGH);
    #else
    #error "7 Segment type value is invalid"
    #endif
#else
#error "DOT port or pin value is invalid"
#endif
	return Local_errorState;
}
