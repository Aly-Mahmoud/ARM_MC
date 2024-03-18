#include "HAL/SWITCH/SWITCH.h"
#include "MCAL/GPIO/GPIO.h"

extern SWITCH_strSWITCHConfig_t SWITCH_arrOfStrSWITCHs[NUM_OF_SWITCHEs];

GPIO_Error_t SWITCH_Init(void)
{
    int iter;
	GPIO_Error_t LOC_Status = GPIO_NOK;
	GPIO_Pin_t Switch;    

    for(iter = 0; iter < NUM_OF_SWITCHEs ; iter++)
    {
		Switch.Pin_num    = GPIO_PIN_7;
		Switch.Port       = GPIO_PORT_A;
        Switch.Pin_Mode   = SWITCH_arrOfStrSWITCHs[iter].Connection;

        LOC_Status = GPIO_Init(&Switch);

        LOC_Status = GPIO_OK;
    }
    return LOC_Status;
}

GPIO_Error_t SWITCH_ReadState (U8 SWITCH_Name,U8* SwitchState)
{		
	    GPIO_Error_t LOC_Status = GPIO_NOK;
        U8 Pinstate;

        if (SWITCH_Name >= NUM_OF_SWITCHEs) 
        {
            return LOC_Status; 
        }

        else
        {
            LOC_Status = GPIO_Get_PinValue(SWITCH_arrOfStrSWITCHs[SWITCH_Name].Port,SWITCH_arrOfStrSWITCHs[SWITCH_Name].Pin, &Pinstate);

            *SwitchState=Pinstate;
        }
 
        return LOC_Status;
}