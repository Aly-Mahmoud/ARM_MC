#include "SERVICE/SCHEDULER/SCHEDULER.h"
#include "SERVICE/SCHEDULER/Runnable_List.h"

extern void Runnable_LED_Toggle_TASK(void);
extern void Runnable_GET_SWITCH_STATE_TASK(void);
extern void Runnable_SWITCH_Control_LED(void);
extern void Runnable_TrafficLight_StateMachine(void);

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
                                        [Led_Toggle]=
                                        {
                                            .name          =  "Toggle Led",
                                            .PeriodicityMs =  1000,
                                            .CB            =  Runnable_LED_Toggle_TASK,
                                            .delayms       =  0,
                                        }
                                        ,
                                        [SWITCH_GET_STATE]=
                                        {
                                            .name          =  "Get the state of all the switches",
                                            .PeriodicityMs =  10,
                                            .CB            =  Runnable_GET_SWITCH_STATE_TASK,
                                            .delayms       =  0,
                                        }
                                        ,
                                        [SWITCH_CONTROL_LED]=
                                        {
                                            .name          =  "SWITCH CONTROL LED",
                                            .PeriodicityMs =  200,
                                            .CB            =  Runnable_SWITCH_Control_LED,
                                            .delayms       =  0,
                                        }
                                        ,
                                        [TRAFFIC_LIGHT]=
                                        {
                                            .name          =  "TRAFFIC LIGHT State Machine",
                                            .PeriodicityMs =  100,
                                            .CB            =  Runnable_TrafficLight_StateMachine,
                                            .delayms       =  0,
                                        }                                   
                                    };
