/*
 * _8bit_Timer.c
 *
 * Created: 10/10/2024 12:10:54
 *  Author: saids
 */ 
#include "GPIO_NEW.h"
#include "_8bit_timer.h"


/*Definition of timer0 functions */
void TIM0_Force_Compare()
{
	Set_Bit(TCCR0,7);						//SET BIT 7 OF TCCR0 reg to force output compare thi
											//this bit is only activ in non pwm mode
}

void TIM0_Wave_Generation_Mode(unsigned char Generation_Mode)
{
	switch(Generation_Mode)
	{
		case Normal_Mode:
				Reset_Bit(TCCR0,3);
				Reset_Bit(TCCR0,6);
				break;
		case Phase_Correct_PWM_Mode:
				Set_Bit(TCCR0,6);
				Reset_Bit(TCCR0,3);
				break;
		case CTC_Mode:
				Reset_Bit(TCCR0,6);
				Set_Bit(TCCR0,3);
				break;
		case Fast_PWM_Mode:
				Set_Bit(TCCR0,3);
				Set_Bit(TCCR0,6);
				break;
		
	}
}
void TIM0_Output_Compare_Mode(unsigned char Compare_Mode)
{
	switch(Compare_Mode)
	{
		case Normal_IO_Pin:
				Reset_Bit(TCCR0,4);
				Reset_Bit(TCCR0,5);
				break;
		case Toggle_OC_Pin:
				Set_Bit(TCCR0,4);
				Reset_Bit(TCCR0,5);
				break;
		case Clear_OC_Pin:
				Reset_Bit(TCCR0,4);
				Set_Bit(TCCR0,5);
				break;	
		case Set_OC_Pin:
				Set_Bit(TCCR0,4);
				Set_Bit(TCCR0,5);
				break;	
				
		
	}	
}
void TIM0_CLCK_Select(unsigned char CLCK)
{
	TCCR0|=CLCK;
}
void TIM0_Interrupt_Enable(unsigned char Interrupt)				/*the interrupt name and the flag are the bits number in macros*/
{
	Set_Bit(TIMSK,Interrupt);
}
void TIM0_Clear_Flag(unsigned char Flag)
{
	Set_Bit(TIFR,Flag);
}
void TIM0_Set_Compare_Value(unsigned char value)
{
	OCR0=value;
}


/*Definition of timer2 functions*/
void TIM2_Force_Compare()
{
	Set_Bit(TCCR2,7);						//SET BIT 7 OF TCCR2 reg to force output compare 
											//this bit is only activ in non pwm mode
}

void TIM2_Wave_Generation_Mode(unsigned char Generation_Mode)
{
	switch(Generation_Mode)
	{
		case Normal_Mode:
		Reset_Bit(TCCR2,3);
		Reset_Bit(TCCR2,6);
		break;
		case Phase_Correct_PWM_Mode:
		Set_Bit(TCCR2,6);
		Reset_Bit(TCCR2,3);
		break;
		case CTC_Mode:
		Reset_Bit(TCCR2,6);
		Set_Bit(TCCR2,3);
		break;
		case Fast_PWM_Mode:
		Set_Bit(TCCR2,3);
		Set_Bit(TCCR2,6);
		break;
		
	}
}
void TIM2_Output_Compare_Mode(unsigned char Compare_Mode)
{
	switch(Compare_Mode)
	{
		case Normal_IO_Pin:
		Reset_Bit(TCCR2,4);
		Reset_Bit(TCCR2,5);
		break;
		case Toggle_OC_Pin:
		Set_Bit(TCCR2,4);
		Reset_Bit(TCCR2,5);
		break;
		case Clear_OC_Pin:
		Reset_Bit(TCCR2,4);
		Set_Bit(TCCR2,5);
		break;
		case Set_OC_Pin:
		Set_Bit(TCCR2,4);
		Set_Bit(TCCR2,5);
		break;
		
		
	}
}
void TIM2_CLCK_Select(unsigned char CLCK)
{
	TCCR2|=CLCK;
}
void TIM2_Interrupt_Enable(unsigned char Interrupt)				/*the interrupt name and the flag are the bits number in macros*/
{
	Set_Bit(TIMSK,Interrupt);
}
void TIM2_Clear_Flag(unsigned char Flag)
{
	Set_Bit(TIFR,Flag);
}
void TIM2_Set_Compare_Value(unsigned char value)
{
	OCR2=value;
}