/****************************************************************/
/* Author   :  Mahmoud Ayman                                    */
/* Date     :  29 OCT 2020                                      */
/* Version  :  V 1.0                                            */
/* File     :  EEPROM_interface                                 */
/* LOG      :                                                   */
/****************************************************************/


#ifndef  EEPROM_INTERFACE_H
#define  EEPROM_INTERFACE_H


void EEPROM_voidWrite(u16 copy_u16Address, u8 copy_u8Data);

u8 EEPROM_voidRead(u16 copy_u16Address);

#endif