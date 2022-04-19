/**
 * @file    HMOT_program.cpp
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains main logic of motor module 
 * @version 1.0
 * @date    2022-04-18
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/**************************************************************************************/
/*                                     Includes                                       */
/**************************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "MPWM_interface.h"
#include "HMOT_interface.h"
#include "HMOT_cfg.h"

/**************************************************************************************/
/*                                  Important macros                                  */
/**************************************************************************************/

#define NO_DUTY_CYCLE   (0)

/**************************************************************************************/
/*                                 Important variables                                */
/**************************************************************************************/

/*Global objects used to define enable pins*/
mdioClass_t motor_1_dioEnPin(MOTOR_CHANNEL_1_PWM_PORT, MOTOR_CHANNEL_1_PWM_PIN);
mdioClass_t motor_2_dioEnPin(MOTOR_CHANNEL_2_PWM_PORT, MOTOR_CHANNEL_2_PWM_PIN);

/*Global objects used to define direction pins*/
mdioClass_t motor_1_dioIn_1_pin(MOTOR_CHANNEL_1_DIR_PORT, MOTOR_CHANNEL_1_DIR_IN1);
mdioClass_t motor_1_dioIn_2_pin(MOTOR_CHANNEL_1_DIR_PORT, MOTOR_CHANNEL_1_DIR_IN2);
mdioClass_t motor_2_dioIn_1_pin(MOTOR_CHANNEL_2_DIR_PORT, MOTOR_CHANNEL_2_DIR_IN1);
mdioClass_t motor_2_dioIn_2_pin(MOTOR_CHANNEL_2_DIR_PORT, MOTOR_CHANNEL_2_DIR_IN2);

/*Global objects used to define PWM pins*/
mpwmClass_t motor_1_pwmChannel(MOTOR_CHANNEL_1_PWM_CHANNEL);
mpwmClass_t motor_2_pwmChannel(MOTOR_CHANNEL_2_PWM_CHANNEL);

/**************************************************************************************/
/*                                Functions' defintions                               */
/**************************************************************************************/

hmotClass_t::hmotClass_t(u8_t au8_motorChannel):au8_prv_motorChannel(au8_motorChannel)
{
    /*Switching over motor channels*/
    switch(au8_motorChannel)
    {
        /*In case of motor channel 1*/
        case MOT_CHANNEL_1:

            /*Motor 1 pins configuration as output*/
            motor_1_dioEnPin.setPinDirection(OUTPUT);
            motor_1_dioIn_1_pin.setPinDirection(OUTPUT);
            motor_1_dioIn_2_pin.setPinDirection(OUTPUT);

            /*Setting PWM settings for motor 1*/
            motor_1_pwmChannel.updatePWM(PWM_2KHZ, NO_DUTY_CYCLE);

            /*Break from this case*/
            break;

        /*In case of motor channel 2*/
        case MOT_CHANNEL_2:

            /*Motor 1 pins configuration as output*/
            motor_2_dioEnPin.setPinDirection(OUTPUT);
            motor_2_dioIn_1_pin.setPinDirection(OUTPUT);
            motor_2_dioIn_2_pin.setPinDirection(OUTPUT);

            /*Setting PWM settings for motor 2*/
            motor_2_pwmChannel.updatePWM(PWM_2KHZ, NO_DUTY_CYCLE);

            /*Break from this case*/
            break;

        /*In case of default*/
        default:

            /*Break from this case*/
            break;
    }
}

void hmotClass_t::updateMotor(u8_t au8_speed, u8_t au8_direction)
{
    /*Switching over motor channels*/
    switch(au8_prv_motorChannel)
    {
        /*In case of motor channel 1*/
        case MOT_CHANNEL_1:

            /*Switching over direction*/
            switch(au8_direction)
            {
                /*In case of main direction*/
                case MOT_MAIN_DIR:

                    /*Motor 1 main direction*/
                    motor_1_dioIn_1_pin.setPinValue(HIGH);
                    motor_1_dioIn_2_pin.setPinValue(LOW);

                    /*Break from this case*/
                    break;

                /*In case of other direction*/
                case MOT_OTHER_DIR:

                    /*Motor 1 other direction*/
                    motor_1_dioIn_1_pin.setPinValue(LOW);
                    motor_1_dioIn_2_pin.setPinValue(HIGH);

                    /*Break from this case*/
                    break;

                /*In case of stop*/
                case MOT_STOP:

                    /*Motor 1 stop*/
                    motor_1_dioIn_1_pin.setPinValue(LOW);
                    motor_1_dioIn_2_pin.setPinValue(LOW);

                    /*Break from this case*/
                    break;

                /*In case of default*/
                default:

                    /*Break from this case*/
                    break;
            }

            /*Setting PWM settings for motor 1*/
            motor_1_pwmChannel.updatePWM(PWM_2KHZ, au8_speed);

            /*Break from this case*/
            break;

        /*In case of motor channel 2*/
        case MOT_CHANNEL_2:

            /*Switching over direction*/
            switch(au8_direction)
            {
                /*In case of main direction*/
                case MOT_MAIN_DIR:

                    /*Motor 2 main direction*/
                    motor_2_dioIn_1_pin.setPinValue(HIGH);
                    motor_2_dioIn_2_pin.setPinValue(LOW);

                    /*Break from this case*/
                    break;

                /*In case of other direction*/
                case MOT_OTHER_DIR:

                    /*Motor 2 other direction*/
                    motor_2_dioIn_1_pin.setPinValue(LOW);
                    motor_2_dioIn_2_pin.setPinValue(HIGH);

                    /*Break from this case*/
                    break;

                /*In case of stop*/
                case MOT_STOP:

                    /*Motor 2 stop*/
                    motor_2_dioIn_1_pin.setPinValue(LOW);
                    motor_2_dioIn_2_pin.setPinValue(LOW);

                    /*Break from this case*/
                    break;

                /*In case of default*/
                default:

                    /*Break from this case*/
                    break;
            }

            /*Setting PWM settings for motor 2*/
            motor_2_pwmChannel.updatePWM(PWM_2KHZ, au8_speed);

            /*Break from this case*/
            break;

        /*In case of default*/
        default:

            /*Break from this case*/
            break;
    }

    /*Return from this function*/
    return;
}