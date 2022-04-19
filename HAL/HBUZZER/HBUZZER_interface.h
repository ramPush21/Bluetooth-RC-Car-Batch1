/**
 * @file    HBUZZER_interface.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the interfacing information of buzzer module 
 * @version 1.0
 * @date    2022-04-18
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __HBUZZER_INTERFACE_H__
#define __HBUZZER_INTERFACE_H__

/****************************************************************************************************************************/
/*                                                   Interfacing class                                                      */
/****************************************************************************************************************************/

class hbuzzerClass_t
{
    /*Public members*/
    public:

        /**
         * @brief Construct a new buzzer class object to initialize preconfigured buzzer
         * 
         */
        hbuzzerClass_t(void);

        /**
         * @brief This function is responsible for turning a preconfigured buzzer to ON
         * 
         */
        void buzzOn(void);

        /**
         * @brief This function is responsible for turning a preconfigured buzzer to OFF
         * 
         */
        void buzzOff(void);
};


#endif /*__HBUZZER_INTERFACE_H__*/