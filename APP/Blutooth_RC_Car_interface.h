/**
 * @file    Bluetooth_RC_Car_interface.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the interfacing information of bluetooth RC car application module 
 * @version 1.0
 * @date    2022-04-19
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __BLUETOOTH_RC_CAR_INTERFACE_H__
#define __BLUETOOTH_RC_CAR_INTERFACE_H__

/****************************************************************************************************************************/
/*                                                       Interfacing macros                                                 */
/****************************************************************************************************************************/

#define MAX_MOTOR_SPEED          (255)
#define MIN_MOTOR_SPEED          (0)

/****************************************************************************************************************************/
/*                                                Interfacing functions' prototypes                                         */
/****************************************************************************************************************************/

/**
 * @brief This function is responsible for initializing the robot system
 * 
 */
void system_init(void);

/**
 * @brief This function is used to get the system input command
 * 
 */
void system_getInput(void);

/**
 * @brief This function is used to process the system input command and update the system actions
 * 
 */
void system_processing_and_update(void);

#endif /*__BLUETOOTH_RC_CAR_INTERFACE_H__*/