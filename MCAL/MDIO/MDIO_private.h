/**
 * @file    MDIO_private.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains private information for DIO module
 * @version 1.0
 * @date    2022-04-06
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __MDIO_PRIVATE_H__
#define __MDIO_PRIVATE_H__

/**************************************************************************************/
/*                                   DIO Registers                                    */
/**************************************************************************************/

/*PORTB registers*/
#define MDIO_PORTB_ADDRESS                  ((u8_t*)(0x38))
#define MDIO_DDRB_ADDRESS                   ((u8_t*)(0x37))
#define MDIO_PINB_ADDRESS                   ((u8_t*)(0x36))

/*PORTC registers*/
#define MDIO_PORTC_ADDRESS                  ((u8_t*)(0x35))
#define MDIO_DDRC_ADDRESS                   ((u8_t*)(0x34))
#define MDIO_PINC_ADDRESS                   ((u8_t*)(0x33))

/*PORTD registers*/
#define MDIO_PORTD_ADDRESS                  ((u8_t*)(0x32))
#define MDIO_DDRD_ADDRESS                   ((u8_t*)(0x31))
#define MDIO_PIND_ADDRESS                   ((u8_t*)(0x30))

#endif /*__MDIO_PRIVATE_H__*/