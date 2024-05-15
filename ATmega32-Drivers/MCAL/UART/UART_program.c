/*
 * UART_program.c
 *
 *  Created on: 20 Oct 2023
 *      Author: Ali
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_register.h"
#include "UART_config.h"
#include "UART_interface.h"

void UART_INIT(void)
{
	UBRRL_register = 51;
	UBRRH_register = 0;
	/* Enable receiver and transmitter */
	UCSRB_register = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 1stop bit */
	UCSRC_register = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}
void UART_SEND_DATA(u8 data)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA_register & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR_register = data;
}
u8 UART_RECEIVE_DATA(void)
{
	/* Wait for data to be received */
	while ( !(UCSRA_register & (1<<RXC)) )
		;
	/* Get and return received data from buffer */
	return UDR_register;
}
