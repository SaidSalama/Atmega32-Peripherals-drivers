/*
 * ADC_New.h
 *
 * Created: 14/10/2024 09:29:34
 *  Author: saids
 */ 


#ifndef ADC_NEW_H_
#define ADC_NEW_H_

/*Registers Adrress*/
#define ADMUX   *((char *)0x27)
#define ADCSRA  *((char *)0x26)
#define ADCL    *((char *)0x24)
#define ADCH    *((char *)0x25)
#define SFIOR   *((char*)0x50)
/*Vref Selection*/
#define AREF		    0
#define AVCC		    1
#define Internal_Vref	3
/*Data Alignement*/
#define Right_Adjust  0
#define Left_Adjust   1
/*Channel Selection*/
#define ADC_CHANNEL_0  0
#define ADC_CHANNEL_1  1
#define ADC_CHANNEL_2  2
#define ADC_CHANNEL_3  3
#define ADC_CHANNEL_4  4
#define ADC_CHANNEL_5  5
#define ADC_CHANNEL_6  6
#define ADC_CHANNEL_7  7
/*ADC PRESCALERS*/
#define DIVISION_FACTOR_2	 1
#define DIVISION_FACTOR_4	 2
#define DIVISION_FACTOR_8	 3
#define DIVISION_FACTOR_16	 4
#define DIVISION_FACTOR_32	 5
#define DIVISION_FACTOR_64	 6
#define DIVISION_FACTOR_128	 7
/*Trigger Source*/
#define Free_Running_Mode     0
#define Analog_Comparator     1
#define EXTI_0_Request		  2
#define Timer0_Compare_Match  3
#define Timer0_OverFlow       4
#define Timer_Compare_Match_B 5
#define Timer1_OverFlow       6
#define Timer1_Capture_Event  7


/*Functions Declaration*/
void ADC_Select_Vref(unsigned char Vref);
void ADC_Select_Channel(unsigned char channel);
void ADC_Enable();
void ADC_Disable();
void ADC_Start_Conversation();
void ADC_Enable_Auto_Trigger();
void ADC_Select_Trigger_Source(unsigned char Trig);
void ADC_Enable_Interrupt();
void ADC_Select_Prescaler(unsigned char Prescaler);
void ADC_Data_Alignement(unsigned char alignement);
short int ADC_Read();


#endif /* ADC_NEW_H_ */