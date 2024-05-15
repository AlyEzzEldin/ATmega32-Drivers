/*
 * TIMER_program.c
 *
 *  Created on: 6 Oct 2023
 *      Author: Ali
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_register.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"

void (* TMR0_CTC_CALLBACK_PTR)(void) = NULL;
void (* TMR0_OVF_CALLBACK_PTR)(void) = NULL;

void (* TMR1_OVF_CALLBACK_PTR)(void) = NULL;
void (* TMR1_CTCA_CALLBACK_PTR)(void) = NULL;
void (* TMR1_CTCB_CALLBACK_PTR)(void) = NULL;
void (* TMR1_ICR_CALLBACK_PTR)(void) = NULL;

void (* TMR2_CTC_CALLBACK_PTR)(void) = NULL;
void (* TMR2_OVF_CALLBACK_PTR)(void) = NULL;




void TMR0_INIT(void)
{
	/*
	 * Select mode
	 */

#if TMR0_MODE == Normal
	Clr_Bit(TCCR0_register,WGM00);
	Clr_Bit(TCCR0_register,WGM01);

#elif TMR0_MODE == PWM
	Set_Bit(TCCR0_register,WGM00);
	Clr_Bit(TCCR0_register,WGM01);

#elif TMR0_MODE == CTC
	Clr_Bit(TCCR0_register,WGM00);
	Set_Bit(TCCR0_register,WGM01);

#elif TMR0_MODE == FPWM
	Set_Bit(TCCR0_register,WGM00);
	Set_Bit(TCCR0_register,WGM01);
#endif

	/*
	 *Output Mode
	 */

	Clr_Bit(TCCR0_register,COM00);
	Clr_Bit(TCCR0_register,COM01);


	/*
	 * Select prescaller = 8
	 */

	Clr_Bit(TCCR0_register,CS00);
	Set_Bit(TCCR0_register,CS01);
	Clr_Bit(TCCR0_register,CS02);

}

void TMR0_OVF_INTERRUPT_ENABLE(void)
{
	Set_Bit(TIMSK_register,TOIE0);
}
void TMR0_OVF_INTERRUPT_DISABLE(void)
{
	Clr_Bit(TIMSK_register,TOIE0);
}

void TMR0_CTC_INTERRUPT_ENABLE(void)
{
	Set_Bit(TIMSK_register,OCIE0);
}
void TMR0_CTC_INTERRUPT_DISABLE(void)
{
	Clr_Bit(TIMSK_register,OCIE0);
}

void TMR0_OVF_Set_Callback_Address(void (*PTR)(void))
{
	TMR0_OVF_CALLBACK_PTR = PTR;
}
void TMR0_CTC_Set_Callback_Address(void (*PTR)(void))
{
	TMR0_CTC_CALLBACK_PTR = PTR;
}

void TMR0_Set_TCNT0_REGISTER(u8 value)
{
	TCNT0_register = value;
}
void TMR0_Set_OCR0_REGISTER(u8 value)
{
	OCR0_register = value;
}

u8 TMR0_Get_TCNT0_REGISTER(void)
{
	return TCNT0_register;
}
u8 TMR0_Get_OCR0_REGISTER(void)
{
	return OCR0_register;
}

void __vector_10 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_10 (void)
{
	TMR0_CTC_CALLBACK_PTR();
}

void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_11 (void)
{
	TMR0_OVF_CALLBACK_PTR();
}

/************************************************************/

