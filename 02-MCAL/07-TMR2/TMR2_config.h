/********************************************************/
/* Author  : Mahmoud Ayman                              */
/* Date    : 13 NOV 2020                                */
/* File    : TMR2_config                               */ 
/* Version : V 1.0                                      */      
/* LOG     :                                            */
/********************************************************/

#ifndef  TMR2_CONFIG_H
#define  TMR2_CONFIG_H


/* Options : 0 for Normal mode 
			 1 for Phase PWM mode 
			 2 for CTC Mode
			 3 for Fast PWM mode 
			 4 for NON-PWM mode 
*/
#define  TMR2_MODE  3

/* Options : for NON PWM
			 0x00 for Normal Port Operation
			 0x10 for Toggle OC2 on Compare match
			 0x20 for Clear  OC2 on Compare match
			 0x30 for Set    OC2 on Compare match
*/
#define  TMR2_COM_NONPWM 0x00

/* Options : for Fast PWM
			 0x00 for Normal Port Operation
			 0x20 for Clear OC2 on Compare match and set on Bottom
			 0x30 for Set   OC2 on Compare match and Clear on Bottom
*/
#define  TMR2_COM_FASTPWM 0x30

/* Options : for Phase Correct PWM
			 0x00 for Normal Port Operation
			 0x20 for Clear OC2 on Compare match on upcount and set at compare match on downcount
			 0x30 for Set   OC2 on Compare match on upcount and Clear at compare match on downcount
*/
// Phase correct PWM
#define  TMR2_COM_PCPWM 0x00

/* Options : 0 for Disable FOC2
			 1 for Enable  FOC2
*/
#define  TMR2_FOC2  0

/* Options : 0 for Disable Overflow Interrupt
			 1 for Enable  Overflow Interrupt
*/
#define TMR2_TOVINTERRUPT   0

/* Options : 0 for Disable Compare match Interrupt
			 1 for Enable  Compare match Interrupt
*/
#define TMR2_TOCINTERRUPT 0

/* Options : 0 for Disable RTC
			 1 for Enable  RTC
*/
#define TMR2_TRCCONTROL  0

#endif