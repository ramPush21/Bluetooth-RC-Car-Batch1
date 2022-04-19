/**
 * @file    HBLTH_program.cpp
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the logical operations of bluetooth module
 * @version 1.0
 * @date    2022-04-18
 * 
 * ©2021 RAM Push Copyrights
 * 
 */

/****************************************************************************************************************************/
/*                                                        Includes                                                          */
/****************************************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MUART_interface.h"
#include "HBLTH_interface.h"
#include "HBLTH_cfg.h"

/****************************************************************************************************************************/
/*                                                    Important class objects                                               */
/****************************************************************************************************************************/

/*Global UART object that used to receive data from bluetooth module*/
muartClass_t obj_uart(BAUD_RATE_9600BPS, NO_INTERRUPTS_USED);

/*Global dio objects for bluetooth Tx and Rx pins*/
mdioClass_t obj_blthTxPin_PD0(BLTH_TX_RX_PORT, BLTH_TX_PIN);
mdioClass_t obj_blthRxPin_PD1(BLTH_TX_RX_PORT, BLTH_RX_PIN);

/****************************************************************************************************************************/
/*                                                     Functions' definitions                                               */
/****************************************************************************************************************************/

hblthClass_t::hblthClass_t(void)
{
    /*Set the bluetooth Tx pin as input float and Rx pin as output*/
    obj_blthTxPin_PD0.setPinDirection(INPUT_FLOAT);
    obj_blthRxPin_PD1.setPinDirection(OUTPUT);

    /*Return from the cognstructor*/
    return;
}

void hblthClass_t::getData(u8_t* pu8_bluetoothData)
{
    /*Receive byte from bluetooth module (polling)*/
    obj_uart.recvByte(pu8_bluetoothData);

    /*Return from this function*/
    return;
}

void hblthClass_t::getData_interrupt(u8_t* pu8_bluetoothData)
{
    /*Receive byte from bluetooth module (interrupt)*/
    obj_uart.recvByte_interrupt(pu8_bluetoothData);

    /*Return from this function*/
    return;
}