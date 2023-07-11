/*
 * LCD_private.h
 *
 *  Created on: Jun 19, 2023
 *      Author: Aya farid
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define _8_BIT      51
#define _4_BIT      9

static inline void LCD_inStaticSendCommand(u8 Copy_u8Commad);
static void LCD_vidLatch(u8 Copy_u8Data);

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
