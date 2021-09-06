/*
 * Traffic Light.c
 *
 * Created: 4/2/2021 11:26:56 AM
 * Author : mody_
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "LED_interface.h"
#include "TMR0_interface.h"
#include "LCD_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>
volatile u8 counter1=0;
volatile u8 counter_green=10;
volatile u8 counter_yellow=5;
volatile u8 counter_red=7;

void fun(void)
{
	counter1++;
}
int main(void)
{
    LCD_voidInit();
	TMR0_voidInit();
	TMR0_voidSetOCR0(80);
	TMR0_voidSetCTCWithInterrupt(&fun);
	TMR0_voidStart(TMR0_CLK_1024);
    while (1) 
    {
		counter_green=10;
		counter_yellow=5;
		counter_red=7;
		LCD_voidClearScreen();
		LCD_voidDisplayString("Remaining 10 Sec");
		LED_voidTurnOn(GPIOD,0);
		while(counter_green>0)
		{
			if(counter1>=100)
			{
				counter1=0;
				counter_green--;
				LCD_voidMoveCursor(1,11);
				LCD_voidDisplayChar(' ');
				LCD_voidDisplayChar((counter_green%10)+48);
			}
		}
		_delay_ms(500);
		LED_voidTurnOn(GPIOD,1);
		LED_voidTurnOff(GPIOD,0);
		LCD_voidClearScreen();
		LCD_voidDisplayString("Remaining  5 sec");
		while(counter_yellow>0)
		{
			if(counter1 >=100)
			{
				counter1=0;
				counter_yellow--;
				LCD_voidMoveCursor(1,11);
				LCD_voidDisplayChar(' ');
				LCD_voidDisplayNumber((counter_yellow));
			}
		}
		_delay_ms(500);
		LED_voidTurnOn(GPIOD,2);
		LED_voidTurnOff(GPIOD,1);
		LCD_voidClearScreen();
		LCD_voidDisplayString("Remaining  7 Sec");
		while(counter_red>0)
		{
			if(counter1 >=100)
			{
				counter1=0;
				counter_red--;
				LCD_voidMoveCursor(1,11);
				LCD_voidDisplayChar(' ');
				LCD_voidDisplayNumber((counter_red));
			}
		}
    }
}

