#ifndef SYSTICK_H
#define SYSTICK_H

    #include "std_types.h"
    #include "Bit_Mask.h"

    /*
        The SysTick counter reload and current value are undefined at reset, the correct 
        initialization sequence for the SysTick counter is:
        1.Program reload value.
        2. Clear current value.
        3. Program Control and Status register.
    */

    #define AHB_FREQ                    42000000 

    #define COUNTER_CONTROL             BIT00_MASK

    #define Assert_SYSTICK_EXPREQ       BIT01_MASK
    #define NOTAssert_SYSTICK_EXPREQ    BITNULL_MASK

    #define TICKINT                     Assert_SYSTICK_EXPREQ   //UerDev options : Assert_SYSTICK_EXPREQ ,
                                                                //                 NOTAssert_SYSTICK_EXPREQ

    #define CLKSRC_AHB                  BIT02_MASK
    #define CLKSRC_AHB_8                BITNULL_MASK

    #define CLKSRC                      CLKSRC_AHB              //UerDev options : CLKSRC_AHB ,
                                                                //                 CLKSRC_AHB_8

    #define RELOAD_min_VALUE            0x00000001
    #define RELOAD_MAX_VALUE            0x00FFFFFF
    

    typedef enum 
    {
        SYSTICK_OK,
        SYSTICK_NULLPOINTER,
        SYSTICK_Wrong_ExecutionPattern_Option
        SYSTICK_NOK
    }SYSTICK_Status_t;

    typedef enum
    {
        OneShot,
        Periodic
    }SYSTICK_ExecutionPattern_t

    /*POINTER to function that takes no arg and has no return*/
    typedef void (*systickcfg_t)(void);



    void SYSTICK_Init ( );

    void SYSTICK_Start ( SYSTICK_ExecutionPattern_t ExecutionPattern );

    void SYSTICK_Stop ( );

    SYSTICK_Status SYSTICK_Did_OneCycle_Finish (U32 *COUNTFLAG);

    SYSTICK_Status_t SYSTICK_SetTickTimeMS     (U16 Copy_TickTime);

    SYSTICK_Status_t GET_COUNTER_VALUE         (U32 *COUNTER_VALUE)

    void SYSTICK_ResetTickTimer ( );

    void Systick_vidRegisterCallBack ( systickcfg_t Copy_pfCallBackFunction ); 

    void SYSTICK_Handler (void);

#endif    

