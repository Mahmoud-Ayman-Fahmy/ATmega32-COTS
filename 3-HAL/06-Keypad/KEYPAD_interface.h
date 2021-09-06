/*************************************************************/
/* Author : Mahmoud Ayman                                    */
/* Date   : 5 NOV 2020                                       */
/* File   : Keypad_interface                                 */
/* LOG    :                                                  */
/*************************************************************/

#ifndef  KEYPAD_INTERFACE_H
#define  KEYPAD_INTERFACE_H


#define NOTPRESSED  0xff
void Keypad_voidInit(u8 copy_u8port); 
u8 Keypad_u8CheckPress(u8 copy_u8Port);


#endif
