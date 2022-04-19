/**
 * @file    HBLTH_interface.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the interfacing information of bluetooth module 
 * @version 1.0
 * @date    2022-04-18
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __HBLTH_INTERFACE_H__
#define __HBLTH_INTERFACE_H__

/****************************************************************************************************************************/
/*                                                   Interfacing class                                                      */
/****************************************************************************************************************************/

class hblthClass_t
{
    /*Public members*/
    public:

        /**
         * @brief Construct a new bluetooth class object to initialize its preconfigured Tx & Rx pins
         * 
         */
        hblthClass_t(void);

        /**
         * @brief This function is responsible for getting data from bluetooth module (polling)
         * 
         * @param pu8_bluetoothData 
         */
        void getData(u8_t* pu8_bluetoothData);

        /**
         * @brief This function is responsible for getting data from bluetooth module (interrupt)
         * 
         * @param pu8_bluetoothData 
         */
        void getData_interrupt(u8_t* pu8_bluetoothData);        
};

#endif /*__HBLTH_INTERFACE_H__*/