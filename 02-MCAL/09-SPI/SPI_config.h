/**********************************************/
/* Author  : Mahmoud Ayman                    */
/* Date    : 17 DEC 2020                      */
/* File    : SPI_config                       */
/* Version : V 1.0                            */
/**********************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Options : MASTER or Slave */
#define SPI_MODE  

/* Options : MSB or LSB */
#define SPI_DATAORDER

/* Options : IDEL_LOW or IDEL_HIGH */
#define SPI_OPERATINGLEVEL

/* Options : RISING or FALLING */
#define SPI_CLOCKPHASE

/* Options : NORMAL_SPEED or DOUBLE_SPEED */
#define SPI_SPEEDMODE

/* Options : FN_4, FN_16, FN_64, FN_128 for Normal Speed 
			 FD_2, FD_8 , FD_32, FD_64  for Double Speed
*/			 
#define SPI_FREQUENCY_PRESCALER


#endif 