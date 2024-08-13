#ifndef SPI_H_
#define SPI_H_

#include "stdtypes.h"
#include <avr/io.h>

//#define SPDR	*((volatile u8*)0x2F)

#define MASTER 1
#define SLAVE 0

void SPI_Init(u8 mode);
void SPI_Send(u8 data);
u8 SPI_Receive();

#endif /* SPI_H_ */
