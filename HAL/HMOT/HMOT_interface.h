/**
 * @file    HMOT_interface.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the interfacing information of motor module 
 * @version 1.0
 * @date    2022-04-18
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __HMOT_INTERFACE_H__
#define __HMOT_INTERFACE_H__

/****************************************************************************************************************************/
/*                                                   Interfacing macros                                                     */
/****************************************************************************************************************************/

/*Motor interfacing channels*/
#define MOT_CHANNEL_1  (1)
#define MOT_CHANNEL_2  (2)

/*Motor directions*/
#define MOT_MAIN_DIR   (1)
#define MOT_OTHER_DIR  (2)
#define MOT_STOP       (3)

/****************************************************************************************************************************/
/*                                                   Interfacing class                                                      */
/****************************************************************************************************************************/

class hmotClass_t
{
    /*Public members*/
    public:

        /**
         * @brief This constructor is used to initialize a specific motor channel
         * 
         * @param au8_motorChannel 
         */
        hmotClass_t(u8_t au8_motorChannel);

        /**
         * @brief This function is used to update a specific motor speed (0 -> 0%, 255 -> 100%) and direction
         * 
         * @param au8_speed 
         * @param au8_direction 
         */
        void updateMotor(u8_t au8_speed, u8_t au8_direction);

    private:

        /*Private variable used to save the selected motor channel*/
        u8_t au8_prv_motorChannel;
};

#endif /*__HMOT_INTERFACE_H__*/