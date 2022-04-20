/**
 * @file    Bluetooth_RC_Car_cfg.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the configuration information of bluetooth RC car application module
 * @version 1.0
 * @date    2022-04-19
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __BLUETOOTH_RC_CAR_CFG_H__
#define __BLUETOOTH_RC_CAR_CFG_H__

/****************************************************************************************************************************/
/*                                                       Application configuration                                          */
/****************************************************************************************************************************/

/*LED configuration*/
#define FRONT_LED           (LED2)
#define REAR_LED            (LED1)

/*Motor configuration*/
#define LEFT_MOTOR          (MOT_CHANNEL_1)
#define RIGHT_MOTOR         (MOT_CHANNEL_2)

/*Bluetooth commands*/
#define FORWARD_CMD         ('F')
#define BACKWARD_CMD        ('B')
#define LEFT_CMD            ('L')
#define RIGHT_CMD           ('R')
#define STOP_CMD            ('S')
#define FRONT_LED_ON_CMD    ('W')
#define FRONT_LED_OFF_CMD   ('w')
#define REAR_LED_ON_CMD     ('U')
#define REAR_LED_OFF_CMD    ('u')
#define HORN_ON_CMD         ('V')
#define HORN_OFF_CMD        ('v')
#define HAZARD_ON_CMD       ('X')
#define HAZARD_OFF_CMD      ('x')
#define SPEED_0_CMD         ('0')
#define SPEED_10_CMD        ('1')
#define SPEED_20_CMD        ('2')
#define SPEED_30_CMD        ('3')
#define SPEED_40_CMD        ('4')
#define SPEED_50_CMD        ('5')
#define SPEED_60_CMD        ('6')
#define SPEED_70_CMD        ('7')
#define SPEED_80_CMD        ('8')
#define SPEED_90_CMD        ('9')
#define SPEED_100_CMD       ('q')

#endif /*__BLUETOOTH_RC_CAR_CFG_H__*/