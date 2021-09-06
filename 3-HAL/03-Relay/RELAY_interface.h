/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 4 OCT 2020                               */
/* File     : RELAY_interface                          */
/* Version  : V 1.0                                    */
/* LOG      :                                          */
/*******************************************************/

#ifndef RELAY_INTERFACE_H
#define RELAY_INTERFACE_H

void RELAY_voidTurnOn(u8 copy_u8Port, u8 copy_u8Pin);

void RELAY_voidTurnOff(u8 copy_u8Port, u8 copy_u8Pin);

void RELAY_voidToggle(u8 copy_u8Port, u8 copy_u8Pin);

#endif