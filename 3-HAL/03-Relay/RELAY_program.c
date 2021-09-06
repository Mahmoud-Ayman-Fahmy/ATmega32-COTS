/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 4 OCT 2020                               */
/* File     : RELAY_program                            */
/* Version  : V 1.0                                    */
/* LOG      :                                          */
/*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "RELAY_interface.h"
#include "RELAY_config.h"
#include "RELAY_private.h"

void RELAY_voidTurnOn(u8 copy_u8Port, u8 copy_u8Pin)
{
	GPIO_voidSetPinDDR(copy_u8Port, copy_u8Pin, OUTPUT);
	GPIO_voidWritePin(copy_u8Port, copy_u8Pin, HIGH);
}

void RELAY_voidTurnOff(u8 copy_u8Port, u8 copy_u8Pin)
{
	GPIO_voidSetPinDDR(copy_u8Port, copy_u8Pin, OUTPUT);
	GPIO_voidWritePin(copy_u8Port, copy_u8Pin, LOW);
	
}

void RELAY_voidToggle(u8 copy_u8Port, u8 copy_u8Pin)
{
	GPIO_voidSetPinDDR(copy_u8Port, copy_u8Pin, OUTPUT);
	GPIO_voidTogglePin(copy_u8Port, copy_u8Pin);
}