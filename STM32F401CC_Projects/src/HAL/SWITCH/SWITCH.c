#include "HAL/SWITCH/SWITCH.h"
#include "MCAL/GPIO/GPIO.h"

extern SWITCH_strSWITCHConfig_t SWITCH_arrOfStrSWITCHs[NUM_OF_SWITCHEs];
U8 Switch_PhysicalState[NUM_OF_SWITCHEs];

GPIO_Error_t SWITCH_Init(void)
{
    int iter;
	GPIO_Error_t LOC_Status = GPIO_NOK;
	GPIO_Pin_t Switch;    

    for(iter = 0; iter < NUM_OF_SWITCHEs ; iter++)
    {
		Switch.Pin_num    =  SWITCH_arrOfStrSWITCHs[iter].Pin;          //GPIO_PIN_7;
		Switch.Port       =  SWITCH_arrOfStrSWITCHs[iter].Port;         // GPIO_PORT_A;
        Switch.Pin_Mode   = SWITCH_arrOfStrSWITCHs[iter].Connection;

        LOC_Status = GPIO_Init(&Switch);

        LOC_Status = GPIO_OK;
    }
    return LOC_Status;
}

GPIO_Error_t SWITCH_ReadState (SWITCHs_t SWITCH_Name,U8* SwitchState)
{		
	    GPIO_Error_t LOC_Status = GPIO_NOK;

        if (SWITCH_Name >= NUM_OF_SWITCHEs || SwitchState == NULL) 
        {
            return LOC_Status; 
        }

        else
        {
            // Calculate switch state based on physical state and connection configuration
            *SwitchState = !( (Switch_PhysicalState[SWITCH_Name]) ^ ( (SWITCH_arrOfStrSWITCHs[SWITCH_Name].Connection) >> FOUR_BIT_OFFSET ) );
            LOC_Status = GPIO_OK;
        }
 
        return LOC_Status;
}

void Runnable_GET_SWITCH_STATE_TASK (void)
{
    U8 Index;
    U8 Current_SWITCH_State;
 
    static U8 Prev_States[NUM_OF_SWITCHEs] = {0};
    static U8 Counts[NUM_OF_SWITCHEs]      = {0};

    for ( Index=0 ; Index<NUM_OF_SWITCHEs; Index++ )
    {
        // Read current state of the switch
        GPIO_Get_PinValue( SWITCH_arrOfStrSWITCHs[Index].Port , SWITCH_arrOfStrSWITCHs[Index].Pin , &Current_SWITCH_State);

        // Update counts and handle stable state transitions
        if ( Current_SWITCH_State == Prev_States[Index] )
        {
            Counts[Index]++;
        }

        else
        {
            Counts[Index] = 0;
        }

        if ( Counts[Index] == SW_STABLE_COUNTER )
        {
            Switch_PhysicalState[Index] = Current_SWITCH_State;
            Counts[Index] = 0;
        }

        Prev_States[Index] = Current_SWITCH_State;
    }

}