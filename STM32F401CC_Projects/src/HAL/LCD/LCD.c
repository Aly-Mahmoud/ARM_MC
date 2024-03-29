#include "Std_Types.h"

#include "Delay_ms.h"

#include "MCAL/GPIO/GPIO.h"

#include "HAL/LCD/LCD.h"

/*Glossary
*    IMH = Initialization Manager Helper 
*/

/*****************************************Defines******************************************/

/******************************************************************************************/

/*-----------------------------------Enum for LCD Stages-----------------------------------*/
typedef enum
{
    Init_Stage,
    Operation_Stage
}LCD_STAGE_t;
/*-----------------------------------------------------------------------------------------*/

/*------------------------------------Enum for InitState-----------------------------------*/
typedef enum
{
    Power_On,
    Function_Set,
    Entry,
    Display,
    End
}InitState_t;
/*-----------------------------------------------------------------------------------------*/

/*--------------------------------------Enum for G_WriteState------------------------------*/
typedef enum
{
    WriteInit_State,
    Writing_State,
    Writing_Done
}G_WriteState_t;
/*-----------------------------------------------------------------------------------------*/

/**/
typedef enum
{
    LCD_EnablePin_OFF,
    LCD_EnablePin_ON
}G_LCD_EnablePinState_t;
/**/

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Concated Commands>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
    int ClearDisplay        = CONCAT( 0, 0, 0, 0, 0, 0, 0, 1);
    int ReturnHome          = CONCAT( 0, 0, 0, 0, 0, 0, 1, 0);
    int EntryModeSet        = CONCAT( 0, 0, 0, 0, 0, 1, Curser_MovDir, DisplayShiftDirection);
    int DisplayControl      = CONCAT( 0, 0, 0, 0, 1, Display_State, Curser_DisplayState, Curser_BlinkingState);
    int CursorDisplayShiftL = CONCAT( 0, 0, 0, 1, 1, 1, 0, 0);
	int CursorDisplayShiftR = CONCAT( 0, 0, 0, 1, 1, 0, 0, 0);
    int FunctionSet         = CONCAT( 0, 0, 1, Interface_DataLength, Lines_Number, Font_Size, 0, 0);
/*---------------------------------------------------------------------------------------*/

/*-------------------------------------Global Variables-----------------------------------*/
    LCD_STAGE_t G_LCD_STAGE ;
    G_LCD_EnablePinState_t G_LCD_EnablePinState;
    G_WriteState_t G_WriteState;
    U8 G_CurserPositionRstring;                     /* CurserPosition Related to String being written */
    InitState_t InitState;
    U8 G_LCD_Curser_Data;
/*----------------------------------------------------------------------------------------*/

/*------------------------------------static functions------------------------------------*/

    static LCD_enuErrorStatus_t LCD_enuWriteCommand(U8 Copy_u8Command);

    static LCD_enuErrorStatus_t LCD_enuWriteData(U8 Copy_u8Data);

    static void LCD_Runnable_Manager(void);

        static void LCD_Init_Manager (void);

            static GPIO_Error_t LCD_IMH_PowerOn(void);

        static void LCD_Write_Proc(void);

        static void LCD_Clear_Proc(void); 

        static void LCD_SetPostion_Proc(void);

/*--------------------------------------------------------------------------------------*/

/*--------------------------------LCD Initilization Function----------------------------*/
    void LCD_InitAsync (void)
    {
        G_LCD_STAGE = Init_Stage;
    }
/*--------------------------------------------------------------------------------------*/

/*---------------------------------LCD Get Status Function------------------------------*/
    void LCD_getStatus (U8 *LCD_Status)
    {
        LCD_Status = UserREQ.State;
    }
/*--------------------------------------------------------------------------------------*/

