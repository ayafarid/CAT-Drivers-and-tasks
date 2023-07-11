/*
 * DIO_config.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Aya farid
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
/*you can use INPUT or OUTPUT*/
#define PA_PIN0_DIR			OUTPUT
#define PA_PIN1_DIR			OUTPUT
#define PA_PIN2_DIR			OUTPUT
#define PA_PIN3_DIR			OUTPUT
#define PA_PIN4_DIR			OUTPUT
#define PA_PIN5_DIR			OUTPUT
#define PA_PIN6_DIR			OUTPUT
#define PA_PIN7_DIR			OUTPUT
/*10010110*/

#define PB_PIN0_DIR			OUTPUT
#define PB_PIN1_DIR			OUTPUT
#define PB_PIN2_DIR         OUTPUT
#define PB_PIN3_DIR         OUTPUT
#define PB_PIN4_DIR         INPUT
#define PB_PIN5_DIR         INPUT
#define PB_PIN6_DIR         INPUT
#define PB_PIN7_DIR         INPUT

#define PC_PIN0_DIR			OUTPUT
#define PC_PIN1_DIR			OUTPUT
#define PC_PIN2_DIR         OUTPUT
#define PC_PIN3_DIR         INPUT
#define PC_PIN4_DIR         OUTPUT
#define PC_PIN5_DIR         INPUT
#define PC_PIN6_DIR         INPUT
#define PC_PIN7_DIR         OUTPUT

#define PD_PIN0_DIR			INPUT
#define PD_PIN1_DIR			OUTPUT
#define PD_PIN2_DIR         OUTPUT
#define PD_PIN3_DIR         INPUT
#define PD_PIN4_DIR         OUTPUT
#define PD_PIN5_DIR         INPUT
#define PD_PIN6_DIR         INPUT
#define PD_PIN7_DIR         OUTPUT


#define PA_PIN0_VAL			HIGH
#define PA_PIN1_VAL			HIGH
#define PA_PIN2_VAL			HIGH
#define PA_PIN3_VAL			HIGH
#define PA_PIN4_VAL			HIGH
#define PA_PIN5_VAL			HIGH
#define PA_PIN6_VAL			HIGH
#define PA_PIN7_VAL			HIGH

// Port B values
#define PB_PIN0_VAL			HIGH
#define PB_PIN1_VAL			HIGH
#define PB_PIN2_VAL			HIGH
#define PB_PIN3_VAL			HIGH
#define PB_PIN4_VAL			PULL_UP
#define PB_PIN5_VAL			PULL_UP
#define PB_PIN6_VAL			PULL_UP
#define PB_PIN7_VAL			PULL_UP
// Port C values
#define PC_PIN0_VAL			HIGH
#define PC_PIN1_VAL			HIGH
#define PC_PIN2_VAL			HIGH
#define PC_PIN3_VAL			HIGH
#define PC_PIN4_VAL			HIGH
#define PC_PIN5_VAL			HIGH
#define PC_PIN6_VAL			HIGH
#define PC_PIN7_VAL			HIGH
// Port D values
#define PD_PIN0_VAL			HIGH
#define PD_PIN1_VAL			HIGH
#define PD_PIN2_VAL			HIGH
#define PD_PIN3_VAL			HIGH
#define PD_PIN4_VAL			HIGH
#define PD_PIN5_VAL			HIGH
#define PD_PIN6_VAL			HIGH
#define PD_PIN7_VAL			HIGH
#endif /* DIO_CONFIG_H_ */
