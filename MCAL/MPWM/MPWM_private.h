/**
 * @file    MPWM_private.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the private information of PWM module
 * @version 1.0
 * @date    2022-04-11
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __MPWM_PRIVATE_H__
#define __MPWM_PRIVATE_H__

/****************************************************************************************************************************/
/*                                                         PWM Registers                                                    */
/****************************************************************************************************************************/

/*Timer1 registers*/
#define MPWM_TCCR1   (*(volatile u16_t*)(0x4E))
#define MPWM_TCNT1   (*(volatile u16_t*)(0x4C))
#define MPWM_OCR1A   (*(volatile u16_t*)(0x4A))
#define MPWM_OCR1B   (*(volatile u16_t*)(0x48))

/*Timer2 registers*/
#define MPWM_TCCR2   (*(volatile u8_t*)(0x45))
#define MPWM_TCNT2   (*(volatile u8_t*)(0x44))
#define MPWM_OCR2    (*(volatile u8_t*)(0x43))

#endif /*__MPWM_PRIVATE_H__*/