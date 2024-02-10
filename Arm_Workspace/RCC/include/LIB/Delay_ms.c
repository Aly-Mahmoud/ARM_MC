#include "Delay_ms.h"

void delay_ms(int volatile ms)
{
    while (ms--)
    {
    asm volatile (
    "    ldi  r18, 11	\n"
    "    ldi  r19, 99	\n"
    "1:  dec  r19	\n"
    "    brne 1b	\n"
    "    dec  r18	\n"
    "    brne 1b	\n"
    );
    }

}