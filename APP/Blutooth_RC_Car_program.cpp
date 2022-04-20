/**
 * @file    Bluetooth_RC_Car_program.cpp
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the logical operations of bluetooth RC car application module
 * @version 1.0
 * @date    2022-04-19
 * 
 * ©2021 RAM Push Copyrights
 * 
 */

/****************************************************************************************************************************/
/*                                                        Includes                                                          */
/****************************************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HBLTH_interface.h"
#include "HLED_interface.h"
#include "HBUZZER_interface.h"
#include "HMOT_interface.h"
#include "STTS_interface.h"
#include "Bluetooth_RC_Car_private.h"
#include "Blutooth_RC_Car_interface.h"
#include "Blutooth_RC_Car_cfg.h"

/****************************************************************************************************************************/
/*                                                           Important macros                                               */
/****************************************************************************************************************************/

#define SPEED_SECTION_VALUE    (23)
#define MAX_MOTOR_SPEED        (255)
#define HAZARD_STATUS_ON       (1)
#define HAZARD_STATUS_OFF      (2)
#define HAZARD_TIMING          (20)

/****************************************************************************************************************************/
/*                                                  Important class objects and variables                                   */
/****************************************************************************************************************************/

/*Global object used to get command through bluetooth communication*/
hblthClass_t obj_blthCommunication;

/*Global object used to control the buzzer*/
hbuzzerClass_t obj_buzzer;

/*Global object used to control the front LEDs*/
hledClass_t obj_frontLEDs(FRONT_LED);

/*Global object used to control the rear LEDs*/
hledClass_t obj_rearLEDs(REAR_LED);

/*Global object used to control the right motor*/
hmotClass_t obj_rightMotor(RIGHT_MOTOR);

/*Global object used to control the left motor*/
hmotClass_t obj_leftMotor(LEFT_MOTOR);

/*Global object used to control the time triggered system with specific tick time*/
sttsClass_t obj_tts(SYSTEM_TICK_TIME);

/*Global variable used to hold the bluetooth command data received*/
static u8_t gu8_blthData;

/*Global variable used to hold the hazard enable status*/
static u8_t gu8_hazardStatus;

/*Global variable used to hold the hazard time counter*/
static u8_t gu8_hazardTimeCounter;

/****************************************************************************************************************************/
/*                                                     System tasks                                                         */
/****************************************************************************************************************************/

void system_init(void)
{
    /*Selcting sleep mode*/
    SELECT_SLEEP_MODE(IDLE_MODE);

    /*Return from this function*/
    return;
}

static void system_getInput(void)
{
    /*Getting the bluetooth data*/
    obj_blthCommunication.getData(&gu8_blthData);

    /*Return from this function*/
    return;
}

