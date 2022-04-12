/**
 * @file    MUART_private.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the private information of UART module
 * @version 1.0
 * @date    2021-04-12
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __MUART_PRIVATE_H__
#define __MUART_PRIVATE_H__

/****************************************************************************************************************************/
/*                                                        UART Registers                                                    */
/****************************************************************************************************************************/

#define MUART_UDR                     (*(volatile u8_t*)(0x2C))
#define MUART_UCSRA                   (*(volatile u8_t*)(0x2B))
#define MUART_UCSRB                   (*(volatile u8_t*)(0x2A))
#define MUART_UCSRC                   (*(volatile u8_t*)(0x40))
#define MUART_UBRRH                   (*(volatile u8_t*)(0x40))
#define MUART_UBRRL                   (*(volatile u8_t*)(0x29))

/****************************************************************************************************************************/
/*                                                  Important registers' bits                                               */
/****************************************************************************************************************************/
#define UCSRA_RXC_BIT                 (7)
#define UCSRA_TXC_BIT                 (6)
#define UCSRA_UDRE_BIT                (5)

#endif /*__MUART_PRIVATE_H__*/