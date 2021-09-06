/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 27 NOV 2020                              */
/* File     : UART_private                             */
/* Version  : V 1.0                                    */
/* LOG      :                                          */
/*******************************************************/


#ifndef  UART_PRIVATE_H
#define  UART_PRIVATE_H

#define  UDR    *((volatile u8*)0x2C)

#define  USCRA  *((volatile u8*)0x2B)
	#define RXC      7
	#define TXC      6
	#define UDRE     5
	#define FE       4
	#define DOR      3
	#define PE       2
	#define U2X      1
	#define MPCM     0
	
#define  USCRB  *((volatile u8*)0x2A)
	#define RXCIE    7
	#define TXCIE    6
	#define UDRIE    5
	#define RXEN     4
	#define TXEN     3
	#define UCSZ2    2
	#define RXB8     1
	#define TXB8     0
	
#define  USCRC  *((volatile u8*)0x40)
	#define URSEL    7
	#define UMSEL    6
	#define UPM1     5
	#define UPM0     4
	#define USBS     3
	#define UCSZ1    2
	#define UCSZ0    1
	#define UCPOL    0
	
#define  UBRRL  *((volatile u8*)0x29)

#define  UBRRH  *((volatile u8*)0x40)


#endif
