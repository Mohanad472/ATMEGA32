#include "DIO.h"
#include "Macros.h"
#include "stdtypes.h"
#include "SPI.h"

int main()
{
	DIO_Set_Pin_Direction(PORTA_NUM, PIN_0, OUTPUT);
	SPI_Init(MASTER);

	SPI_Send('7');
	while(1) ;
}
