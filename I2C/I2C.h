/*
 * I2C.h
 *
 * Created: 17/10/2024 12:03:27
 *  Author: saids
 */ 


#ifndef I2C_H_
#define I2C_H_

#define I2C			((volatile I2C_t *)0x20)						//I2C base address
#define TWCR		*((volatile char *)0x56)							//address of TWCR because it is not in seies with other reg of I2C

/*Frequency of I2C*/
#define F_CPU		8000000UL
#define  SCL_CLK	100000
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<0)|(1<<1))))) //FORMULA GIVEN IN DATASHEET

/*Data type*/
typedef struct 
{
	unsigned char TWBR;
	unsigned char TWSR;
	unsigned char TWAR;
	unsigned char TWDR;
	
	}I2C_t;

/*Prescalers*/
#define  I2C_Prescaler_1			0
#define  I2C_Prescaler_4			1
#define  I2C_Prescaler_16			2
#define  I2C_Prescaler_64			3

/*Errors*/
#define I2C_Start_Condition_Failed			0
#define I2C_SLA_W_Failed					0
#define I2C_Data_Transfer_Failed			0


/*Functions Declaration*/
void  I2C_Enable();
void I2C_Select_DivFactor(unsigned char DivFactor);
void I2C_Clear_Interrupt_Flag();
void I2C_Enable_ACK();						//the ACK pulse is generated in the cases mentionned in data sheet
void I2C_Trig_Start_Condition();
void I2C_Clear_Start_Condition();
void I2C_Trig_Stop_Condition();
void I2C_Select_Prescaler(unsigned char Prescaler);
unsigned char I2C_Check_Status();
void I2C_Write_Byte(unsigned char byte);
unsigned char I2C_Read_Byte();
void I2C_Slave_Address(unsigned char Address);
void I2C_Enable_General_Call();							//this function enables the recognition of a General Call given over the I2C Bus when Address 0000 0000
unsigned char I2C_Master_Init( );
unsigned char I2C_Master_Transmit(unsigned char Data);
unsigned char I2C_Master_Transmit_To(unsigned char Address);
void I2C_Stop();
void I2C_Repeat_Start();
/****************************/
 
#endif /* I2C_H_ */