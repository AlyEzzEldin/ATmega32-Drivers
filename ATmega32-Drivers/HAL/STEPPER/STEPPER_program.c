/*
 * STEPPER_program.c
 *
 *  Created on: 16 Sep 2023
 *      Author: Ali
 */
#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "STEPPER_config.h"
#include "STEPPER_interface.h"
#include "avr/delay.h"
#define F_CPU 8000000

void STEPPER_INIT(void)
{
	DIO_SetPinDirection(STEPPER_PORT,PIN_OUTPUT,BLUE);
	DIO_SetPinDirection(STEPPER_PORT,PIN_OUTPUT,PINK);
	DIO_SetPinDirection(STEPPER_PORT,PIN_OUTPUT,YELLOW);
	DIO_SetPinDirection(STEPPER_PORT,PIN_OUTPUT,ORANGE);

	DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,BLUE);
	DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,PINK);
	DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,YELLOW);
	DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,ORANGE);

}
void STEPPER_ClockWise(u16 Degrees)
{
	DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,BLUE);
	DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,PINK);
	DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,YELLOW);
	DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,ORANGE);

	u16 max = (Degrees * 10) / 7;
	u16 i = 0;
	for(i = 0;i < max;i++)
	{
		DIO_SetPinValue(STEPPER_PORT,PIN_LOW,BLUE);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,PINK);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,YELLOW);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,ORANGE);

		_delay_ms(2);

		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,BLUE);
		DIO_SetPinValue(STEPPER_PORT,PIN_LOW,PINK);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,YELLOW);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,ORANGE);

		_delay_ms(2);

		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,BLUE);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,PINK);
		DIO_SetPinValue(STEPPER_PORT,PIN_LOW,YELLOW);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,ORANGE);

		_delay_ms(2);

		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,BLUE);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,PINK);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,YELLOW);
		DIO_SetPinValue(STEPPER_PORT,PIN_LOW,ORANGE);

		_delay_ms(2);

	}

}
void STEPPER_CounterClockWise(u16 Degrees)
{
	DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,BLUE);
	DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,PINK);
	DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,YELLOW);
	DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,ORANGE);

	u16 max = (Degrees * 10) / 7;
	u16 i = 0;
	for(i = 0;i < max;i++)
	{
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,BLUE);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,PINK);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,YELLOW);
		DIO_SetPinValue(STEPPER_PORT,PIN_LOW,ORANGE);

		_delay_ms(2);

		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,BLUE);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,PINK);
		DIO_SetPinValue(STEPPER_PORT,PIN_LOW,YELLOW);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,ORANGE);

		_delay_ms(2);

		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,BLUE);
		DIO_SetPinValue(STEPPER_PORT,PIN_LOW,PINK);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,YELLOW);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,ORANGE);

		_delay_ms(2);

		DIO_SetPinValue(STEPPER_PORT,PIN_LOW,BLUE);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,PINK);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,YELLOW);
		DIO_SetPinValue(STEPPER_PORT,PIN_HIGH,ORANGE);

		_delay_ms(2);

	}

}
