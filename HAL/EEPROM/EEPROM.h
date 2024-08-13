#ifndef EEPROM_H_
#define EEPROM_H_

#define READ	 		1
#define WRITE 			0
#define ENABLE_HIGH		1
#define ENABLE_LOW		0
#define BLOCK_0			0
#define BLOCK_1			1
#define BLOCK_2			2
#define BLOCK_3			3

void EEPROM_Init();
u8 EEPROM_Write(u8 Enable_Pin, u8 Block_ID, u8 *data, u8 Number_Of_Bytes, u8 EEPROM_Internal_Address);
u8 EEPROM_Read(u8 Enable_Pin, u8 Block_ID, u8 *Read_data, u8 Number_Of_Bytes, u8 EEPROM_Internal_Address);

#endif /* EEPROM_H_ */
