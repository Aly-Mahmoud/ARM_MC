#include "HAL/LED/LED.h"

U8 Prev_State = 0;

void Runnable_LED_Toggle_TASK(void)
{
    if ( Prev_State ) 
    {
        LED_SetStatus ( LED_TOGGLE , LED_SET_OFF );
        Prev_State= LED_SET_OFF;
    }
    else 
    {
        LED_SetStatus ( LED_TOGGLE , LED_SET_ON );
        Prev_State = LED_SET_ON;
    }
}