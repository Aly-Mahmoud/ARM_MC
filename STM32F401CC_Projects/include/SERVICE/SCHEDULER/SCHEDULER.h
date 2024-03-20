#ifndef _SCHEDULER_
#define _SCHEDULER_

    /*Includes*/
        #include "Std_Types.h"
        #include "SERVICE/SCHEDULER/Runnable_List.h"
    /*--------*/

    #define TICKTIME 10

    /*Types*/
        typedef enum 
        {
            NOK,
            NullPointer,
            Wrong_Parameter,
            OK
        }SCHEDULER_Error_t;

        typedef void (*RunnableCB_t)(void);

        typedef struct 
        {
            char *name;
            U32 PeriodicityMs;
            RunnableCB_t CB;
            U32 delayms;
        }Runnable_t;

        typedef struct 
        {
            Runnable_t *Runnable;
            U32        RemainingTime;
        }RunnableInfo_t;
    /*-----*/

    /*APIs*/


        /**
         * @brief Initializes the scheduler and associated components.
         * 
         * This function initializes the SysTick timer with a tick time of TICKTIME
         * and registers a callback function `TickCb` to be called on each SysTick interrupt.
         * 
         * Additionally, it initializes the runnables by assigning their addresses to `RunnablesInfo` array
         * and sets the remaining time for each runnable to its delay in milliseconds.
         * 
         * Note: Ensure that `Runnables` array is populated with the appropriate runnable structures before calling this function.
         */
        void Schedular_Init (void);


        /**
         * @brief Starts the scheduler.
         * 
         * This function initializes the system tick timer and enters an infinite loop where it continuously checks for pending ticks.
         * When a pending tick is detected, it decrements the count and calls the scheduler function.
         * 
         * The function never returns.
         */
        void Schedular_Start (void);

        /**
         * @brief Scheduler function to execute registered runnables.
         * 
         * This function iterates over the list of runnables and executes them if:
         * 1. The runnable callback function is not NULL.
         * 2. The remaining time for the runnable is 0, indicating it needs to be executed.
         * 
         * If a NULL callback function is encountered during iteration, the function returns with an error status.
         * 
         * @return SCHEDULER_Error_t Returns the status of the scheduler operation:
         *         - OK: Operation was successful.
         *         - NullPointer: Encountered a NULL callback function during iteration.
         */

        SCHEDULER_Error_t Sched (void);
        
    /*----*/


#endif