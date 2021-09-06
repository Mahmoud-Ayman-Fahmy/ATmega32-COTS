#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SEVSEG_interface.h"

#define F_CPU  8000000UL
#include "util/delay.h"

int main(void)
{
	SEVSEG_voidInit(GPIOD);
	u8 i;

	while(1)
	{
		for(i=0; i<=9 ; i++)
		{
			SEVSEG_voidDisplayNum(GPIOD, i);
			_delay_ms(300);
		}
	}
}

