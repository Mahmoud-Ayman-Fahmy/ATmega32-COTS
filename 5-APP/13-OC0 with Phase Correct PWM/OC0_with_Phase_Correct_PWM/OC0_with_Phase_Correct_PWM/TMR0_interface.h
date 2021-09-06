/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 13 NOV 2020                                */
/* File    : TMR0_interface                             */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

#ifndef  TMR0_INTERFACE_H
#define  TMR0_INTERFACE_H

#define TMR0_CLKMC    0x01
#define TMR0_CLK_8    0x02
#define TMR0_CLK_64   0x03 
#define TMR0_CLK_256  0x04
#define TMR0_CLK_1024 0x05
#define TMR0_EVENT_FE 0x06
#define TMR0_EVENT_RE 0x07

void  TMR0_voidInit(void);
void  TMR0_voidStart(u8 copy_u8Prescaler);
// SetTMR0Start
void  TMR0_voidSetTCNT0(u8 copy_u8InitValue);

u32   TMR0_u32ReadTMR0(void);

void  TMR0_voidSetNormalWithInterrupt(void (*copy_CB)(void));
//SetTMR0Compare
void  TMR0_voidSetOCR0(u8 copy_u8InitValue);

void  TMR0_voidSetCTCWithInterrupt(void (*copy_CB)(void));

void  TMR0_voidStopTMR0(void);
// Set TCCR0 =0x00
void  TMR0_voidDInit(void);

void TMR0_GenerateFastPWM(u8 copy_u8DutyCycle);

void TMR0_GeneratePhaseCorrectPWM(u8 copy_u8DutyCycle);

#endif