#include "GPIO.h"

#include "LED.h"
#include "LED_Config.h"

const LED_strLEDConfig_t LED_arrOfStrLEDs[NUM_OF_LEDS] =
{     
    /*Just names of LEDs added by the user*/
    /*[NAME_OF_LED]= 
    {
        .Port=                 Select value from the following       ( GPIO_PORT_A , GPIO_PORT_B , GPIO_PORT_C )
        .Pin=                  Select value from the following       ( GPIO_PIN_0 , GPIO_PIN_1 , GPIO_PIN_2 , ... , GPIO_PIN_15 ) 
        .Connection=           Select value form enum Direction      ( LED_Connection_FW , LED_Connection_RV )
        .Init_Value=           Select value from enum Active State   ( LED_DIR_FW , LED_DIR_RV )
    }*/

    [LED_Number_0]= 
    {
        .Port          =    GPIO_PORT_A;                         
        .Pin           =    GPIO_PIN_0;                        
        .Direction     =    LED_DIR_FW;   
        .Init_Value    =    LED_SET_OFF                        
    }
    
 };