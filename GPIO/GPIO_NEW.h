/*
 * IncFile1.h
 *
 * Created: 07/10/2024 21:19:02
 *  Author: saids
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

/*Macros*/
#define GPIO_BASE_ADDRESS  ((volatile GPIO_t *)0x30)				//THE BASE ADDRESS OF ALL GPIO REGISTERS (Address of PIND reg) pointer to struct

#define High      1													//used for 5v
#define Low       0													//used for 0v
#define Output    1													//direction of pin
#define Input     0

#define PORT_D    0													// offsets of the base address of GPIO (indexes of Gpio array)
#define PORT_C    1
#define PORT_B    2
#define PORT_A    3

#define PIN_0     0													//PIN Numbers							
#define PIN_1     1
#define PIN_2     2
#define PIN_3     3
#define PIN_4     4
#define PIN_5     5
#define PIN_6     6
#define PIN_7     7
/*Function Macro*/
#define Set_Bit(reg,bit)      reg |= (1<<bit)
#define Reset_Bit(reg,bit)    reg &= ~(1<<bit)
#define Read_Bit(reg,bit)	 (reg & (1<<bit))>>bit


/*Function Declaration*/
void Port_Direction(unsigned char port,unsigned char direction);
unsigned char Port_Read(unsigned char port);
void Port_Write(unsigned char port,unsigned char value);
void Pin_Direction(unsigned char port,unsigned char direction,unsigned char pin);
unsigned char Pin_Read(unsigned char port,unsigned char pin);
void Pin_Set(unsigned char port,unsigned char pin);
void Pin_Reset(unsigned char port,unsigned char pin);

/*Data Types*/
typedef struct
{
	unsigned char PIN;
	unsigned char DDR;
	unsigned char PORT;
	
}GPIO_t;






#endif /* INCFILE1_H_ */