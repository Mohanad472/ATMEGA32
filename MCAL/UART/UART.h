#ifndef UART_H_
#define UART_H_

#include "Macros.h"
#include "stdtypes.h"

void UART_Init();
u8 UART_Receive();
void UART_Transmit(u8 data);

#endif /* UART_H_ */
