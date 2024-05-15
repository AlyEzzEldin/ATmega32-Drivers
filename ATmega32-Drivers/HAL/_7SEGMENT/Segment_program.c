/*
 * Segment_program.c
 *
 *  Created on: 8 Sep 2023
 *      Author: Ali
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "Segment_interface.h"

void SEGMENT_INIT(u8 DataPort,u8 ControlPort,u8 ControlPin,u8 SegmentType)
{
	switch(SegmentType)
	{
	case COMMON_CATHODE :
		DIO_SetPortDirection(DataPort,PORT_OUTPUT);
		DIO_SetPinDirection(ControlPort,PIN_OUTPUT,ControlPin);
		DIO_SetPortValue(DataPort,PORT_LOW);
		DIO_SetPinValue(ControlPort,PIN_HIGH,ControlPin);
		break;
	case COMMON_ANODE:
		DIO_SetPortDirection(DataPort,PORT_OUTPUT);
		DIO_SetPinDirection(ControlPort,PIN_OUTPUT,ControlPin);
		DIO_SetPortValue(DataPort,PORT_HIGH);
		DIO_SetPinValue(ControlPort,PIN_LOW,ControlPin);
		break;
	default:
		break;
	}
}

void SEGMENT_ENABLE(u8 ControlPort,u8 ControlPin,u8 SegmentType)
{
	switch(SegmentType)
	{
	case COMMON_CATHODE :
		DIO_SetPinValue(ControlPort,PIN_LOW,ControlPin);
		break;
	case COMMON_ANODE:
		DIO_SetPinValue(ControlPort,PIN_HIGH,ControlPin);
		break;
	default:
		break;
	}
}

void SEGMENT_DISABLE(u8 ControlPort,u8 ControlPin,u8 SegmentType)
{
	switch(SegmentType)
	{
	case COMMON_CATHODE :
		DIO_SetPinValue(ControlPort,PIN_HIGH,ControlPin);
		break;
	case COMMON_ANODE:
		DIO_SetPinValue(ControlPort,PIN_LOW,ControlPin);
		break;
	default:
		break;
	}
}

void SEGMENT_DISPLAY_NUMBER(u8 DataPort,u8 SegmentType,u8 Number)
{
	switch (SegmentType)
	{
	case COMMON_CATHODE :
		DIO_SetPortValue(DataPort,Number);
		break;
	case COMMON_ANODE :
		DIO_SetPortValue(DataPort,~Number);
		break;
	default:
		break;
	}
}

