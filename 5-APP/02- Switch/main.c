/*
 * main.c
 *
 *  Created on: Oct 14, 2020
 *      Author: Mahmoud Ayman
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SWITCH_interface.h"
#include "LED_interface.h"
#define F_CPU   8000000UL
#include "util/delay.h"
int main(void)
{
	SWITCH_voidInit(GPIOA,0);
	u8 i;
	while(1)
	{
		i= SWITCH_u8Read(GPIOA,0);
		_delay_ms(50);
		if(i == 0)
		{
			LED_voidToggle(GPIOA,2);
			_delay_ms(100);
		}
	}
}
