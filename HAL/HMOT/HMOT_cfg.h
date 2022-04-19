/**
 * @file    HMOT_cfg.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the configuration information of motor module
 * @version 1.0
 * @date    2021-07-17
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __HMOT_CONFIG_H__
#define __HMOT_CONFIG_H__

/****************************************************************************************************************************/
/*                                                       Motors' configuration                                              */
/****************************************************************************************************************************/

/*Motor channel 1 configuation*/

/*Motor channel 1 PWM configuration*/
#define MOTOR_CHANNEL_1_PWM_CHANNEL  (PWM_CHANNEL_1)
#define MOTOR_CHANNEL_1_PWM_PORT     (PORTB)
#define MOTOR_CHANNEL_1_PWM_PIN      (PIN1)

/*Motor channel 1 direction configuration*/
#define MOTOR_CHANNEL_1_DIR_PORT     (PORTD)
#define MOTOR_CHANNEL_1_DIR_IN1      (PIN2)
#define MOTOR_CHANNEL_1_DIR_IN2      (PIN3)

/*Motor channel 2 configuation*/

/*Motor channel 2 PWM configuration*/
#define MOTOR_CHANNEL_2_PWM_CHANNEL  (PWM_CHANNEL_2)
#define MOTOR_CHANNEL_2_PWM_PORT     (PORTB)
#define MOTOR_CHANNEL_2_PWM_PIN      (PIN2)

/*Motor channel 2 direction configuration*/
#define MOTOR_CHANNEL_2_DIR_PORT     (PORTD)
#define MOTOR_CHANNEL_2_DIR_IN1      (PIN4)
#define MOTOR_CHANNEL_2_DIR_IN2      (PIN5)

#endif /*__HMOT_CONFIG_H__*/