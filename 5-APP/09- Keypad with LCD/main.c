/*
 * main.c
 *
 *  Created on: Nov 5, 2020
 *      Author: Mahmoud Ayman
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"

#define F_CPU 8000000UL
#include "util/delay.h"
int main(void)
{
	u8 g;
	Keypad_voidInit(GPIOC);
	LCD_voidInit();
	LCD_voidDisplayChar('A');
	while(1)
	{
		g = Keypad_u8CheckPress(GPIOC);
		if(g != NOTPRESSED)
		{
			LCD_voidDisplayChar(g);
			_delay_ms(300);
		}

	}
}
