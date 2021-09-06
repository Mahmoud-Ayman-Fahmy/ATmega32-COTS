/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 4 OCT 2020                               */
/* File     : LED_program                              */
/* Version  : V 1.0                                    */
/* LOG      :                                          */
/*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

void LED_voidTurnOn(u8 copy_u8Port, u8 copy_u8Pin)
{
	GPIO_voidSetPinDDR(copy_u8Port, copy_u8Pin, OUTPUT);
	GPIO_voidWritePin(copy_u8Port, copy_u8Pin, HIGH);
}

void LED_voidTurnOff(u8 copy_u8Port, u8 copy_u8Pin)
{
	GPIO_voidSetPinDDR(copy_u8Port, copy_u8Pin, OUTPUT);
	GPIO_voidWritePin(copy_u8Port, copy_u8Pin, LOW);
	
}

void LED_voidToggle(u8 copy_u8Port, u8 copy_u8Pin)
{
	GPIO_voidSetPinDDR(copy_u8Port, copy_u8Pin, OUTPUT);
	GPIO_voidTogglePin(copy_u8Port, copy_u8Pin);
}