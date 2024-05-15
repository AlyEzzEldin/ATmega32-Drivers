///*
// * main.c
// *
// *  Created on: 22 Oct 2023
// *      Author: Ali
// */
//
//
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#define F_CPU 8000000
#include "util/delay.h"

void main(void)
{
	DIO_SetPinDirection(PORT_A,PIN_OUTPUT,PIN_0);
	while(1)
	{
		DIO_TogglePinValue(PORT_A,PIN_0);
		_delay_ms(500);
	}
}
