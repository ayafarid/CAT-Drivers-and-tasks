/*
 * LCD_init.h
 *
 *  Created on: Jun 19, 2023
 *      Author: Aya farid
 */

#ifndef HAL_LCD_LCD_INIT_H_
#define HAL_LCD_LCD_INIT_H_
#define Direction_Increment   0
#define Direction_Decrement   1
ES_t LCD_enuInit(void);
ES_t LCD_enuDisplayChar(u8 Copy_u8Data);
ES_t LCD_enuSendCommand(u8 Copy_u8Commad);
ES_t LCD_enuDisplayExtraCGROMData(u8 Copy_u8AData[],u8 Copy_u8NumberOfChar,u8 Copy_u8Entry,u8 returnPosition);
ES_t LCD_enuDisplayIntegerNum(s32 Copy_s32Num);
#endif /* HAL_LCD_LCD_INIT_H_ */
