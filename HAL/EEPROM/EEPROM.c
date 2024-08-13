#include "I2C.h"
#include "DIO.h"
#include "EEPROM.h"

void EEPROM_Init()
{
	I2C_Init();
}

u8 EEPROM_Write(u8 Enable_Pin, u8 Block_ID, u8 *data, u8 Number_Of_Bytes, u8 EEPROM_Internal_Address)
{
	u8 return_value = OK;

	//*** Max no. of bytes to write to the EEPROM = 8 ***//
	if(Number_Of_Bytes > 8 || Block_ID > BLOCK_3)
	{
		return_value = NOK;
	}
	else
	{
		I2C_Init();

		//*** Start condition ***//
		I2C_Start_Condition();

		//*** Slave address = 0b1010 + Enable(0 or 1) + Block_ID + Read/Write ***//
		u8 EEPROM_Slave_Address = 0b10100000 | (Enable_Pin << 3) | (Block_ID << 1) | WRITE;

		//*** Send the slave address then wait for ACK (done automatically by hardware) ***//
		I2C_Write(EEPROM_Slave_Address);

		//*** Send the address where we want to write the data ***//
		I2C_Write(EEPROM_Internal_Address);

		//*** Send the data ***//
		for(int i = 0; i < Number_Of_Bytes; i++)
		{
			I2C_Write(data[i]);
		}

		//*** Stop condition ***//
		I2C_Stop_Condition();
	}

	return return_value;
}


u8 EEPROM_Read(u8 Enable_Pin, u8 Block_ID, u8 *Read_data, u8 Number_Of_Bytes, u8 EEPROM_Internal_Address)
{
	u8 return_value = OK;

	//*** Max no. of bytes to read to the EEPROM = 8 ***//
	if(Number_Of_Bytes > 8 || Block_ID > BLOCK_3)
	{
		return_value = NOK;
	}
	else
	{
		I2C_Start_Condition();

		u8 EEPROM_Slave_Address = 0b10100000 | (Enable_Pin << 3) | (Block_ID << 1) | WRITE;

		I2C_Write(EEPROM_Slave_Address);

		I2C_Write(EEPROM_Internal_Address);

		I2C_Repeated_Start();

		EEPROM_Slave_Address = 0b10100000 | (Enable_Pin << 3) | (Block_ID << 1) | READ;

		I2C_Write(EEPROM_Slave_Address);

		for(int i = 0; i < Number_Of_Bytes; i++)
		{
			if(i == Number_Of_Bytes - 1)
			{
				Read_data[i] = I2C_Read_NACK();
			}
			else
			{
				Read_data[i] = I2C_Read_ACK();
			}
		}

		I2C_Stop_Condition();
	}
	return return_value;
}
