#include "NVIC.h"

#define NVIC_REG_THRESHOLD 32
#define PRIGROUP_POSI_BITS  8
#define IPQs_InOneReg       4
#define SOC_Wirte_Passcode  0x05FA0000

U32 Subgroupbits = 0;

typedef struct
{
    volatile U32 ISER[8];
    volatile U32 Reserved1[24];
    volatile U32 ICER[8];
    volatile U32 Reserved2[24];
    volatile U32 ISPR[8];
    volatile U32 Reserved3[24];
    volatile U32 ICPR[8];
    volatile U32 Reserved4[24];
    volatile U32 IABR[8];
    volatile U32 Reserved5[56];
    volatile U32 IPR[60];
    volatile U32 Reserved6[580];
    volatile U32 STIR;
} NVIC_Registerts_t;

#define NVIC_BASE_ADDRESS    0xE000E100
#define NVIC                ((volatile NVIC_Registerts_t * const)NVIC_BASE_ADDRESS)

typedef struct
{
    volatile U32 ACTLR;
    volatile U32 Reserved1[829];
    volatile U32 CPUID;
    volatile U32 ICSR;
    volatile U32 VTOR;
    volatile U32 AIRCR;
    volatile U32 SCR;
    volatile U32 CCR;
    volatile U32 SHPR[3];
    volatile U32 SHCSR;
    volatile U32 CFSR;
    volatile U32 HFSR;
    volatile U32 Reserved2;
    volatile U32 MMAR;
    volatile U32 BFAR;
    volatile U32 AFSR;

} SCB_Registers_t;

#define SCB_BASE_ADDRESS     0xE000E008
#define SCB                 ((volatile SCB_Registers_t * const)SCB_BASE_ADDRESS)


NVIC_Error_Status NVIC_CTRL_EnableIRQ       (IRQ_ID_t NVIC_IQR)
{
    NVIC_Error_Status Local_Error_Status = NVIC_NOK;

    if ( NVIC_IQR & BIT14_MASK )
    {
        /*Setting Local_Error_Status*/
            Local_Error_Status = NVIC_OK; 
        /*-------------------------*/

        /*Clear the verification bit*/
            NVIC_IQR &= ~(BIT00_MASK << BIT_INDEX);
        /*--------------------------*/

        /*Get the REG_INDEX*/
            U32 REG_INDEX = NVIC_IQR / NVIC_REG_THRESHOLD;
        /*----------------*/

        /*Get the BIT_INDEX*/
            U32 BIT_INDEX = NVIC_IQR % NVIC_REG_THRESHOLD;
        /*----------------*/|

        /*set the suitablee bit in the suitable register*/
            NVIC->ISER[REG_INDEX] |= (BIT00_MASK <<  BIT_INDEX);
        /*----------------------------------------------*/
    }

    else 
    {
        Local_Error_Status = NVIC_Wrong_IRQ_Value;
    }

    return Local_Error_Status;
}

NVIC_Error_Status NVIC_CTRL_DisableIRQ      (IRQ_ID_t NVIC_IQR)
{
    NVIC_Error_Status Local_Error_Status = NVIC_NOK;

    if ( NVIC_IQR & BIT14_MASK )
    {
        /*Setting Local_Error_Status*/
            Local_Error_Status = NVIC_OK; 
        /*-------------------------*/

        /*Clear the verification bit*/
            NVIC_IQR &= ~(BIT00_MASK << BIT_INDEX);
        /*--------------------------*/

        /*Get the REG_INDEX*/
            U32 REG_INDEX = NVIC_IQR / NVIC_REG_THRESHOLD;
        /*----------------*/

        /*Get the BIT_INDEX*/
            U32 BIT_INDEX = NVIC_IQR % NVIC_REG_THRESHOLD;
        /*----------------*/

        /*Clear the suitable bit in the suitable register*/
            NVIC->ICER[REG_INDEX] = (BIT00_MASK << BIT_INDEX);
        /*-----------------------------------------------*/
    }

    else 
    {
        Local_Error_Status = NVIC_Wrong_IRQ_Value;
    }

    return Local_Error_Status;        
}

