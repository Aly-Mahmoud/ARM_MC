#ifndef SWITCH_H_
#define SWITCH_H_

    #include "SWITCH_Config.h"
	#include "Std_Types.h"

    typedef enum{
        SWITCH_enumOK,
        SWITCH_enumNOK,
        SWITCH_NullPointer,
        SWITCH_enumWrong_PortNo,
        SWITCH_enumWrong_PinNo,
        SWITCH_enumWrong_ConnectionType,
    }SWITCH_enumSWITCHerrorState_t;

    SWITCH_enumSWITCHerrorState_t SWITCH_enumInit(void);

    SWITCH_enumSWITCHerrorState_t SWITCH_enumReadState (U8 SWITCH_Name,U8* SwitchState);

#endif