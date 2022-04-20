/**
 * @file    STTS_interface.h
 * @author  Ahmed Ashraf (info.rampush@gmail.com)
 * @brief   This file contains the interfacing information of TTS module 
 * @version 1.0
 * @date    2022-04-20
 * 
 * ©2021 RAM Push Copyright
 * 
 */

/*Header file guard*/
#ifndef __STTS_INTERFACE_H__
#define __STTS_INTERFACE_H__

/************************************************************************************************/
/*                                    Interfacing task structure                                */
/************************************************************************************************/

typedef struct
{	
	/*Task main code*/
	void (*pfunc)(void);

	/*Task periodicity*/
	u8_t au8_priodicity;
}task_t;

/************************************************************************************************/
/*                                       Interfacing classes                                    */
/************************************************************************************************/

class sttsClass_t
{
	/*Public members*/
	public:

		/**
		 * @brief Construct a new TTS class object with a specific time tick in milliseconds
		 * 
		 * @param au8_systemTickMs 
		 */
		sttsClass_t(u8_t au8_systemTickMs);

		/**
		 * @brief This function is used to add single task to the system
		 * 
		 * @param ast_newTask 
		 */
		void addTask(task_t ast_newTask);
		
		/**
		 * @brief This function is used to run TTS scheduler
		 * 
		 */
		void schedulerRun(void);
};

#endif /* __STTS_INTERFACE_H__ */