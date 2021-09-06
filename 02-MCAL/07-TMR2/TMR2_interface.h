/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 13 NOV 2020                                */
/* File    : TMR2_interface                             */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

#ifndef  TMR2_INTERFACE_H
#define  TMR2_INTERFACE_H

#define TMR2_CLK_1    0x01
#define TMR2_CLK_8    0x02
#define TMR2_CLK_32   0x03
#define TMR2_CLK_64   0x04
#define TMR2_CLK_128  0x05
#define TMR2_CLK_256  0x06
#define TMR2_CLK_1024 0x07

void  TMR2_voidInit(void);
void  TMR2_voidStart(u8 copy_u8Prescaler);
// SetTMR0Start
void  TMR2_voidSetTCNT2(u8 copy_u8InitValue);

u32   TMR2_u32ReadTMR2(void);

void  TMR2_voidSetNormalWithInterrupt(void (*copy_CB)(void));
//SetTMR0Compare
void  TMR2_voidSetOCR2(u8 copy_u8InitValue);

void  TMR2_voidSetCTCWithInterrupt(void (*copy_CB)(void));

void  TMR2_voidStopTMR2(void);
// Set TCCR0 =0x00
void  TMR2_voidDInit(void);

void  TMR2_GenerateFastPWM(u8 copy_u8DutyCycle);

void  TMR2_GeneratePhaseCorrectPWM(u8 copy_u8DutyCycle);


#endif