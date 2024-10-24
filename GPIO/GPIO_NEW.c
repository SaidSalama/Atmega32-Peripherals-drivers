/*
 * CFile1.c
 *
 * Created: 07/10/2024 22:34:58
 *  Author: saids
 */ 
#include "GPIO_NEW.h"

/*Array of pointers to each GPIO port so we can use them to access the rigesters of each port*/
GPIO_t * GPIO_PORTS[4]={GPIO_BASE_ADDRESS,GPIO_BASE_ADDRESS+1,GPIO_BASE_ADDRESS+2,GPIO_BASE_ADDRESS+3};
	
/*Functions Definitions*/
void Port_Direction(unsigned char port,unsigned char direction)
{
	if(direction==Output)
	{
		GPIO_PORTS[port]->DDR=0xff;
	}
	else if (direction==Input)
	{
		GPIO_PORTS[port]->DDR=0x00;
	}
}

unsigned char Port_Read(unsigned char port)
{
	return GPIO_PORTS[port]->PIN;
}
	
void Port_Write(unsigned char port,unsigned char value)
{
	GPIO_PORTS[port]->PORT=value;
}
void Pin_Direction(unsigned char port,unsigned char direction,unsigned char pin)
{
	if(direction==Output)
	{
		GPIO_PORTS[port]->DDR|=(1<<pin);
	}
	else if (direction==Input)
	{
		GPIO_PORTS[port]->DDR &= ~(1<<pin);
	}
}
unsigned char Pin_Read(unsigned char port,unsigned char pin)
{
	 unsigned char Pin_Value=(GPIO_PORTS[port]->PIN & (1<<pin));					//if the result of the bitwise logical operation is 0
	 if(Pin_Value==Low)																//it means that the bit is low (bit=0)
				return Low;
	 else
				return High;
		
}
void Pin_Set(unsigned char port,unsigned char pin)
{
	GPIO_PORTS[port]->PORT|=(1<<pin);
}
void Pin_Reset(unsigned char port,unsigned char pin)
{
	GPIO_PORTS[port]->PORT &= ~(1<<pin);
}