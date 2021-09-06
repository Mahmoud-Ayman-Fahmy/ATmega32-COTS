/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 13 NOV 2020                                */
/* File    : TMR1_private                               */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

#ifndef  TMR1_PRIVATE_H
#define  TMR1_PRIVATE_H


#define ICR1      (*(volatile u16*)0x46)
#define ICR1L     (*(volatile u8* )0x46)
#define ICR1H     (*(volatile u8* )0x47)
#define OCR1B     (*(volatile u16*)0x48)
#define OCR1BL    (*(volatile u8* )0x48)
#define OCR1BH    (*(volatile u8* )0x49)
#define OCR1A     (*(volatile u16*)0x4A)
#define OCR1AL    (*(volatile u8* )0x4A)
#define OCR1AH    (*(volatile u8* )0x4B)
#define TCNT1     (*(volatile u16*)0x4C)
#define TCNT1L    (*(volatile u8* )0x4C)
#define TCNT1H    (*(volatile u8* )0x4D)
#define TCCR1B    (*(volatile u8* )0x4E)
	#define ICNC1   7
	#define ICES1   6
	/* bit 5 reserved */
	#define WGM13   4
	#define WGM12   3
	#define CS12    2
	#define CS11    1
	#define CS10    0
#define TCCR1A    (*(volatile u8* )0x4F)
	#define COM1A1  7
	#define COM1A0  6
	#define COM1B1  5
	#define COM1B0  4
	#define FOC1A   3
	#define FOC1B   2
	#define WGM11   1
	#define WGM10   0



#endif