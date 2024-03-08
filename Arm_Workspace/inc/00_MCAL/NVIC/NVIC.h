#include "std_types.h"
#include "Bit_Mask.h"


typedef enum
{
    NO_SUBGROUP        =    0x04000000,
    TWO_SUBGROUP       =    0x04000400,
    FOUR_SUBGROUPS     =    0x04000500,
    EIGHT_SUBGROUPS    =    0x04000600,
    SIXTEEN_SUBGROUPS  =    0x04000700
}NUM_OF_SUBGROUPS_t;


typedef enum 
{
    NVIC_NOK,
    NVIC_Wrong_IRQ_Value,
    NVIC_Null_Ptr,
    NVIC_OK
}NVIC_Error_Status;


/*
 * use this function to Enable an IRQ
 * parameters:
 * NVIC_IQR -> the ID of the requested interrupt from the target IRQ_ID list
 * return:
 *     NVIC_NOK , NVIC_Wrong_IRQ_Value , NVIC_OK
 */
NVIC_Error_Status NVIC_CTRL_EnableIRQ       (IRQ_ID_t NVIC_IQR);

/*
 * use this function to Disable an IRQ
 * parameters:
 * NVIC_IQR -> the ID of the requested interrupt from the target IRQ_ID list
 * return:
 * NVIC_NOK , NVIC_Wrong_IRQ_Value , NVIC_OK
 */
NVIC_Error_Status NVIC_CTRL_DisableIRQ      (IRQ_ID_t NVIC_IQR);

/*
 * use this function to Set the pending bit corresponding to an IRQ
 * parameters:
 * NVIC_IQR -> the ID of the requested interrupt from the target IRQ_ID list
 * return:
 * NVIC_NOK , NVIC_Wrong_IRQ_Value , NVIC_OK
 */
NVIC_Error_Status NVIC_CTRL_SetIRQPending   (IRQ_ID_t NVIC_IQR);

/*
 * use this function to Clear the pending bit correspondin to an IRQ
 * parameters:
 * NVIC_IQR -> the ID of the requested interrupt from the target IRQ_ID list
 * return:
 * NVIC_NOK , NVIC_Wrong_IRQ_Value , NVIC_OK
 */
NVIC_Error_Status NVIC_CTRL_ClearIRQPending (IRQ_ID_t NVIC_IQR);

/*
 * use this function to read the status of Pending IRQ
 * parameters:
 * NVIC_IQR -> the ID of the requested interrupt from the target IRQ_ID list
 * Status -> address of the var to hold the status -> NVIC_STATUS_NOT_ACTIVE, NVIC_STATUS_ACTIVE
 * return:
 * NVIC_NOK , NVIC_Wrong_IRQ_Value , NVIC_Null_Ptr, NVIC_OK
 */
NVIC_Error_Status NVIC_GetPendingIRQ        (IRQn_t IRQn);

/*
 * use this function to read the status of an IRQ
 * parameters:
 * NVIC_IQR -> the ID of the requested interrupt from the target IRQ_ID list
 * Status -> address of the var to hold the status -> NVIC_STATUS_NOT_ACTIVE, NVIC_STATUS_ACTIVE
 * return:
 * NVIC_NOK , NVIC_Wrong_IRQ_Value , NVIC_Null_Ptr, NVIC_OK
 */
NVIC_Error_Status NVIC_Get_ActiveStatus     (IRQ_ID_t NVIC_IQR, U32 *Status);

/*
 * use this function to Generate a software interrupt corresponding to an IRQ
 * parameters:
 * NVIC_IQR -> the ID of the requested interrupt from the target IRQ_ID list
 * return:
 * NVIC_NOK , NVIC_Wrong_IRQ_Value , NVIC_OK
 */
NVIC_Error_Status NVIC_CTRL_GenerateSWI     (IRQ_ID_t NVIC_IQR);

/*
 * use this function to Set the priority bits to specify the subgroup and group priority levels
 * parameters:
 * SubGroupBit ->     NO_SUBGROUP,TWO_SUBGROUP,FOUR_SUBGROUPS,EIGHT_SUBGROUPS,SIXTEEN_SUBGROUPS
 * return:
 * Status_NOK, Status_OK, Status_Null_Pointer, Status_Invalid_Input
 */
NVIC_Error_Status NVIC_CFG_SetSubGroup      (NUM_OF_SUBGROUPS_t NUM_OF_SUBGROUPS);


/*
 * use this function to Set the priority levels corresponding to an IRQ
 * parameters:
 * NVIC_IQR -> the ID of the requested interrupt from the target IRQ_ID list
 * PreemptPri -> value of the Preemption priority level
 * SubGroupPri -> value of the Subgroup priority level
 * SubGroupBits -> the number of configured subgroup bits
 * return:
 * Status_NOK, Status_OK, Status_Null_Pointer, Status_Invalid_Input
 */
NVIC_Error_Status NVIC_CFG_SetPriority      (IRQ_ID_t NVIC_IQR, U8 PreemptPri, U8 SubGroupPri);


// /*
//  * use this function to read the priority of an IRQ
//  * parameters:
//  * NVIC_IQR -> the ID of the requested interrupt from the target IRQ_ID list
//  * Priority -> address of the var to hold the Priority
//  * return:
//  * Status_NOK, Status_OK, Status_Null_Pointer, Status_Invalid_Input
//  */
// NVIC_Error_Status NVIC_Get_Priority(IRQ_ID_t NVIC_IQR, u32_t *Priority);


// NVIC_Error_Status NVIC_SystemReset (void);


