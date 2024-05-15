/*
 * SPI_program.c
 *
 *  Created on: 21 Oct 2023
 *      Author: Ali
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_register.h"
#include "SPI_interface.h"

void SPI_MASTER_INIT(void)
{
	/* Enable SPI, Master, set clock rate fck/16 */
	// SPCR_register = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	Set_Bit(SPCR_register,SPE);
	Set_Bit(SPCR_register,MSTR);

	Clr_Bit(SPSR_register,SPI2X);
	Clr_Bit(SPCR_register,SPR1);
	Set_Bit(SPCR_register,SPR0);

}

void SPI_SLAVE_INIT(void)
{
	//SPCR_register = (1<<SPE);
	Set_Bit(SPCR_register,SPE);

	Clr_Bit(SPCR_register,MSTR);

}
u8 SPI_TRANCEIVE(u8 Data)
{
	/* Start transmission */
	SPDR_register = Data;
	/* Wait for transmission complete */
	while(!(SPSR_register & (1<<SPIF)));

	 /* Return data register */
	 return SPDR_register;
}
