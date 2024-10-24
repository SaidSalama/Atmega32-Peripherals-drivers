/*
 * Exteranal_Interupt__New.h
 *
 * Created: 09/10/2024 09:43:59
 *  Author: saids
 */ 


#ifndef EXTERANAL_INTERUPT _NEW_H_
#define EXTERANAL_INTERUPT _NEW_H_

/*Macros*/

/*Registers Adrresses*/
#define  MCUCR *((char *)0x55)
#define  MCUCSR *((char *)0x54)
#define  GIFR *((char *)0x5a)
#define  SREG *((char *)0x5f)
#define  GICR *((char *)0x5b)
/*number of interrupts in GICR register*/
#define EXTI_1  7
#define EXTI_0  6
#define EXTI_2  5
/*Interrupt Sense control for EXTI_0 and EXTI_1*/		 /*To siimplify (EXTI_0 and EXTI_1) --> EXTI_0_1 */
#define EXTI_0_1_Low_Level		  0
#define EXTI_0_1_Logical_Change	  1
#define EXTI_0_1_Falling_Edge     2
#define EXTI_0_1_Rising_Edge	  3
/*Interrupt Sense control for EXTI_2*/					/*note that INT2 is only edge trigerred*/
#define EXTI_2_Falling_Edge     0
#define EXTI_2_Rising_Edge	    1

/*Functions Declaration*/
void Enable_Global_Interrupt();
void Disable_Global_Interrupt();
void Enable_External_Interrupt(unsigned char EXTI_x);
void Disable_External_Interrupt(unsigned char EXTI_x);
void Control_External_Interrupt(unsigned char EXTI_x,unsigned char control);

#endif /* EXTERANAL_INTERUPT _NEW_H_ */