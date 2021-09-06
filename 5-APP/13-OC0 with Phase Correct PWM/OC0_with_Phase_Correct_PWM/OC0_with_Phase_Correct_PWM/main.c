/*
 * OC0_with_Phase_Correct_PWM.c
 *
 * Created: 4/2/2021 10:58:18 AM
 * Author : mody_
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TMR0_interface.h"

int main(void)
{
	TMR0_voidInit();
	TMR0_voidStart(TMR0_CLK_1024);
	TMR0_GeneratePhaseCorrectPWM(75);
	while(1)
	{

	}
}

