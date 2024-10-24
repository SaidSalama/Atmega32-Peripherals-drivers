/*
 * Exteranal_Interupt__New.c
 *
 * Created: 09/10/2024 09:44:15
 *  Author: saids
 */ 
#include "GPIO_NEW.h"
#include "Exteranal_Interupt _New.h"
#include <util/delay.h>

/*Functions Definitions*/
void Enable_Global_Interrupt()
{
	Set_Bit(SREG,7);				//SETTING BIT 7 to enable global interrupt
}
void Disable_Global_Interrupt()
{
	Reset_Bit(SREG,7);				//RESETTING BIT 7 to disable global interrupt
}
void Enable_External_Interrupt(unsigned char EXTI_x)
{
	Set_Bit(GICR,EXTI_x);
}
void Disable_External_Interrupt(unsigned char EXTI_x)					/*To disable an external interrupt we have to clear its flag bit */
{
	Set_Bit(GIFR,EXTI_x);												//writing 1 to the flag to clear it 										
	Reset_Bit(GICR,EXTI_x);

}
void Control_External_Interrupt(unsigned char EXTI_x,unsigned char control)
{
	if(EXTI_x==EXTI_0)
	{
		MCUCR|=(control<<0);
	}
	else if (EXTI_x==EXTI_1)
	{
		MCUCR|=(control<<0);
	}
	else if (EXTI_x==EXTI_2)
	{
		MCUCSR|=(control<<6);
	}
}
