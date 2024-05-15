/*
 * UART_interface.h
 *
 *  Created on: 20 Oct 2023
 *      Author: Ali
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_INIT(void);
void UART_SEND_DATA(u8 data);
u8 UART_RECEIVE_DATA(void);


#endif /* UART_INTERFACE_H_ */
