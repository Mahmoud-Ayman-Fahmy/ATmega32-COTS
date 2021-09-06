/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 10 OCT 2020                              */
/* File     : SWITCH_interface                         */
/* Version  : V 1.0                                    */
/* LOG      :                                          */
/*******************************************************/


#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H 

void SWITCH_voidInit(u8 copy_u8Port, u8 copy_u8Pin);

u8 SWITCH_u8Read(u8 copy_u8Port, u8 copy_u8Pin);

#endif