/*
 * SPI_register.h
 *
 *  Created on: 21 Oct 2023
 *      Author: Ali
 */

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPDR_register  *((volatile u8*)(0x2F))
#define SPSR_register  *((volatile u8*)(0x2E))
#define SPCR_register  *((volatile u8*)(0x2D))


#define SPIF  7
#define WCOL  6
#define SPI2X 0


#define SPIE  7
#define SPE   6
#define DORD  5
#define MSTR  4
#define CPOL  3
#define CPHA  2
#define SPR1  1
#define SPR0  0

#endif /* SPI_REGISTER_H_ */
