/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 13 OCT 2020                              */
/* File     : SEVSEG_program                           */
/* Version  : V 1.0                                    */
/* LOG      :                                          */
/*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SEVSEG_interface.h"
#include "SEVSEG_config.h"
#include "SEVSEG_private.h"

void SEVSEG_voidInit(u8 copy_u8Port)
{
	GPIO_voidSetPortDDR(copy_u8Port, OUTPUT);
}

void SEVSEG_voidDisplayNum(u8 copy_u8Port, u8 copy_u8Value)
{
	u8 Local_u8arr[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	GPIO_voidWritePort(copy_u8Port, Local_u8arr[copy_u8Value]);
}

void SEVSEG_voidDisplayNumFourPin(u8 copy_u8Port, u8 copy_u8Value ,u8 copy_u8Nibble)
{
	if( NIBBLE == 0){
		GPIO_voidLOWNibbleSetDDR(copy_u8Port, OUTPUT);
		GPIO_voidLOWNibbleWrite(copy_u8Port, copy_u8Value);
	}else{ 
		GPIO_voidHIGHNibbleSetDDR(copy_u8Port, OUTPUT);
		GPIO_voidHIGHNibbleWrite(copy_u8Port, copy_u8Value);
	}	
}