/**
 * @file    HLED_program.cpp
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains main logic for LED module
 * @version 1.0
 * @date    2022-04-13
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
#include "HLED_interface.h"
#include "HLED_cfg.h"

/**************************************************************************************/
/*                                 Important variables                                */
/**************************************************************************************/

/*Global objects used to control LED DIO pins*/
mdioClass_t gobj_led1Pin(LED1_PORT, LED1_PIN);
mdioClass_t gobj_led2Pin(LED2_PORT, LED2_PIN);

/**************************************************************************************/
/*                                Functions' defintions                               */
/**************************************************************************************/

hledClass_t::hledClass_t(u8_t au8_ledNumber):au8_prv_ledNumber(au8_ledNumber)
{
    /*Switching over LED number*/
    switch (au8_ledNumber)
    {
        /*In case of LED 1*/
        case LED1:

            /*Set LED1 pin to output*/
            gobj_led1Pin.setPinDirection(OUTPUT);

            /*Break from this case*/
            break;

        /*In case of LED 2*/
        case LED2:

            /*Set LED2 pin to output*/
            gobj_led2Pin.setPinDirection(OUTPUT);

            /*Break from this case*/
            break;

        /*in case of default*/
        default:

            /*Break from this case*/
            break;
    }
}

void hledClass_t::ledOn(void)
{
    /*Switching over LED number*/
    switch (au8_prv_ledNumber)
    {
        /*In case of LED 1*/
        case LED1:

            /*Set LED1 pin to high*/
            gobj_led1Pin.setPinValue(HIGH);

            /*Break from this case*/
            break;

        /*In case of LED 2*/
        case LED2:

            /*Set LED2 pin to high*/
            gobj_led2Pin.setPinValue(HIGH);

            /*Break from this case*/
            break;

        /*in case of default*/
        default:

            /*Break from this case*/
            break;
    }

    /*Return from this function*/
    return;
}
void hledClass_t::ledOff(void)
{
    /*Switching over LED number*/
    switch (au8_prv_ledNumber)
    {
        /*In case of LED 1*/
        case LED1:

            /*Set LED1 pin to LOW*/
            gobj_led1Pin.setPinValue(LOW);

            /*Break from this case*/
            break;

        /*In case of LED 2*/
        case LED2:

            /*Set LED2 pin to LOW*/
            gobj_led2Pin.setPinValue(LOW);

            /*Break from this case*/
            break;

        /*in case of default*/
        default:

            /*Break from this case*/
            break;
    }

    /*Return from this function*/
    return;
}

void hledClass_t::ledToggle(void)
{
    /*Switching over LED number*/
    switch (au8_prv_ledNumber)
    {
        /*In case of LED 1*/
        case LED1:

            /*Toogle LED1 pin*/
            gobj_led1Pin.togglePinValue();

            /*Break from this case*/
            break;

        /*In case of LED 2*/
        case LED2:

            /*Toogle LED2 pin*/
            gobj_led2Pin.togglePinValue();

            /*Break from this case*/
            break;

        /*in case of default*/
        default:

            /*Break from this case*/
            break;
    }

    /*Return from this function*/
    return;
}
