/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 4 OCT 2020                               */
/* File     : LED_interface                            */
/* Version  : V 1.0                                    */
/* LOG      :                                          */
/*******************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

void LED_voidTurnOn(u8 copy_u8Port, u8 copy_u8Pin);

void LED_voidTurnOff(u8 copy_u8Port, u8 copy_u8Pin);

void LED_voidToggle(u8 copy_u8Port, u8 copy_u8Pin);

#endif