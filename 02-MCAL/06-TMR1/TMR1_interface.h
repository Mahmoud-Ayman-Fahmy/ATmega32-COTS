/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 13 NOV 2020                                */
/* File    : TMR1_interface                             */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

#ifndef  TMR1_INTERFACE_H
#define  TMR1_INTERFACE_H
/***********************Timer1 Scaler Type***************/
#define	TIMER1_STOP                  0   
#define	TIMER1_SCALER_1              1
#define	TIMER1_SCALER_8              2
#define	TIMER1_SCALER_64             3
#define	TIMER1_SCALER_256            4
#define	TIMER1_SCALER_1024           5
#define	EXTERNAL0_FALLING            6
#define	EXTERNAL0_RISING             7


/***********************Timer1 Mode Type***************/
#define	TIMER1_NORMAL_MODE           0
#define	TIMER1_CTC_ICR_TOP_MODE      1
#define	TIMER1_CTC_OCRA_TOP_MODE     2
#define	TIMER1_FASTPWM_ICR_TOP_MODE  3
#define	TIMER1_FASTPWM_OCRA_TOP_MODE 4

/***********************OCR1A Scaler Type***************/
#define	OCRA_DISCONNECTED            0  
#define	OCRA_TOGGLE                  1
#define	OCRA_NON_INVERTING           2
#define	OCRA_INVERTING               3

/***********************OCR1B Scaler Type***************/
#define	OCRB_DISCONNECTED            0 
#define	OCRB_TOGGLE                  1
#define	OCRB_NON_INVERTING           2
#define	OCRB_INVERTING               3

/***********************ICU Edge Type***************/
#define ICU_RISING                   1
#define ICU_FALLING                  2

/****************************************************/

/*********************ProtoType**********************/

void Timer1_voidInit(u8 Timer1_Mode, u8 Timer1_Scaler, u8 Timer1_OCR1AMode, u8 Timer1_OCR1BMode);

void Timer1_InputCaptureEdge(u8 ICU_Edge);

u16 Timer1_ReturnICU(void);

void Timer1_OVF_InterruptEnable(void);

void Timer1_OVF_InterruptDisable(void);

void Timer1_OCR1A_InterruptEnable(void);

void Timer1_OCR1A_InterruptDisable(void);

void Timer1_OCR1B_InterruptEnable(void);

void Timer1_OCR1B_InterruptDisable(void);

void Timer1_ICU_InterruptEnable(void);

void Timer1_ICU_InterruptDisable(void);

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void));

void Timer1_OCR1A_SetCallBack(void(*LocalFptr)(void));

void Timer1_OCR1B_SetCallBack(void(*LocalFptr)(void));

void Timer1_ICU_SetCallBack(void(*LocalFptr)(void));


#endif