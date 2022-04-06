/**
 * @file    MDIO_interface.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains interfacing information for DIO module
 * @version 1.0
 * @date    2022-04-06
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __MDIO_INTERFACE_H__
#define __MDIO_INTERFACE_H__

/**************************************************************************************/
/*                                 Interfacing macros                                 */
/**************************************************************************************/

/*DIO ports*/
#define PORTB              (0)
#define PORTC              (1)
#define PORTD              (2)

/*DIO pins*/
#define PIN0               (0)
#define PIN1               (1)
#define PIN2               (2)
#define PIN3               (3)
#define PIN4               (4)
#define PIN5               (5)
#define PIN6               (6)
#define PIN7               (7)

/*DIO pin status*/
#define OUTPUT             (0)
#define INPUT_FLOAT        (1)
#define INPUT_PULLUP       (2)

/*DIO pin value*/
#define LOW                (0)
#define HIGH               (1)

/**************************************************************************************/
/*                                    DIO Class                                       */
/**************************************************************************************/

class mdioClass_t
{
    /*Public attributes*/
    public:

        /**
         * @brief DIO Class constuctor that will be called after creating an object from the class
         * 
         * @param au8_dioPort 
         * @param au8_dioPin 
         */
        mdioClass_t(u8_t au8_dioPort, u8_t au8_dioPin)
        {
            /*Assign the chosen port and pin to their private variables*/
            au8_prv_dioPort = au8_dioPort;
            au8_prv_dioPin = au8_dioPin;
        }

        /**
         * @brief This function is used to set the chosen DIO pin direction [OUTPUT - INPUT_FLOAT - INPUT_PULLUP]
         * 
         * @param au8_pinDirection 
         */
        void setPinDirection(u8_t au8_pinDirection);

        /**
         * @brief This function is responsible for setting the DIO pin value [HIGH - LOW]
         * 
         * @param au8_pinValue 
         */
        void setPinValue(u8_t au8_pinValue);

        /**
         * @brief This function is responsible for toggling the DIO pin value
         * 
         */
        void togglePinValue(void);

        /**
         * @brief This function is responsible for getting the DIO pin value [HIGH - LOW]
         * 
         * @param pu8_pinValue 
         */
        void getPinValue(u8_t* pu8_pinValue);

    /*Private attributes*/
    private:

        /*Private local variable used to carry the DIO port*/
        u8_t au8_prv_dioPort;

        /*Private local variable used to carry the DIO pin*/
        u8_t au8_prv_dioPin;
};

#endif /*__MDIO_INTERFACE_H__*/