/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 13 NOV 2020                                */
/* File    : TMR0_config                               */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

#ifndef  TMR0_CONFIG_H
#define  TMR0_CONFIG_H

/* Options : 0 for Normal mode 
			 1 for Phase PWM mode 
			 2 for CTC Mode
			 3 for Fast PWM mode 
			 4 for NON-PWM mode 
*/
#define  TMR0_MODE  3

/* Options : for NON PWM
			 0x00 for Normal Port Operation
			 0x10 for Toggle OC0 on Compare match
			 0x20 for Clear OC0 on Compare match
			 0x30 for Set OC0 on Compare match
*/
#define  TMR0_COM_NONPWM 0x00

/* Options : for Fast PWM
			 0x00 for Normal Port Operation
			 0x20 for Clear OC0 on Compare match and set on Bottom
			 0x30 for Set OC0 on Compare match and Clear on Bottom
*/
#define  TMR0_COM_FASTPWM 0x30

/* Options : for Phase Correct PWM
			 0x00 for Normal Port Operation
			 0x20 for Clear OC0 on Compare match on upcount and set at compare match on downcount
			 0x30 for Set OC0 on Compare match on upcount and Clear at compare match on downcount
*/
// Phase correct PWM
#define  TMR0_COM_PCPWM 0x00

/* Options : 0 for Disable FOC0
			 1 for Enable  FOC0
*/
#define  TMR0_FOC0  0

/* Options : 0 for Disable Overflow Interrupt
			 1 for Enable  Overflow Interrupt
*/
#define TMR0_TOVINTERRUPT   0

/* Options : 0 for Disable Compare match Interrupt
			 1 for Enable  Compare match Interrupt
*/
#define TMR0_TOCINTERRUPT 0

#endif
