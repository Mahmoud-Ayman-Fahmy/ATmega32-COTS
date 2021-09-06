/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 12 NOV 2020                                */
/* File    : LM35_program                               */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"

#include "Lm35_interface.h"
#include "Lm35_config.h"
#include "Lm35_private.h"

void LM35_voidInit(u8 copy_u8Channel)
{
	ADC_voidInit(copy_u8Channel);
}

u8 LM35_u8Read(void)
{
	u16 Local_u16Read, Local_u16Analog;
	u8 Local_u8Temp;
	/* Return Digital value*/=
	Local_u16Read = ADC_u16Read();
	/* Calculate Analog value */
	Local_u16Analog = (INT_VREF * Local_16Read) / 1024;
	/* Calculate Temperature value */
	Local_u8Temp = Local_u16Analog / 10;
	return Local_u8Temp;
}