/**
 * @file    STTS_private.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the private information of TTS module 
 * @version 1.0
 * @date    2022-04-20
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __STTS_PRIVATE_H__
#define __STTS_PRIVATE_H__

/************************************************************************************************/
/*                                       TTS used registers          	                        */
/************************************************************************************************/

/*Timer2 registers*/
#define STTS_TCCR2     (*(volatile u8_t*)(0x45))
#define STTS_TCNT2     (*(volatile u8_t*)(0x44))
#define STTS_OCR2      (*(volatile u8_t*)(0x43))
#define STTS_TIMSK     (*(volatile u8_t*)(0x59))

/************************************************************************************************/
/*                                        Registers' bits            	                        */
/************************************************************************************************/

#define TIMSK_OCIE_BIT (7)

#endif /* __STTS_PRIVATE_H__ */
