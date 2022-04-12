/**
 * @file    LINTERRUPTS.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the vector table of AVR MCU
 * @version 1.0
 * @date    2021-04-12
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __LINTERRUPTS_H__
#define __LINTERRUPTS_H__

/*Status Register*/
#define SREG                (*(volatile u8_t*)(0x5F))

/*Enable and disable interrupts' macros*/
#define ENABLE_INTERRUPTS   (SREG |= (1 << 7))
#define DISABLE_INTERRUPTS  (SREG &= ~(1 << 7))

/*Vector table*/
#define INT0_VECT           (__vector_1)
#define INT1_VECT           (__vector_2)
#define TIMER2_COMP_VECT    (__vector_3)
#define TIMER2_OVF_VECT     (__vector_4)
#define TIMER1_CAPT_VECT    (__vector_5)
#define TIMER1_COMPA_VECT   (__vector_6)
#define TIMER1_COMPB_VECT   (__vector_7)
#define TIMER1_OVF_VECT     (__vector_8)
#define TIMER0_OVF_VECT     (__vector_9)
#define SPI_STC_VECT        (__vector_10)
#define USART_RXC_VECT      (__vector_11)
#define USART_UDRE_VECT     (__vector_12)
#define USART_TXC_VECT      (__vector_13)
#define ADC_VECT            (__vector_14)
#define EE_RDY_VECT         (__vector_15)
#define ANA_COMP_VECT       (__vector_16)
#define TWI_VECT            (__vector_17)
#define SPM_RDY_VECT        (__vector_18)

/*ISR format*/
#define ISR(VECTOR_NUM)   extern "C" void VECTOR_NUM(void) __attribute__((signal));\
                          void VECTOR_NUM(void)

#endif /*__LINTERRUPTS_H__*/