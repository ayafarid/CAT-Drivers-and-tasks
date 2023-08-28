/*
 * LCD_prog.c
 *
 *  Created on: Jun 19, 2023
 *      Author: Aya farid
 */
#include "../../Services/STD_types.h"
#include "../../Services/errorState.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LCD_config.h"
#include "LCD_private.h"
#include "util/delay.h"

ES_t LCD_enuInit(void){
	ES_t Local_enuErrorState=ES_NOK;
	DIO_enuSetPinDirection(RS_PORT,RS_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RW_PORT,RW_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(EN_PORT,EN_PIN,DIO_u8OUTPUT);

	DIO_enuSetPinDirection(D7_PORT,D7_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D6_PORT,D6_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D5_PORT,D5_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D4_PORT,D4_PIN,DIO_u8OUTPUT);
	_delay_ms(35);

#if LCD_MODE == _8_BIT
	DIO_enuSetPinDirection(D3_PORT,D3_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D2_PORT,D2_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D1_PORT,D1_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D0_PORT,D0_PIN,DIO_u8OUTPUT);
	LCD_inStaticSendCommand(0x38);
#elif LCD_MODE == _4_BIT
	LCD_inStaticSendCommand(0x28);
#endif
	_delay_ms(1);
	LCD_inStaticSendCommand(0x0f);
	_delay_ms(1);
	LCD_inStaticSendCommand(0x01);
	_delay_ms(2);
	LCD_inStaticSendCommand(0x06);
	return Local_enuErrorState;
}
ES_t LCD_enuDisplayChar(u8 Copy_u8Data){
	ES_t Local_enuErrorState=ES_NOK;
	DIO_enuSetPinValue(RS_PORT,RS_PIN,HIGH);
	LCD_vidLatch(Copy_u8Data);
	return Local_enuErrorState;
}
ES_t LCD_enuSendCommand(u8 Copy_u8Commad){
	ES_t Local_enuErrorState=ES_NOK;
	DIO_enuSetPinValue(RS_PORT,RS_PIN,LOW);
	LCD_vidLatch(Copy_u8Commad);
	return Local_enuErrorState;
}
static void LCD_vidLatch(u8 Copy_u8Data){
	DIO_enuSetPinValue(RW_PORT,RW_PIN,LOW);
	DIO_enuSetPinValue(EN_PORT,EN_PIN,LOW);

	DIO_enuSetPinValue(D7_PORT,D7_PIN,((Copy_u8Data>>7)&1));
	DIO_enuSetPinValue(D6_PORT,D6_PIN,((Copy_u8Data>>6)&1));
	DIO_enuSetPinValue(D5_PORT,D5_PIN,((Copy_u8Data>>5)&1));
	DIO_enuSetPinValue(D4_PORT,D4_PIN,((Copy_u8Data>>4)&1));
#if LCD_MODE == _8_BIT
	DIO_enuSetPinValue(D3_PORT,D3_PIN,((Copy_u8Data>>3)&1));
	DIO_enuSetPinValue(D2_PORT,D2_PIN,((Copy_u8Data>>2)&1));
	DIO_enuSetPinValue(D1_PORT,D1_PIN,((Copy_u8Data>>1)&1));
	DIO_enuSetPinValue(D0_PORT,D0_PIN,((Copy_u8Data>>0)&1));
#elif LCD_MODE == _4_BIT

#endif

	DIO_enuSetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT,EN_PIN,LOW);
}
void LCD_Clear(void)
{
	LCD_enuSendCommand(0x01);						// send clear command to the LCD
}
void LCD_Line_Column(unsigned char line , unsigned char column)
{
	if (line == 1 && column >= 1 && column <= 16)
	{
		LCD_enuSendCommand( 0x80 | (0x00 +     column - 1 ) );			// move AC to line 1 , column's position
	}
	else if (line == 2 && column >= 1 && column <= 16)
	{
		LCD_enuSendCommand( 0x80 | (0x40 +     column - 1 ) );			// move AC to line 2 , column's position
	}
}
static inline void LCD_inStaticSendCommand(u8 Copy_u8Commad){
	DIO_enuSetPinValue(RS_PORT,RS_PIN,LOW);
	DIO_enuSetPinValue(RW_PORT,RW_PIN,LOW);
	DIO_enuSetPinValue(EN_PORT,EN_PIN,LOW);

	DIO_enuSetPinValue(D7_PORT,D7_PIN,((Copy_u8Commad>>7)&1));
	DIO_enuSetPinValue(D6_PORT,D6_PIN,((Copy_u8Commad>>6)&1));
	DIO_enuSetPinValue(D5_PORT,D5_PIN,((Copy_u8Commad>>5)&1));
	DIO_enuSetPinValue(D4_PORT,D4_PIN,((Copy_u8Commad>>4)&1));
	DIO_enuSetPinValue(D3_PORT,D3_PIN,((Copy_u8Commad>>3)&1));
	DIO_enuSetPinValue(D2_PORT,D2_PIN,((Copy_u8Commad>>2)&1));
	DIO_enuSetPinValue(D1_PORT,D1_PIN,((Copy_u8Commad>>1)&1));
	DIO_enuSetPinValue(D0_PORT,D0_PIN,((Copy_u8Commad>>0)&1));

	DIO_enuSetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT,EN_PIN,LOW);
}
ES_t LCD_enuDisplayExtraCGROMData(u8 Copy_u8AData[],u8 Copy_u8NumberOfChar,u8 Copy_u8Entry,u8 returnPosition){
	ES_t Local_enuErrorState=ES_NOK;
	    if(Copy_u8NumberOfChar<=8){
		LCD_inStaticSendCommand(0x40);
		DIO_enuSetPinValue(RS_PORT,RS_PIN,HIGH);
		for(u8 i=0;i<Copy_u8NumberOfChar*8;i++){
			LCD_vidLatch(Copy_u8AData[i]);
		}
		if(Copy_u8Entry==0x04){
			LCD_inStaticSendCommand(returnPosition);
			LCD_inStaticSendCommand(Copy_u8Entry);
		}else if(Copy_u8Entry==0x06){
			LCD_inStaticSendCommand(returnPosition);
			LCD_inStaticSendCommand(Copy_u8Entry);
		}
		for(int i=0;i<Copy_u8NumberOfChar;i++){
			DIO_enuSetPinValue(RS_PORT,RS_PIN,HIGH);
			LCD_vidLatch(i);
		}
		Local_enuErrorState=ES_OK;
	}else{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}
ES_t LCD_enuDisplayIntegerNum(s32 Copy_s32Num)
{
	ES_t Local_enuErrorState = ES_NOK;

	s32 Local_s32Reverse=0;
	u8 Local_u8Remainder=0 , Local_u8NumDigit=0;

	if(Copy_s32Num <0)
	{
		DIO_enuSetPinValue(RS_PORT , RS_PIN , HIGH);
		LCD_vidLatch('-');
		Copy_s32Num *= -1 ;
	}
	if(Copy_s32Num!=0)
	{
	while (Copy_s32Num)
	{
		Local_u8Remainder = Copy_s32Num % 10;
		Local_s32Reverse = Local_s32Reverse * 10 + Local_u8Remainder;
		Copy_s32Num /=10;
		Local_u8NumDigit ++;
	}

	while (Local_u8NumDigit)
	{
		Local_u8Remainder = Local_s32Reverse % 10;
		DIO_enuSetPinValue(RS_PORT , RS_PIN , HIGH);
		LCD_vidLatch(Local_u8Remainder + '0');
		Local_s32Reverse /= 10;
		Local_u8NumDigit --;
	}
	}
	else
	{
		LCD_vidLatch('0');
	}
	return Local_enuErrorState;
}
