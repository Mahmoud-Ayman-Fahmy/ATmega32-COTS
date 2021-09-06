/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 30 OCT 2020                              */
/* File     : LCD_config                               */
/* Version  : V 1.0                                    */
/* LOG      :                                          */
/*******************************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/* Options : 0 For 8bit_Mode 
			 1 For 4bit_Mode
*/

#define LCD_MODE  0

/* Options : 0 For LOW_NIBBLE
             1 For High_NIBBLE
*/
#define LCD_NIBBLE  0

/* Options : GPIOA -> 0
			 GPIOB -> 1
			 GPIOC -> 2
			 GPIOD -> 3
*/
#define LCD_PORT  0

/* Options : GPIOA -> 0
			 GPIOB -> 1
			 GPIOC -> 2
			 GPIOD -> 3
*/
#define LCD_RSPORT  1

/* Options : 0~7
*/ 
#define LCD_RSPIN  1

/* Options : GPIOA -> 0
			 GPIOB -> 1
			 GPIOC -> 2
			 GPIOD -> 3
*/
#define LCD_RWPORT  1

/* Options : 0~7
*/ 
#define LCD_RWPIN  2

/* Options : GPIOA -> 0
			 GPIOB -> 1
			 GPIOC -> 2
			 GPIOD -> 3
*/
#define LCD_ENPORT  1

/* Options : 0~7
*/ 
#define LCD_ENPIN  0
			 

#endif