/*-------------------------------LCD Clear Screen Function------------------------------*/
    LCD_enuErrorStatus_t LCD_ClearScreenAsync(void)
    {
        LCD_enuErrorStatus_t Local_Error = LCD_enumNOK;

        if ( (G_LCD_STAGE == Operation_Stage) && (UserREQ.State == readyForNewRequest) ) 
        {
            UserREQ.State = REQ_Pending;
            UserREQ.Operation_Type = Clear;
            Local_Error = LCD_enumOK;           
        }
        else
        {
            Local_Error = LCD_enumNotReady;  
        }

        return Local_Error;
    }
/*--------------------------------------------------------------------------------------*/

/*-----------------------------LCD GO to DDRAM Address Function-------------------------*/
    LCD_enuErrorStatus_t LCD_SetCursorPosAsync(U8 Copy_u8X, U8 Copy_u8Y)
    {
        LCD_enuErrorStatus_t LCD_enuErrorStatus = LCD_enumOK;

        U8 LOC_u8data;

        /*Error Handling*/
            if(Copy_u8X >2 || Copy_u8X<1)
            {
                LCD_enuErrorStatus = LCD_enumOutof_Range;
            }

            else if (Copy_u8Y>16 || Copy_u8Y<1)
            {
                LCD_enuErrorStatus = LCD_enumOutof_Range;
            }
        /*--------------*/

        /*Actual Implementation*/

            else
            {
            /* Getting Curser Data */
                if (Copy_u8X == 0)
                {
                    LOC_u8data = ( (LCD_SetCursor) + (Copy_u8Y-1) );
                }

                else if (Copy_u8X == 1)
                {
                    LOC_u8data = ( (LCD_SetCursor) + 64 + (Copy_u8Y-1) );
                }

                G_LCD_Curser_Data = LOC_u8data ;
            /*---------------------*/

            /* Setting Flags */
                UserREQ.State=REQ_Pending;
                UserREQ.Operation_Type = SetPosition;
            /*---------------*/

            }

            return LCD_enuErrorStatus;

        /*---------------------*/    
    }
/*--------------------------------------------------------------------------------------*/

/*------------------------------------Write String Function-----------------------------*/
    LCD_enuErrorStatus_t LCD_enuWriteStringAsync(char* Copy_pchPattern , U8 Length)
    {
        LCD_enuErrorStatus_t Local_Error = LCD_enumNOK;

        if (Copy_pchPattern == NULL)
        {
            Local_Error = LCD_NullPointer;
        }

        else if ( (G_LCD_STAGE == Operation_Stage) && (UserREQ.State == readyForNewRequest) ) 
        {
            UserREQ.State = REQ_Pending;
            UserREQ.Operation_Type = Write;

            UserREQ.String = Copy_pchPattern;
            UserREQ.Length = Length;
            Local_Error = LCD_enumOK;                 
        }
        else
        {
            Local_Error = LCD_enumNotReady;  
        }

        return Local_Error;        
    }
/*--------------------------------------------------------------------------------------*/

/*-----------------------------Get Operations State Function----------------------------*/
    LCD_enuErrorStatus_t Get_OperationState (U8 *Op_State)
    {
        UserREQ.Operation_Type;
    }
/*---------------------------------------------------------------------------------------*/

