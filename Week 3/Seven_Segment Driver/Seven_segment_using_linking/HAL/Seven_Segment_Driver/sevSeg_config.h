/*
 * sevSeg_config.h
 *
 *  Created on: May 5, 2023
 *      Author: Aya farid
 */

#ifndef HAL_SEVEN_SEGMENT_DRIVER_SEVSEG_CONFIG_H_
#define HAL_SEVEN_SEGMENT_DRIVER_SEVSEG_CONFIG_H_

#define SEVEN_SEG 1
#define NOT_CONNECTED   10
#define COMMON_ANODE    0
#define COMMON_CATHOD   1
typedef struct{
	u8 Seven_Seg_APIN;
	u8 Seven_Seg_APORT;

	u8 Seven_Seg_BPIN;
	u8 Seven_Seg_BPORT;

	u8 Seven_Seg_CPIN;
	u8 Seven_Seg_CPORT;

	u8 Seven_Seg_DPIN;
	u8 Seven_Seg_DPORT;

	u8 Seven_Seg_EPIN;
	u8 Seven_Seg_EPORT;

	u8 Seven_Seg_FPIN;
	u8 Seven_Seg_FPORT;

	u8 Seven_Seg_GPIN;
	u8 Seven_Seg_GPORT;

	u8 Seven_Seg_CMN_PIN;
	u8 Seven_Seg_CMN_PORT;

	u8 Seven_Seg_DOT_PIN;
	u8 Seven_Seg_DOT_PORT;

	u8 Seven_Seg_type;
}SEV_SEG_t;

#endif /* HAL_SEVEN_SEGMENT_DRIVER_SEVSEG_CONFIG_H_ */
