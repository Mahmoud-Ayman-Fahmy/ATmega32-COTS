/****************************************************************/
/* Author   :  Mahmoud Ayman                                    */
/* Date     :  29 OCT 2020                                      */
/* Version  :  V 1.0                                            */
/* File     :  EEPROM_program                                   */
/* LOG      :                                                   */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"


void EEPROM_voidWrite(u16 copy_u16Address, u8 copy_u8Data)
{
	EEARL = (u8)copy_u16Address;
	EEARH = (u8)(copy_u16Address >> 8);
	EEDR  =  copy_u8Data;
	SET_BIT(EECR, EEMWE);
	SET_BIT(EECR, EEWE);
	while(GET_BIT(EECR, EEWE)==1);
}

u8 EEPROM_voidRead(u16 copy_u16Address)
{
	EEARL = (u8)copy_u16Address;
	EEARH = (u8)(copy_u16Address >> 8);
	SET_BIT(EECR, EERE);
	return EEDR;
}