#include <avr/io.h>
#include "stdtypes.h"
#include "Macros.h"
#include "DIO.h"


u8 DIO_Set_Pin_Direction(u8 PORT_NUM, u8 PIN_NUM, u8 PIN_DIRECTION)
{

	u8 return_value = OK;

	if((PORT_NUM > PORTD_NUM) || (PIN_NUM > PIN_7) || (PIN_DIRECTION > OUTPUT))
	{
		return_value = NOK;
	}
	else
	{
		switch(PORT_NUM){

		case PORTA_NUM :

			if(PIN_DIRECTION == OUTPUT)
			{
				SET_BIT(DDRA, PIN_NUM);
			}
			else
			{
				CLR_BIT(DDRA, PIN_NUM);
			}
			break;

		case PORTB_NUM :

			if(PIN_DIRECTION == OUTPUT)
			{
				SET_BIT(DDRB, PIN_NUM);
			}
			else
			{
				CLR_BIT(DDRB, PIN_NUM);
			}
			break;

		case PORTC_NUM :

			if(PIN_DIRECTION == OUTPUT)
			{
				SET_BIT(DDRC, PIN_NUM);
			}
			else
			{
				CLR_BIT(DDRC, PIN_NUM);
			}
			break;

		case PORTD_NUM :

			if(PIN_DIRECTION == OUTPUT)
			{
				SET_BIT(DDRD, PIN_NUM);
			}
			else
			{
				CLR_BIT(DDRD, PIN_NUM);
			}
			break;
		}
	}

	return return_value;
}


u8 DIO_Set_Port_Direction(u8 PORT_NUM, u8 PORT_DIRECTION){

	u8 return_value = OK;

	if(PORT_NUM > PORTD_NUM || PORT_DIRECTION > HIGH)
	{
		return_value = NOK;
	}
	else
	{
		switch(PORT_NUM)
		{
		case PORTA_NUM:
			if(PORT_DIRECTION == OUTPUT)
			{
				DDRA = 0xFF;
			}
			else
			{
				DDRA = 0;
			}
			break;

		case PORTB_NUM:
			if(PORT_DIRECTION == OUTPUT)
			{
				DDRB = 0xFF;
			}
			else
			{
				DDRB = 0;
			}
			break;

		case PORTC_NUM:
			if(PORT_DIRECTION == OUTPUT)
			{
				DDRC = 0xFF;
			}
			else
			{
				DDRC = 0;
			}
			break;

		case PORTD_NUM:
			if(PORT_DIRECTION == OUTPUT)
			{
				DDRD = 0xFF;
			}
			else
			{
				DDRD = 0;
			}
			break;
		}
	}
	return return_value;
}


u8 DIO_Set_Port_Value(u8 PORT_NUM, u8 PORT_VALUE)
{
	u8 return_value = OK;

	if(PORT_NUM > PORTD_NUM)
	{
		return_value = NOK;
	}
	else
	{
		switch(PORT_NUM)
		{
		case PORTA_NUM:
			PORTA = PORT_VALUE;
			break;

		case PORTB_NUM:
			PORTB = PORT_VALUE;
			break;

		case PORTC_NUM:
			PORTC = PORT_VALUE;
			break;

		case PORTD_NUM:
			PORTD = PORT_VALUE;
			break;
		}
	}
	return return_value;
}


u8 DIO_Set_Pin_Value(u8 PORT_NUM, u8 PIN_NUM, u8 PIN_VALUE)
{

	u8 return_value = OK;

	if((PORT_NUM > PORTD_NUM) || (PIN_NUM > PIN_7) || (PIN_VALUE > OUTPUT))
	{
		return_value = NOK;
	}

	else
	{
		switch(PORT_NUM)
		{

		case PORTA_NUM:

			if(PIN_VALUE == HIGH)
			{
				SET_BIT(PORTA, PIN_NUM);
			}
			else
			{
				CLR_BIT(PORTA, PIN_NUM);
			}
			break;

		case PORTB_NUM:

			if(PIN_VALUE == HIGH)
			{
				SET_BIT(PORTB, PIN_NUM);
			}
			else
			{
				CLR_BIT(PORTB, PIN_NUM);
			}
			break;

		case PORTC_NUM:

			if(PIN_VALUE == HIGH)
			{
				SET_BIT(PORTC, PIN_NUM);
			}
			else
			{
				CLR_BIT(PORTC, PIN_NUM);
			}
			break;

		case PORTD_NUM:

			if(PIN_VALUE == HIGH)
			{
				SET_BIT(PORTD, PIN_NUM);
			}
			else
			{
				CLR_BIT(PORTD, PIN_NUM);
			}
			break;
		}
	}
	return return_value;
};


u8 DIO_Get_Pin_Value(u8 PORT_NUM, u8 PIN_NUM, u8 *PIN_VALUE)
{
	u8 return_value = OK;

	if((PORT_NUM > PORTD_NUM) || (PIN_NUM > PIN_7))
	{
		return_value = NOK;
	}
	else
	{
		switch(PORT_NUM)
		{
		case PORTA_NUM:
			*PIN_VALUE = (PINA & (1 << PIN_NUM)) >> PIN_NUM;
			break;

		case PORTB_NUM:
			*PIN_VALUE = (PINB & (1 << PIN_NUM)) >> PIN_NUM;
			break;

		case PORTC_NUM:
			*PIN_VALUE = (PINC & (1 << PIN_NUM)) >> PIN_NUM;
			break;

		case PORTD_NUM:
			*PIN_VALUE = (PIND & (1 << PIN_NUM)) >> PIN_NUM;
			break;
		}
	}

	return return_value;
}

