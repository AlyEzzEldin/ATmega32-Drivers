/*
 * PUSHBUTTON_program.c
 *
 *  Created on: 13 Sep 2023
 *      Author: Ali
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"


void SWITCH_INIT(u8 Port , u8 Pin)
{
	DIO_SetPinDirection(Port,PIN_INPUT,Pin);
	DIO_SetPinValue(Port,PIN_HIGH,Pin);
}
void DIP_SWITCH_INIT(u8 Port)
{
	DIO_SetPortDirection(Port,PORT_INPUT);
	DIO_SetPortValue(Port,PORT_HIGH);
}

u8 GET_SWITCH_STATE(u8 Port,u8 Pin)
{
	u8 Switch_Return = 0;
	Switch_Return = !DIO_GetPinValue(Port,Pin);
	return Switch_Return;
}
u8 GET_DIP_SWITCH_STATE(u8 Port)
{
	u8 DIP_Switch_Return = 0;
	DIP_Switch_Return = ~DIO_GetPortValue(Port);
	return DIP_Switch_Return;
}
