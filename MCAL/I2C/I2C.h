#ifndef I2C_H_
#define I2C_H_

#include "stdtypes.h"

void I2C_Init();
u8 I2C_Start_Condition();
u8 I2C_Repeated_Start();
void I2C_Stop_Condition();
void I2C_Write(u8 data);
u8 I2C_Read_ACK();
u8 I2C_Read_NACK();

#endif /* I2C_H_ */
