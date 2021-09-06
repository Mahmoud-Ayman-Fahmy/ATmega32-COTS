/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 13 NOV 2020                                */
/* File    : ULTRASONIC_program                         */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "TMR1_interface.h"

#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_private.h"

#define F_CPU  8000000UL
#include "util/delay.h"

static volatile u16 t1,t2,flag=0,c=0;

void ULTRASONIC_voidInit(void)
{
	Timer1_voidInit(TIMER1_NORMAL_MODE,TIMER1_SCALER_8,OCRA_DISCONNECTED,OCRB_DISCONNECTED);
	Timer1_OVF_SetCallBack(Func_OVF);
	Timer1_ICU_SetCallBack(Func_ICU);
}

u8 ULTRASONIC_GetDistance(u8 ultrasonicTX_port,u8 ultrasonicTx_pin)
{
	u8 distance;
	u16 time;
	GPIO_voidSetPinDDR(ultrasonicTX_port,ultrasonicTx_pin,OUTPUT);
	//TCNT1=0;
	c=0;
	flag=0;
	GPIO_voidWritePin(ultrasonicTX_port,ultrasonicTx_pin,HIGH);
	_delay_us(10);
	GPIO_voidWritePin(ultrasonicTX_port,ultrasonicTx_pin,LOW);
	Timer1_InputCaptureEdge(ICU_RISING);
	Timer1_ICU_InterruptEnable();
	while (flag<2);
	time=t2-t1+((u32)c*65535);
	distance=time/58;
	Timer1_ICU_InterruptDisable();
	return distance;	
}


static void Func_ICU(void)
{
	if(flag==0)
	{
		c=0;
		t1=Timer1_ReturnICU();
		flag=1;
		Timer1_InputCaptureEdge(ICU_FALLING);
	}
	else if (flag==1)
	{
		t2=Timer1_ReturnICU();
		flag=2;
		Timer1_InputCaptureEdge(ICU_RISING);
		Timer1_OVF_InterruptDisable();
		Timer1_ICU_InterruptDisable();
	}
}

static void Func_OVF(void)
{
	c++
}