static void system_processing_and_update(void)
{
    /*Local static variable used to hold the motors speed*/
    static u8_t au8_motorSpeed = 0;

    /*Switching over bluetooth commands*/
    switch(gu8_blthData)
    {
        /*In case of forward command*/
        case FORWARD_CMD:

            /*Setting speed for right and left motors with main direction*/
            obj_rightMotor.updateMotor(au8_motorSpeed, MOT_MAIN_DIR);
            obj_leftMotor.updateMotor(au8_motorSpeed, MOT_MAIN_DIR);

            /*Breaking from this case*/
            break;

        /*In case of backward command*/
        case BACKWARD_CMD:

            /*Setting speed for right and left motors with other direction*/
            obj_rightMotor.updateMotor(au8_motorSpeed, MOT_OTHER_DIR);
            obj_leftMotor.updateMotor(au8_motorSpeed, MOT_OTHER_DIR);

            /*Breaking from this case*/
            break;

        /*In case of left command*/
        case LEFT_CMD:

            /*Setting speed for right and left motors with left direction*/
            obj_rightMotor.updateMotor(au8_motorSpeed, MOT_MAIN_DIR);
            obj_leftMotor.updateMotor(au8_motorSpeed, MOT_STOP);

            /*Breaking from this case*/
            break;

        /*In case of right command*/
        case RIGHT_CMD:

            /*Setting speed for right and left motors with right direction*/
            obj_rightMotor.updateMotor(au8_motorSpeed, MOT_STOP);
            obj_leftMotor.updateMotor(au8_motorSpeed, MOT_MAIN_DIR);

            /*Breaking from this case*/
            break;

        /*In case of stop command*/
        case STOP_CMD:

            /*Stopping right and left motors*/
            obj_rightMotor.updateMotor(au8_motorSpeed, MOT_STOP);
            obj_leftMotor.updateMotor(au8_motorSpeed, MOT_STOP);

            /*Breaking from this case*/
            break;

        /*In case of front LED ON command*/
        case FRONT_LED_ON_CMD:

            /*Turning ON front LEDs*/
            obj_frontLEDs.ledOn();

            /*Breaking from this case*/
            break;

        /*In case of front LED OFF command*/
        case FRONT_LED_OFF_CMD:

            /*Turning OFF front LEDs*/
            obj_frontLEDs.ledOff();

            /*Breaking from this case*/
            break;

        /*In case of rear LED ON command*/
        case REAR_LED_ON_CMD:

            /*Turning ON rear LEDs*/
            obj_rearLEDs.ledOn();

            /*Breaking from this case*/
            break;

        /*In case of rear LED OFF command*/
        case REAR_LED_OFF_CMD:

            /*Turning OFF rear LEDs*/
            obj_rearLEDs.ledOff();

            /*Breaking from this case*/
            break;

        /*In case of horn ON command*/
        case HORN_ON_CMD:

            /*Turning ON horn*/
            obj_buzzer.buzzOn();

            /*Breaking from this case*/
            break;

        /*In case of horn OFF command*/
        case HORN_OFF_CMD:

            /*Turning OFF horn*/
            obj_buzzer.buzzOff();

            /*Breaking from this case*/
            break;

        /*In case of hazard ON command*/
        case HAZARD_ON_CMD:

            /*Report hazard ON status*/
            gu8_hazardStatus = HAZARD_STATUS_ON;

            /*Breaking from this case*/
            break;

        /*In case of hazard OFF command*/
        case HAZARD_OFF_CMD:

            /*Report hazard OFF status*/
            gu8_hazardStatus = HAZARD_STATUS_OFF;

            /*Breaking from this case*/
            break;

        /*In case of speed percentage (0% -> 90%) command*/
        case SPEED_0_CMD ... SPEED_90_CMD:

            /*Updating the motor speed duty cycle value*/
            au8_motorSpeed = (gu8_blthData - '0') * SPEED_SECTION_VALUE;

            /*Breaking from this case*/
            break;

        /*In case of 100% speed command*/
        case SPEED_100_CMD:

            /*Updating the motor speed duty cycle value*/
            au8_motorSpeed = MAX_MOTOR_SPEED;

            /*Breaking from this case*/
            break;

        /*In case of default*/        
        default:

            /*Breaking from this case*/
            break;
    }

    /*Checking the current hazard status ON or OFF*/
    if(gu8_hazardStatus == HAZARD_STATUS_ON)
    {
        /*Increment hazard time counter by 1*/
        gu8_hazardTimeCounter++;

        /*If the hazard time comes toggle the rear LED*/
        if(gu8_hazardTimeCounter >= HAZARD_TIMING)
        {
            /*Toggle rear LED*/
            obj_rearLEDs.ledToggle();

            /*Reset hazard time counter*/
            gu8_hazardTimeCounter = 0;
        }
        else
        {
            /*Do nothing*/
        }        
    }
    else if(gu8_hazardStatus == HAZARD_STATUS_OFF)
    {
        /*Turn OFF rear LEDs*/
        obj_rearLEDs.ledOff();

        /*Reset hazard time counter*/
        gu8_hazardTimeCounter = 0;

        /*Reset hazard report status*/
        gu8_hazardStatus = 0;
    }
    else
    {
        /*Do nothing*/
    }

    /*Reset bluetooth data*/
    gu8_blthData = 0;

    /*Return from this function*/
    return;
}

void system_run(void)
{
    /*Static local variables used to hold the system tasks with specific periodicity*/
    static task_t str_task1 = {system_getInput, TASK1_PERIODICITY};
    static task_t str_task2 = {system_processing_and_update, TASK2_PERIODICITY};

    /*Adding two tasks to TTS*/
    obj_tts.addTask(str_task1);
    obj_tts.addTask(str_task2);

    /*Run scheduler*/
    obj_tts.schedulerRun();
    
    /*Enable WDT with 65ms time to reset*/
    WDT_ENABLE(RESET_65_0_MS);

    /*System infinite loop*/
    while(1)
    {
        /*Refresh WDT*/
        WDT_REFRESH();

        /*Sending the MCU to sleep mode*/
        MCU_GTS();
    }

    /*Return from this function*/
    return;
}