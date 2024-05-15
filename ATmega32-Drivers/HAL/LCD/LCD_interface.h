/*
 * LCD_interface.h
 *
 *  Created on: 9 Sep 2023
 *      Author: Ali
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define lcd_Clear           0x01
#define lcd_Home            0x02
#define lcd_EntryMode       0x06
#define lcd_DisplayOff      0x08
#define lcd_DisplayOn       0x0C
#define lcd_FunctionReset   0x30
#define lcd_FunctionSet8Bit 0x38  // 0011 1000
#define lcd_SetCursor       0x80



void LCD_INIT(void);
void LCD_Write_Command(u8 Command);
void LCD_Write_Data(u8 Data);
void LCD_Custom_Char (unsigned char loc, unsigned char *msg);
void LCD_String(u8 *str,u8 length);
void LCD_Goto(u8 y, u8 x);
void LCD_ARABIC(u8 y , u8 x);


#endif /* LCD_INTERFACE_H_ */
