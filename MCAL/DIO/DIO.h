#ifndef DIO_H_
#define DIO_H_

#include "stdtypes.h"

#define PORTA_NUM 0
#define PORTB_NUM 1
#define PORTC_NUM 2
#define PORTD_NUM 3

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0

#define OK 1
#define NOK 0

#define PORT_ALL_HIGH 0xFF
#define PORT_ALL_LOW 0


u8 DIO_Set_Pin_Direction(u8 PORT_NUM, u8 PIN_NUM, u8 PIN_DIRECTION);
u8 DIO_Set_Port_Direction(u8 PORT_NUM, u8 PORT_DIRECTION);
u8 DIO_Set_Port_Value(u8 PORT_NUM, u8 PORT_VALUE);
u8 DIO_Set_Pin_Value(u8 PORT_NUM, u8 PIN_NUM, u8 PIN_VALUE);
u8 DIO_Get_Pin_Value(u8 PORT_NUM, u8 PIN_NUM, u8 *PIN_VALUE);

#endif /* DIO_H_ */
