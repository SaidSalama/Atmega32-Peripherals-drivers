/*
 * ADC_New.c
 *
 * Created: 14/10/2024 09:29:13
 *  Author: saids
 */ 
#include "ADC_New.h"
#include "GPIO_NEW.h"

/*Functions Definitions*/
void ADC_Select_Vref(unsigned char Vref)
{
	ADMUX|=(Vref<<6);
}

void ADC_Select_Channel(unsigned char channel)
{
	ADMUX|=channel;
}

void ADC_Enable()
{
	Set_Bit(ADCSRA,7);
}

void ADC_Disable()
{
	Reset_Bit(ADCSRA,7);
}

void ADC_Start_Conversation()
{
	Set_Bit(ADCSRA,6);
}

void ADC_Enable_Auto_Trigger()
{
	Set_Bit(ADCSRA,5);
}

void ADC_Select_Trigger_Source(unsigned char Trig)
{
	SFIOR|=(Trig<<5);
}

void ADC_Enable_Interrupt()
{
	Set_Bit(ADCSRA,3);
}

void ADC_Select_Prescaler(unsigned char Prescaler)
{
	ADCSRA|=Prescaler;
}
void ADC_Data_Alignement(unsigned char alignement)
{
	if(alignement==Right_Adjust)
			Reset_Bit(ADMUX,5);
	else if (alignement==Left_Adjust)
			Set_Bit(ADMUX,5);
}
 short int ADC_Read()
{
	if(Read_Bit(ADMUX,5)==Low)									//it means the bit is set
	{
		return ADCL+(ADCH<<8);									//read the right adjusted data									                                            
	}
	else
	{
		return (ADCL>>6)+((ADCH<<8)>>6);									//read the right adjusted data															
	}
}