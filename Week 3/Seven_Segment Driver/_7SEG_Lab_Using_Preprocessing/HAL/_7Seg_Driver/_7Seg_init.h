/*
 * _7Seg_init.h
 *
 *  Created on: May 4, 2023
 *      Author: Aya farid
 */

#ifndef HAL__7SEG_DRIVER__7SEG_INIT_H_
#define HAL__7SEG_DRIVER__7SEG_INIT_H_
#define NOT_CONNECTED   10
#define COMMON_ANODE    0
#define COMMON_CATHOD   1
ES_t _7Seg_enuInit();
ES_t _7Seg_enuDispayNumber(u8 Copy_u8PNummber);
ES_t _7Seg_enuClearNumber(u8 Copy_u8PNummber);
ES_t _7Seg_enuSetDot();
ES_t _7Seg_enuClearDot();
ES_t _7Seg_enuEnableCommon();
ES_t _7Seg_enuDisableCommon();

#endif /* HAL__7SEG_DRIVER__7SEG_INIT_H_ */
