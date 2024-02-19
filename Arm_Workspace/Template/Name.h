/*#include*/
    //All includes that will be nedded in .h and .c
/*--------*/

/*#defines*/

    //Example
    #define SYSCLK_HSE 0
    #define SYSCLK_HSI 1
    #define SYSCLK_PLL 2
    
    /* Here you notice that SYSCLK_<Something> so, 
        the DevUser Can Write SYSCLK_ and Press tab to AUTO COMPLETE easily*/

/*--------*/

/*New types*/

    /*Enums*/
        /*here you write enums*/

        /*Error Enum*/
            typedef enum 
            {

                Driver_NOK,
                Driver_OK

            }Driver_Error_t
        /*----------*/

        /*Other Enums*/
        /*-----------*/

    /*-----*/

    /*Structs*/
        /*Here you write your structs*/

    /*-------*/

/*---------*/

/*API's*/

    /*Naming of API*/
                //    ErrorStatus_Driver_<Operation><On_What> ( Data type On_What )
        //Example ->
                //    ErrorStatus_RCC_SelectSYSCLK (uint8_t SYSCLK)
    /*-------------*/

/*-----*/