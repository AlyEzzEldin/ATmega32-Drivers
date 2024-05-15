/*
 * ADC_program.c
 *
 *  Created on: 29 Sep 2023
 *      Author: Ali
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_register.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "DIO_interface.h"

void (* ADC_CALLBACK_PTR)(void) = NULL;


void ADC_INIT(void)
{
	/*
	 * Select Conversion Speed
	 */

	Set_Bit(ADCSRA_register,ADPS0);
	Set_Bit(ADCSRA_register,ADPS1);
	Set_Bit(ADCSRA_register,ADPS2);

	/*
	 * Select reference Voltage
	 */

	Set_Bit(ADMUX_register,REFS0);
	Clr_Bit(ADMUX_register,REFS1);

	/*
	 * Select Right adjust
	 */

	Clr_Bit(ADMUX_register,ADLAR);

	/*
	 * Enable
	 */
	Set_Bit(ADCSRA_register,ADEN);

}
u16 ADC_START_CONVERSION_SYNC(u8 Channel)
{
	/*
	 * Set Direction
	 */

	DIO_SetPinDirection(PORT_A,PIN_INPUT,Channel);

	/*
	 * Select Channel
	 */
	if(Channel >= 0 && Channel <= 7)
	{
		ADMUX_register &= 0b11100000;
		ADMUX_register |= Channel;
	}
	else
	{

	}
	/*
	 * Start conversion
	 */
	Set_Bit(ADCSRA_register,ADSC);

	/*
	 * Wait Conversion
	 */

	while(~Get_Bit(ADCSRA_register,ADIF));

	/*
	 * Clear flag
	 */
	Set_Bit(ADCSRA_register,ADIF);

	return ADC_register;

}

u32 ADC_Mapping(u32 Range_X_Min,u32 Range_X_Max,u32 Range_Y_Min,u32 Range_Y_Max,u32 Range_X_Input)
{
	u32 Y;
	Y = (((Range_X_Input-Range_X_Min)*(Range_Y_Max-Range_Y_Min))/(Range_X_Max-Range_X_Min))+Range_Y_Min;
	return Y;
}

void ADC_START_CONVERSION_ASYNC(u8 Channel)
{
	/*
	 * Set Direction
	 */

	DIO_SetPinDirection(PORT_A,PIN_INPUT,Channel);

	/*
	 * Select Channel
	 */
	if(Channel >= 0 && Channel <= 7)
	{
		ADMUX_register &= 0b11100000;
		ADMUX_register |= Channel;
	}
	else
	{

	}
	/*
	 * Start conversion
	 */
	Set_Bit(ADCSRA_register,ADSC);

}

void __vector_16 (void) __attribute__ ((signal,used, externally_visible)) ; \
    void __vector_16 (void)
{
	ADC_CALLBACK_PTR();
}

void ADC_INTERRUPT_ENABLE(void)
{
	Set_Bit(ADCSRA_register,ADIE);
}

void ADC_INTERRUPT_DISABLE (void)
{
	Clr_Bit(ADCSRA_register,ADIE);
}


void ADC_Set_Callback_Address(void (*PTR)(void))
{
	ADC_CALLBACK_PTR = PTR;
}


