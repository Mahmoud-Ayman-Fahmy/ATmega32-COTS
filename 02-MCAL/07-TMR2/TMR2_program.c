/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 13 NOV 2020                                */
/* File    : TMR2_program                               */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

/* LIB include */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Driver Include */
#include "TMR2_interface.h"
#include "TMR2_config.h"
#include "TMR2_private.h"

#include "avr/interrupt.h"

u8 flag =0;
u32 TOV_Counter = 0;
void (*Global_CBTOV)(void);
void (*Global_CBCTC)(void);

void  TMR2_voidInit(void)
{
/*********************Enable Global Interrupt************/
	SET_BIT(SREG , 7);
/***********************Adjust Mode *********************/

	#if    TMR2_MODE == 0  //Normal (Overflow) Mode
		CLR_BIT(TCCR2 , WGM20);
		CLR_BIT(TCCR2 , WGM21);
	#elif  TMR2_MODE == 1  // Phase PWM Mode
		SET_BIT(TCCR2 , WGM20);
		CLR_BIT(TCCR2 , WGM21);
	#elif  TMR2_MODE == 2 || TMR2_MODE == 4 // CTC Mode
		CLR_BIT(TCCR2 , WGM20);
		SET_BIT(TCCR2 , WGM21);
	#elif  TMR2_MODE == 3  // Fast PWM Mode
		SET_BIT(TCCR2 , WGM20);
		SET_BIT(TCCR2 , WGM21);
	#endif
/**********************Adjust COM*************************/
	TCCR2 &= 0xCF; // Make COM bits zeros
	#if    TMR2_COM_NONPWM  != 0x00
		TCCR2 |= TMR2_COM_NONPWM ;
	#elif  TMR2_COM_FASTPWM != 0x00
		TCCR2 |= TMR2_COM_FASTPWM ;
	#elif  TMR2_COM_PCPWM   != 0x00
		TCCR2 |= TMR2_COM_PCPWM ;
	#endif 
/*****************Adjust FOC0************************/
	#if  TMR2_FOC2 == 0
		CLR_BIT(TCCR2, FOC2); // Disable FOC0
	#else
		SET_BIT(TCCR2, FOC2); // Enable FOC0
	#endif
/*****************Adjust TOV Interrupt *******************/
	#if  TMR2_TOVINTERRUPT == 0
		CLR_BIT(TIMASK, TOIE2); // Disable TOV Interrupt
	#else
		SET_BIT(TIMASK, TOIE2); // Enable TOV Interrupt
	#endif
/***************** Adjust OCF Interrupt *******************/
	#if  TMR2_TOCINTERRUPT == 0
		CLR_BIT(TIMASK, OCIE2); // Disable OCF Interrupt
	#else
		SET_BIT(TIMASK, OCIE2);    // Enable OCF Interrupt
	#endif
/***************** Adjust RTC ******************************/
	#if  TMR2_TRCCONTROL ==0
		CLR_BIT(ASSR, AS2); // Disable RTC
	#else 
		SET_BIT(ASSR, AS2); // Enable RTC
	#endif
}

void  TMR2_voidStart(u8 copy_u8Prescaler)
{
	flag =0;
/*********** Adjust Clock Prescaler******************/
	TCCR2 &= 0xF8;
	TCCR2 |= copy_u8Prescaler;
}

// SetTMR0Start
void  TMR2_voidSetTCNT2(u8 copy_u8InitValue)
{
	TCNT2 = copy_u8InitValue;
}

u32   TMR2_u32ReadTMR2(void)
{
	u32 Return_Val;
	Return_Val = (TOV_Counter * 256)+ TCNT2;
	return Return_Val;
}

void  TMR2_voidSetNormalWithInterrupt(void (*copy_CB)(void))
{
	if(copy_CB != 0)
	{
		flag =1;
		Global_CBTOV = copy_CB;
	}
}

//SetTMR0Compare
void  TMR2_voidSetOCR2(u8 copy_u8InitValue)
{
	OCR2 = copy_u8InitValue;
}

void  TMR2_voidSetCTCWithInterrupt(void (*copy_CB)(void))
{
	Global_CBCTC = copy_CB;
}

void  TMR2_voidStopTMR2(void)
{
	// Make CS bit Zeros
	TCCR2 &= 0xF8;
}

// Set TCCR0 =0x00
void  TMR2_voidDInit(void)
{
	// Put TCCR0 all bits zeros
	TCCR2 = 0x00;
}

void  TMR2_GenerateFastPWM(u8 copy_u8DutyCycle)
{
	// Make OC2 Output pin
	SET_BIT(DDRD,7);
	volatile u8 Local_u8Data = 0;
	#if   TMR2_COM_FASTPWM == 0x20
		Local_u8Data = ((256 * copy_u8DutyCycle)/100)-1;
		TMR2_voidSetOCR2(Local_u8Data);
	#elif TMR2_COM_FASTPWM == 0x30
		Local_u8Data = 255-((256 * copy_u8DutyCycle)/100);
		TMR2_voidSetOCR2(Local_u8Data);
	#endif
}

void  TMR2_GeneratePhaseCorrectPWM(u8 copy_u8DutyCycle)
{
	// Make OC0 Output pin
	SET_BIT(DDRD,7);
	volatile u8 Local_u8Data = 0;
	#if   TMR2_COM_PCPWM == 0x20
		Local_u8Data = ((255 * copy_u8DutyCycle)/100);
		TMR2_voidSetOCR2(Local_u8Data);
	#elif TMR2_COM_PCPWM == 0x30
		Local_u8Data = 255-((255 * copy_u8DutyCycle)/100);
		TMR2_voidSetOCR2(Local_u8Data);
	#endif
}

ISR(TIMER2_OVF_vect)
{
	TOV_Counter++;
	if(flag !=0)
	{
		(*Global_CBTOV)();
	}
}

ISR(TIMER2_COMP_vect)
{
	(*Global_CBCTC)();
	SET_BIT(TIFR,OCF0);
}