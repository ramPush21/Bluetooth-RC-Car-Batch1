/**
 * @file    MUART_interface.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the interfacing information of UART module 
 * @version 1.0
 * @date    2021-04-12
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __MUART_INTERFACE_H__
#define __MUART_INTERFACE_H__

/****************************************************************************************************************************/
/*                                                   Interfacing macros                                                     */
/****************************************************************************************************************************/

/*Baud rate values for 4MHz*/
#define BAUD_RATE_2400BPS      (103)
#define BAUD_RATE_4800BPS      (51)
#define BAUD_RATE_9600BPS      (25)
#define BAUD_RATE_19200BPS     (12)
#define BAUD_RATE_115200BPS    (1)

/*Interrupt options*/
#define NO_INTERRUPTS_USED     (0x00)
#define USE_TX_INTERRUPT_ONLY  (0x40)
#define USE_RX_INTERRUPT_ONLY  (0x80)
#define USE_TX_RX_INTERRUPTS   (0xC0)

/****************************************************************************************************************************/
/*                                                   Interfacing class                                                      */
/****************************************************************************************************************************/

class muartClass_t
{
    /*Public members*/
    public:
        
        /**
         * @brief Construct a new UART object with specific baud rate and with/without using interrupts
         * 
         * @param au16_baudRate 
         * @param au8_useInterruptOption 
         */
        muartClass_t(u16_t au16_baudRate, u8_t au8_useInterruptOption);

        /*Functions' prototypes*/

        /**
         * @brief This function is used to send one byte of data over UART protocol
         * 
         * @param au8_dataByte 
         */
        void sendByte(u8_t au8_dataByte);

        /**
         * @brief This function is used to send stream of data bytes with certain size over UART protocol
         * 
         * @param pu8_dataStream 
         * @param au8_dataSize 
         */
        void sendStream(u8_t* pu8_dataStream, u8_t au8_dataSize);

        /**
         * @brief This function is used to receive one byte of data over UART protocol
         * 
         * @param pu8_dataByte 
         */
        void recvByte(u8_t* pu8_dataByte);

        /**
         * @brief This function is used to send one byte of data over UART protocol by using Tx interrupt
         * 
         * @param au8_dataByte 
         */
        void sendByte_interrupt(u8_t au8_dataByte);

        /**
         * @brief This function is used to receive one byte of data over UART protocol by using Rx interrupt
         * 
         * @param pu8_dataByte 
         */
        void recvByte_interrupt(u8_t* pu8_dataByte);
};

#endif /*__MUART_INTERFACE_H__*/