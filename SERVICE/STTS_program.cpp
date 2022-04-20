/**
 * @file 	STTS_program.cpp
 * @author 	Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the logical implementation for TTS module
 * @version 1.0
 * @date 	2022-04-20
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/************************************************************************************************/
/*                                             Includes                                         */
/************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LINTERRUPTS.h"
#include "STTS_private.h"
#include "STTS_interface.h"
#include "STTS_cfg.h"

/************************************************************************************************/
/*                                          Important variables                                 */
/************************************************************************************************/

/*Global array used as a tasks pool*/
static task_t gst_TaskArr[NUMBER_OF_TASKS];

/*Global variable used to count tasks*/
static u8_t gu8_tasksCounter = 0;

/*Global variable used to count ticks*/
static u32_t gu32_tickCounter = 0;

/************************************************************************************************/
/*                                          Important macros                                    */
/************************************************************************************************/

#define TASK_TIME                 		 (0)
#define ENABLE_CTC_MODE          		 (0x08)
#define TICK_TIME_VALUE_CONVERT_FACTOR   (4)
#define TIMER_PRESCALER_1024             (0x07)

/************************************************************************************************/
/*                                        Functions' definitions                                */
/************************************************************************************************/

static void stts_scheduler(void)
{
	/*Local variable used in looping operations*/
	u8_t au8_loopingVar = 0;

	/*Checking the number of tasks*/
	if(gu8_tasksCounter == NUMBER_OF_TASKS)
	{
		/*Looping over tasks*/
		for(au8_loopingVar = 0; au8_loopingVar < NUMBER_OF_TASKS; au8_loopingVar++)
		{
			/*Checking that task time has come or not*/
			if( (gu32_tickCounter % gst_TaskArr[au8_loopingVar].au8_priodicity) == TASK_TIME)
			{
				/*Execute task*/
				gst_TaskArr[au8_loopingVar].pfunc();
			}
			else
			{
				/*Do nothing*/
			}
		}
	}
	else
	{
		/*Do nothing*/
	}

	/*Return from this function*/
	return;
}

sttsClass_t::sttsClass_t(u8_t au8_systemTickMs)
{
	/*Enable CTC mode in timer2*/
	STTS_TCCR2 = ENABLE_CTC_MODE;

	/*Set the tick time value up to 63ms @ 4 MHz and 1024 prescaler (4 = ((1 ms * 1000)us / 256us))*/
	STTS_OCR2 = au8_systemTickMs * TICK_TIME_VALUE_CONVERT_FACTOR;

	/*Return from this function*/
	return;
}

void sttsClass_t::addTask(task_t ast_newTask)
{
	/*Add new task to the system*/
	gst_TaskArr[gu8_tasksCounter] = ast_newTask;

	/*Increment the tasks counter*/
	gu8_tasksCounter++;

	/*Return from this function*/
	return;
}

void sttsClass_t::schedulerRun(void)
{
	/*Enable global interrupts*/
	ENABLE_INTERRUPTS;

	/*Enable timer2 CTC mode interrupt*/
	SET_BIT(STTS_TIMSK, TIMSK_OCIE_BIT);

	/*Run timer2 with 256us timer tick*/
	STTS_TCCR2 |= TIMER_PRESCALER_1024;

	/*Return from this function*/
	return;
}

/************************************************************************************************/
/*                                         System tick ISR                                      */
/************************************************************************************************/

ISR(TIMER2_COMP_VECT)
{
	/*Increment tick counter*/
	gu32_tickCounter++;

	/*Execute system scheduler*/
	stts_scheduler();
}