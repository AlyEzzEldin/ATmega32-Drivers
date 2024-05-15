/*
 * TIMER_interface.h
 *
 *  Created on: 6 Oct 2023
 *      Author: Ali
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define FALLING_EDGE 2
#define RISING_EDGE 3

/************************************************************/

void TMR0_INIT(void);

void TMR0_OVF_INTERRUPT_ENABLE(void);
void TMR0_OVF_INTERRUPT_DISABLE(void);

void TMR0_CTC_INTERRUPT_ENABLE(void);
void TMR0_CTC_INTERRUPT_DISABLE(void);

void TMR0_OVF_Set_Callback_Address(void (*PTR)(void));
void TMR0_CTC_Set_Callback_Address(void (*PTR)(void));

void TMR0_Set_TCNT0_REGISTER(u8 value);
void TMR0_Set_OCR0_REGISTER(u8 value);

u8 TMR0_Get_TCNT0_REGISTER(void);
u8 TMR0_Get_OCR0_REGISTER(void);

/************************************************************/

void TMR1_INIT(void);

void TMR1_OVF_INTERRUPT_ENABLE(void);
void TMR1_OVF_INTERRUPT_DISABLE(void);

void TMR1_CTCA_INTERRUPT_ENABLE(void);
void TMR1_CTCA_INTERRUPT_DISABLE(void);

void TMR1_CTCB_INTERRUPT_ENABLE(void);
void TMR1_CTCB_INTERRUPT_DISABLE(void);

void TMR1_ICU_INTERRUPT_ENABLE(void);
void TMR1_ICU_INTERRUPT_DISABLE(void);

void TMR1_ICU_INTERRUPT_SET_EDGE(u8 edge);

void TMR1_OVF_Set_Callback_Address(void (*PTR)(void));
void TMR1_CTCA_Set_Callback_Address(void (*PTR)(void));
void TMR1_CTCB_Set_Callback_Address(void (*PTR)(void));
void TMR1_ICU_Set_Callback_Address(void (*PTR)(void));

void TMR1_Set_TCNT1_REGISTER(u8 value);
void TMR1_Set_OCR1A_REGISTER(u16 value);
void TMR1_Set_OCR1B_REGISTER(u8 value);
void TMR1_Set_ICR1_REGISTER(u8 value);

u8 TMR1_Get_TCNT1_REGISTER(void);
u8 TMR1_Get_OCR1A_REGISTER(void);
u8 TMR1_Get_OCR1B_REGISTER(void);
u8 TMR1_Get_ICR1_REGISTER(void);

void TMR1_Close_Timer(void);

/*
 * ELECTRONICS WINGS
 */


/************************************************************/

void TMR2_INIT(void);

void TMR2_OVF_INTERRUPT_ENABLE(void);
void TMR2_OVF_INTERRUPT_DISABLE(void);

void TMR2_CTC_INTERRUPT_ENABLE(void);
void TMR2_CTC_INTERRUPT_DISABLE(void);

void TMR2_OVF_Set_Callback_Address(void (*PTR)(void));
void TMR2_CTC_Set_Callback_Address(void (*PTR)(void));

void TMR2_Set_TCNT2_REGISTER(u8 value);
void TMR2_Set_OCR2_REGISTER(u8 value);

u8 TMR2_Get_TCNT2_REGISTER(void);
u8 TMR2_Get_OCR2_REGISTER(void);

/************************************************************/


#endif /* TIMER_INTERFACE_H_ */
