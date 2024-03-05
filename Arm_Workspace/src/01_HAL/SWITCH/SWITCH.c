#include "SWITCH.h"
#include "SWITCH_Config.h"
#include "PORT_Config.h"
#include "PORT.h"
#include "Std_Types.h"
#include "DIO.h"
#include "DIO_Config.h"

extern SWITCH_strLEDConfig_t SWITCH_arrOfStrSWITCH[NUM_OF_SWITCHES];

SWITCH_enumSWITCHerrorState_t SWITCH_enumInit(void)
{
    extern PORT_strConfig_t PORT_arrofstr_HALComp[NUM_OF_SWITCHES];

    for(int iter = 0; iter < NUM_OF_SWITCHES; iter++)
    {
        PORT_arrofstr_HALComp[iter].Port_enumPortNumber= SWITCH_arrOfStrSWITCH[iter].SWITCH_enumPortNumber;
        PORT_arrofstr_HALComp[iter].Port_enumPinNumber=  SWITCH_arrOfStrSWITCH[iter].SWITCH_enumPinNumber; 
        PORT_arrofstr_HALComp[iter].PORT_enumPinDir=     SWITCH_arrOfStrSWITCH[iter].SWITCH_enumDir;           
    }
	 PORT_PinConfig(&PORT_arrofstr_HALComp, NUM_OF_SWITCHES);
}

SWITCH_enumSWITCHerrorState_t SWITCH_enumReadState (U8 SWITCH_Name,U8* SwitchState)
{		
		DIO_enumReadState(SWITCH_arrOfStrSWITCH[SWITCH_Name].SWITCH_enumPortNumber,SWITCH_arrOfStrSWITCH[SWITCH_Name].SWITCH_enumPinNumber,SwitchState);
}