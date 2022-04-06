#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"

#include "util/delay.h"

mdioClass_t dioPin_PC2(PORTC, PIN2);

int main(void)
{
    dioPin_PC2.setPinDirection(OUTPUT);

    while(1)
    {
        dioPin_PC2.setPinValue(HIGH);    
        _delay_ms(1000);

        dioPin_PC2.setPinValue(LOW);    
        _delay_ms(1000);
    }    

    return 0;
}