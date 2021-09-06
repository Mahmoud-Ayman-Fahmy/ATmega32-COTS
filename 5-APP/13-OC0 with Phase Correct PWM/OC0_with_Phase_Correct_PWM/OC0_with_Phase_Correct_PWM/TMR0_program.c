/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 13 NOV 2020                                */
/* File    : TMR0_program                               */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/
/* LIB include */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Driver Include */
#include "TMR0_interface.h"
#include "TMR0_config.h"
#include "TMR0_private.h"

#include "avr/interrupt.h"
u8 flag =0;
u32 TOV_Counter = 0;
void (*Global_CBTOV)(void);
void (*Global_CBCTC)(void);
void  TMR0_voidInit(void)
{
/*********************Enable Global Interrupt************/
	SET_BIT(SREG , 7);
/***********************Adjust Mode *********************/

	#if    TMR0_MODE == 0  //Normal (Overflow) Mode
		CLR_BIT(TCCR0 , WGM00);
		CLR_BIT(TCCR0 , WGM01);
	#elif  TMR0_MODE == 1  // Phase PWM Mode
		SET_BIT(TCCR0 , WGM00);
		CLR_BIT(TCCR0 , WGM01);
	#elif  TMR0_MODE == 2 || TMR0_MODE == 4 // CTC Mode
		CLR_BIT(TCCR0 , WGM00);
		SET_BIT(TCCR0 , WGM01);
	#elif  TMR0_MODE == 3  // Fast PWM Mode
		SET_BIT(TCCR0 , WGM00);
		SET_BIT(TCCR0 , WGM01);
	#endif
/**********************Adjust COM*************************/
	TCCR0 &= 0xCF; // Make COM bits zeros
	#if    TMR0_COM_NONPWM  != 0x00
		TCCR0 |= TMR0_COM_NONPWM ;
	#elif  TMR0_COM_FASTPWM != 0x00
		TCCR0 |= TMR0_COM_FASTPWM ;
	#elif  TMR0_COM_PCPWM   != 0x00
		TCCR0 |= TMR0_COM_PCPWM ;
	#endif 
/*****************Adjust FOC0************************/
	#if  TMR0_FOC0 == 0
		CLR_BIT(TCCR0, FOC0); // Disable FOC0
	#else
		SET_BIT(TCCR0, FOC0); // Enable FOC0
	#endif
/*****************Adjust TOV Interrupt *******************/
	#if  TMR0_TOVINTERRUPT == 0
		CLR_BIT(TIMASK, TOIE0); // Disable TOV Interrupt
	#else
		SET_BIT(TIMASK, TOIE0); // Enable TOV Interrupt
	#endif
/***************** Adjust OCF Interrupt *******************/
	#if  TMR0_TOCINTERRUPT == 0
		CLR_BIT(TIMASK, OCIE0); // Disable OCF Interrupt
	#else
		SET_BIT(TIMASK, 1);    // Enable OCF Interrupt
	#endif
}

void  TMR0_voidStart(u8 copy_u8Prescaler)
{
	flag =0;
/*********** Adjust Clock Prescaler******************/
	TCCR0 &= 0xF8;
	TCCR0 |= copy_u8Prescaler;
}
// SetTMR0Start
void  TMR0_voidSetTCNT0(u8 copy_u8InitValue)
{
	TCNT0 = copy_u8InitValue;
}

u32   TMR0_u32ReadTMR0(void)
{
	u32 Return_Val;
	Return_Val = (TOV_Counter * 256)+ TCNT0;
	return Return_Val;
}

void  TMR0_voidSetNormalWithInterrupt( void (*copy_CB)(void))
{
	if(copy_CB != 0)
	{
		flag =1;
		Global_CBTOV = copy_CB;
	}
}
//SetTMR0Compare
void  TMR0_voidSetOCR0(u8 copy_u8InitValue)
{
	OCR0 = copy_u8InitValue;
}

void  TMR0_voidSetCTCWithInterrupt( void (*copy_CB)(void))
{
	Global_CBCTC = copy_CB;
}
void  TMR0_voidStopTMR0(void)
{
    // Make CS bit Zeros
	TCCR0 &= 0xF8;
}
// Set TCCR0 =0x00
void  TMR0_voidDInit(void)
{
	// Put TCCR0 all bits zeros
	TCCR0 = 0x00;
}

void TMR0_GenerateFastPWM(u8 copy_u8DutyCycle)
{
	// Make OC0 Output pin
	SET_BIT(DDRB,3);
	volatile u8 Local_u8Data = 0;
	#if   TMR0_COM_FASTPWM == 0x20
		Local_u8Data = ((256 * copy_u8DutyCycle)/100)-1;
		TMR0_voidSetOCR0(Local_u8Data);
	#elif TMR0_COM_FASTPWM == 0x30
		Local_u8Data = 255-((256 * copy_u8DutyCycle)/100);
		TMR0_voidSetOCR0(Local_u8Data);
	#endif
}

void TMR0_GeneratePhaseCorrectPWM(u8 copy_u8DutyCycle)
{
	// Make OC0 Output pin
	SET_BIT(DDRB,3);
	volatile u8 Local_u8Data = 0;
	#if   TMR0_COM_PCPWM == 0x20
		Local_u8Data = ((255 * copy_u8DutyCycle)/100);
		TMR0_voidSetOCR0(Local_u8Data);
	#elif TMR0_COM_PCPWM == 0x30
		Local_u8Data = 255-((255 * copy_u8DutyCycle)/100);
		TMR0_voidSetOCR0(Local_u8Data);
	#endif
}

ISR(TIMER0_OVF_vect)
{
	TOV_Counter++;
	if(flag !=0)
	{
		(*Global_CBTOV)();
	}
}

ISR(TIMER0_COMP_vect)
{
	(*Global_CBCTC)();
	SET_BIT(TIFR,OCF0);
}
