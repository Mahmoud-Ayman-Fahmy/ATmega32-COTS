/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 30 OCT 2020                              */
/* File     : LCD_interface                            */
/* Version  : V 1.0                                    */
/* LOG      :                                          */
/*******************************************************/


#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidInit();

void LCD_voidSendCmd(u8 copy_u8cmd);

void LCD_voidMoveCursor(u8 copy_u8Line, u8 copy_u8Position);

void LCD_voidClearScreen();

void LCD_voidDisplayChar(u8 copy_u8Char);

void LCD_voidDisplayString(u8 *copy_u8String);

void LCD_voidDisplayNumber(u32 copy_u32Number);

void LCD_voidDisplayRealNumber(f64 Number);

#endif