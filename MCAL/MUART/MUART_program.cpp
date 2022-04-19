/**
 * @file    MUART_program.cpp
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the logical operations of UART module
 * @version 1.0
 * @date    2021-04-12
 * 
 * ©2021 RAM Push Copyrights
 * 
 */

/****************************************************************************************************************************/
/*                                                        Includes                                                          */
/****************************************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LINTERRUPTS.h"
#include "MUART_private.h"
#include "MUART_interface.h"

/****************************************************************************************************************************/
/*                                                     Important macros                                                     */
/****************************************************************************************************************************/

#define ENABLE_TX_RX_OPERATION    (0x18)
#define ASYNC_1SB_8BCS_NO_PARITY  (0x86)
#define SHIFTING_BY_8             (8)
#define NEW_DATA_RECEIVED         (1)
#define NEW_DATA_TRANSMITTED      (1)
#define FLAG_RESET                (0)

/****************************************************************************************************************************/
/*                                                     Important variables                                                  */
/****************************************************************************************************************************/

/*Global variable used to indicate if the data has transmitted or not*/
static volatile u8_t gu8_transFlag = NEW_DATA_TRANSMITTED;

/*Global variable used to indicate if there's a data to be received or not*/
static volatile u8_t gu8_recvFlag = FLAG_RESET;

/*Global variable used to get the received data*/
static volatile u8_t gu8_receivedData;

/****************************************************************************************************************************/
/*                                                   Functions' definitions                                                 */
/****************************************************************************************************************************/

muartClass_t::muartClass_t(u16_t au16_baudRate, u8_t au8_useInterruptOption)
{
    /*Enabling the Tx and Rx pins and setting the passed interrupt options*/
    MUART_UCSRB = ENABLE_TX_RX_OPERATION | au8_useInterruptOption;

    /*Setting the asynchronous mode, 1 stop bit, 8 bits character size and no parity bit used*/
    MUART_UCSRC = ASYNC_1SB_8BCS_NO_PARITY;

    /*Setting the baud rate value*/
    MUART_UBRRL = (u8_t)(au16_baudRate);
    MUART_UBRRH = (u8_t)(au16_baudRate >> SHIFTING_BY_8);

    /*Return from this constructor*/
    return;
}

void muartClass_t::sendByte(u8_t au8_dataByte)
{
    /*Checking if the UDR register is empty or not*/
    if(GET_BIT(MUART_UCSRA, UCSRA_UDRE_BIT))
    {
        /*Setting the data byte to be sent*/
        MUART_UDR = au8_dataByte;

        /*Waiting until the data sending is complete*/
        while(!GET_BIT(MUART_UCSRA, UCSRA_TXC_BIT));

        /*Clearing the Tx complete flag*/
        SET_BIT(MUART_UCSRA, UCSRA_TXC_BIT);
    }
    else
    {
        /*Do nothing*/
    }

    /*Return from this function*/
    return;
}

void muartClass_t::sendStream(u8_t* pu8_dataStream, u8_t au8_dataSize)
{
    /*Looping over data size*/
    while(au8_dataSize--)
    {
        /*Checking if the UDR register is empty or not*/
        if(GET_BIT(MUART_UCSRA, UCSRA_UDRE_BIT))
        {
            /*Setting the data byte to be sent*/
            MUART_UDR = *pu8_dataStream;

            /*Waiting until the data sending is complete*/
            while(!GET_BIT(MUART_UCSRA, UCSRA_TXC_BIT));

            /*Clearing the Tx complete flag*/
            SET_BIT(MUART_UCSRA, UCSRA_TXC_BIT);

            /*Incrementing the data pointer*/
            pu8_dataStream++;
        }
        else
        {
            /*Do nothing*/
        }
    }

    /*Return from this function*/
    return;
}

void muartClass_t::recvByte(u8_t* pu8_dataByte)
{
    /*Checking if there's a data to be received or not*/
    if(GET_BIT(MUART_UCSRA, UCSRA_RXC_BIT))
    {
        /*Getting the received data byte*/
        *pu8_dataByte = MUART_UDR;
    }
    else
    {
        /*Do nothing*/
    }

    /*Return from this function*/
    return;
}

void muartClass_t::sendByte_interrupt(u8_t au8_dataByte)
{
    /*Checking if the data is transmitted or not*/
    if(gu8_transFlag == NEW_DATA_TRANSMITTED)
    {
        /*Resetting the transmit flag*/
        gu8_transFlag = FLAG_RESET;

        /*Setting the data byte to be sent*/
        MUART_UDR = au8_dataByte;
    }
    else
    {
        /*Do nothing*/
    }

    /*Return from this function*/
    return;
}

void muartClass_t::recvByte_interrupt(u8_t* pu8_dataByte)
{
    /*Checking if there's a data to be received or not*/
    if(gu8_recvFlag == NEW_DATA_RECEIVED)
    {
        /*Resetting the receive flag*/
        gu8_recvFlag = FLAG_RESET;

        /*Getting the received data byte*/
        *pu8_dataByte = gu8_receivedData;
    }
    else
    {
        /*Do nothing*/
    }

    /*Return from this function*/
    return;
}

/****************************************************************************************************************************/
/*                                                              UART ISRs                                                   */
/****************************************************************************************************************************/

/*Tx complete ISR*/
ISR(USART_TXC_VECT)
{
    /*Assuring that the data has been transmitted*/
    gu8_transFlag = NEW_DATA_TRANSMITTED;
}

/*Rx complete ISR*/
ISR(USART_RXC_VECT)
{
    /*Reading the data register*/
    gu8_receivedData = MUART_UDR;

    /*Assuring that there's new data to be received*/
    gu8_recvFlag = NEW_DATA_RECEIVED;
}
