/****************************************************************/
/* Author   :  Mahmoud Ayman                                    */
/* Date     :  23 OCT 2020                                      */
/* Version  :  V 1.0                                            */
/* File     :  EXTI_private                                     */
/* LOG      :                                                   */
/****************************************************************/

#ifndef   EXTI_PRIVATE_H
#define   EXTI_PRIVATE_H

	#define  SREG     *((volatile u8*)0x5F)
		#define GI      7
	#define  GIFR     *((volatile u8*)0x5A)
		#define INTF1   7
		#define INTF0   6
		#define INTF2   5
	#define  MCUCSR   *((volatile u8*)0x54)
		#define ISC2    6
	#define  MCUCR    *((volatile u8*)0x55)
		#define ISC11   3
		#define ISC10   2
		#define ISC01   1
		#define ISC00   0
	#define  GICR     *((volatile u8*)0x5B)
		#define INT1    7
		#define INT0    6
		#define INT2    5
			
	#define   DDRB    *((volatile u8*)0x37)
	
	#define   DDRD    *((volatile u8*)0x31) 

#endif  