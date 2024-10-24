/*
 * I2C.c
 *
 * Created: 17/10/2024 12:03:48
 *  Author: saids
 */ 
#include "I2C.h"
#include "GPIO_NEW.h"

/*Functions Definitions*/
 void I2C_Enable()
{
	Set_Bit(TWCR,2);
}
void I2C_Select_DivFactor(unsigned char  DivFactor)
{
	I2C->TWBR=DivFactor;
}
void I2C_Clear_Interrupt_Flag()
{
	Set_Bit(TWCR,7);
}
void I2C_Enable_ACK()						//the ACK pulse is generated in the cases mentionned in data sheet
{
	Set_Bit(TWCR,6);
}
void I2C_Trig_Start_Condition()
{
	Set_Bit(TWCR,5);
}
void I2C_Clear_Start_Condition()
{
	Reset_Bit(TWCR,5);
}
void I2C_Trig_Stop_Condition()
{
	Set_Bit(TWCR,4);
}


unsigned char I2C_Check_Status()
{
	return ((I2C->TWSR)&0xf8);						//this & with 0xf8 is to force the first 3 bits to be 0 like mentioned in data sheet
	
}
void I2C_Stop()
{
	I2C_Enable();							/*enable peripheral*/
	I2C_Clear_Interrupt_Flag();
	I2C_Trig_Stop_Condition();				//generate stop condition
}

void I2C_Repeat_Start()
{
	I2C_Enable();							/*enable peripheral*/
	I2C_Clear_Interrupt_Flag();
	I2C_Trig_Start_Condition();					//generate a start condition to stay in master mode (explained in data sheet)
}
/*************************************************************************************************************************/
/*Function to be used in Master  mode , you can develop functions for recieve or for slave mode refer to datasheet   */

unsigned char I2C_Master_Init( )				/*THIS FUNCTION IS FOR INITIALIZING I2C BY SENDING START CONDITION*/
{
	I2C->TWBR = BITRATE(I2C->TWSR=0x00);	/* Get bit rate register value by formula */
	I2C_Enable();							/*enable peripheral*/
	I2C_Clear_Interrupt_Flag();
	I2C_Trig_Start_Condition();					//generate a start condition to enter master mode (explained in data sheet)
	while(Read_Bit(TWCR,7)!=1);								//Wait for the I2C to send the start condition
	if(I2C_Check_Status()==0x08)					//check that the start condition has been successfully send
	{
		return 1 ;
	}
	else
	{
		return I2C_Start_Condition_Failed ;				//some action has to be done in this case
	}
}

unsigned char  I2C_Master_Transmit_To(unsigned char Address)			/*THIS FUNCTION IS FOR SELECTING THE SLAVE AND WRITE OPERATION*/
{
		
		I2C->TWDR=(Address<<1);						//Note that it should be a 7 bit address so shifted by one
		Reset_Bit(I2C->TWDR,0);						//Reset the read /write bit to indicate a write operation
		I2C_Enable();
		I2C_Clear_Start_Condition();
		I2C_Clear_Interrupt_Flag();					//clear flag after sending SLA+W
		while(Read_Bit(TWCR,7)!=1);								//Wait for the I2C to send	SLA+W
		if(I2C_Check_Status()==0x18)					//check that the start condition has been successfully send
		{
			return 1 ;
		}
		else
		{
			return I2C_SLA_W_Failed ;				//some action has to be done in this case
		}
				
	
}
unsigned char I2C_Master_Transmit(unsigned char Data)
{
								
	I2C->TWDR=Data;
	I2C_Clear_Interrupt_Flag();
	I2C_Enable();
	while(Read_Bit(TWCR,7)!=1);								//WAIT BECAUSE I2C TO SEND DATA
	if(I2C_Check_Status()==0x28)					//check that the data has been successfully send
	{
		return 1 ;
	}
	else
	{
		return I2C_Data_Transfer_Failed ;				//some action has to be done in this case
	}
	
		
	
}
/*************************************************************************************************************************/
