/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 27 NOV 2020                              */
/* File     : UART_interface                           */
/* Version  : V 1.0                                    */
/* LOG      :                                          */
/*******************************************************/


#ifndef  UART_INTERFACE_H
#define  UART_INTERFACE_H


void USART_voidInit(u32 copy_u8BaudRate);

void USART_voidSendByte(u8 copy_u8DataSend);

u8 USART_u8RecieveByte(void);

void USART_voidEnableTXInterrupt(void);

void USART_voidEnableRXInterrupt(void);

void USART_voidEnableUDREInterrupt(void);

void USART_voidSetCBTX(void(*copy_CB)(void));

void USART_voidSetCBRX(void(*copy_CB)(void));

void USART_voidSetCBUDRE(void(*copy_CB)(void));

void USART_voidSendString(u8 *copy_ptrString);

void USART_voidSendu32Block(u32 copy_u32DataSend);

u32 USART_u32Recieveu32Block(void);

#endif
