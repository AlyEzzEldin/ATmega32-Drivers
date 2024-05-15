/*
 * EEPROM_program.c
 *
 *  Created on: 3 Nov 2023
 *      Author: Ali
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_interface.h"
#include "EEPROM_interface.h"

void EEPROM_INIT(void)
{
	I2C_MASTER_INIT(0x01);

}
void EEPROM_WRITE(u16 addr,u8 data)
{
	/*
	 *
	 *  1- Master Sends Start Condition.
		2- Master Sends Slave address(1010+E+Block) + Write Operation.
		3- Slave Sends Acknowledge.
		4- Master Sends Byte address within the chosen block (0 To 255) To Write.
		5- Slave Sends Acknowledge.
		6- Master Send up to 8 byte, each followed by an acknowledge from the slave
	 */
	I2C_Start();
	u8 Block_NO = (addr)/256;
	u8 address = (0b10101000)|(Block_NO << 1);

	I2C_Write(address);

	I2C_Write((u8)(addr%256));


	I2C_Write(data);

	I2C_Stop();


}
u8 EEPROM_READ(u16 addr)
{
	/*
	 *
	 *  1- Master Sends Start Condition.
		2- Master Sends Slave address(1010+E+Block) + Write Operation.
		3- Slave Sends Acknowledge.
		4- Master Sends Byte address within the chosen block (0 To 255) To read.
		5- Slave Sends Acknowledge.
		6- Master Sends Repeated Start Condition
		7- Master Sends Slave address(1010+E+Block) + Read Operation.
		8- Slave Sends Acknowledge.
		9- Slave send up to 8 byte each followed by an acknowledge from the master
	 */
	I2C_Start();

	u8 Block_NO = (addr)/256;
	u8 address = (0b10101000)|(Block_NO<<1);

	I2C_Write(address);

	I2C_REPEATED_Start();

	address |= 0x01;

	I2C_Write(address);

	u8 data = I2C_READ_ACK();

	I2C_Stop();

	return data;

}
