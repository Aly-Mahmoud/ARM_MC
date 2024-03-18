#include "MCAL/SYSTICK/SYSTICK.h"

typedef struct
{
    volatile U32 STK_CTRL;
    volatile U32 STK_LOAD;
    volatile U32 STK_VAL;
    volatile U32 STK_CALIB;                  // NOT IMPLEMENTATION 4 IT
} SYSTICK_Registerts_t;

static systickcfg_t Systick_prvAppNotify;
static U8 G_ExecutionPattern  = Periodic;

#define SYSTICK_BASEADDRESS     0xE000E010
#define SYSTICK                 ((volatile SYSTICK_Registerts_t* const)SYSTICK_BASEADDRESS)

void SYSTICK_Init()
{
    SYSTICK->STK_CTRL |= (CLKSRC | TICKINT);
}

SYSTICK_Status_t SYSTICK_Start(SYSTICK_ExecutionPattern_t ExecutionPattern )
{
    SYSTICK_Status_t SYSTICK_Status = SYSTICK_NOK; 

    if ( ExecutionPattern == OneShot  )
    {
        SYSTICK->STK_CTRL |= COUNTER_CONTROL;
        G_ExecutionPattern = OneShot;
    }
    else if ( ExecutionPattern == Periodic )
    {
        SYSTICK->STK_CTRL |= COUNTER_CONTROL;
        G_ExecutionPattern = Periodic;
    }
    else 
    {
        SYSTICK_Status = SYSTICK_Wrong_ExecutionPattern_Option;        
    }
        return SYSTICK_Status;
}

void SYSTICK_Stop()
{
    SYSTICK->STK_CTRL &=~ COUNTER_CONTROL;
}

SYSTICK_Status_t SYSTICK_Did_OneCycle_Finish  (U32 *COUNTFLAG)
{
    SYSTICK_Status_t SYSTICK_Status = SYSTICK_NOK;

    if (COUNTFLAG == NULL)
    {
        SYSTICK_Status = SYSTICK_NULLPOINTER;
    } 
    else
    {
        SYSTICK_Status = SYSTICK_OK;

        SYSTICK->STK_CTRL &= BIT16_MASK;
    }
    return SYSTICK_Status;
}

SYSTICK_Status_t SYSTICK_SetTickTimeMS  ( U16 Copy_TickTime )
{
    SYSTICK_Status_t SYSTICK_Status = SYSTICK_NOK;

    U32 RELOAD_VALUE;

    RELOAD_VALUE = (AHB_FREQ * Copy_TickTime)/1000 - 1;

    if ( RELOAD_min_VALUE < RELOAD_VALUE && RELOAD_VALUE > RELOAD_MAX_VALUE )
    {
        SYSTICK_Status = SYSTICK_OK;
        SYSTICK->STK_LOAD = RELOAD_VALUE;
    }

    else 
    {
        SYSTICK_Status = SYSTICK_NOK;
    }
    return SYSTICK_Status;
}

SYSTICK_Status_t GET_COUNTER_VALUE ( U32 *COUNTER_VALUE )
{
    SYSTICK_Status_t SYSTICK_Status = SYSTICK_NOK;

    if(COUNTER_VALUE == NULL)
    {
        SYSTICK_Status = SYSTICK_NULLPOINTER;
    }
    else 
    {
        SYSTICK_Status = SYSTICK_OK;        
        *COUNTER_VALUE = SYSTICK->STK_VAL;
    }
    return SYSTICK_Status;
}

void SYSTICK_ResetTickTimer()
{
    SYSTICK->STK_VAL = BIT00_MASK;
}

void Systick_vidRegisterCallBack ( systickcfg_t Copy_pfCallBackFunction )
{
    Systick_prvAppNotify = Copy_pfCallBackFunction;
}

/*this function will be called by the hardware after the time countdown end*/ /*How?should it be static?*/
void SYSTICK_Handler (void)
{   

    /*If the static var holds a function address*/
    if (Systick_prvAppNotify)
    {   
        /*Call the function in the application layer*/
            Systick_prvAppNotify();
        /*------------------------------------------*/
    }

    if (G_ExecutionPattern == OneShot)
    {
        SYSTICK_Stop();
    }
}