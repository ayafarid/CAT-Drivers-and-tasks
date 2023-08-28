/*
 * LCD_init.h
 *
 *  Created on: Jun 19, 2023
 *      Author: Aya farid
 */

#ifndef HAL_LCD_LCD_INIT_H_
#define HAL_LCD_LCD_INIT_H_

#define LCD_CLEAR    0x01
ES_t LCD_enuInit(void);
void LCD_Clear(void);
ES_t LCD_enuDisplayChar(u8 Copy_u8Data);
ES_t LCD_enuSendCommand(u8 Copy_u8Commad);
<<<<<<<< HEAD:Week 5/Calculator_Driver/HAL/LCD/LCD_int.h
void LCD_Clear(void);
void LCD_Line_Column(unsigned char line , unsigned char column);
========
void LCD_String (char *str);
void LCD_Line_Column(unsigned char line , unsigned char column);

>>>>>>>> 1db1589be2f9dbf8c358d87807869f7397ae6192:Week 5/Calculator_TASK/HAL/LCD/LCD_int.h
#endif /* HAL_LCD_LCD_INIT_H_ */
