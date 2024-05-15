/*
 * LED_program.c
 *
 *  Created on: 12 Sep 2023
 *      Author: Ali
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

void LED_PIN_INIT(u8 LED_port,u8 LED_pin)
{
	DIO_SetPinDirection(LED_port,PIN_OUTPUT,LED_pin);
}
void LED_PORT_INIT(u8 LED_port)
{
	DIO_SetPortDirection(LED_port,PORT_OUTPUT);
}

void LED_PIN_WRITE(u8 LED_port,u8 LED_pin,u8 LED_value)
{
	DIO_SetPinValue(LED_port,LED_value,LED_pin);
}
void LED_PORT_WRITE(u8 LED_port,u8 LED_value)
{
	DIO_SetPortValue(LED_port,LED_value);
}