NVIC_Error_Status NVIC_CTRL_SetIRQPending   (IRQ_ID_t NVIC_IQR)
{
    NVIC_Error_Status Local_Error_Status = NVIC_NOK;

    if ( NVIC_IQR & BIT14_MASK )
    {
        /*Setting Local_Error_Status*/
            Local_Error_Status = NVIC_OK; 
        /*-------------------------*/

        /*Clear the verification bit*/
            NVIC_IQR &= ~(BIT00_MASK << BIT_INDEX);
        /*--------------------------*/

        /*Get the REG_INDEX*/
            U32 REG_INDEX = NVIC_IQR / NVIC_REG_THRESHOLD;
        /*----------------*/

        /*Get the BIT_INDEX*/
            U32 BIT_INDEX = NVIC_IQR % NVIC_REG_THRESHOLD;
        /*----------------*/

        /*Write on the sutable bit in the suitable register*/
            NVIC->ISPR[REG_INDEX] |= (BIT00_MASK << BIT_INDEX);
        /*-------------------------------------------------*/
    }

    else 
    {
        Local_Error_Status = NVIC_Wrong_IRQ_Value;
    }

    return Local_Error_Status;        
}

NVIC_Error_Status NVIC_CTRL_ClearIRQPending (IRQ_ID_t NVIC_IQR)
{
    NVIC_Error_Status Local_Error_Status = NVIC_NOK;

    if ( NVIC_IQR & BIT14_MASK )
    {
        /*Setting Local_Error_Status*/
            Local_Error_Status = NVIC_OK; 
        /*-------------------------*/

        /*Clear the verification bit*/
            NVIC_IQR &= ~(BIT00_MASK << BIT_INDEX);
        /*--------------------------*/

        /*Get the REG_INDEX*/
            U32 REG_INDEX = NVIC_IQR / NVIC_REG_THRESHOLD;
        /*----------------*/

        /*Get the BIT_INDEX*/
            U32 BIT_INDEX = NVIC_IQR % NVIC_REG_THRESHOLD;
        /*----------------*/

        /*Clear the suitable bit in the suitable register*/       
            NVIC->ICPR[REG_INDEX] = (BIT00_MASK << BIT_INDEX);
        /*-----------------------------------------------*/
    }

    else 
    {
        Local_Error_Status = NVIC_Wrong_IRQ_Value;
    }

    return Local_Error_Status;        
}

NVIC_Error_Status NVIC_GetPendingIRQ        (IRQn_t IRQn)
{
    NVIC_Error_Status Local_Error_Status = NVIC_NOK;
        
    if ( NVIC_IQR & BIT14_MASK )
    {
        /*Setting Local_Error_Status*/
            Local_Error_Status = NVIC_OK; 
        /*-------------------------*/

        /*Clear the verification bit*/
            NVIC_IQR &= ~(BIT00_MASK << BIT_INDEX);
        /*--------------------------*/

        /*Get the REG_INDEX*/
            U32 REG_INDEX = NVIC_IQR / NVIC_REG_THRESHOLD;
        /*----------------*/

        /*Get the BIT_INDEX*/
            U32 BIT_INDEX = NVIC_IQR % NVIC_REG_THRESHOLD;
        /*----------------*/

        /*  Get the suitable bit in the suitable register  */
            Status = (NVIC->ICPR[REG_INDEX] & (BIT00_MASK << BIT_INDEX))>>BIT_INDEX;
        /*-------------------------------------------------*/
    }

    else 
    {
        Local_Error_Status = NVIC_Wrong_IRQ_Value;
    }

    return Local_Error_Status;      
}

NVIC_Error_Status NVIC_Get_ActiveStatus     (IRQ_ID_t NVIC_IQR, U32 *Status)
{
    NVIC_Error_Status Local_Error_Status = NVIC_NOK;
        
    if ( NVIC_IQR & BIT14_MASK )
    {
        /*Setting Local_Error_Status*/
            Local_Error_Status = NVIC_OK; 
        /*-------------------------*/

        /*Clear the verification bit*/
            NVIC_IQR &= ~(BIT00_MASK << BIT_INDEX);
        /*--------------------------*/

        /*Get the REG_INDEX*/
            U32 REG_INDEX = NVIC_IQR / NVIC_REG_THRESHOLD;
        /*----------------*/

        /*Get the BIT_INDEX*/
            U32 BIT_INDEX = NVIC_IQR % NVIC_REG_THRESHOLD;
        /*----------------*/

        /*  Get the suitable bit in the suitable register  */
            Status = (NVIC->IABR[REG_INDEX] & (BIT00_MASK << BIT_INDEX))>>BIT_INDEX;
        /*-------------------------------------------------*/
    }

    else 
    {
        Local_Error_Status = NVIC_Wrong_IRQ_Value;
    }

    return Local_Error_Status;        
}

