/****************************************************************/
/* Author   :  Mahmoud Ayman                                    */
/* Date     :  29 OCT 2020                                      */
/* Version  :  V 1.0                                            */
/* File     :  EEPROM_private                                   */
/* LOG      :                                                   */
/****************************************************************/


#ifndef  EEPROM_PRIVATE_H
#define  EEPROM_PRIVATE_H
	
	#define  EEARH     *((volatile u8*)0x3F)
	#define  EEARL	   *((volatile u8*)0x3E)
	#define  EEDR 	   *((volatile u8*)0x3D)
	#define  EECR	   *((volatile u8*)0x3C)
		#define  EERE   0
		#define  EEWE   1
		#define  EEMWE  2
		#define  EERIE  3

#endif