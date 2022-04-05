#include "avr/io.h"

int main(void)
{
    DDRC = 0b00001100;

    PORTC = 0b00001100;

    return 0;
}