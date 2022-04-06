/**
 * @file    MDIO_program.cpp
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains main logic for DIO module
 * @version 1.0
 * @date    2022-04-06
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/**************************************************************************************/
/*                                     Includes                                       */
/**************************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

/**************************************************************************************/
/*                                Important macros                                    */
/**************************************************************************************/

#define PORTS_NUMBER    (3)

/**************************************************************************************/
/*                                Important variables                                 */
/**************************************************************************************/

/*Global arrays used to carry ports [B - C - D] registers*/
u8_t* gu8Arr_ddrArray[PORTS_NUMBER] = {MDIO_DDRB_ADDRESS, MDIO_DDRC_ADDRESS, MDIO_DDRD_ADDRESS};
u8_t* gu8Arr_portArray[PORTS_NUMBER] = {MDIO_PORTB_ADDRESS, MDIO_PORTC_ADDRESS, MDIO_PORTD_ADDRESS};
u8_t* gu8Arr_pinArray[PORTS_NUMBER] = {MDIO_PINB_ADDRESS, MDIO_PINC_ADDRESS, MDIO_PIND_ADDRESS};

/**************************************************************************************/
/*                                Functions' defintions                               */
/**************************************************************************************/

void mdioClass_t::setPinDirection(u8_t au8_pinDirection)
{
    /*Switching over pin direction values*/
    switch(au8_pinDirection)
    {
        /*In case of output*/
        case OUTPUT:

            /*Setting the DIO pin to output*/
            SET_BIT(*gu8Arr_ddrArray[au8_prv_dioPort], au8_prv_dioPin);

            /*Break from this case*/
            break;

        /*In case of input floating*/
        case INPUT_FLOAT:

            /*Setting the DIO pin to input floating*/
            CLEAR_BIT(*gu8Arr_ddrArray[au8_prv_dioPort], au8_prv_dioPin);

            /*Break from this case*/
            break;

        /*In case of input pullup*/
        case INPUT_PULLUP:

            /*Setting the DIO pin to input floating*/
            CLEAR_BIT(*gu8Arr_ddrArray[au8_prv_dioPort], au8_prv_dioPin);

            /*Enabling the pullup resistor*/
            SET_BIT(*gu8Arr_portArray[au8_prv_dioPort], au8_prv_dioPin);

            /*Break from this case*/
            break;

        /*In case of default*/
        default:

            /*Do nothing*/

            /*Break from this case*/
            break;
    }

    /*Return from this function*/
    return;
}

void mdioClass_t::setPinValue(u8_t au8_pinValue)
{
    /*Switching over pin direction values*/
    switch(au8_pinValue)
    {
        /*In case of LOW*/
        case LOW:

            /*Setting the DIO pin to LOW*/
            CLEAR_BIT(*gu8Arr_portArray[au8_prv_dioPort], au8_prv_dioPin);

            /*Break from this case*/
            break;

        /*In case of HIGH*/
        case HIGH:

            /*Setting the DIO pin to HIGH*/
            SET_BIT(*gu8Arr_portArray[au8_prv_dioPort], au8_prv_dioPin);

            /*Break from this case*/
            break;

        /*In case of default*/
        default:

            /*Do nothing*/

            /*Break from this case*/
            break;
    }

    /*Return from this function*/
    return;
}

void mdioClass_t::togglePinValue(void)
{
    /*Toggling the DIO pin value*/
    TOGGLE_BIT(*gu8Arr_portArray[au8_prv_dioPort], au8_prv_dioPin);

    /*Return from this function*/
    return;
}

void mdioClass_t::getPinValue(u8_t* pu8_pinValue)
{
    /*Checking the return value from pin*/
    if(GET_BIT(*gu8Arr_pinArray[au8_prv_dioPort], au8_prv_dioPin))
    {
        /*Set the return value to HIGH*/
        *pu8_pinValue = HIGH;
    }
    else
    {
        /*Set the return value to LOW*/
        *pu8_pinValue = LOW;
    }

    /*Return from this function*/
    return;
}
