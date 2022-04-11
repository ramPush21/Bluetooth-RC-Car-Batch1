#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MPWM_interface.h"


mdioClass_t dioPin_PB1(PORTB, PIN1);
mdioClass_t dioPin_PB2(PORTB, PIN2);
mdioClass_t dioPin_PB3(PORTB, PIN3);

mpwmClass_t pwmChannel1(PWM_CHANNEL_1);
mpwmClass_t pwmChannel2(PWM_CHANNEL_2);
mpwmClass_t pwmChannel3(PWM_CHANNEL_3);

int main(void)
{
    dioPin_PB1.setPinDirection(OUTPUT);
    dioPin_PB2.setPinDirection(OUTPUT);
    dioPin_PB3.setPinDirection(OUTPUT);

    pwmChannel1.updatePWM(PWM_15KHZ, 128);
    pwmChannel2.updatePWM(PWM_15KHZ, 50);
    pwmChannel3.updatePWM(PWM_2KHZ, 155);

    while(1)
    {
    }

    return 0;
}