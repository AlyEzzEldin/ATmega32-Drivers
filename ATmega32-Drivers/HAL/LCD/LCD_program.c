/*
 * LCD_program.c
 *
 *  Created on: 9 Sep 2023
 *      Author: Ali
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/delay.h"
#define F_CPU 8000000
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"

void LCD_INIT(void)
{
	DIO_SetPortDirection(DATA_PORT,PORT_OUTPUT);
	DIO_SetPinDirection(CONTROL_PORT,PIN_OUTPUT,RS_PIN);
	DIO_SetPinDirection(CONTROL_PORT,PIN_OUTPUT,RW_PIN);
	DIO_SetPinDirection(CONTROL_PORT,PIN_OUTPUT,E_PIN);

	_delay_ms(30);
	LCD_Write_Command(lcd_FunctionSet8Bit);

	_delay_ms(3);
	LCD_Write_Command(lcd_DisplayOn);

	_delay_ms(3);
	LCD_Write_Command(lcd_Clear);

	_delay_ms(3);
	LCD_Write_Command(lcd_EntryMode);

	_delay_ms(3);
	LCD_Write_Command(lcd_Home);

}
void LCD_Write_Command(u8 Command)
{
	DIO_SetPinValue(CONTROL_PORT,PIN_LOW,RS_PIN);
	DIO_SetPinValue(CONTROL_PORT,PIN_LOW,RW_PIN);
	DIO_SetPinValue(CONTROL_PORT,PIN_LOW,E_PIN);

	DIO_SetPortValue(DATA_PORT,Command);

	_delay_ms(3);
	DIO_SetPinValue(CONTROL_PORT,PIN_HIGH,E_PIN);
	_delay_ms(3);

	DIO_SetPinValue(CONTROL_PORT,PIN_LOW,E_PIN);


}
void LCD_Write_Data(u8 Data)
{
	DIO_SetPinValue(CONTROL_PORT,PIN_HIGH,RS_PIN);
	DIO_SetPinValue(CONTROL_PORT,PIN_LOW,RW_PIN);
	DIO_SetPinValue(CONTROL_PORT,PIN_LOW,E_PIN);

	DIO_SetPortValue(DATA_PORT,Data);

	_delay_ms(3);
	DIO_SetPinValue(CONTROL_PORT,PIN_HIGH,E_PIN);
	_delay_ms(3);
	DIO_SetPinValue(CONTROL_PORT,PIN_LOW,E_PIN);


}

void LCD_Custom_Char (unsigned char loc, unsigned char *msg)
{
	u8 i = 0;
	if(loc<8)
	{
		LCD_Write_Command(0x40 + (loc*8));
		for(i=0;i<8;i++)
		{
			LCD_Write_Data(msg[i]);
		}
	}
}

void LCD_String(u8 *str,u8 length)
{
	int i = 0;
	/*while(str[i]!=0) // loop will go on till the NULL character in the string
	{
		LCD_Write_Data(str[i]); // sending data on LCD byte by byte
		i++;
	}*/
	for(i = 0;i<length;i++)
	{
		LCD_Write_Data(str[i]);
	}
}

void LCD_Goto(u8 y, u8 x)
{
	/*if(x == 0)
	LCD_Write_Command(0x80 + y);
	else if(x == 1)
	LCD_Write_Command(0xC0 + y);*/
	LCD_Write_Command(128+(y * 0x40)+x);
}

void LCD_ARABIC(u8 y , u8 x)
{

}
