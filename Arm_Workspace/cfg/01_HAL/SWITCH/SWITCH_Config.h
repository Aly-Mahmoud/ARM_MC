#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

    #include "PORT_Config.h"

    #define  NUM_OF_SWITCHES  1

    /*enum for Active State*/
     typedef enum{
        SWITCH_PullUp,
        SWITCH_PullDown
     }SWITCH_enumConnectionType_t;
    /*---------------------*/

    /*enum for switch state*/
      typedef enum{
        SWITCH_High,
        SWITCH_Low
      }SWITCH_enumSWITCHState_t;
    /*---------------------*/


    /* -------------Struct for the SWITCH Configuration-------------- */
        typedef struct
        {  
            Port_enumPortNumber_t          SWITCH_enumPortNumber;            //Used in Config function
            Port_enumPinNumber_t           SWITCH_enumPinNumber;             //Used in Config function 
            PORT_enumPinDir_t              SWITCH_enumDir;                   //Used in Config function
            SWITCH_enumConnectionType_t    SWITCH_enumConnectionType;        //Used in Get function
            SWITCH_enumSWITCHState_t       SWITCH_enumSWITCHState;           //Used in Get function (NOT)
        }SWITCH_strLEDConfig_t;
    /*-------------------------------------------------------------*/

    /*------------------------ SWITCHes List-------------------------- */
        #define SWITCH_1 0
    /*-------------------------------------------------------------*/

  #endif  