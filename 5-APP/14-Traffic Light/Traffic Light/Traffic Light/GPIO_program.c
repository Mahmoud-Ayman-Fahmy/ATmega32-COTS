/*******************************************************/
/* Author   : Mahmoud Ayman                            */
/* Date     : 10 OCT 2020                              */
/* File     : GPIO_program                             */
/* Version  : V 1.0                                    */
/* LOG      : 1- Add Port set Direction                */
/*				 Add Write On Port                     */
/*			  2- Add Nibble Set Direction			   */	
/*				 Add Write On Nibble     			   */				   
/*******************************************************/


/* LIB include */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Driver Include */
#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

void GPIO_voidSetPinDDR(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Mode)
{
	switch(copy_u8Port)
	{
		case GPIOA :
			if(copy_u8Mode == OUTPUT)
			{
				SET_BIT(DDRA,copy_u8Pin);
			}
			else
			{
				CLR_BIT(DDRA,copy_u8Pin);
			}
			break;
		case GPIOB :
			if(copy_u8Mode == OUTPUT)
			{
				SET_BIT(DDRB,copy_u8Pin);
			}
			else
			{
				CLR_BIT(DDRB,copy_u8Pin);
			}
			break;
		case GPIOC :
			if(copy_u8Mode == OUTPUT)
			{
				SET_BIT(DDRC,copy_u8Pin);
			}
			else
			{
				CLR_BIT(DDRC,copy_u8Pin);
			}
			break;
		case GPIOD :
			if(copy_u8Mode == OUTPUT)
			{
				SET_BIT(DDRD,copy_u8Pin);
			}
			else
			{
				CLR_BIT(DDRD,copy_u8Pin);
			}
			break;
		default :  
			break;	
	}
}

