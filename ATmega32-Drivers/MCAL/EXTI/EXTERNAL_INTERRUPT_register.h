/*
 * EXTERNAL_INTERRUPT_register.h
 *
 *  Created on: 22 Sep 2023
 *      Author: Ali
 */

#ifndef EXTERNAL_INTERRUPT_REGISTER_H_
#define EXTERNAL_INTERRUPT_REGISTER_H_

#define MCUCR_register *((volatile u8*)(0x55))
#define MCUCSR_register *((volatile u8*)(0x54))
#define GICR_register *((volatile u8*)(0x5B))
#define GIFR_register *((volatile u8*)(0x5A))

#define INT0 6
#define INT1 7
#define INT2 5

#define INTF0 6
#define INTF1 7
#define INTF2 5

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define ISC2 6

#endif /* EXTERNAL_INTERRUPT_REGISTER_H_ */