NVIC_Error_Status NVIC_CTRL_GenerateSWI     (IRQ_ID_t NVIC_IQR)
{
    NVIC_Error_Status Local_Error_Status = NVIC_NOK;
        
    if ( NVIC_IQR & BIT14_MASK )
    {
        /*Setting Local_Error_Status*/
            Local_Error_Status = NVIC_OK; 
        /*-------------------------*/

        /*Clear the verification bit*/
            NVIC_IQR &= ~(BIT00_MASK << BIT_INDEX);
        /*--------------------------*/

        /*Send the interrupt requist to be generated*/
            NVIC->STIR = NVIC_IQR;
        /*------------------------------------------*/
    }   

    else 
    {
        Local_Error_Status = NVIC_Wrong_IRQ_Value;
    }

    return Local_Error_Status;  
}

NVIC_Error_Status NVIC_CFG_SetSubGroup      (NUM_OF_SUBGROUPS_t NUM_OF_SUBGROUPS)
{
    NVIC_Error_Status Local_Error_Status = NVIC_NOK;

    if(NUM_OF_SUBGROUPS & BIT26_MASK)
    {
        /*Clear the verification bit*/
            NUM_OF_SUBGROUPS &= ~(BIT26_MASK);
        /*--------------------------*/

        /*Save the register value in local var*/
           U32 LOC_AIRCR = SCB->AIRCR 
        /*------------------------------------*/

        /*clear the PRIGROUP bits*/
            LOC_AIRCR &= ~(FIRST_THREE_BITS_MASK<<PRIGROUP_POSI_BITS)
        /*-----------------------*/

        /*Write the subgroup number to the local_var with the passcode*/
            LOC_AIRCR |= ( NUM_OF_SUBGROUPS ) | SOC_Wirte_Passcode
        /*-----------------------------------------*/

        /*write the value of subgroup in the suitable reg*/
            SCB->AIRCR = LOC_AIRCR;
        /*------------------------------------------------*/

        Subgroupbits = NUM_OF_SUBGROUPS;
    }
    else
    {
        Local_Error_Status = NVIC_Wrong_IRQ_Value;        
    }
}

NVIC_Error_Status NVIC_CFG_SetPriority      (IRQ_ID_t NVIC_IQR, U8 PreemptPri, U8 SubGroupPri)
{
    NVIC_Error_Status Local_Error_Status = NVIC_NOK;

    if ( NVIC_IQR & BIT14_MASK )
    {

        /*Setting Local_Error_Status*/
            Local_Error_Status = NVIC_OK; 
        /*-------------------------*/

        /*Clear the verification bit*/
            NVIC_IQR &= ~(BIT00_MASK << BIT_INDEX);
        /*--------------------------*/

        /*Cal Pri_Total_Value*/
            Pri_Total_Value =  (PreemptPri<<Subgroupbits)|SubGroupPri
        /*-------------------*/

        /*Get the REG_INDEX*/
            U32 REG_INDEX = NVIC_IQR / IPQs_InOneReg;
        /*----------------*/

        /*Get the IPQ Field*/
            U32 IPQ_Field = NVIC_IQR % IPQs_InOneReg;
        /*-----------------*/

        /*Write on the suitable place*/
            NVIC->IPR[REG_INDEX] = Pri_Total_Value << (( IPQ_Field * PRIGROUP_POSI_BITS )+IMPLEMENTED_PRIORITY_BITS)
        /*---------------------------*/

    }
    else
    {
        Local_Error_Status = NVIC_Wrong_IRQ_Value;        
    }
}

NVIC_Error_Status NVIC_Get_Priority(IRQ_ID_t NVIC_IQR, u32_t *Priority)
{
    
}