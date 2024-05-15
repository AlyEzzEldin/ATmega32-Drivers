/*
 * ADC_register.h
 *
 *  Created on: 29 Sep 2023
 *      Author: Ali
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX_register *((volatile u8*)(0x27))
#define ADCSRA_register *((volatile u8*)(0x26))
#define ADC_register	*((volatile u16*)(0x24))

#define  REFS1 7
#define  REFS0 6
#define  ADLAR 5
#define  MUX4  4
#define  MUX3  3
#define  MUX2  2
#define  MUX1  1
#define  MUX0  0

#define ADEN   7
#define ADSC   6
#define ADATE  5
#define ADIF   4
#define ADIE   3
#define ADPS2  2
#define ADPS1  1
#define ADPS0  0

#endif /* ADC_REGISTER_H_ */
