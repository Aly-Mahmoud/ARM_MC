#ifndef SWITCH_H_
#define SWITCH_H_

    #include "00_MCAL/GPIO/GPIO.h"
    #include "01_HAL/SWITCH/SWITCH_Config.h"
	#include "Std_Types.h"


    /* -------------Struct for the LED Configuration-------------- */
        typedef struct
        {  
            void *Port;
            U32  Pin;
            U32  Connection;                                         
        }SWITCH_strSWITCHConfig_t;
    /*-------------------------------------------------------------*/    

    // typedef enum{
    //     SWITCH_enumOK,
    //     SWITCH_enumNOK,
    //     SWITCH_NullPointer,
    //     SWITCH_enumWrong_PortNo,
    //     SWITCH_enumWrong_PinNo,
    //     SWITCH_enumWrong_ConnectionType,
    // }SWITCH_enumSWITCHerrorState_t;

    /**
    * @brief Initializes all the SWITCHES configured in configure files
    * 
    * @return GPIO_Error_t as the led is a HAL that uses MCAL GPIO functions the error would be GPIO_Error_t with a terminology that can be understod from your LED_Driver
    * 
    * @note SWITCHs Must be configured in SWITCH_config.h and SWITCH_config.c files before using this function
    */

    GPIO_Error_t SWITCH_Init(void);

    /**
    * @brief Read the State of the Specified SWITCH (ON or OFF)
    * 
    * @param  Copy_Led Name of the LED as defined in LED_config.h
    * @param  Create a pointer and pass it as the 2nd paramter to have the value of the switch in it  
    * @return GPIO_Error_t as the led is a HAL that uses MCAL GPIO functions the error would be GPIO_Error_t with a terminology that can be understod from your LED_Driver       
    * 
    * @note SWITCHs must be initialized first by calling SWITCH_Init() function
    */

    GPIO_Error_t SWITCH_ReadState (SWITCHs_t SWITCH_Name , U8* SwitchState);

#endif