void TMR1_INIT(void)
{
	/*
	 * Select Mode
	 */

	/*
	 * #if TMR1_MODE == Normal

	Clr_Bit(TCCR1B_register,WGM13);
	Clr_Bit(TCCR1B_register,WGM12);
	Clr_Bit(TCCR1A_register,WGM11);
	Clr_Bit(TCCR1A_register,WGM10);
#elif TMR1_MODE == PWM_PC_8
	Clr_Bit(TCCR1B_register,WGM13);
	Clr_Bit(TCCR1B_register,WGM12);
	Clr_Bit(TCCR1A_register,WGM11);
	Clr_Bit(TCCR1A_register,WGM10);
#elif TMR1_MODE == PWM_PC_9
	Clr_Bit(TCCR1B_register,WGM13);
	Clr_Bit(TCCR1B_register,WGM12);
	Clr_Bit(TCCR1A_register,WGM11);
	Clr_Bit(TCCR1A_register,WGM10);
#elif TMR1_MODE == FPWM_ICR1
	Set_Bit(TCCR1B_register,WGM13);
	Set_Bit(TCCR1B_register,WGM12);
	Set_Bit(TCCR1A_register,WGM11);
	Clr_Bit(TCCR1A_register,WGM10);
#endif
	 */

	Clr_Bit(TCCR1B_register,WGM13);
	Clr_Bit(TCCR1B_register,WGM12);
	Clr_Bit(TCCR1A_register,WGM11);
	Clr_Bit(TCCR1A_register,WGM10);
	/*
	 * Output Mode
	 */
	Clr_Bit(TCCR1A_register,COM1A0);
	Clr_Bit(TCCR1A_register,COM1A1);
	Clr_Bit(TCCR1A_register,COM1B0);
	Clr_Bit(TCCR1A_register,COM1B1);

	/*
	 * Prescaller
	 */
	Set_Bit(TCCR1B_register,CS10);
	Set_Bit(TCCR1B_register,CS11);
	Clr_Bit(TCCR1B_register,CS12);
}

void TMR1_OVF_INTERRUPT_ENABLE(void)
{
	Set_Bit(TIMSK_register,TOIE1);
}
void TMR1_OVF_INTERRUPT_DISABLE(void)
{
	Clr_Bit(TIMSK_register,TOIE1);
}

void TMR1_CTCA_INTERRUPT_ENABLE(void)
{
	Set_Bit(TIMSK_register,OCIE1A);
}
void TMR1_CTCA_INTERRUPT_DISABLE(void)
{
	Clr_Bit(TIMSK_register,OCIE1A);
}

void TMR1_CTCB_INTERRUPT_ENABLE(void)
{
	Set_Bit(TIMSK_register,OCIE1B);
}
void TMR1_CTCB_INTERRUPT_DISABLE(void)
{
	Clr_Bit(TIMSK_register,OCIE1B);
}

void TMR1_ICU_INTERRUPT_ENABLE(void)
{
	Set_Bit(TIMSK_register,TICIE1);
}
void TMR1_ICU_INTERRUPT_DISABLE(void)
{
	Clr_Bit(TIMSK_register,TICIE1);
}

void TMR1_ICU_INTERRUPT_SET_EDGE(u8 edge)
{
	switch(edge)
	{
	case RISING_EDGE:
		Set_Bit(TCCR1B_register,ICES1);
		break;
	case FALLING_EDGE:
		Clr_Bit(TCCR1B_register,ICES1);
		break;
	default:
		break;
	}


}


void TMR1_OVF_Set_Callback_Address(void (*PTR)(void))
{
	TMR1_OVF_CALLBACK_PTR = PTR;
}
void TMR1_CTCA_Set_Callback_Address(void (*PTR)(void))
{
	TMR1_CTCA_CALLBACK_PTR = PTR;
}
void TMR1_CTCB_Set_Callback_Address(void (*PTR)(void))
{
	TMR1_CTCB_CALLBACK_PTR = PTR;
}
void TMR1_ICU_Set_Callback_Address(void (*PTR)(void))
{
	TMR1_ICR_CALLBACK_PTR = PTR;
}

