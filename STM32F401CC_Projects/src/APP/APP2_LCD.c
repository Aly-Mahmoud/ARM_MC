#include "HAL/LCD/LCD.h"

void Runnable_LCD_TASK (void)
{

    LCD_InitAsync           (           );   
    LCD_enuWriteStringAsync ( "ALY" , 3 );
    LCD_SetCursorPosAsync   ( 2 , 1 );
    LCD_enuWriteStringAsync ( "MAHMOUD" , 7 );

}