void GPIO_voidWritePin(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{
	switch(copy_u8Port)
	{
		case GPIOA :
			if(copy_u8Value == HIGH)
			{
				SET_BIT(PORTA,copy_u8Pin);
			}
			else
			{
				CLR_BIT(PORTA,copy_u8Pin);
			}
			break;
		case GPIOB :
			if(copy_u8Value == HIGH)
			{
				SET_BIT(PORTB,copy_u8Pin);
			}
			else
			{
				CLR_BIT(PORTB,copy_u8Pin);
			}
			break;
		case GPIOC :
			if(copy_u8Value == HIGH)
			{
				SET_BIT(PORTC,copy_u8Pin);
			}
			else
			{
				CLR_BIT(PORTC,copy_u8Pin);
			}
			break;
		case GPIOD :
			if(copy_u8Value == HIGH)
			{
				SET_BIT(PORTD,copy_u8Pin);
			}
			else
			{
				CLR_BIT(PORTD,copy_u8Pin);
			}
			break;
		default :  
			break;	
	}
}


u8   GPIO_u8ReadPin(u8 copy_u8Port, u8 copy_u8Pin)
{
	u8 Local_u8ReturnValue;
	switch(copy_u8Port)
	{
		case GPIOA :
			Local_u8ReturnValue = GET_BIT(PINA,copy_u8Pin);
			break;
		case GPIOB :
			Local_u8ReturnValue = GET_BIT(PINB,copy_u8Pin);
			break;
		case GPIOC :
			Local_u8ReturnValue = GET_BIT(PINC,copy_u8Pin);
			break;
		case GPIOD :
			Local_u8ReturnValue = GET_BIT(PIND,copy_u8Pin);
			break;
		default :
			break;
	}
	return Local_u8ReturnValue;
}

void GPIO_voidTogglePin(u8 copy_u8Port, u8 copy_u8Pin)
{
	switch(copy_u8Port)
		{
			case GPIOA :
				TOG_BIT(PORTA, copy_u8Pin);
				break;
			case GPIOB :
				TOG_BIT(PORTB, copy_u8Pin);
				break;
			case GPIOC :
				TOG_BIT(PORTC, copy_u8Pin);
				break;
			case GPIOD :
				TOG_BIT(PORTD, copy_u8Pin);
				break;
			default:
				break;
		}
}

void GPIO_voidSetPortDDR(u8 copy_u8Port, u8 copy_u8Mode)
{
	switch(copy_u8Port)
	{
		case GPIOA :  
			if(copy_u8Mode == OUTPUT)
			{
				DDRA = 0xff;
			}
			else
			{
				DDRA = 0x00;
			}
			break;
		case GPIOB :  
			if(copy_u8Mode == OUTPUT)
			{
				DDRB = 0xff;
			}
			else
			{
				DDRB = 0x00;
			}
			break;
		case GPIOC :  
			if(copy_u8Mode == OUTPUT)
			{
				DDRC = 0xff;
			}
			else
			{
				DDRC = 0x00;
			}
			break;
		case GPIOD :  
			if(copy_u8Mode == OUTPUT)
			{
				DDRD = 0xff;
			}
			else
			{
				DDRD = 0x00;
			}
			break;
		default:
			break;
	}
}

void GPIO_voidWritePort(u8 copy_u8Port , u8 copy_u8Value)
{
	switch (copy_u8Port)
	{
		case GPIOA :  PORTA = copy_u8Value;
					  break;
		case GPIOB :  PORTB = copy_u8Value;
					  break;
		case GPIOC :  PORTC = copy_u8Value;
					  break;
		case GPIOD :  PORTD = copy_u8Value;
					  break;
		default    :
					  break;
	}
}

void GPIO_voidSetLowNibbleDDR( u8 copy_u8Port, u8 copy_u8Dir)
{
	if (copy_u8Dir == OUTPUT)
	{
		GPIO_voidSetPinDDR(copy_u8Port,0,OUTPUT);
		GPIO_voidSetPinDDR(copy_u8Port,1,OUTPUT);
		GPIO_voidSetPinDDR(copy_u8Port,2,OUTPUT);
		GPIO_voidSetPinDDR(copy_u8Port,3,OUTPUT);
	}
	else 
	{
		GPIO_voidSetPinDDR(copy_u8Port,0,INPUT);
		GPIO_voidSetPinDDR(copy_u8Port,1,INPUT);
		GPIO_voidSetPinDDR(copy_u8Port,2,INPUT);
		GPIO_voidSetPinDDR(copy_u8Port,3,INPUT);
	}
}

void GPIO_voidSetHighNibbleDDR(u8 copy_u8Port, u8 copy_u8Dir)
{
	if (copy_u8Dir == OUTPUT)
	{
		GPIO_voidSetPinDDR(copy_u8Port,4,OUTPUT);
		GPIO_voidSetPinDDR(copy_u8Port,5,OUTPUT);
		GPIO_voidSetPinDDR(copy_u8Port,6,OUTPUT);
		GPIO_voidSetPinDDR(copy_u8Port,7,OUTPUT);
	}
	else 
	{
		GPIO_voidSetPinDDR(copy_u8Port,4,INPUT);
		GPIO_voidSetPinDDR(copy_u8Port,5,INPUT);
		GPIO_voidSetPinDDR(copy_u8Port,6,INPUT);
		GPIO_voidSetPinDDR(copy_u8Port,7,INPUT);
	}
}

void GPIO_voidWriteLowNibble(u8 copy_u8Port, u8 copy_u8Value)
{
	copy_u8Value &=0x0f;
	switch (copy_u8Port){
		case GPIOA:
			PORTA &=0xf0;
			PORTA |=copy_u8Value;
			break;
		case GPIOB:
			PORTB &=0xf0;
			PORTB |=copy_u8Value;
			break;
		case GPIOC:
			PORTC &=0xf0;
			PORTC |=copy_u8Value;
			break;
		case GPIOD:
			PORTD &=0xf0;
			PORTD |=copy_u8Value;
			break;
		default: break;
	}
}

void GPIO_voidWriteHighNibble(u8 copy_u8Port, u8 copy_u8Value)
{
	copy_u8Value &=0xf0;
	switch (copy_u8Port){
		case GPIOA:
			PORTA &=0x0f;
			PORTA |=copy_u8Value;
			break;
		case GPIOB:
			PORTB &=0x0f;
			PORTB |=copy_u8Value;
			break;
		case GPIOC:
			PORTC &=0x0f;
			PORTC |=copy_u8Value;
			break;
		case GPIOD:
			PORTD &=0x0f;
			PORTD |=copy_u8Value;
			break;
		default: break;
	}
}
