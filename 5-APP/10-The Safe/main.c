/*
 * TheSafe.c
 *
 * Created: 11/6/2020 11:30:02 AM
 * Author : Mahmoud Ayman
 */ 



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "EEPROM_interface.h"

#include "LCD_interface.h"

#include "KEYPAD_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define E_KEY  0xED
#define EEPROM_ADDRESS  0x20
#define STATUS_ADDRESS  0x06
u8 counter =3;
u8 arr[4],pass[4];
u8 Pass_check(void);
int main(void)
{
	u8 flag,g,i,j,d;
	
	LCD_voidInit();
	Keypad_voidInit(GPIOD);
	flag = EEPROM_voidRead(STATUS_ADDRESS);
	if(flag == 0xff)
	{
		LCD_voidDisplayString("Set Pass:");
		LCD_voidMoveCursor(2,1);
		for(i=1;i<5;i++)
		{
			if(i==1)
			{
				LCD_voidMoveCursor(2,1);
			}
			do{
				g = Keypad_u8CheckPress(GPIOD);
			}while(g==NOTPRESSED);
			LCD_voidDisplayChar(g);
			if(g=='A')
			{
				for(j=i+1;j>=1;j--)
				{
					LCD_voidMoveCursor(2,j);
					LCD_voidDisplayChar(' ');
				}
				i=0;
			}
			_delay_ms(300);
			if(g!='A')
			{
				LCD_voidMoveCursor(2,i);
				LCD_voidDisplayChar('*');
				g^=E_KEY;
				EEPROM_voidWrite(EEPROM_ADDRESS+(i-1),g);
			}
			
		}
		EEPROM_voidWrite(STATUS_ADDRESS,0x00);
		LCD_voidClearScreen();
		LCD_voidDisplayString("Password is set");
		_delay_ms(500);
		LCD_voidClearScreen();
	}
	Enter_pass();
	d = Pass_check();
	while(d==0)
	{
		Enter_pass();
		d=Pass_check();	
	}
	
	while(1)
	{
	
	}
}

void Enter_pass(void)
{
	u8 k,g,h;
	LCD_voidClearScreen();
	LCD_voidDisplayString("Enter Pass:");
	LCD_voidMoveCursor(2,1);
	for(k=0;k<4;k++)
	{
		do{
			g = Keypad_u8CheckPress(GPIOC);
		}while(g==NOTPRESSED);
		LCD_voidDisplayChar(g);
		_delay_ms(300);
		LCD_voidMoveCursor(2,k+1);
		LCD_voidDisplayChar('*');
		arr[k]=g;
	}
	for(h=0;h<4;h++)
	{
		pass[h]=EEPROM_voidRead(EEPROM_ADDRESS+h) ^ E_KEY;
	}
}

u8 Pass_check(void)
{
	u8 d;
	if(pass[0]==arr[0] && pass[1]==arr[1] && pass[2]==arr[2] && pass[3]==arr[3])
	{
		LCD_voidClearScreen();
		LCD_voidDisplayString("Right Pass");
		LCD_voidMoveCursor(2,1);
		LCD_voidDisplayString("Safe is open");
		_delay_ms(500);
		d=1;
	}
	else
	{
		LCD_voidClearScreen();
		LCD_voidDisplayString("Wrong Pass");
		LCD_voidMoveCursor(2,1);
		LCD_voidDisplayString("Tries remain=");
		LCD_display_number(counter);
		_delay_ms(500);
		counter--;
		d=0;
	}
	return d;
}