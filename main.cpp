#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LINTERRUPTS.h"
#include "MDIO_interface.h"
#include "MUART_interface.h"

#include "util/delay.h"

mdioClass_t dioPin_PD0(PORTD, PIN0);
mdioClass_t dioPin_PD1(PORTD, PIN1);

muartClass_t uartData(BAUD_RATE_9600BPS, NO_INTERRUPTS_USED);

int main(void)
{
    u8_t x = 0;

    ENABLE_INTERRUPTS;

    dioPin_PD0.setPinDirection(INPUT_FLOAT);
    dioPin_PD1.setPinDirection(OUTPUT);

    while(1)
    {   
        uartData.recvByte(&x);

        if(x)
        {
            uartData.sendStream((u8_t*)"Ahmed\r\n", 7);

            x = 0;
        }
        else
        {
            /*Do nothing*/
        }
    }

    return 0;
}