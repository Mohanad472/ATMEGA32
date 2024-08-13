#include "UART.h"
#include "DIO.h"
#include <avr/io.h>

void UART_Init()
{
	SET_BIT(UCSRB, RXEN);		// Receiver enable
	SET_BIT(UCSRB, TXEN);		// Transmitter enable

	UCSRC = 0b10110110;			// Access UCSRC register     --> ERROR LINE
								// 1 stop bit
								// Enable even parity mode
								// 8-bit data
								// Asynchronous mode
								// Disable clock parity (as we are asynchronous mode)

	CLR_BIT(UCSRB, UCSZ2);

	UBRRL = 51;					// Baud rate = 9600 symbols/sec (bits/sec), Double speed = 0
}

u8 UART_Receive()
{
	while(GET_BIT(UCSRA, RXC) == 0);			// Wait until flag == 1 (receive is complete)
	return UDR;
}

void UART_Transmit(u8 data)
{
	while(GET_BIT(UCSRA, UDRE) == 0);			// Wait until transmit buffer (UDR) is empty and ready to transmit data
	UDR = data;									// Write data in UDR and it will transmit
}
