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


    /**
    * @brief Initializes the SysTick timer.
    *
    * This function configures the SysTick timer with the specified clock source
    * and enables the SysTick interrupt.
    */
    void SYSTICK_Init ( );

    /**
    * @brief Starts the SysTick timer with the specified execution pattern.
    *
    * This function starts the SysTick timer based on the provided execution pattern,
    * either OneShot or Periodic. If the execution pattern is OneShot, the SysTick timer
    * will trigger once; if it's Periodic, the timer will repeatedly trigger at the
    * specified intervals.
    *
    * @param ExecutionPattern The execution pattern of the SysTick timer (OneShot or Periodic).
    */
    void SYSTICK_Start ( SYSTICK_ExecutionPattern_t ExecutionPattern );

    /**
    * @brief Stops the SysTick timer.
    *
    * This function disables the SysTick timer, halting its operation.
    */
    void SYSTICK_Stop ( );

    /**
    * @brief Checks if one cycle of SysTick timer has finished.
    *
    * This function checks if one cycle of the SysTick timer has finished and updates
    * the COUNTFLAG parameter accordingly. If COUNTFLAG is NULL, it returns an error
    * status. If the cycle has finished, it resets the COUNTFLAG.
    *
    * @param COUNTFLAG Pointer to a variable where the count flag will be updated.
    * @return SYSTICK_OK if the check is successful, SYSTICK_NULLPOINTER if COUNTFLAG is NULL.
    */
    SYSTICK_Status SYSTICK_Did_OneCycle_Finish (U32 *COUNTFLAG);

    /**
    * @brief Sets the SysTick timer tick time in milliseconds.
    *
    * This function calculates the reload value for the SysTick timer based on the desired
    * tick time in milliseconds. It sets the SysTick load register with the calculated
    * reload value if it's within the valid range. Returns SYSTICK_OK if successful, 
    * otherwise returns SYSTICK_NOK.
    *
    * @param Copy_TickTime The desired tick time in milliseconds.
    * @return SYSTICK_OK if the tick time is set successfully, SYSTICK_NOK if the tick time
    *         is out of range.
    */
    SYSTICK_Status_t SYSTICK_SetTickTimeMS     (U16 Copy_TickTime);

    /**
    * @brief Gets the current value of the SysTick timer counter.
    *
    * This function retrieves the current value of the SysTick timer counter and updates
    * the provided pointer variable. If the pointer is NULL, it returns an error status.
    * Returns SYSTICK_OK if successful, SYSTICK_NULLPOINTER if the pointer is NULL.
    *
    * @param COUNTER_VALUE Pointer to a variable where the counter value will be stored.
    * @return SYSTICK_OK if successful, SYSTICK_NULLPOINTER if COUNTER_VALUE is NULL.
    */
    SYSTICK_Status_t GET_COUNTER_VALUE         (U32 *COUNTER_VALUE)

    /**
    * @brief Resets the SysTick timer.
    *
    * This function resets the SysTick timer by writing a value to the STK_VAL register,
    * effectively setting it to zero. This action restarts the timer from its initial value.
    */
    void SYSTICK_ResetTickTimer ( );

    /**
    * @brief Registers a callback function to be called by the SysTick interrupt handler.
    *
    * This function allows registering a callback function to be called by the SysTick
    * interrupt handler when the interrupt occurs. The provided callback function will
    * be executed in response to the SysTick interrupt.
    *
    * @param Copy_pfCallBackFunction Pointer to the callback function to be registered.
    */
    void Systick_vidRegisterCallBack ( systickcfg_t Copy_pfCallBackFunction ); 

    /**
    * @brief SysTick interrupt handler.
    *
    * This function is the interrupt handler for the SysTick timer. It checks if a callback
    * function is registered and calls it if available. If the execution pattern is set to
    * Periodic, it restarts the SysTick timer for periodic execution.
    */
    void SYSTICK_Handler (void);

#endif    

