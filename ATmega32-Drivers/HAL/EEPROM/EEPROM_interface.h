/*
 * EEPROM_interface.h
 *
 *  Created on: 3 Nov 2023
 *      Author: Ali
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_INIT(void);
void EEPROM_WRITE(u16 addr,u8 data);
u8 EEPROM_READ(u16 addr);




#endif /* EEPROM_INTERFACE_H_ */
