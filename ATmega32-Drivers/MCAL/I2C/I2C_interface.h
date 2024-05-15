/*
 * I2C_interface.h
 *
 *  Created on: 28 Oct 2023
 *      Author: Ali
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#define I2C_MT_ARB_LOST     0x38
#define I2C_MR_ARB_LOST     0x38
#define I2C_START           0x08
#define I2C_REP_START       0x10
#define I2C_MT_SLA_ACK 		0x18
#define I2C_MT_DATA_ACK 	0x28
#define I2C_MR_DATA_NOT_ACK 0x58
#define I2C_MR_SLA_NOT_ACK  0x48
#define I2C_MT_SLA_NOT_ACK  0x20
#define I2C_MT_DATA_NOT_ACK 0x30
#define I2C_MR_DATA_ACK 	0x50
#define I2C_MR_SLA_ACK 	    0x40

#define read  1
#define write 0

void I2C_MASTER_INIT(u8 Slave_Address);
void I2C_SLAVE_INIT(u8 Slave_Address);

void I2C_Start(void);
void I2C_REPEATED_Start(void);
void I2C_Stop(void);

void I2C_SEND_SLAVE_ADDRESS(u8 Slave_Address,u8 read_write);
void I2C_Write(u8 data);

u8 I2C_READ_ACK(void);
u8 I2C_READ_NACK(void);

u8 I2C_Get_Status(void);


#endif /* I2C_INTERFACE_H_ */
