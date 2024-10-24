/*
 * _8bit_Timer.h
 *
 * Created: 10/10/2024 12:11:23
 *  Author: saids
 */ 


#ifndef _8BIT_TIMER_H_
#define _8BIT_TIMER_H_

/*Macros */

/*Adresses of registers*/
#define TCNT0				 *((char *)0x52)
#define TCCR0				 *((char *)0x53)
#define OCR0				 *((char *)0x5C)
#define TIMSK				 *((char *)0x59)
#define TIFR				 *((char *)0x58)
#define TCNT2				 *((char *)0x44)
#define TCCR2				 *((char *)0x45)
#define OCR2				 *((char *)0x43)
/*Wave Generation modes*/
#define Normal_Mode					 0
#define Phase_Correct_PWM_Mode       1
#define CTC_Mode                     2
#define Fast_PWM_Mode                3
/*Compare Output modes*/						/*the output mode depends on the wave generation mode -- refer to the data sheet */
#define Normal_IO_Pin                0
#define Toggle_OC_Pin                1
#define Clear_OC_Pin                 2
#define Set_OC_Pin					 3
/*Clock Select*/
#define No_Clck						 0		//no clock source timer is stopped
#define Clck_1						 1		//clock io without prescaler
#define Clck_8						 2	   //clock io divided by 8
#define Clck_64						 3	
#define Clck_256					 4	
#define Clck_1024					 5	
#define Ext_Clck_Falling_Edge		 6	   //external source connevted with T0 Pin
#define Ext_Clck_Rising_Edge		 7	
/*Timer0_Interrrupt*/
#define TIM0_Compare_Match_Interrupt	  1
#define TIM0_Overflow_Interrupt			  0
#define TIM2_Compare_Match_Interrupt	  7
#define TIM2_Overflow_Interrupt			  6
/*Flags*/
#define TIM0_Overflow_Flag                0
#define TIM0_Compare_Match_Flag           1
#define TIM2_Overflow_Flag                6
#define TIM2_Compare_Match_Flag           7

/*Functions Declaration for Timer0*/
void TIM0_Force_Compare();											//note that to use this function you must be in a non pwm mode
void TIM0_Wave_Generation_Mode(unsigned char Generation_Mode);
void TIM0_Output_Compare_Mode(unsigned char Compare_Mode);			//output compare mode is the behaviour of oc0 pin when compare match
void TIM0_CLCK_Select(unsigned char CLCK);							//to select the clock source and clock prescaler
void TIM0_Interrupt_Enable(unsigned char Interrupt);
void TIM0_Clear_Flag(unsigned char Flag);
void TIM0_Set_Compare_Value(unsigned char value);						//set the value to be compared OCR0 

/*Functions Declaration for Timer2*/
void TIM2_Force_Compare();											//note that to use this function you must be in a non pwm mode
void TIM2_Wave_Generation_Mode(unsigned char Generation_Mode);
void TIM2_Output_Compare_Mode(unsigned char Compare_Mode);			//output compare mode is the behaviour of oc2 pin when compare match
void TIM2_CLCK_Select(unsigned char CLCK);							//to select the clock source and clock prescaler
void TIM2_Interrupt_Enable(unsigned char Interrupt);
void TIM2_Clear_Flag(unsigned char Flag);
void TIM2_Set_Compare_Value(unsigned char value);						//set the value to be compared OCR2






#endif /* TIMER0_H_ */