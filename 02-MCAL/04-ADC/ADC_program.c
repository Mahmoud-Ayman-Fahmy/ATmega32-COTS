/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 8 NOV 2020                                 */
/* File    : ADC_program                                */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

/* LIB include */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Driver include */ 
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"


void ADC_voidInit(u8 copy_u8Channel)
{
	//1- Make Channel selected I/p
	CLR_BIT(DDRA,copy_u8Channel);
	//2- Select Conversion Speed of ADC
	#if   ADC_PRESCALER == 0
		ADCSRA &= 0xF8;
	#elif ADC_PRESCALER == 2
		ADCSRA &= 0xF8;
		ADCSRA |= 0x02;
	#elif ADC_PRESCALER == 3
		ADCSRA &= 0xF8;
		ADCSRA |= 0x03;
	#elif ADC_PRESCALER == 4
		ADCSRA &= 0xF8;
		ADCSRA |= 0x04;
	#elif ADC_PRESCALER == 5
		ADCSRA &= 0xF8;
		ADCSRA |= 0x05;
	#elif ADC_PRESCALER == 6
		ADCSRA &= 0xF8;
		ADCSRA |= 0x06;
	#elif ADC_PRESCALER == 7
		ADCSRA &= 0xF8;
		ADCSRA |= 0x07;
	#endif
	//3- Select Voltage reference for ADC 
	#if   ADC_VOLT_REF == 0
		ADMUX &= 0x3F;
	#elif ADC_VOLT_REF == 1
		CLR_BIT(ADMUX, REFS1);
		SET_BIT(ADMUX, REFS0);
	#elif ADC_VOLT_REF == 3
		SET_BIT(ADMUX, REFS1);
		SET_BIT(ADMUX, REFS0);
	#endif
	
	//4- Select Type of Storing of the output
	#if ADC_STORE == 0
		CLR_BIT(ADMUX, ADLAR);
	#else 
		SET_BIT(ADMUX, ADLAR);
	#endif 
	
	//5- Turn on ADC
	SET_BIT(ADCSRA, ADEN);
	
}

u16  ADC_u16Read(void)
{
	u16 Return_val;
	//1- Activate Start of Conversion
	SET_BIT(ADCSRA, ADSC);
	//2- Wait until conversion Ended
	while(GET_BIT(ADCSRA, ADIF)==0);
	//3- Clear Interrupt Flag after Ended
	SET_BIT(ADCSRA, ADIF);
	//4- Read ADCL then ADCH in order
	Return_val = ADCL;
	Return_val |= (ADCH << 8);
	return Return_val;
}

