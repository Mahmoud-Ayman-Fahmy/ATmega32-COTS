/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 13 NOV 2020                                */
/* File    : TMR1_program                               */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TMR1_interface.h"
#include "TMR1_private.h"
#include "TMR1_config.h"

#define NULLPTR   ((void*)0)

static void (*Timer1_OVF_Fptr) (void)=NULLPTR;
static void (*Timer1_OCA_Fptr) (void)=NULLPTR;
static void (*Timer1_OCB_Fptr) (void)=NULLPTR;
static void (*Timer1_ICU_Fptr) (void)=NULLPTR;


void Timer1_voidInit(u8 Timer1_Mode, u8 Timer1_Scaler, u8 Timer1_OCR1AMode, u8 Timer1_OCR1BMode)
{
	switch (Timer1_Mode)
	{
		case TIMER1_NORMAL_MODE:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_CTC_ICR_TOP_MODE:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
			CLR_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_FASTPWM_ICR_TOP_MODE:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
	}
	switch (Timer1_OCR1AMode)
	{
		case OCRA_DISCONNECTED:
			CLR_BIT(TCCR1A,COM1A0);
			CLR_BIT(TCCR1A,COM1A1);
			break;
		case OCRA_TOGGLE:
			SET_BIT(TCCR1A,COM1A0);
			CLR_BIT(TCCR1A,COM1A1);
			break;
		case OCRA_NON_INVERTING:
			CLR_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break;
		case OCRA_INVERTING:
			SET_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break;
	}
	switch (Timer1_OCR1BMode)
	{
		case OCRB_DISCONNECTED:
			CLR_BIT(TCCR1A,COM1B0);
			CLR_BIT(TCCR1A,COM1B1);
			break;
		case OCRB_TOGGLE:
			SET_BIT(TCCR1A,COM1B0);
			CLR_BIT(TCCR1A,COM1B1);
			break;
		case OCRB_NON_INVERTING:
			CLEAR_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
			break;
		case OCRB_INVERTING:
			SET_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
			break;
	}
	TCCR1B&=0XF8;
	TCCR1B|=scaler;
}

void Timer1_InputCaptureEdge(u8 ICU_Edge)
{
	if(ICU_Edge==ICU_RISING)
	{
		SET_BIT(TCCR1B,ICES1);
	}
	else if(ICU_Edge==ICU_FALLING)
	{
		CLR_BIT(TCCR1B,ICES1);
	}
	
}

u16 Timer1_ReturnICU(void)
{
	return ICR1;
}

void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}

void Timer1_OVF_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE1);
}

void Timer1_OCR1A_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}

void Timer1_OCR1A_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE1A);
}

void Timer1_OCR1B_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}

void Timer1_OCR1B_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE1B);
}

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TICIE1);
}

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OVF_Fptr=LocalFptr;
}

void Timer1_OCR1A_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr=LocalFptr;
}

void Timer1_OCR1B_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr=LocalFptr;
}

void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}

/*********************************Timer 1 ISR functions*********************************************/
ISR(TIMER1_OVF_vect)
{
	if(Timer1_OVF_Fptr!=NULLPTR)
	{
		Timer1_OVF_Fptr();
	}
}
ISR(TIMER1_OCA_vect)
{
	if(Timer1_OCA_Fptr!=NULLPTR)
	{
		Timer1_OCA_Fptr();
	}
}
ISR(TIMER1_OCB_vect)
{
	if(Timer1_OCB_Fptr!=NULLPTR)
	{
		Timer1_OCB_Fptr();
	}
}
ISR(TIMER1_ICU_vect)
{
	if(Timer1_ICU_Fptr!=NULLPTR)
	{
		Timer1_ICU_Fptr();
	}
}