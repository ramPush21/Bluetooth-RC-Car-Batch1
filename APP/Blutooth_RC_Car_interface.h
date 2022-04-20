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
/*                                                Interfacing functions' prototypes                                         */
/****************************************************************************************************************************/

/**
 * @brief This function is responsible for initializing the robot system
 * 
 */
void system_init(void);

/**
 * @brief This function is responsible for running the robot system
 * 
 */
void system_run(void);

#endif /*__BLUETOOTH_RC_CAR_INTERFACE_H__*/