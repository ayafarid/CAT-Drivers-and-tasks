/*
 * LCD_init.h
 *
 *  Created on: Jun 19, 2023
 *      Author: Aya farid
 */

#ifndef HAL_LCD_LCD_INIT_H_
#define HAL_LCD_LCD_INIT_H_

ES_t LCD_enuInit(void);
ES_t LCD_enuDisplayChar(u8 Copy_u8Data);
ES_t LCD_enuSendCommand(u8 Copy_u8Commad);

#endif /* HAL_LCD_LCD_INIT_H_ */
