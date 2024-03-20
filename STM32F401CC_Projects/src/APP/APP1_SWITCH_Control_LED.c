#include "HAL/LED/LED.h"
#include "HAL/SWITCH/SWITCH.h"

void Runnable_SWITCH_Control_LED (void)
{
    U8 LOC_SWITCH_STATE = SWITCH_NOT_PRESSED;

    SWITCH_ReadState ( SWITCH_Number_0 , &LOC_SWITCH_STATE );

    if ( LOC_SWITCH_STATE == SWITCH_PRESSED )
    {
        LED_SetStatus ( LED_SWITCH_1 , LED_SET_ON );
    }
    else 
    {
        LED_SetStatus ( LED_SWITCH_1 , LED_SET_OFF );
    }
}