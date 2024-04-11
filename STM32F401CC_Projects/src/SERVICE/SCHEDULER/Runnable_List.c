#include "SERVICE/SCHEDULER/SCHEDULER.h"
#include "SERVICE/SCHEDULER/Runnable_List.h"

// extern void Runnable_LED_Toggle_TASK(void);
extern void Runnable_GET_SWITCH_STATE_TASK(void);
extern void Runnable_SWITCH_Control_LED(void);
// extern void Runnable_TrafficLight_StateMachine(void);
// extern void LCD_Runnable_Manager(void);
// extern void Runnable_LCD_TASK (void);

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
                                        [Switch_Reading]=
                                        {
                                            .name          =  "Switch",
                                            .PeriodicityMs =  2,
                                            .CB            =  Runnable_GET_SWITCH_STATE_TASK,
                                            .delayms       =  0,
                                        }
                                        ,
                                        [Switch_Control]=
                                        {
                                            .name          =  "SWITCH_Ctrl",
                                            .PeriodicityMs =  2,
                                            .CB            =  Runnable_SWITCH_Control_LED,
                                            .delayms       =  3,
                                        }

                                    };
