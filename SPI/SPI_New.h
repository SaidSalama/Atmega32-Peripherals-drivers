/*
 * SPI_New.h
 *
 * Created: 16/10/2024 13:51:13
 *  Author: saids
 */ 


#ifndef SPI_NEW_H_
#define SPI_NEW_H_


#include "GPIO_NEW.h"
/*Base address of spi peripheral*/
#define SPI	 ( (volatile SPI_t*) 0x2D)

typedef struct
{
	unsigned char _SPCR;
	unsigned char _SPSR;
	unsigned char _SPDR;
}SPI_t;

/*Macros*/

/*SPI Modes*/																/*thr modes of operation see the data sheet*/
#define SPI_Mode_0			0
#define SPI_Mode_1			1
#define SPI_Mode_2			2
#define SPI_Mode_3			3

/*SCK Frequency*/
#define FOSC_4				0
#define FOSC_16				1
#define FOSC_64				2
#define FOSC_128			3
#define FOSC_2				0
#define FOSC_8				1
#define FOSC_32				2
/*Master/Slave*/
#define SPI_Master			1
#define SPI_Slave			0
/*SPI Port & Pins*/
#define SS                  4
#define MOSI				5
#define MISO				6
#define SCK					7
#define SPI_PORT			PORT_B


/*Functions Declarations*/
void SPI_Interrupt_Enable();
void SPI_Enable();
void SPI_Select_Master_Slave(unsigned char selection);
void SPI_Select_Mode(unsigned char spi_mode);
void SPI_Select_Freq(unsigned char freq);
void SPI_Send(unsigned char Data);
unsigned char SPI_Recieve();
void SPI_IO_Confg(unsigned char spi_mode);				//when spi is enabled it overrides io operation but I prefer to configure io to be more safe



#endif /* SPI_NEW_H_ */