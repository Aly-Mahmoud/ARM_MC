#include "SERVICE/SCHEDULER/SCHEDULER.h"
#include "SERVICE/SCHEDULER/Runnable_List.h"

extern void Runnable_LED_Toggle_TASK(void);
extern void Runnable_GET_SWITCH_STATE_TASK(void);
extern void Runnable_SWITCH_Control_LED(void);
extern void Runnable_TrafficLight_StateMachine(void);
extern void LCD_Runnable_Manager(void);
extern void Runnable_LCD_TASK (void);

Runnable_t Runnables[] =
                                    {
                                    /*
                                        [Task_Name_In_Enum]=
                                        {
                                            .name          =  "put the desired name here",
                                            .PeriodicityMs =  xxx,
                                            .CB            =  Runnable_<Func>_Task,
                                            .delayms       =  xxx,
                                        }
                                        ,
                                    */
                                        [LCD_Runnable_Mngr]=
                                        {
                                            .name          =  "LCD",
                                            .PeriodicityMs =  2,
                                            .CB            =  LCD_Runnable_Manager,
                                            .delayms       =  40,
                                        }
                                        ,
                                        [LCD_APP]=
                                        {
                                            .name          =  "LCD_APP",
                                            .PeriodicityMs =  20,
                                            .CB            =  Runnable_LCD_TASK,
                                            .delayms       =  1000,
                                        }

                                    };
