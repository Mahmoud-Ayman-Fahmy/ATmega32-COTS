/*
 * main.c
 *
 *  Created on: Oct 27, 2020
 *      Author: Mahmoud Ayman
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_interface.h"

#include "EXTI_interface.h"

#include "LED_interface.h"
#define F_CPU  8000000UL
#include "util/delay.h"
void fun(void)
{
	LED_voidTurnOn(GPIOA,2);
	_delay_ms(200);
	LED_voidTurnOff(GPIOA,2);
}
int main()
{
	EXTI_voidInit(EXTI_INT0 , &fun);
	while (1)
	{

	}
}
