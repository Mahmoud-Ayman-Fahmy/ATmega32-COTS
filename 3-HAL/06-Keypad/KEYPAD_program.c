/*************************************************************/
/* Author : Mahmoud Ayman                                    */
/* Date   : 5 NOV 2020                                       */
/* File   : Keypad_program                                   */
/* LOG    :                                                  */
/*************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "Keypad_interface.h"
#include "Keypad_config.h"
#include "Keypad_private.h"





void Keypad_voidInit(u8 copy_u8Port)
{
	#if KEYPAD_INPUTNIBBLE ==1
		GPIO_voidSetHighNibbleDDR(copy_u8Port,INPUT);
		GPIO_voidSetLowNibbleDDR(copy_u8Port,OUTPUT);
	#else
		GPIO_voidSetHighNibbleDDR(copy_u8Port,OUTPUT);
		GPIO_voidSetLowNibbleDDR(copy_u8Port,INPUT);
	#endif
	#if KEYPAD_INPUTNIBBLE ==1
		GPIO_voidWritePin(copy_u8Port,4,HIGH);
		GPIO_voidWritePin(copy_u8Port,5,HIGH);
		GPIO_voidWritePin(copy_u8Port,6,HIGH);
		GPIO_voidWritePin(copy_u8Port,7,HIGH);
	#else
		GPIO_voidWritePin(copy_u8Port,0,HIGH);
		GPIO_voidWritePin(copy_u8Port,1,HIGH);
		GPIO_voidWritePin(copy_u8Port,2,HIGH);
		GPIO_voidWritePin(copy_u8Port,3,HIGH);
	#endif

}

u8 Keypad_u8CheckPress(u8 copy_u8Port)
{
	u8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	u8 ROW , Coloumn , x;
	u8 Return_val=NOTPRESSED;
	#if KEYPAD_INPUTNIBBLE ==0
		for(ROW = 0; ROW < 4; ROW++)
		{
			GPIO_voidWritePin(copy_u8Port,0,HIGH);
			GPIO_voidWritePin(copy_u8Port,1,HIGH);
			GPIO_voidWritePin(copy_u8Port,2,HIGH);
			GPIO_voidWritePin(copy_u8Port,3,HIGH);
			GPIO_voidWritePin(copy_u8Port,ROW,LOW);
			for(Coloumn=0 ; Coloumn < 4; Coloumn++)
			{
				x = GPIO_u8ReadPin(copy_u8Port,(Coloumn+4));
				if(0==x)
				{
					Return_val= arr[ROW][Coloumn];
					break;
				}
			}
			if(0==x)
			{
				break;
			}
		}
	#else
		for(ROW = 0; ROW < 4; ROW++)
		{
			GPIO_voidWritePin(copy_u8Port,4,HIGH);
			GPIO_voidWritePin(copy_u8Port,5,HIGH);
			GPIO_voidWritePin(copy_u8Port,6,HIGH);
			GPIO_voidWritePin(copy_u8Port,7,HIGH);
			GPIO_voidWritePin(copy_u8Port,(ROW+4),LOW);
			for(Coloumn=0 ; Coloumn < 4; Coloumn++)
			{
				x = GPIO_u8ReadPin(copy_u8Port,(Coloumn));
				if(0==x)
				{
					Return_val= arr[ROW][Coloumn];
					break;
				}
			}
			if(0==x)
			{
				break;
			}
		}
	#endif

	return Return_val;
}