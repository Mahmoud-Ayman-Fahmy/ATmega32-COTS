/*
 * main.c
 *
 *  Created on: Oct 12, 2020
 *      Author: Mahmoud Ayman
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "GPIO_interface.h"

#define F_CPU   8000000UL
#include "util/delay.h"
int main(void)
{
	u8 i=0;
	u8 j,k;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			LED_voidTurnOn(GPIOA,i);
			_delay_ms(400);
			LED_voidTurnOff(GPIOA,i);
		}
		for(i=8;i>0;i--)
		{
			LED_voidTurnOn(GPIOA,i-1);
			_delay_ms(400);
			LED_voidTurnOff(GPIOA,i-1);
		}
		for(j=4;j>0;j--)
		{
			for(k=4;k<8;k++)
			{
				if((k+(j-1))==7)
				{
					LED_voidTurnOn(GPIOA,j-1);
					LED_voidTurnOn(GPIOA,k);
					_delay_ms(400);
				}
			}
		}
		for(j=4;j>0;j--)
		{
			for(k=4;k<8;k++)
			{
				if((k+(j-1))==7)
				{
					LED_voidTurnOff(GPIOA,j-1);
					LED_voidTurnOff(GPIOA,k);
					_delay_ms(400);
				}
			}
		}
	}
}
