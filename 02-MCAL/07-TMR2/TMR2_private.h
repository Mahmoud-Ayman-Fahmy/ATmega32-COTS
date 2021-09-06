/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 13 NOV 2020                                */
/* File    : TMR2_private                               */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

#ifndef  TMR2_PRIVATE_H
#define  TMR2_PRIVATE_H

// Timer2 counter Register
#define TCNT2    *((volatile u8*)0x44)
// Timer2 Compare Register
#define OCR2     *((volatile u8*)0x43)
// Timer2 control Register
#define TCCR2    *((volatile u8*)0x45)
	#define CS20  0
	#define CS21  1
	#define CS22  2
	#define WGM21 3
	#define COM20 4
	#define COM21 5
	#define WGM20 6
	#define FOC2  7
// Interrupt Control
#define TIMASK   *((volatile u8*)0x59)
	#define TOIE2 6
	#define OCIE2 7
// Interrupt Flags
#define TIFR     *((volatile u8*)0x58)
	#define TOV2  6
	#define OCF2  7
// Global Interrupt Register
#define SREG     *((volatile u8*)0x5F)
// OC0 Data Direction Register
#define DDRD     *((volatile u8*)0x31)

#define ASSR     *((volatile u8*)0x42)
	#define AS2  3

#endif