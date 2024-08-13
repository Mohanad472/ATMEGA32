#include "SPI.h"
#include "DIO.h"
#include "Macros.h"
#include <util/delay.h>

void SPI_Init(u8 mode)
{
	if(mode == MASTER)
	{
		CLR_BIT(SPCR, DORD);	//	 MSB transmitted first

		SET_BIT(SPCR, MSTR);	// Master mode

		CLR_BIT(SPCR, CPOL);	// Rising then falling edge   --------> Ask why?
		CLR_BIT(SPCR, CPHA);	// Transmit then setup

		CLR_BIT(SPCR, SPR0);	// Clk = Freq/64
		SET_BIT(SPCR, SPR1);
		CLR_BIT(SPSR, SPI2X);

		DIO_Set_Pin_Direction(PORTB_NUM, PIN_5, OUTPUT);		// MOSI
		DIO_Set_Pin_Direction(PORTB_NUM, PIN_6, INPUT);			// MISO
		DIO_Set_Pin_Direction(PORTB_NUM, PIN_7, OUTPUT);		// CLK
		DIO_Set_Pin_Direction(PORTB_NUM, PIN_4, OUTPUT);		// Slave Select

	}
	else if(mode == SLAVE)
	{
		CLR_BIT(SPCR, MSTR);	// Slave mode

		CLR_BIT(SPCR, DORD);	//	 MSB transmitted first

		SET_BIT(SPCR, CPOL);	// Falling edge then rising edge
		SET_BIT(SPCR, CPHA);	// Setup then transmit

		DIO_Set_Pin_Direction(PORTB_NUM, PIN_5, INPUT);			// MOSI
		DIO_Set_Pin_Direction(PORTB_NUM, PIN_6, OUTPUT);		// MISO
		DIO_Set_Pin_Direction(PORTB_NUM, PIN_7, INPUT);			// Serial Clock
		DIO_Set_Pin_Direction(PORTB_NUM, PIN_4, INPUT);		// Slave Select
	}
	SET_BIT(SPCR, SPE);			// SPI enable
}


void SPI_Send(u8 data)
{
	SPDR = data;
	while(GET_BIT(SPSR, SPIF) == 0);		// Wait until the transfer is complete
	TOGGLE_BIT(PORTA, 0);
	_delay_ms(100);
	TOGGLE_BIT(PORTA, 0);
	_delay_ms(100);
}


u8 SPI_Receive()
{
	while(GET_BIT(SPSR, SPIF) == 0);		// Wait until the receive data is complete
	return SPDR;
}
