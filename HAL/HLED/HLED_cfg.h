/**
 * @file    HLED_cfg.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains configuration information for LED module
 * @version 1.0
 * @date    2022-04-13
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __HLED_CFG_H__
#define __HLED_CFG_H__

/****************************************************************************************************************************/
/*                                                       LEDs configuration                                                 */
/****************************************************************************************************************************/

/*LEDs port*/
#define LED1_PORT              (PORTC)
#define LED2_PORT              (PORTC)

/*LEDs pins*/
#define LED1_PIN               (PIN2)
#define LED2_PIN               (PIN3)

#endif /*__HLED_CFG_H__*/