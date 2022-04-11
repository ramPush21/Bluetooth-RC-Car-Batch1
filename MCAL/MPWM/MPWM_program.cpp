/**
 * @file    MPWM_program.cpp
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the logical operations of PWM module
 * @version 1.0
 * @date    2022-04-11
 * 
 * ©2021 RAM Push Copyrights
 * 
 */

/****************************************************************************************************************************/
/*                                                        Includes                                                          */
/****************************************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MPWM_private.h"
#include "MPWM_interface.h"

/****************************************************************************************************************************/
/*                                                     Important macros                                                     */
/****************************************************************************************************************************/

#define TIMER1_CHANNEL1_CMP_RESET                       (0x3FFF)
#define TIMER1_CHANNEL2_CMP_RESET                       (0xCFFF)
#define TIMER1_CH1_PHASE_CORRECT_NON_INV_MODES_2KHZ     (0x8102)
#define TIMER1_CH2_PHASE_CORRECT_NON_INV_MODES_2KHZ     (0x2102)
#define TIMER2_PHASE_CORRECT_NON_INV_MODES_2KHZ         (0x62)
#define TIMER1_RESET_CLK_BITS                           (0xFFF8)
#define TIMER2_RESET_CLK_BITS                           (0xF8)

/****************************************************************************************************************************/
/*                                                   Functions' definitions                                                 */
/****************************************************************************************************************************/

mpwmClass_t::mpwmClass_t(u8_t au8_channel)
{
    /*Setting the chosen channel number*/
    au8_prv_chosenChannel = au8_channel;

    /*Switching over PWM channels*/
    switch(au8_channel)
    {
        /*In case of choosing channel 1*/
        case PWM_CHANNEL_1:

            /*Reset the compare mode bits*/
            MPWM_TCCR1 &= TIMER1_CHANNEL1_CMP_RESET;
            
            /*Enable phase correct and non inverted mode with 2KHz*/
            MPWM_TCCR1 |= TIMER1_CH1_PHASE_CORRECT_NON_INV_MODES_2KHZ;
            
            /*Set the duty cycle to 0%*/
            MPWM_OCR1A = 0;

            /*Breaking form this case*/
            break;

        /*In case of choosing channel 2*/
        case PWM_CHANNEL_2:

            /*Reset the compare mode bits*/
            MPWM_TCCR1 &= TIMER1_CHANNEL2_CMP_RESET;
            
            /*Enable phase correct and non inverted mode with 2KHz*/
            MPWM_TCCR1 |= TIMER1_CH2_PHASE_CORRECT_NON_INV_MODES_2KHZ;
            
            /*Set the duty cycle to 0%*/
            MPWM_OCR1B = 0;

            /*Breaking form this case*/
            break;

        /*In case of choosing channel 3*/
        case PWM_CHANNEL_3:

            /*Enable phase correct and non inverted mode with 2KHz*/
            MPWM_TCCR2 = TIMER2_PHASE_CORRECT_NON_INV_MODES_2KHZ;
            
            /*Set the duty cycle to 0%*/
            MPWM_OCR2 = 0;

            /*Breaking form this case*/
            break;

        /*In case of default case*/
        default:

            /*Breaking from default case*/
            break;
    }

    /*Return from this constructor*/
    return;
}

void mpwmClass_t::updatePWM(u8_t au8_frequency, u8_t au8_dutyCycle)
{
    /*Switching over PWM chosen channel*/
    switch(au8_prv_chosenChannel)
    {
        /*In case of choosing channel 1*/
        case PWM_CHANNEL_1:

            /*Reset the CLK bits*/
            MPWM_TCCR1 &= TIMER1_RESET_CLK_BITS;

            /*Setting the new frequency*/
            MPWM_TCCR1 |= au8_frequency;

            /*Setting the new duty cycle*/
            MPWM_OCR1A = au8_dutyCycle;

            /*Breaking form this case*/
            break;

        /*In case of choosing channel 2*/
        case PWM_CHANNEL_2:

            /*Reset the CLK bits*/
            MPWM_TCCR1 &= TIMER1_RESET_CLK_BITS;

            /*Setting the new frequency*/
            MPWM_TCCR1 |= au8_frequency;

            /*Setting the new duty cycle*/
            MPWM_OCR1B = au8_dutyCycle;

            /*Breaking form this case*/
            break;

        /*In case of choosing channel 3*/
        case PWM_CHANNEL_3:

            /*Reset the CLK bits*/
            MPWM_TCCR2 &= TIMER2_RESET_CLK_BITS;

            /*Setting the new frequency*/
            MPWM_TCCR2 |= au8_frequency;

            /*Setting the new duty cycle*/
            MPWM_OCR2 = au8_dutyCycle;

            /*Breaking form this case*/
            break;

        /*In case of default case*/
        default:

            /*Breaking from default case*/
            break;
    }

    /*Return from this function*/
    return;
}