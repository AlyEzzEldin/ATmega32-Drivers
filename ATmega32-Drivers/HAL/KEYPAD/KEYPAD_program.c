/*
 * KEYPAD_program.c
 *
 *  Created on: 15 Sep 2023
 *      Author: Ali
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"



u8 KEYS[4][4] = {
		'7','8','9','/',
		'4','5','6','*',
		'1','2','3','+',
		'#','0','=','-'
};



void KEYPAD_Init(void)
{
	u8 i = 0;
	for(i = INPUT_START;i<=INPUT_END;i++)
	{
		DIO_SetPinDirection(KEYPAD_PORT,PIN_INPUT,i);
		DIO_SetPinValue(KEYPAD_PORT,PIN_HIGH,i);
	}
	for(i = OUTPUT_START;i<=OUTPUT_END;i++)
	{
		DIO_SetPinDirection(KEYPAD_PORT,PIN_OUTPUT,i);
		DIO_SetPinValue(KEYPAD_PORT,PIN_HIGH,i);
	}

}
u8 KEYPAD_Get(void)
{
	u8 KEY = NOT_PRESSED;

	u8 column = 0;
	u8 row = 0;
	u8 i = 0;

	for(column = OUTPUT_START;column <= OUTPUT_END;column++)
	{
		for(i = OUTPUT_START;i<=OUTPUT_END;i++)
		{
			DIO_SetPinDirection(KEYPAD_PORT,PIN_OUTPUT,i);
			DIO_SetPinValue(KEYPAD_PORT,PIN_HIGH,i);
		}
		DIO_SetPinValue(KEYPAD_PORT,PIN_LOW,column);
		for(row = INPUT_START;row<=INPUT_END;row++)
		{
			if(DIO_GetPinValue(KEYPAD_PORT,row)==PIN_LOW)
			{
				KEY = KEYS[row-INPUT_START][column-OUTPUT_START];

				break;
			}
		}
	}
	return KEY;
}
