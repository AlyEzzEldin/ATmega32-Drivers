/*
 * WDG_program.c
 *
 *  Created on: 14 Oct 2023
 *      Author: Ali
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WDG_register.h"
#include "WDG_interface.h"

void WDG_INIT(u8 Timeout)
{
	WDTCR_register &= 0b11111000;
	WDTCR_register |= Timeout;
}
void WDG_ENABLE(void)
{
	Set_Bit(WDTCR_register,WDE);
}
void WDG_DISABLE(void)
{
	/* Write logical one to WDTOE and WDE */
	WDTCR_register = (1<<WDTOE) | (1<<WDE);
	/* Turn off WDT */
	WDTCR_register = 0x00;
}
void WDG_RESET(void)
{
	asm volatile("WDR");
}
