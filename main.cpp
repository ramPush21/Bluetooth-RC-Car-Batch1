#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

/**
 * @brief This function is responsible for initializing the robot system
 * 
 */
void system_init(void);

/**
 * @brief This function is used to get the system input command
 * 
 */
void system_getInput(void);

/**
 * @brief This function is used to process the system input command and update the system actions
 * 
 */
void system_processing_and_update(void);

int main(void)
{
    system_init();

    while(1)
    {
        system_getInput();

        system_processing_and_update();
    }

    return 0;
}