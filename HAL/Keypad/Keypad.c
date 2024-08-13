#include "Keypad.h"
#include "DIO.h"


u8 array[4][4] = {	{1, 2, 3, 0},
		{4, 5, 6, 0},
		{7, 8, 9, 0},
		{0, 0, 0, 0}  };
void Keypad_Init()
{
	// Define rows as inputs
	DIO_Set_Pin_Direction(KEYPAD_PORT, R1, INPUT);
	DIO_Set_Pin_Direction(KEYPAD_PORT, R2, INPUT);
	DIO_Set_Pin_Direction(KEYPAD_PORT, R3, INPUT);
	DIO_Set_Pin_Direction(KEYPAD_PORT, R4, INPUT);

	// Define columns as outputs
	DIO_Set_Pin_Direction(KEYPAD_PORT, C1, OUTPUT);
	DIO_Set_Pin_Direction(KEYPAD_PORT, C2, OUTPUT);
	DIO_Set_Pin_Direction(KEYPAD_PORT, C3, OUTPUT);
	DIO_Set_Pin_Direction(KEYPAD_PORT, C4, OUTPUT);

	// Activate PUR in rows
	DIO_Set_Pin_Value(KEYPAD_PORT, R1, ACTIVATE_PUR);
	DIO_Set_Pin_Value(KEYPAD_PORT, R2, ACTIVATE_PUR);
	DIO_Set_Pin_Value(KEYPAD_PORT, R3, ACTIVATE_PUR);
	DIO_Set_Pin_Value(KEYPAD_PORT, R4, ACTIVATE_PUR);
}

u8 Keypad_Get_Pressed_Value(u8 *pressed_value)
{
	u8 return_value = NOK;
	u8 col, row;

	DIO_Set_Port_Value(KEYPAD_PORT, PORT_ALL_HIGH); // C1 to C1 output, activate PUR in R1 to R4

	u8 value = 1;

	for(col = C1; col <= C4; col++)
	{
		DIO_Set_Pin_Value(KEYPAD_PORT, col, LOW);

		for(row = R1; row <= R4; row++)
		{
			DIO_Get_Pin_Value(KEYPAD_PORT, row, &value);
			if(value == LOW)
			{
				*pressed_value = array[row - R1][col - C1];
				return_value = OK;
				break;
			}
		}
		DIO_Set_Pin_Value(KEYPAD_PORT, col, HIGH);
	}

	return return_value;
}
