/**
 * @file    MPWM_interface.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the interfacing information of PWM module 
 * @version 1.0
 * @date    2022-04-11
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __MPWM_INTERFACE_H__
#define __MPWM_INTERFACE_H__

/****************************************************************************************************************************/
/*                                                   Interfacing macros                                                     */
/****************************************************************************************************************************/

/*PWM Channels*/
#define PWM_CHANNEL_1     (1)
#define PWM_CHANNEL_2     (2)
#define PWM_CHANNEL_3     (3)

/*PWM Frequencies at 8MHz CLK*/
#define PWM_STOP          (0)
#define PWM_15KHZ         (1)
#define PWM_2KHZ          (2)
#define PWM_244HZ         (3)
#define PWM_60HZ          (4)
#define PWM_14HZ          (5)

/****************************************************************************************************************************/
/*                                                   Interfacing class                                                      */
/****************************************************************************************************************************/

class mpwmClass_t
{
    /*Public members*/
    public:
        
        /**
         * @brief Construct a new PWM class object with 2KHz frequency and 0% duty cycle by default 
         * 
         * @param au8_channel 
         */
        mpwmClass_t(u8_t au8_channel);

        /**
         * @brief This function is used to update a specific PWM channel with specific frequency and duty cycle
         * 
         * @param au8_frequency 
         * @param au8_dutyCycle 
         */
        void updatePWM(u8_t au8_frequency, u8_t au8_dutyCycle);

    /*Private members*/
    private:

        /*Private variable contains the chosen channel number*/
        u8_t au8_prv_chosenChannel;
};

#endif /*__MPWM_INTERFACE_H__*/