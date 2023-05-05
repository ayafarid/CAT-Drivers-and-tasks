/*
 * sevSeg_init.h
 *
 *  Created on: May 5, 2023
 *      Author: Aya farid
 */
#include "sevSeg_config.h"
#ifndef HAL_SEVEN_SEGMENT_DRIVER_SEVSEG_INIT_H_
#define HAL_SEVEN_SEGMENT_DRIVER_SEVSEG_INIT_H_
ES_t _7Seg_enuInit(SEV_SEG_t * Copy_PStrASeg);
ES_t _7Seg_enuDispayNumber(u8 Copy_u8SegID,u8 Copy_u8Num);
ES_t _7Seg_enuClearNumber(u8 Copy_u8SegID);
ES_t _7Seg_enuSetDot(u8 Copy_u8SegID);
ES_t _7Seg_enuClearDot(u8 Copy_u8SegID);
ES_t _7Seg_enuEnableCommon(u8 Copy_u8SegID);
ES_t _7Seg_enuDisableCommon(u8 Copy_u8SegID);

#endif /* HAL_SEVEN_SEGMENT_DRIVER_SEVSEG_INIT_H_ */
