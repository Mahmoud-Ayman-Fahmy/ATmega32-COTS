/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 10 OCT 2020                              */
/* File     : GPIO_interface                           */
/* Version  : V 1.0                                    */
/* LOG      :                                          */
/*******************************************************/


#ifndef  GPIO_INTERFACE_H
#define  GPIO_INTERFACE_H

#define  GPIOA  0
#define  GPIOB  1
#define  GPIOC  2
#define  GPIOD  3

#define  INPUT  0
#define  OUTPUT 1

#define  HIGH   1
#define  LOW    0

/* PIN */

void GPIO_voidSetPinDDR(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Mode);

void GPIO_voidWritePin(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value);

u8   GPIO_u8ReadPin(u8 copy_u8Port, u8 copy_u8Pin);

void GPIO_voidTogglePin(u8 copy_u8Port, u8 copy_u8Pin);

void GPIO_voidSetPortDDR(u8 copy_u8Port, u8 copy_u8Mode);

void GPIO_voidWritePort(u8 copy_u8Port , u8 copy_u8Value);

void GPIO_voidSetLowNibbleDDR( u8 copy_u8Port, u8 copy_u8Dir);

void GPIO_voidSetHighNibbleDDR(u8 copy_u8Port, u8 copy_u8Value);

void GPIO_voidWriteLowNibble(u8 copy_u8Port, u8 copy_u8Value);

void GPIO_voidWriteHighNibble(u8 copy_u8Port, u8 copy_u8Value);
#endif
