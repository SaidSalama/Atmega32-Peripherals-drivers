/*
 * USART_NEW.h
 *
 * Created: 15/10/2024 11:19:43
 *  Author: saids
 */ 


#ifndef USART_NEW_H_
#define USART_NEW_H_

#include "GPIO_NEW.h"
/*Register Address*/
#define UDR		*((unsigned char *)0x2C)
#define UCSRA	*((unsigned char *)0x2B)
#define UCSRB	*((unsigned char *)0x2A)
#define UCSRC	*((unsigned char *)0x40)
#define UBRRH	*((unsigned char *)0x40)				//IT SHARES THE SAME MEMORY LOCATION AS UCSRC
#define UBRRL	*((unsigned char *)0x29)

/*Interrupts*/
#define USART_Recieve_Interrupt			7
#define USART_Transmit_Interrupt		6
#define USART_Data_Empty_Interrupt		5

/*Modes*/
#define USART_Double_Speed				1
#define USART_Multi_Processor_Mode		0
#define USART_Asynchronus_Mode			0
#define USART_Synchronus_Mode			1

/*Parity Mode*/
#define USART_Parity_Disabled			0
#define USART_Parity_Even				2
#define USART_Parity_Odd				3

/*Char Size*/
#define _5bit					0
#define _6bit					1
#define _7bit					2
#define _8bit					3
#define _9bit					3

/*Uart port and bits */
#define RX					0
#define TX					1
#define USART_PORT			PORT_D

/*Frequency and BaudRate of MC*/
#define F_CPU 8000000UL		/* Define frequency here its 8MHz */
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

/*Functions Declaration*/
void USART_send(unsigned char data);
unsigned char USART_Recieve();
void USART_Enable_Interrupt(unsigned char interrupt);
void USART_Enable_MultiProcessor_Mode();
void USART_Enable_Transmit();
void USART_Enable_Recieve();
void USART_Select_CharSize(unsigned char size);
void USART_Select_Mode(unsigned char mode);
void USART_Select_Parity(unsigned char parity);
void USART_Select_Baudrate(int baudrate);
void USART_IO_Config();												//config tx and rx bit 



#endif /* USART_NEW_H_ */