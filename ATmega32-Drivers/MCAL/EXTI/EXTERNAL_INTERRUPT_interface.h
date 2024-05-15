/*
 * EXTERNAL_INTERRUPT_interface.h
 *
 *  Created on: 22 Sep 2023
 *      Author: Ali
 */

#ifndef EXTERNAL_INTERRUPT_INTERFACE_H_
#define EXTERNAL_INTERRUPT_INTERFACE_H_

#define LOW_LEVEL 0
#define IOC 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

#define EXTI0 0
#define EXTI1 1
#define EXTI2 2

void EXTERNAL_INTERRUPT_INIT(void);
void EXTERNAL_INTERRUPT_ENABLE(u8 INT_no);
void EXTERNAL_INTERRUPT_DISABLE(u8 INT_no);
void EXTERNAL_INTERRUPT_Set_MODE(u8 INT_no,u8 Mode);

void EXTERNAL_INTERRUPT_INT0_Set_Callback_Address(void (*PTR)(void));
void EXTERNAL_INTERRUPT_INT1_Set_Callback_Address(void (*PTR)(void));
void EXTERNAL_INTERRUPT_INT2_Set_Callback_Address(void (*PTR)(void));

#endif /* EXTERNAL_INTERRUPT_INTERFACE_H_ */
