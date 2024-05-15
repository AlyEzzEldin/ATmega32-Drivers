/*
 * GLOBAL_INTERRUPT_program.c
 *
 *  Created on: 22 Sep 2023
 *      Author: Ali
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GLOBAL_INTERRUPT_interface.h"
#include "GLOBAL_INTERRUPT_REGISTER.h"

void Global_Interrupt_Enable(void)
{
	Set_Bit(SREG_REGISTER,I);
}

void Global_Interrupt_Disable(void)
{
	Clr_Bit(SREG_REGISTER,I);
}
