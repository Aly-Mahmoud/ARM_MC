#include "SERVICE/SCHEDULER/SCHEDULER.h"
#include "MCAL/SYSTICK/SYSTICK.h"

extern Runnable_t Runnables [_Run_Num];

RunnableInfo_t RunnablesInfo [_Run_Num];

    /*Global Variable*/
        U32 PendingTicks = 0;
    /*--------------*/

    /*Static function prototype*/
        void TickCb(void);
    /*-------------------------*/


    /*IMPLEMENTATION*/


        void Schedular_Init (void)
        {
            /*SysTick Init*/
                SYSTICK_SetTickTimeMS       (TICKTIME);
                Systick_vidRegisterCallBack ( TickCb ); 
                SYSTICK_Init                (        );
            /*------------*/

            U32 idx=0;            
            
            for (idx=0; idx<_Run_Num ; idx++)
            {
                RunnablesInfo[idx].Runnable      = &Runnables[idx];             
                RunnablesInfo[idx].RemainingTime = Runnables[idx].delayms;
            }
        }

        SCHEDULER_Error_t Sched (void)
        {
            SCHEDULER_Error_t Local_Error_Status  = OK;

            U32 idx=0;

            for (idx = 0 ; idx < _Run_Num ; idx++)
            {
                if ( ( RunnablesInfo[idx].Runnable->CB != NULL ) && ( RunnablesInfo[idx].RemainingTime == 0 ) )
                {
                    RunnablesInfo[idx].Runnable->CB();
                    RunnablesInfo[idx].RemainingTime=RunnablesInfo[idx].Runnable->PeriodicityMs;
                }
                else if (RunnablesInfo[idx].Runnable->CB == NULL)
                {
                    Local_Error_Status = NullPointer;
                }
                    RunnablesInfo[idx].RemainingTime -= TICKTIME;

            }
            return Local_Error_Status;
        }

        void Schedular_Start (void)
        {
            SYSTICK_Start(Periodic);

            while (1)
            {
                if (PendingTicks)          /*if the Pending value is more than 1 it means that the CPU value is 200 or more */
                {
                    PendingTicks--;
                    Sched();                    
                }
            }
        }

        void TickCb (void)
        {
            PendingTicks++;
        }
        

    /*----------------*/