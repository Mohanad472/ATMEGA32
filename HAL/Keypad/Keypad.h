#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stdtypes.h"
#include "DIO.h"

#define KEYPAD_PORT PORTC_NUM
#define R1 PIN_0
#define R2 PIN_1
#define R3 PIN_2
#define R4 PIN_3
#define C1 PIN_4
#define C2 PIN_5
#define C3 PIN_6
#define C4 PIN_7



void Keypad_Init();
u8 Keypad_Get_Pressed_Value(u8 *pressed_value);

#endif /* KEYPAD_H_ */
