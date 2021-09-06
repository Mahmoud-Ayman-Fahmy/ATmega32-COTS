

u8 DateSerPin,DataSerPort,DataClkPin,DataClkPort,StrClkPin,StrClkPort;

void STP_voidInit(u8 copy_u8DateSerPort,u8 copy_u8DateSerPin,u8 copy_u8DateClkPort,u8 copy_u8DateClkPin,u8 copy_u8StrClkPort,u8 copy_u8StrClkPin)
{
	DateSerPin=copy_u8DateSerPin;
	DataSerPort=copy_u8DateSerPort;
	DataClkPin=copy_u8DateClkPin;
	DataClkPort=copy_u8DateClkPort;
	StrClkPin=copy_u8StrClkPin;
	StrClkPort=copy_u8StrClkPort;
	GPIO_voidSetPinDDR(copy_u8DateSerPort,copy_u8DateSerPin,OUTPUT);
	GPIO_voidSetPinDDR(copy_u8DateClkPort,copy_u8DateClkPin,OUTPUT);
	GPIO_voidSetPinDDR(copy_u8StrClkPort,copy_u8StrClkPin,OUTPUT);
}

void STP_voidSend(u8 copy_u8DataSend)
{
	u8 local_u8Data,counter;
	for(counter=8;counter>0;counter--)
	{
		//local_u8Data=GET_BIT(copy_u8DataSend,counter-1);
		GPIO_voidWritePin(DataSerPort,DateSerPin,GET_BIT(copy_u8DataSend,counter-1));
		//send Pulse 
		GPIO_voidWritePin(DataClkPort,DataClkPin,HIGH);
		_delay_us(1);
		GPIO_voidWritePin(DataClkPort,DataClkPin,LOW);
		_delay_us(1);
	}
	//send Pulse 
	GPIO_voidWritePin(StrClkPort,StrClkPin,HIGH);
	_delay_us(1);
	GPIO_voidWritePin(StrClkPort,StrClkPin,LOW);
	_delay_us(1);
}