#include "HAL/LCD/LCD.h"

void Runnable_LCD_TASK (void)
{
    static U8 counter = 0;

    switch (counter)
    {
        
        case 0:
            LCD_SetCursorPosAsync(2,2);
            counter ++;
        break;

        case 1:
            counter++;
        break;   

        case 2:
            LCD_enuWriteStringAsync ( "ALY" , 3 );
            counter++;
        break; 

    } 


}
