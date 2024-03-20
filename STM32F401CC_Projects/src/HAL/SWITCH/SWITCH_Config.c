#include "MCAL/GPIO/GPIO.h"

#include "HAL/SWITCH/SWITCH.h"
#include "HAL/SWITCH/SWITCH_Config.h"

const SWITCH_strSWITCHConfig_t SWITCH_arrOfStrSWITCHs[NUM_OF_SWITCHEs] =
{     
    /*Just names of Switches added by the user*/
    /*[NAME_OF_SWITCHEs]= 
    {
        .Port=                 Select value from the following       ( GPIO_PORT_A , GPIO_PORT_B , GPIO_PORT_C )
        .Pin=                  Select value from the following       ( GPIO_PIN_0 , GPIO_PIN_1 , GPIO_PIN_2 , ... , GPIO_PIN_15 ) 
        .Connection=           Select value form the following       ( SW_PULL_UP, SW_PULL_DOWN )
    }*/

    [SWITCH_Number_0]= 
    {
        .Port          =    GPIO_PORT_A,                        
        .Pin           =    GPIO_PIN_7,                        
        .Connection    =    SW_PULL_UP                         
    }
    
 };