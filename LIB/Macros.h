#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(reg, bit_num) reg |= (1 << bit_num)
#define CLR_BIT(reg, bit_num) reg &= (~(1 << bit_num))
#define TOGGLE_BIT(reg, bit_num) reg ^= (1 << bit_num)
#define GET_BIT(reg, bit_num) (reg & (1 << bit_num)) >> bit_num

#endif /* MACROS_H_ */
