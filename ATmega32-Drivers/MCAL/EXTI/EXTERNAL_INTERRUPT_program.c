/*
 * EXTERNAL_INTERRUPT_program.c
 *
 *  Created on: 22 Sep 2023
 *      Author: Ali
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTERNAL_INTERRUPT_register.h"
#include "EXTERNAL_INTERRUPT_config.h"
#include "EXTERNAL_INTERRUPT_interface.h"

void (* INT0_CALLBACK_PTR)(void) = NULL;
void (* INT1_CALLBACK_PTR)(void) = NULL;
void (* INT2_CALLBACK_PTR)(void) = NULL;

void EXTERNAL_INTERRUPT_INIT(void)
{
#if EXTI0_MODE == LOW_LEVEL
	Clr_Bit(MCUCR_register,ISC00);
	Clr_Bit(MCUCR_register,ISC01);
#elif EXTI0_MODE == IOC
	Clr_Bit(MCUCR_register,ISC00);
	Set_Bit(MCUCR_register,ISC01);
#elif EXTI0_MODE == FALLING_EDGE
	Set_Bit(MCUCR_register,ISC00);
	Clr_Bit(MCUCR_register,ISC01);
#elif EXTI0_MODE == RISING_EDGE
	Set_Bit(MCUCR_register,ISC00);
	Set_Bit(MCUCR_register,ISC01);
#else
#endif

#if EXTI1_MODE == LOW_LEVEL
	Clr_Bit(MCUCR_register,ISC10);
	Clr_Bit(MCUCR_register,ISC11);
#elif EXTI1_MODE == IOC
	Clr_Bit(MCUCR_register,ISC10);
	Set_Bit(MCUCR_register,ISC11);
#elif EXTI1_MODE == FALLING_EDGE
	Set_Bit(MCUCR_register,ISC10);
	Clr_Bit(MCUCR_register,ISC11);
#elif EXTI1_MODE == RISING_EDGE
	Set_Bit(MCUCR_register,ISC10);
	Set_Bit(MCUCR_register,ISC11);
#else
#endif



#if EXTI2_MODE == FALLING_EDGE
	Clr_Bit(MCUCSR_register,ISC2);
#elif EXTI2_MODE == RISING_EDGE
	Clr_Bit(MCUCSR_register,ISC2);
#else
#endif
}
void EXTERNAL_INTERRUPT_ENABLE(u8 INT_no)
{
	switch(INT_no)
	{
	case EXTI0 :
		Set_Bit(GICR_register,INT0);
		break;
	case EXTI1 :
		Set_Bit(GICR_register,INT1);
		break;
	case EXTI2 :
		Set_Bit(GICR_register,INT2);
		break;
	default:
		break;
	}

}
void EXTERNAL_INTERRUPT_DISABLE(u8 INT_no)
{
	switch(INT_no)
	{
	case EXTI0 :
		Clr_Bit(GICR_register,INT0);
		break;
	case EXTI1 :
		Clr_Bit(GICR_register,INT1);
		break;
	case EXTI2 :
		Clr_Bit(GICR_register,INT2);
		break;
	default:
		break;
	}

}
void EXTERNAL_INTERRUPT_Set_MODE(u8 INT_no,u8 Mode)
{
	switch(INT_no)
	{
	case EXTI0 :
		switch(Mode)
		{
		case LOW_LEVEL :
			Clr_Bit(MCUCR_register,ISC00);
			Clr_Bit(MCUCR_register,ISC01);
			break;
		case IOC :
			Clr_Bit(MCUCR_register,ISC00);
			Set_Bit(MCUCR_register,ISC01);
			break;
		case FALLING_EDGE :
			Set_Bit(MCUCR_register,ISC00);
			Clr_Bit(MCUCR_register,ISC01);
			break;
		case RISING_EDGE :
			Set_Bit(MCUCR_register,ISC00);
			Set_Bit(MCUCR_register,ISC01);
			break;
		default:
			break;
		}
		break;
		case EXTI1 :
			switch(Mode)
			{
			case LOW_LEVEL :
				Clr_Bit(MCUCR_register,ISC10);
				Clr_Bit(MCUCR_register,ISC11);
				break;
			case IOC :
				Clr_Bit(MCUCR_register,ISC10);
				Set_Bit(MCUCR_register,ISC11);
				break;
			case FALLING_EDGE :
				Set_Bit(MCUCR_register,ISC10);
				Clr_Bit(MCUCR_register,ISC11);
				break;
			case RISING_EDGE :
				Set_Bit(MCUCR_register,ISC10);
				Set_Bit(MCUCR_register,ISC11);
				break;
			default:
				break;
			}
			break;
			case EXTI2 :
				switch(Mode)
				{
				case FALLING_EDGE :
					Clr_Bit(MCUCSR_register,ISC2);
					break;
				case RISING_EDGE :
					Set_Bit(MCUCSR_register,ISC2);
					break;
				default:
					break;
				}
				break;
				default:
					break;
	}

}

void __vector_1 (void) __attribute__ ((signal,used, externally_visible)) ; \
    void __vector_1 (void)
{
	 INT0_CALLBACK_PTR();
}

void __vector_2 (void) __attribute__ ((signal,used, externally_visible)) ; \
    void __vector_2 (void)
{
	 INT1_CALLBACK_PTR();

}

void __vector_3 (void) __attribute__ ((signal,used, externally_visible)) ; \
    void __vector_3 (void)
{
	 INT2_CALLBACK_PTR();

}

void EXTERNAL_INTERRUPT_INT0_Set_Callback_Address(void (*PTR)(void))
{
	INT0_CALLBACK_PTR = PTR;
}
void EXTERNAL_INTERRUPT_INT1_Set_Callback_Address(void (*PTR)(void))
{
	INT1_CALLBACK_PTR = PTR;
}
void EXTERNAL_INTERRUPT_INT2_Set_Callback_Address(void (*PTR)(void))
{
	INT2_CALLBACK_PTR = PTR;
}
