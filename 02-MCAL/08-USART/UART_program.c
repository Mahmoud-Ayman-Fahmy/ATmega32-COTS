/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 27 NOV 2020                              */
/* File     : UART_program                             */
/* Version  : V 1.0                                    */
/* LOG      :                                          */
/*******************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"

void (*CB_TX)(void);
void (*CB_RX)(void);
void (*CB_UDR)(void);

void USART_voidInit(u32 copy_u8BaudRate)
{
	u16 Local_UBRR;
	/* Adjust Mode */
	CLR_BIT(USCRC,URSEL);
	#if    USART_MODE == 0
		//SET_BIT(USCRC,URSEL);
		CLR_BIT(USCRC,UMSEL);
		Local_UBRR = (8000000/(16*copy_u8BaudRate))-1;
	#elif  USART_MODE == 2
		CLR_BIT(USCRC,UMSEL);
		SET_BIT(USCRA,U2X);
		Local_UBRR = (8000000/(8*copy_u8BaudRate))-1;
	#else 
		SET_BIT(USCRC,UMSEL);
		Local_UBRR = (8000000/(2*copy_u8BaudRate))-1;
	#endif
	
	/* Adjust Word Size */
	#if   USART_WORDSIZE == 0
		CLR_BIT(USCRC,UCSZ0);
		CLR_BIT(USCRC,UCSZ1);
		CLR_BIT(USCRB,UCSZ2);
	#elif USART_WORDSIZE == 1
		SET_BIT(USCRC,UCSZ0);
		CLR_BIT(USCRC,UCSZ1);
		CLR_BIT(USCRB,UCSZ2);
	#elif USART_WORDSIZE == 2
		CLR_BIT(USCRC,UCSZ0);
		SET_BIT(USCRC,UCSZ1);
		CLR_BIT(USCRB,UCSZ2);
	#elif USART_WORDSIZE == 3
		SET_BIT(USCRC,UCSZ0);
		SET_BIT(USCRC,UCSZ1);
		CLR_BIT(USCRB,UCSZ2);
	#else 
		SET_BIT(USCRC,UCSZ0);
		SET_BIT(USCRC,UCSZ1);
		SET_BIT(USCRB,UCSZ2);
	#endif
	
	/* Adjust Parity */
	#if   USART_PARITY  == 0
		CLR_BIT(USCRC,UPM0);
		CLR_BIT(USCRC,UPM1);
	#elif USART_PARITY  == 1
		CLR_BIT(USCRC,UPM0);
		SET_BIT(USCRC,UPM1);
	#else 
		SET_BIT(USCRC,UPM0);
		SET_BIT(USCRC,UPM1);
	#endif
	
	/* Adjust Stop bit */
	#if  USART_STOPBIT == 0
		CLR_BIT(USCRC,USBS);
	#else 
		SET_BIT(USCRC,USBS);
	#endif
	
	/* Enable TX and RX */
	SET_BIT(USCRB,TXEN);
	SET_BIT(USCRB,RXEN);
	
	/* Adjust UBRR */
	SET_BIT(USCRC,URSEL);
	UBRRH = (u8)(Local_UBRR >> 8);
	UBRRL = (u8)(Local_UBRR);
}
void USART_voidSendByte(u8 copy_u8DataSend)
{
	while(GET_BIT(USCRA,UDRE)==0);
	UDR = copy_u8DataSend ;
}

u8 USART_u8RecieveByte(void)
{
	while(GET_BIT(USCRA,RXC)==0);
	return UDR;
}

void USART_voidEnableTXInterrupt(void)
{
	SET_BIT(USCRB,TXCIE);
}

void USART_voidEnableRXInterrupt(void)
{
	SET_BIT(USCRB,RXCIE);
}

void USART_voidEnableUDREInterrupt(void)
{
	SET_BIT(USCRB,UDRIE);
}

void USART_voidSetCBTX(void(*copy_CB)(void))
{
	CB_TX = copy_CB;
}

void USART_voidSetCBRX(void(*copy_CB)(void))
{
	CB_RX = copy_CB;
}

void USART_voidSetCBUDRE(void(*copy_CB)(void))
{
	CB_UDR = copy_CB;
}

void USART_voidSendString(u8 *copy_ptrString)
{
	while((*copy_ptrString) != '\0')
	{
		USART_voidSendByte(*copy_ptrString);
		copy_ptrString++;
	}
}

void USART_voidSendu32Block(u32 copy_u32DataSend)
{
	u8 Data;
	u8 counter;
	for(counter = 0; counter <=3 ; counter ++)
	{
		Data = (u8)(copy_u32DataSend >> (8*counter));
		USART_voidSendByte(Data);
	}
}
u32 USART_u32Recieveu32Block(void)
{
	u32 Data;
	u8 counter;
	for(counter = 0; counter <=3 ; counter ++)
	{
		Data |=(USART_u8RecieveByte() << (8* counter)); 
	} 
	return Data;
}
