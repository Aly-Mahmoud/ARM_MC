#include "GPIO.h"

#include "LED.h"
#include "LED_Config.h"

const SWITCH_strSWITCHConfig_t SWITCH_arrOfStrSWITCHs[NUM_OF_SWITCHEs] =
{     
    /*Just names of Switches added by the user*/
    /*[NAME_OF_SWITCHEs]= 
    {
        .Port=                 Select value from the following       ( GPIO_PORT_A , GPIO_PORT_B , GPIO_PORT_C )
        .Pin=                  Select value from the following       ( GPIO_PIN_0 , GPIO_PIN_1 , GPIO_PIN_2 , ... , GPIO_PIN_15 ) 
        .Connection=           Select value form the following       ( GPIO_MODE_IN_FL , GPIO_MODE_IN_PU, GPIO_MODE_IN_PD )
    }*/

    [SWITCH_Number_0]= 
    {
        .Port          =    GPIO_PORT_B;                         
        .Pin           =    GPIO_PIN_0;                        
        .Connection    =    GPIO_MODE_IN_PD;                         
    }
    
 };