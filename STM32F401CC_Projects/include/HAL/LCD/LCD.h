#ifndef LED_H_
#define LED_H_
	#include "HAL/LCD/LCD_Config.h"

    /*------------------------------Enum for error of LCD Driver----------------------------*/
        typedef enum{
            LCD_enumNOK,
            LCD_NullPointer,
            LCD_enumWrong_PortNo,
            LCD_enumWrong_PinNo,
            LCD_enumWrong_Value,
            LCD_enumOutof_Range,
            LCD_enumNotReady,
            LCD_enumOK
        }LCD_enuErrorStatus_t;
    /*--------------------------------------------------------------------------------------*/

    /*-----------------------------------Enum for Command Types-----------------------------*/
        typedef enum
        {
            None,
            Write,
            Clear,
            SetPosition,
            ShiftDisplay
        }Operation_Type_t;
    /*---------------------------------------------------------------------------------------*/

    /*----------------------------------Enum for LCD States----------------------------------*/

        typedef enum
        {
            readyForNewRequest,
            REQ_Pending
        }State_t;
    /*---------------------------------------------------------------------------------------*/

    /*************************************Struct for User Reg*********************************/

        struct 
        {
            const char *String;                  
            U8 Length;                           
            State_t State;                            
            Operation_Type_t Operation_Type;                         
        }UserREQ;

    /*****************************************************************************************/

    /*--------------------------------------Struct for Wirte---------------------------------*/

        struct 
        {
            U8     stringCursorPosition;
            void   *CB;
        }Write_t;
        

    /*---------------------------------------------------------------------------------------*/

    /*-----------------------------------------Commands--------------------------------------*/
        #define LCD_Home                      0x02          // return cursor to first position on first line 
        #define LCD_CGRAM                     0x40          // the first Place/Address at CGRAM
        #define LCD_SetCursor                 0x80          // set cursor position
        #define LCD_FunctionReset             0x30          // reset the LCD
    /*---------------------------------------------------------------------------------------*/
    
/*APIs*/
    /*--------------------------------LCD Initilization Function----------------------------*/
        void LCD_InitAsync (void);    
    /*--------------------------------------------------------------------------------------*/

    /*---------------------------------LCD Get Status Function------------------------------*/
        void LCD_getStatus (U8 *LCD_Status);
    /*--------------------------------------------------------------------------------------*/

    /*-------------------------------LCD Clear Screen Function------------------------------*/
        LCD_enuErrorStatus_t LCD_ClearScreenAsync();
    /*--------------------------------------------------------------------------------------*/

    /*-----------------------------LCD GO to DDRAM Address Function-------------------------*/
         LCD_enuErrorStatus_t LCD_SetCursorPosAsync(U8 Copy_u8X, U8 Copy_u8Y);
    /*--------------------------------------------------------------------------------------*/

    /*------------------------------------Write String Function-----------------------------*/
        LCD_enuErrorStatus_t LCD_enuWriteStringAsync(char* Copy_pchPattern , U8 Length);
    /*--------------------------------------------------------------------------------------*/

    /*-----------------------------Get Operations State Function----------------------------*/
        LCD_enuErrorStatus_t Get_OperationState (U8 *Op_State);
    /*---------------------------------------------------------------------------------------*/
/*****/

// /*Extra*/	
// 	/*-------------------------------ShiftDisplay+Cursor-------------------------------------*/
// 	    LCD_enuErrorStatus_t LCD_ShiftDisplay(ShiftDir_t ShiftDir);
// 	/*---------------------------------------------------------------------------------------*/	

//     /*-----------------------------------Write Number Function------------------------------*/
// 		 LCD_enuErrorStatus_t LCD_enuWriteNumber(U8 Copy_u8Number);
//     /*--------------------------------------------------------------------------------------*/    
// /******/    
// /*------*/




#endif

