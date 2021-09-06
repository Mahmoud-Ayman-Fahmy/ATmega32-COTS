/****************************************************************/
/* Author   :  Mahmoud Ayman                                    */
/* Date     :  18 JAN 2021                                      */
/* Version  :  V 1.0                                            */
/* File     :  TWI_program                                      */
/* LOG      :                                                   */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"

void TWI_voidInitMaster(u64 SCL_frequency)
{
	TWBR = (u8)(((F_CPU/SCL_frequency)-16)/(2* PRESCALER))
	/* Adjust prescaler */ 
	#if   PRESCALER == 1
		TWSR = 0;
	#elif PRESCALER == 4
		TWSR = 1;
	#elif PRESCALER == 16
		TWSR = 2; 
	#else 
		TWSR = 3;
	#endif
}

void TWI_voidStart(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);   //1010 0100 /*SET_BIT(TWCR, TWINT); SET(TWCR , TWEN); SET_BIT(TWCR , TWSTA);*/
	//TWCR = 0b10100100
	while(GET_BIT(TWCR,TWINT)==0); // wait until start condition sent
	while((TWSR &0xF8) != 0x08);
}

void TWI_voidWriteAddress(u8 Address);
{
	TWDR = Address;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR, TWINT) ==0); // wait to finish 
	while((TWSR &0xF8) != 0x18); // Address has been transmitted and ACK has been Received 
}

void TWI_voidWriteDate(u8 Data)
{
	TWDR = Data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR, TWINT) ==0); // wait to finish 
	while((TWSR &0xF8) != 0x28); // Data has been Transmitted and ACK received
}

void TWI_voidStop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO); 
}

void TWI_voidSetAddress(u8 Address)
{
	TWAR = Address;
}

u8 TWI_u8SalveRead(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(GET_BIT(TWCR, TWINT) ==0);
	while((TWSR &0xF8) != 0x60); // Address Recived and ACK has been returned
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(GET_BIT(TWCR, TWINT) ==0);
	while((TWSR &0xF8) != 0x80); // Data Recived and ACK has been returned
	return TWDR;
	
}