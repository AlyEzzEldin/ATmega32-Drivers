/*
 * LED_interface.h
 *
 *  Created on: 12 Sep 2023
 *      Author: Ali
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

void LED_PIN_INIT(u8 LED_port,u8 LED_pin);
void LED_PORT_INIT(u8 LED_port);

void LED_PIN_WRITE(u8 LED_port,u8 LED_pin,u8 LED_value);
void LED_PORT_WRITE(u8 LED_port,u8 LED_value);

#endif /* LED_INTERFACE_H_ */
