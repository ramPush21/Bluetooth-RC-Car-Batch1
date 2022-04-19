/**
 * @file    HBUZZER_program.cpp
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the logical operations of buzzer module
 * @version 1.0
 * @date    2021-07-19
 * 
 * ©2021 RAM Push Copyrights
 * 
 */

/****************************************************************************************************************************/
/*                                                        Includes                                                          */
/****************************************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HBUZZER_interface.h"
#include "HBUZZER_cfg.h"

/****************************************************************************************************************************/
/*                                                       Important variables                                                */
/****************************************************************************************************************************/

/*Global objects used to control Buzzer DIO pin*/
mdioClass_t gobj_buzzerPin(BUZZER_PORT, BUZZER_PIN);

/****************************************************************************************************************************/
/*                                                     Functions' definitions                                               */
/****************************************************************************************************************************/

hbuzzerClass_t::hbuzzerClass_t(void)
{
    /*Set preconfigured buzzer to output*/
    gobj_buzzerPin.setPinDirection(OUTPUT);

    /*Return from this constructor*/
    return;
}

void hbuzzerClass_t::buzzOn(void)
{
    /*Setting buzzer pin to high (ON)*/
    gobj_buzzerPin.setPinValue(HIGH);

    /*Return from this function*/
    return;
}

void hbuzzerClass_t::buzzOff(void)
{
    /*Setting buzzer pin to low (OFF)*/
    gobj_buzzerPin.setPinValue(LOW);

    /*Return from this function*/
    return;
}