void TMR1_Set_TCNT1_REGISTER(u8 value)
{
	TCNT1_register = value;
}
void TMR1_Set_OCR1A_REGISTER(u16 value)
{
	OCR1A_register = value;
}
void TMR1_Set_OCR1B_REGISTER(u8 value)
{
	OCR1B_register = value;
}
void TMR1_Set_ICR1_REGISTER(u8 value)
{
	ICR1_register = value;
}


u8 TMR1_Get_TCNT1_REGISTER(void)
{
	return TCNT1_register;
}
u8 TMR1_Get_OCR1A_REGISTER(void)
{
	return OCR1A_register;
}
u8 TMR1_Get_OCR1B_REGISTER(void)
{
	return OCR1B_register;
}
u8 TMR1_Get_ICR1_REGISTER(void)
{
	return ICR1_register;
}


void TMR1_Close_Timer(void)
{
	Clr_Bit(TCCR1B_register,CS10);
	Clr_Bit(TCCR1B_register,CS11);
	Clr_Bit(TCCR1B_register,CS12);
}


void __vector_9 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_9 (void)
{
	TMR1_OVF_CALLBACK_PTR();
}

void __vector_7 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_7 (void)
{
	TMR1_CTCA_CALLBACK_PTR();
}

void __vector_8 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_8 (void)
{
	TMR1_CTCB_CALLBACK_PTR();
}

void __vector_6 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_6 (void)
{
	TMR1_ICR_CALLBACK_PTR();
}







/************************************************************/

void TMR2_INIT(void)
{
	/*
	 * Select mode
	 */

#if TMR2_MODE == Normal
	Clr_Bit(TCCR2_register,WGM20);
	Clr_Bit(TCCR2_register,WGM21);

#elif TMR2_MODE == PWM
	Set_Bit(TCCR2_register,WGM20);
	Clr_Bit(TCCR2_register,WGM21);

#elif TMR2_MODE == CTC
	Clr_Bit(TCCR2_register,WGM20);
	Set_Bit(TCCR2_register,WGM21);

#elif TMR2_MODE == FPWM
	Set_Bit(TCCR2_register,WGM20);
	Set_Bit(TCCR2_register,WGM21);
#endif

	/*
	 * Output Mode
	 */
	Clr_Bit(TCCR2_register,COM20);
	Clr_Bit(TCCR2_register,COM21);

	/*
	 * Select Prescaller
	 */

	Clr_Bit(TCCR2_register,CS20);
	Set_Bit(TCCR2_register,CS21);
	Clr_Bit(TCCR2_register,CS22);

}

void TMR2_OVF_INTERRUPT_ENABLE(void)
{
	Set_Bit(TIMSK_register,TOIE2);
}
void TMR2_OVF_INTERRUPT_DISABLE(void)
{
	Clr_Bit(TIMSK_register,TOIE2);
}

void TMR2_CTC_INTERRUPT_ENABLE(void)
{
	Set_Bit(TIMSK_register,OCIE2);
}
void TMR2_CTC_INTERRUPT_DISABLE(void)
{
	Clr_Bit(TIMSK_register,OCIE2);
}

void TMR2_OVF_Set_Callback_Address(void (*PTR)(void))
{
	TMR2_OVF_CALLBACK_PTR = PTR;
}
void TMR2_CTC_Set_Callback_Address(void (*PTR)(void))
{
	TMR2_CTC_CALLBACK_PTR = PTR;
}

void TMR2_Set_TCNT2_REGISTER(u8 value)
{
	TCNT2_register = value;
}
void TMR2_Set_OCR2_REGISTER(u8 value)
{
	OCR2_register = value;
}

u8 TMR2_Get_TCNT2_REGISTER(void)
{
	return TCNT2_register;
}
u8 TMR2_Get_OCR2_REGISTER(void)
{
	return OCR2_register;
}

void __vector_4 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_4 (void)
{
	TMR2_CTC_CALLBACK_PTR();
}

void __vector_5 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_5 (void)
{
	TMR2_OVF_CALLBACK_PTR();
}

/************************************************************/

