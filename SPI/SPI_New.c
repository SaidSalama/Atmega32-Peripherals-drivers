/*
 * SPI_New.c
 *
 * Created: 16/10/2024 13:49:26
 *  Author: saids
 */ 
#include "GPIO_NEW.h"
#include "SPI_New.h"

void SPI_Interrupt_Enable()
{
	Set_Bit(SPI->_SPCR,7);
}
void SPI_Enable()
{
	Set_Bit(SPI->_SPCR,6);
}
void SPI_Select_Master_Slave(unsigned char selection)
{
	if(selection==SPI_Master)
	{
		Set_Bit(SPI->_SPCR,4);
	}	
	else if(selection==SPI_Slave)
	{
		Reset_Bit(SPI->_SPCR,4);
	}														
}
void SPI_Select_Mode(unsigned char spi_mode)
{
	SPI->_SPCR|=(spi_mode<<2);									//bitwise or because i assumed that this mode does not change in main 
}
void SPI_Select_Freq(unsigned char freq)
{
	SPI->_SPCR|=(freq);															//bitwise or because i assumed that this mode does not change in main
	if((freq==FOSC_4)||(freq==FOSC_16)||(freq==FOSC_64)||(freq==FOSC_128))				//for these frequencies we need to reset SI2X bit in the SPSR
	{
		Reset_Bit(SPI->_SPSR,0);
	}
	else
	{
		Set_Bit(SPI->_SPSR,0);							//set the SI2X bit in the SPSR register for other frequencies
	}
}
void SPI_IO_Confg(unsigned char spi_mode)
{
	if(spi_mode==SPI_Master)
	{
		Pin_Direction(SPI_PORT,Output,MOSI);
		Pin_Direction(SPI_PORT,Input,MISO);
		Pin_Direction(SPI_PORT,Output,SCK);
		Pin_Direction(SPI_PORT,Output,SS);
	}
	else if(spi_mode==SPI_Slave)
	{
		Pin_Direction(SPI_PORT,Input,MOSI);
		Pin_Direction(SPI_PORT,Output,MISO);
		Pin_Direction(SPI_PORT,Input,SCK);
		Pin_Direction(SPI_PORT,Input,SS);
	}
}
void SPI_Send(unsigned char Data)
{
	SPI->_SPDR=Data;
	while(Read_Bit(SPI->_SPSR,7)!=1);
}
unsigned char SPI_Recieve()
{
	while(Read_Bit(SPI->_SPSR,7)!=1);
	return SPI->_SPDR;
}