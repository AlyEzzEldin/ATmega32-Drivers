/*
 * DIO_program.c
 *
 *  Created on: 1 Sep 2023
 *      Author: Ali
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"

void DIO_SetPortDirection(u8 PortNo,u8 Direction)
{
	switch(PortNo)
	{
	case PORT_A:
		DDRA_register = Direction;
		break;

	case PORT_B:
		DDRB_register = Direction;
		break;

	case PORT_C:
		DDRC_register = Direction;
		break;

	case PORT_D:
		DDRD_register = Direction;
		break;

	default:
		break;
	}
}
void DIO_SetPinDirection(u8 PortNo,u8 Direction,u8 PinNo)
{
	if(PinNo >= PIN_0 && PinNo <= PIN_7)
	{
		switch(PortNo)
		{
		case PORT_A:
			if(Direction == PIN_OUTPUT)
			{
				Set_Bit(DDRA_register,PinNo);
			}
			else if(Direction == PIN_INPUT)
			{
				Clr_Bit(DDRA_register,PinNo);
			}
			else
			{

			}
			break;

		case PORT_B:
			if(Direction == PIN_OUTPUT)
			{
				Set_Bit(DDRB_register,PinNo);
			}
			else if(Direction == PIN_INPUT)
			{
				Clr_Bit(DDRB_register,PinNo);
			}
			else
			{

			}
			break;

		case PORT_C:
			if(Direction == PIN_OUTPUT)
			{
				Set_Bit(DDRC_register,PinNo);
			}
			else if(Direction == PIN_INPUT)
			{
				Clr_Bit(DDRC_register,PinNo);
			}
			else
			{

			}
			break;

		case PORT_D:
			if(Direction == PIN_OUTPUT)
			{
				Set_Bit(DDRD_register,PinNo);
			}
			else if(Direction == PIN_INPUT)
			{
				Clr_Bit(DDRD_register,PinNo);
			}
			else
			{

			}
			break;

		default:
			break;
		}
	}
	else
	{

	}
}

void DIO_SetPortValue(u8 PortNo,u8 value)
{
	switch(PortNo)
	{
	case PORT_A:
		PORTA_register = value;
		break;

	case PORT_B:
		PORTB_register = value;
		break;

	case PORT_C:
		PORTC_register = value;
		break;

	case PORT_D:
		PORTD_register = value;
		break;

	default:
		break;
	}
}
void DIO_SetPinValue(u8 PortNo,u8 value,u8 PinNo)
{
	if(PinNo >= PIN_0 && PinNo <= PIN_7)
	{
		switch(PortNo)
		{
		case PORT_A:
			if(value == PIN_HIGH)
			{
				Set_Bit(PORTA_register,PinNo);
			}
			else if(value == PIN_LOW)
			{
				Clr_Bit(PORTA_register,PinNo);
			}
			else
			{

			}
			break;

		case PORT_B:
			if(value == PIN_HIGH)
			{
				Set_Bit(PORTB_register,PinNo);
			}
			else if(value == PIN_LOW)
			{
				Clr_Bit(PORTB_register,PinNo);
			}
			else
			{

			}
			break;

		case PORT_C:
			if(value == PIN_HIGH)
			{
				Set_Bit(PORTC_register,PinNo);
			}
			else if(value == PIN_LOW)
			{
				Clr_Bit(PORTC_register,PinNo);
			}
			else
			{

			}
			break;

		case PORT_D:
			if(value == PIN_HIGH)
			{
				Set_Bit(PORTD_register,PinNo);
			}
			else if(value == PIN_LOW)
			{
				Clr_Bit(PORTD_register,PinNo);
			}
			else
			{

			}
			break;

		default:
			break;
		}
	}
	else
	{

	}
}

u8 DIO_GetPortValue(u8 PortNo)
{
	u8 local_return;
	switch(PortNo)
	{
	case PORT_A:
		local_return = PINA_register;
		break;

	case PORT_B:
		local_return = PINB_register;
		break;

	case PORT_C:
		local_return = PINC_register;
		break;

	case PORT_D:
		local_return = PIND_register;
		break;

	default:
		break;
	}

	return local_return;
}
u8 DIO_GetPinValue(u8 PortNo,u8 PinNo)
{
	u8 local_return;
	if(PinNo >= PIN_0 && PinNo <= PIN_7)
	{
		switch(PortNo)
		{
		case PORT_A:
			local_return = Get_Bit(PINA_register,PinNo);
			break;

		case PORT_B:
			local_return = Get_Bit(PINB_register,PinNo);
			break;

		case PORT_C:
			local_return = Get_Bit(PINC_register,PinNo);
			break;

		case PORT_D:
			local_return = Get_Bit(PIND_register,PinNo);
			break;

		default:
			break;
		}
	}
	else
	{

	}
	return local_return;
}

void DIO_TogglePortValue(u8 PortNo)
{
	u8 PortState = DIO_GetPortValue(PortNo);
	DIO_SetPortValue(PortNo,~PortState);

}
void DIO_TogglePinValue(u8 PortNo,u8 PinNo)
{
	if(PinNo >= 0 && PinNo <= 7)
	{
		switch(PortNo)
		{
		case PORT_A:
			Toggle_Bit(PORTA_register,PinNo);
			break;
		case PORT_B:
			Toggle_Bit(PORTB_register,PinNo);
			break;
		case PORT_C:
			Toggle_Bit(PORTC_register,PinNo);
			break;
		case PORT_D:
			Toggle_Bit(PORTD_register,PinNo);
			break;
		default:
			break;
		}
	}

}
