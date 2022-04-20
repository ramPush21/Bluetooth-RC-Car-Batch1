/**
 * @file    Bluetooth_RC_Car_private.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains private information for Bluetooth rc car module
 * @version 1.0
 * @date    2022-04-20
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __BLTH_RC_CAR_PRIAVTE_PRIVATE_H__
#define __BLTH_RC_CAR_PRIAVTE_PRIVATE_H__

/**************************************************************************************/
/*                                   Important macros                                 */
/**************************************************************************************/

/*Sleep modes*/
#define IDLE_MODE              (0)
#define ADC_NOISE_REDUCTION    (1)
#define POWER_DOWN_MODE        (2)
#define POWER_SAVE_MODE        (3)
#define STANDBY_MODE           (6)

/*WDT Reset time*/
#define RESET_16_3_MS          (0)
#define RESET_32_5_MS          (1)
#define RESET_65_0_MS          (2)
#define RESET_0_13_S           (3)
#define RESET_0_26_S           (4)
#define RESET_0_52_S           (5)
#define RESET_1_0_S            (6)
#define RESET_2_1_S            (7)

/**************************************************************************************/
/*                                  Control registers                                 */
/**************************************************************************************/

#define MCUCR                   (*(volatile u8_t*)(0x55))
#define WDTCR                   (*(volatile u8_t*)(0x41))

/**************************************************************************************/
/*                            Operations on control registers                         */
/**************************************************************************************/

/*Sleep mode operations*/
#define SELECT_SLEEP_MODE(mode)             MCUCR |= ((0x80) | (mode << 4))

#define MCU_GTS()                           asm("sleep")

/*WDT operations*/
#define WDT_ENABLE(RST_TIME)                WDTCR = 0x18;\
                                            WDTCR = (0x08) | RST_TIME

#define WDT_REFRESH()                       asm("wdr")

#define WDT_DISABLE()                       asm("wdr");    \
                                            WDTCR |= 0x18; \
                                            WDTCR = 0

#endif /*__BLTH_RC_CAR_PRIAVTE_PRIVATE_H__*/