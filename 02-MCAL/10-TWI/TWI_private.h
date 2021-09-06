/****************************************************************/
/* Author   :  Mahmoud Ayman                                    */
/* Date     :  18 JAN 2021                                      */
/* Version  :  V 1.0                                            */
/* File     :  TWI_private                                      */
/* LOG      :                                                   */
/****************************************************************/

#ifndef   TWI_PRIVATE_H
#define   TWI_PRIVATE_H

#define TWDR *((volatile u8*)0x23)

#define TWAR *((volatile u8*)0x22)

#define TWSR *((volatile u8*)0x21)

#define TWCR *((volatile u8*)0x56)
	#define TWINT  7
	#define TWEA   6 
	#define TWSTA  5
	#define TWSTO  4
	#define TWWC   3
	#define TWEN   2
	#define TWIE   0
	

#endif 