/*-------------------------------------Static functions---------------------------------*/

    /*----------------------------------Write Command-----------------------------------*/
        static LCD_enuErrorStatus_t LCD_enuWriteCommand(U8 Copy_u8Command)
        {
            switch (G_LCD_EnablePinState)
            {
                case LCD_EnablePin_OFF:
                    /*Enable Trigger Pin*/
                        LCD_CtrlEnablePin(LCD_EnablePin_ON);
                    /*-----------------*/

                    /*Registers Set*/
                        GPIO_Set_PinValue ( LCD_strLCDpinConfig [ RS ] .LCD_PortNumber , LCD_strLCDpinConfig [ RS ] .LCD_PinNumber , GPIO_STATE_RESET );
                        GPIO_Set_PinValue ( LCD_strLCDpinConfig [ RW ] .LCD_PortNumber , LCD_strLCDpinConfig [ RW ] .LCD_PinNumber , GPIO_STATE_RESET );
                    /*-------------*/ 

                    /*Data Transfer*/
                    for (int LCD_iter = 3; LCD_iter < LCD_PINs; LCD_iter++)
                        {
                            U8 Local_Data_bit = ( ( Copy_u8Command & ( BIT00_MASK << LCD_iter-3 ) ) >> LCD_iter-3 );
                            GPIO_Set_PinValue( LCD_strLCDpinConfig[ LCD_iter ].LCD_PortNumber , LCD_strLCDpinConfig[ LCD_iter ].LCD_PinNumber , Local_Data_bit );		
                        }
                    /*-------------*/

                    /*Change Global variable to the next stage*/
                        G_LCD_EnablePinState = LCD_EnablePin_ON;
                    /*--------------------------------------*/

                break;

                case LCD_EnablePin_ON :
                    /*Disable Trigger Pin*/
                        LCD_CtrlEnablePin(LCD_EnablePin_OFF);
                    /*-------------------*/

                    /*Change Global variable to the default stage*/
                        G_LCD_EnablePinState = LCD_EnablePin_OFF;
                    /*-------------------------------------------*/

                break;
            }
        }
    /*----------------------------------------------------------------------------------*/

    /*---------------------------------LCD_RUNNABLE MANAGER-----------------------------*/
    static void LCD_Runnable_Manager(void)
    {
        if (G_LCD_STAGE == Init_Stage)
        {
            InitState = Power_On;
            LCD_Init_Manager ();
        }
        else if (G_LCD_STAGE == Operation_Stage)
        {
            if(UserREQ.State == REQ_Pending)
            {
                switch (UserREQ.Operation_Type)
                {
                    case Write:
                        LCD_Write_Proc();                  
                    break;

                    case Clear:
                        LCD_Clear_Proc();                  
                    break;

                    case SetPosition:
                        LCD_SetPostion_Proc();             
                    break;    

                    default:
                                    
                    break;

                }
            }
        }
    }
    /*-----------------------------------------------------------------------------*/  

    /*-----------------------------------LCD Init Manager---------------------------*/
        static void LCD_Init_Manager (void)
        {

            switch(InitState)
            {
                case Power_On:
                    LCD_IMH_PowerOn();                    
                break;

                case Function_Set: 
                    LCD_enuWriteCommand(FunctionSet);
                    G_LCD_STAGE = Entry;           
                break;

                case Entry:
                    LCD_enuWriteCommand(EntryModeSet);
                    G_LCD_STAGE = Display;                        
                break;

                case Display:
                    LCD_enuWriteCommand(DisplayControl);    
                    G_LCD_STAGE = End;                         
                break;

                case End:
                    G_LCD_STAGE = Operation_Stage;
                break;
            }

        }
    /*-----------------------------------------------------------------------------*/  

    /*-----------------------------------LCD PowerOn-------------------------------*/
        static GPIO_Error_t LCD_IMH_PowerOn(void)
        {
            GPIO_Error_t LOC_Status = GPIO_NOK;

            extern const LCD_strLCDPinConfig_t LCD_strLCDpinConfig[LCD_PINs];
            GPIO_Pin_t  LCD;
            
            LCD.Pin_Mode  = GPIO_MODE_OP_PP;
            LCD.Pin_Speed = GPIO_SPEED_HIGH;

            U8 Index = 0;

            for (Index = 0 ; Index < LCD_PINs ; Index ++)
            {
                LCD.Port    = LCD_strLCDpinConfig[Index].LCD_PortNumber;
                LCD.Pin_num = LCD_strLCDpinConfig[Index].LCD_PinNumber;
                LOC_Status  = GPIO_Init(&LCD);
            }

            InitState = Function_Set;

            return LOC_Status;
        }
    /*-----------------------------------------------------------------------------*/

    /*-----------------------------------Write Process----------------------------*/
        static void LCD_Write_Proc(void)
        {
            switch (G_WriteState)
            {
                case WriteInit_State : 
                    G_CurserPositionRstring = 0;
                    G_WriteState = Writing_State;
                break;

                case Writing_State :
                    if ( G_CurserPositionRstring =! UserREQ.Length )
                    {
                        LCD_enuWriteData( UserREQ.String[ G_CurserPositionRstring ] );

                        if( G_LCD_EnablePinState == LCD_EnablePin_OFF )
                        {
                            G_CurserPositionRstring++;
                        }
                    }
                    else
                    {
                        G_WriteState = Writing_Done;
                    }
                break;

                case Writing_Done:
                    UserREQ.State = readyForNewRequest;
                    UserREQ.Operation_Type  = None;
                    G_WriteState = WriteInit_State;
                break;

            }
        }
    /*-----------------------------------------------------------------------------*/

    /*---------------------------------WriteData-----------------------------------*/
        static LCD_enuErrorStatus_t LCD_enuWriteData(U8 Copy_u8Data)
        {
            switch (G_LCD_EnablePinState)
            {
                case LCD_EnablePin_OFF :
                    /*Enable Trigger Pin*/
                        LCD_CtrlEnablePin(LCD_EnablePin_ON);
                    /*-----------------*/

                    /*Registers Set*/
                        GPIO_Set_PinValue ( LCD_strLCDpinConfig [ RS ] .LCD_PortNumber , LCD_strLCDpinConfig [ RS ] .LCD_PinNumber , GPIO_STATE_SET );
                        GPIO_Set_PinValue ( LCD_strLCDpinConfig [ RW ] .LCD_PortNumber , LCD_strLCDpinConfig [ RW ] .LCD_PinNumber , GPIO_STATE_RESET );
                    /*-------------*/

                    /*Get & Send data*/
                    U8 Data_Iter;
                    for (Data_Iter = 0 ; Data_Iter<8 ; Data_Iter++)
                    {
                        /*Get needed Bit*/
                            U8 Local_Data_Bit = ( Copy_u8Data & (1 << Data_Iter ) ) ? GPIO_STATE_SET : GPIO_STATE_RESET ;
                        /*--------------*/

                        /*Set needed Bit*/
                            GPIO_Set_PinValue ( LCD_strLCDpinConfig [ Data_Iter+3 ] .LCD_PortNumber , LCD_strLCDpinConfig [ Data_Iter+3 ] .LCD_PinNumber , Local_Data_Bit );
                        /*-------------*/
                    }
                    /*---------*/

                    /*Change Global variable to the next stage*/
                        G_LCD_EnablePinState = LCD_EnablePin_ON;
                    /*--------------------------------------*/
                break;

                case LCD_EnablePin_ON :

                    /*Disable Trigger Pin*/
                        LCD_CtrlEnablePin(LCD_EnablePin_OFF);
                    /*-------------------*/

                    /*Change Global variable to the default stage*/
                        G_LCD_EnablePinState = LCD_EnablePin_OFF;
                    /*-------------------------------------------*/                    

                break;
            }
            
        }
    /*-----------------------------------------------------------------------------*/

    /*----------------------------------Clear Process------------------------------*/
        static void LCD_Clear_Proc(void)
        {
            LCD_enuWriteCommand( ClearDisplay );
            UserREQ.State = readyForNewRequest;
            UserREQ.Operation_Type  = None;
        }
    /*-----------------------------------------------------------------------------*/

    /*---------------------------------SetPostion Process---------------------------*/
        static void LCD_SetPostion_Proc(void)
        {
            
        }
    /*------------------------------------------------------------------------------*/

    /*----------------------------------CtrlEnablePin-------------------------------*/
        static void LCD_CtrlEnablePin(U8 Copy_LCDEnablePinState)
        {
            GPIO_Set_PinValue(LCD_strLCDpinConfig[ ET ].LCD_PortNumber, LCD_strLCDpinConfig[ ET ].LCD_PinNumber, Copy_LCDEnablePinState);
        }
    /*------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------*/