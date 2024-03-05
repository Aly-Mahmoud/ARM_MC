#include "SWITCH.h"
#include "GPIO.h"

extern SWITCH_strLEDConfig_t SWITCH_arrOfStrSWITCH[NUM_OF_SWITCHEs];

GPIO_Error_t SWITCH_Init(void)
{
	GPIO_Error_t LOC_Status = GPIO_NOK;
	GPIO_Pin_t Switch;    

    for(int iter = 0; iter < NUM_OF_SWITCHEs; iter++)
    {
		Switch.pin    = SWITCH_arrOfStrSWITCH[idx].pin;
		Switch.Port   = SWITCH_arrOfStrSWITCH[idx].Port;
        Switch.Mode   = SWITCH_arrOfStrSWITCH[idx].Connection;
        LOC_Status = GPIO_Init(&LED_arrOfStrLEDs);
    }
    return LOC_Status;
}

SWITCH_enumSWITCHerrorState_t SWITCH_enumReadState (U8 SWITCH_Name,U8* SwitchState)
{		
	    GPIO_Error_t LOC_Status = GPIO_NOK;

		GPIO_Get_PinValue(SWITCH_arrOfStrSWITCH[SWITCH_Name].Port,SWITCH_arrOfStrSWITCH[SWITCH_Name].Pin, &SwitchState);
 
        return LOC_Status;
}