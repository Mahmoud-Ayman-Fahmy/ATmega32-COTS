/**********************************************/
/* Author  : Mahmoud Ayman                    */
/* Date    : 17 DEC 2020                      */
/* File    : SPI_interface                    */
/* Version : V 1.0                            */
/**********************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_voidInit(void);

u8 SPI_u8SendReceive(u8 copy_Data);

void SPI_voidSendString(u8 *copy_ptr);

#endif