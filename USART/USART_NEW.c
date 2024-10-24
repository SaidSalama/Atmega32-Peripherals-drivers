/*
 * USART_NEW.c
 *
 * Created: 15/10/2024 11:19:09
 *  Author: saids
 */ 
#include "USART_NEW.h"
#include "GPIO_NEW.h"

/*Functions Definition*/
void USART_send(unsigned char data)
{
	while((UCSRA&(1<<5))!=1);							//WAIT FOR THE DATA REG TO BE EMpTY
	UDR=data;
}
unsigned char USART_Recieve()
{
	while(UCSRA&(1<<7));							//WAIT FOR THE Flag of unread data to be cleared so we can read new data
	return UDR;
}
void USART_Enable_Interrupt(unsigned char interrupt)
{
	Set_Bit(UCSRB,interrupt);
}

void USART_Enable_MultiProcessor_Mode()
{
	Set_Bit(UCSRA,USART_Multi_Processor_Mode);
}

void USART_Enable_Transmit()
{
	Set_Bit(UCSRB,3);
}
void USART_Enable_Recieve()
{
	Set_Bit(UCSRB,4);
}
void USART_Select_Mode(unsigned char mode)
{
	Set_Bit(UCSRC,7);														//SETTING URSEL TO WRITE THE UCSRC REG refer to datasheet.....
	if(mode==USART_Asynchronus_Mode)
	{
		Reset_Bit(UCSRC,6);
	}
	else if(mode==USART_Synchronus_Mode)
	{
		Set_Bit(UCSRC,6);
	}
}
void USART_Select_Parity(unsigned char parity)
{
	Set_Bit(UCSRC,7);								//SETTING URSEL TO WRITE THE UCSRC REG refer to datasheet.....
	UCSRC|=(parity<<4);
}

void USART_Select_Baudrate(int baudrate)
{
	Reset_Bit(UCSRC,7);								//ReSETTING URSEL TO WRITE THE UBRRH REG refer to datasheet.....
	UBRRL=BAUD_PRESCALE;
	UBRRH=BAUD_PRESCALE>>8;
}

void USART_Select_CharSize(unsigned char size)
{
	
	UCSRC|=(size<<1);
	if(size==_9bit)
	{
		Set_Bit(UCSRB,2);
	}
}
void USART_IO_Config()
{
	Pin_Direction(USART_PORT,Output,TX);
	Pin_Direction(USART_PORT,Input,RX);
}