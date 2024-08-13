#include "I2C.h"
#include <avr/io.h>
#include "Macros.h"
#include "DIO.h"

void I2C_Init()
{
	//*** Set the clock speed and enable TWI (optional) ***//

	CLR_BIT(TWSR, TWPS0);		// Prescaller = 1
	CLR_BIT(TWSR, TWPS1);
	TWBR = 2;					// Freq = 8000000/(16+2*2*(4^1)) = 250000 Hz

	TWAR &= 1;					// Masking
	TWAR |= 1 << TWGCE;			// Put an address = 1 to the Master in case another master wants to communicate
}

u8 I2C_Start_Condition()
{
	u8 return_value = OK;

	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	// 1- Clear the flag TWINT therefore now TWINT = 0
	// 2- Start condition
	// 3- Enable TWI to start the operation

	while(GET_BIT(TWCR, TWINT) == 0);		// Wait until the flag is risen which means that the start condition is sent successfully
											// and we are ready for the following steps

	if((TWSR & 0b11111000) != 0x08)			// Check if the start condition has been transmitted
	{
		return_value = NOK;
	}

	return return_value;
}

u8 I2C_Repeated_Start()
{
	//*** Same as start but the only difference is in the check status ***//
	u8 return_value = OK;

	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	// 1- Clear the flag TWINT therefore now TWINT = 0
	// 2- Start condition
	// 3- Enable TWI to start the operation

	while(GET_BIT(TWCR, TWINT) == 0);		// Wait until the flag is risen which means that the start condition is sent successfully
											// and we are ready for the following steps

	if((TWSR & 0b11111000) != 0x10)			// Check if the start condition has been transmitted
	{
		return_value = NOK;
	}

	return return_value;
}

void I2C_Stop_Condition()
{
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
	// 1- Clear the flag TWINT therefore now TWINT = 0
	// 2- Stop condition
	// 3- Enable TWI to start operation
}

void I2C_Write(u8 data)
{
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);

	while(GET_BIT(TWCR, TWINT) == 0);
}

u8 I2C_Read_ACK()
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);		// Enable ACK --> TWEA
	while(GET_BIT(TWCR, TWINT) == 0);
	return TWDR;
}

u8 I2C_Read_NACK()
{
	TWCR = (1 << TWINT) | (1 << TWEN);
	while(GET_BIT(TWCR, TWINT) == 0);
	return TWDR;
}
