/*
 * ADC_interface.h
 *
 *  Created on: 29 Sep 2023
 *      Author: Ali
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

#define ADC_result	*((volatile u16*)(0x24))

void ADC_INIT(void);
u16 ADC_START_CONVERSION_SYNC(u8 Channel);
void ADC_START_CONVERSION_ASYNC(u8 Channel);
u32 ADC_Mapping(u32 Range_X_Min,u32 Range_X_Max,u32 Range_Y_Min,u32 Range_Y_Max,u32 Range_X_Input);
void ADC_INTERRUPT_ENABLE (void);
void ADC_INTERRUPT_DISABLE (void);

void ADC_Set_Callback_Address(void (*PTR)(void));

#endif /* ADC_INTERFACE_H_ */
