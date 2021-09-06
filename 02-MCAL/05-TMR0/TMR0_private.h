/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 13 NOV 2020                                */
/* File    : TMR0_private                               */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

#ifndef  TMR0_PRIVATE_H
#define  TMR0_PRIVATE_H

// Timer0 counter Register
#define TCNT0    *((volatile u8*)0x52)
// Timer0 Compare Register
#define OCR0     *((volatile u8*)0x5C)
// Timer0 control Register
#define TCCR0    *((volatile u8*)0x53)
	#define CS00  0
	#define CS01  1
	#define CS02  2
	#define WGM01 3
	#define COM00 4
	#define COM01 5
	#define WGM00 6
	#define FOC0  7
// Interrupt Control
#define TIMASK   *((volatile u8*)0x59)
	#define TOIE0 0
	#define OCIE0 1
// Interrupt Flags
#define TIFR     *((volatile u8*)0x58)
	#define TOV0  0
	#define OCF0  1
// Global Interrupt Register
#define SREG     *((volatile u8*)0x5F)
// OC0 Data Direction Register
#define DDRB     *((volatile u8*)0x37)

#endif
