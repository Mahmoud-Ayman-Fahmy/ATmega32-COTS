/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 12 NOV 2020                                */
/* File    : LM35_interface                             */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H

#define ADC0  0
#define ADC1  1
#define ADC2  2
#define ADC3  3
#define ADC4  4
#define ADC5  5
#define ADC6  6
#define ADC7  7

void LM35_voidInit(u8 copy_u8Channel);

u8 LM35_u8Read(void);

#endif