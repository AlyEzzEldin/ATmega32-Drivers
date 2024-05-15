/*
 * TIMER_config.h
 *
 *  Created on: 6 Oct 2023
 *      Author: Ali
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define Normal 0
#define PWM 1
#define CTC 2
#define FPWM 3

#define Normal 0
#define PWM_PC_8 1
#define PWM_PC_9 2
#define PWM_PC_10 3
#define CTC_OCR1A 4
#define FPWM_8 5
#define FPWM_9 6
#define FPWM_10 7
#define PWM_P_F_CORRECT_ICR1 8
#define PWM_P_F_CORRECT_OCR1A 9
#define PWM_PC_ICR1 10
#define PWM_PC_OCR1A 11
#define CTC_ICR1 12
#define RESERVED 13
#define FPWM_ICR1 14
#define FPWM_OCR1A 15

#define TMR0_MODE  Normal
#define TMR1_MODE Normal
#define TMR2_MODE Normal

#endif /* TIMER_CONFIG_H_ */
