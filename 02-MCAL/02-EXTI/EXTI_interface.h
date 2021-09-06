/****************************************************************/
/* Author   :  Mahmoud Ayman                                    */
/* Date     :  23 OCT 2020                                      */
/* Version  :  V 1.0                                            */
/* File     :  EXTI_interface                                   */
/* LOG      :                                                   */
/****************************************************************/

#ifndef   EXTI_INTERFACE_H
#define   EXTI_INTERFACE_H

	#define EXTI_INT0   0
	#define EXTI_INT1   1
	#define EXTI_INT2   2
	
	void EXTI_voidInit(u8 copy_u8IntNum, void (* copy_CB)(void));




#endif  