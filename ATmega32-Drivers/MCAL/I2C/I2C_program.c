/*
 * I2C_program.c
 *
 *  Created on: 28 Oct 2023
 *      Author: Ali
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_register.h"
#include "I2C_interface.h"



void I2C_MASTER_INIT(u8 Slave_Address)
{
	Set_Bit(TWSR_register,TWPS0);
	Set_Bit(TWSR_register,TWPS1);

	TWBR_register = 32;

	Set_Bit(TWCR_register,TWEN);

	if(Slave_Address != 0)
	{
		TWAR_register = Slave_Address << 1;
	}

	Set_Bit(TWCR_register,TWEA);
}
void I2C_SLAVE_INIT(u8 Slave_Address)
{
	if(Slave_Address != 0)
	{
		TWAR_register = Slave_Address << 1;
	}

	Set_Bit(TWCR_register,TWEA);
	Set_Bit(TWCR_register,TWEN);

}

void I2C_Start(void)
{
	TWCR_register =  (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	while(Get_Bit(TWCR_register,TWINT) == 0);

}
void I2C_REPEATED_Start(void)
{
	Set_Bit(TWCR_register,TWSTA);

	Set_Bit(TWCR_register,TWINT);

	Set_Bit(TWCR_register,TWEN);

	while(Get_Bit(TWCR_register,TWINT) == 0);
}
void I2C_Stop(void)
{
	TWCR_register =  (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);

}

void I2C_SEND_SLAVE_ADDRESS(u8 Slave_Address,u8 read_write)
{
	TWDR_register = (Slave_Address << 1) | read_write;

	Clr_Bit(TWCR_register,TWSTA);

	TWCR_register = (1<<TWINT)|(1<<TWEN);

	while(Get_Bit(TWCR_register,TWINT) == 0);



}
void I2C_Write(u8 data)
{
	TWDR_register = data;

	TWCR_register = (1<<TWINT)|(1<<TWEN);


	while(Get_Bit(TWCR_register,TWINT) == 0);

}

u8 I2C_READ_ACK(void)
{
	TWCR_register = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);

	while(Get_Bit(TWCR_register,TWINT) == 0);

	return TWDR_register;


}
u8 I2C_READ_NACK(void)
{
	TWCR_register = (1<<TWINT)|(1<<TWEN);

	Clr_Bit(TWCR_register,TWEA);

	while(Get_Bit(TWCR_register,TWINT) == 0);

	return TWDR_register;
}

u8 I2C_Get_Status(void)
{
	u8 status;
	status = TWSR_register & 0xF8;
	return status;
}
