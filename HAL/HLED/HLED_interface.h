/**
 * @file    HLED_interface.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains interfacing information for LED module
 * @version 1.0
 * @date    2022-04-13
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __HLED_INTERFACE_H__
#define __HLED_INTERFACE_H__

/**************************************************************************************/
/*                                 Interfacing macros                                 */
/**************************************************************************************/

/*LED numbers*/
#define LED1    (1)
#define LED2    (2)

/**************************************************************************************/
/*                                    LED Class                                       */
/**************************************************************************************/

class hledClass_t
{
    /*Public attributes*/
    public:

        /**
         * @brief This constructor is responsible for configuring LED pin as output
         * 
         */
        hledClass_t(u8_t au8_ledNumber);

        /**
         * @brief This function is responsible for turning ON the LED
         * 
         */
        void ledOn(void);

        /**
         * @brief This function is responsible for turning OFF the LED
         * 
         */
        void ledOff(void);

        /**
         * @brief This function is responsible for toggling the LED
         * 
         */
        void ledToggle(void);

    /*Private members*/
    private:

        /*Private variable used to hold the chosen LED number*/
        u8_t au8_prv_ledNumber;
};

#endif /*__HLED_INTERFACE_H__*/