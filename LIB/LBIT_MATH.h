/**
 * @file    LBIT_MATH.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the bit manipulation macros
 * @version 1.0
 * @date    2021-04-06
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __LBIT_MATH_H__
#define __LBIT_MATH_H__

/*Macro used to set a specific bit in a variable*/
#define SET_BIT(REG, BIT)       (REG |= (1 << BIT))

/*Macro used to clear a specific bit in a variable*/
#define CLEAR_BIT(REG, BIT)     (REG &= ~(1 << BIT))

/*Macro used to toggle a specific bit in a variable*/
#define TOGGLE_BIT(REG, BIT)    (REG ^= (1 << BIT))

/*Macro used to get a specific bit from a variable*/
#define GET_BIT(REG, BIT)       ((REG >> BIT) & 1)

#endif /*__LBIT_MATH_H__*/