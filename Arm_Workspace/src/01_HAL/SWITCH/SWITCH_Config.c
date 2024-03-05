#include "SWITCH_Config.h"

SWITCH_strLEDConfig_t SWITCH_arrOfStrSWITCH[NUM_OF_SWITCHES] =
{     
    /*Just names of LEDs added by the user*/
    /*[NAME_OF_SWITCH]= 
    {
        .SWITCH_enumPortNumber=      Select value from enum Port Number 
        .SWITCH_enumPinNumber=       Select value from enum Pin Number 
        .SWITCH_enumDir=             Select value form enum Direction
        .SWITCH_enumConnectionType=  Select value from enum Active State
    }*/
    
    [SWITCH_1] = 
    {
        .SWITCH_enumPortNumber=        PortC,              /* Select value from enum Port Number */
        .SWITCH_enumPinNumber=         Pin0,               /* Select value from enum Pin Number */
        .SWITCH_enumDir=               Port_PinDir_Input,  /* Select value from enum Dir*/
        .SWITCH_enumConnectionType=    SWITCH_PullDown     /* Select value from enum Connection Type*/
    }
    
 };