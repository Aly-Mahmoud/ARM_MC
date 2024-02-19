#ifndef _<HALC>_CONFIG_H_
#define _<HALC>_CONFIG_H_

    #include "PORT_Config.h"

    /*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<For Simple Nature HALC>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

        /*----------------------UserDev Config (if needed )---------------------*/

            /*----------Number of <HALC>---------*/
                #define NUM_OF_<HALC>   
            /*-----------------------------------*/ 

            /*--------UserDev <1st_Config>-------*/

                    /*<1st_Config_Options>*/
                        //Choices:
                        //0 -> <1st_Config_Option1>                    
                        //1 -> <1st_Config_Option2>
                    /*---------------------------------------*/

                    #define <1st_Config> 
            /*-----------------------------------*/

            /*--------UserDev <2nd_Config>-------*/

                    /*<2nd_Config_Options>*/
                        //Choices:
                        //0 -> <2nd_Config_Option1>                    
                        //1 -> <2nd_Config_Option2>
                    /*---------------------------------------*/

                    #define <2nd_Config> 
            /*-----------------------------------*/            

        /*----------------------------------------------------------------------*/

        /* ----------------Struct for the <HALC> Pin Configuration-------------- */
            typedef struct
            {  
                Port_enumPortNumber_t         <HALC>_enumPortNumber;              //Used in Config function
                Port_enumPinNumber_t          <HALC>_enumPinNumber;               //Used in Config function                        
            }<HALC>_str7<HALC>PinConfig_t;
        /* ----------------------------------------------------------------------*/ 

        /* -------------------Struct for the <HALC> Configuration----------------*/
            typedef struct
            {  
                <HALC>_str7<HALC>PinConfig_t        <HALC>_str7<HALC>PinConfig;     //Used in Config function                    
            }<HALC>_str<HALC>Config_t;
        /* ----------------------------------------------------------------------*/ 
       
        /*-------------------------------<HALC> List-----------------------------*/
            #define <HALC>1     0
            #define <HALC>2     1
            #define <HALC>3     2
            #define <HALC>4     3
        /*-----------------------------------------------------------------------*/         

        /*--------------------------<HALC> Elements List--------------------------*/
            #define <HALC_Pin1>     0
            #define <HALC_Pin2>     1
            #define <HALC_Pin3>     2
            #define <HALC_Pin4>     3
        /*------------------------------------------------------------------------*/        

    /*--------------------------------------------------------------------------------------------------------------------------------------*/ 

    /*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<For Special Nature HALC>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/  

        /*------------------------UserDev Config (if needed )----------------*/

            /*Number of HALC and HALC_Elments*/
                #define NUM_OF_<HALC>
                #define NUM_OF_<HALC>_<HALC_NATURE>
            /*-------------------------------*/

            /*--------UserDev <1st_Config>-------*/

                    /*<1st_Config_Options>*/
                        //Choices:
                        //0 -> <1st_Config_Option1>                    
                        //1 -> <1st_Config_Option2>
                    /*---------------------------------------*/

                    #define <1st_Config> 
            /*-----------------------------------*/

            /*--------UserDev <2nd_Config>-------*/

                    /*<2nd_Config_Options>*/
                        //Choices:
                        //0 -> <2nd_Config_Option1>                    
                        //1 -> <2nd_Config_Option2>
                    /*---------------------------------------*/

                    #define <2nd_Config> 
            /*-----------------------------------*/    

        /*-------------------------------------------------------------------*/

        /* -----Struct for the <HALC> Fundmental Element Configuration----- */
            typedef struct
            {  
                Port_enumPortNumber_t         <HALC>_enumPortNumber;              //Used in Config function
                Port_enumPinNumber_t          <HALC>_enumPinNumber;               //Used in Config function                        
            }<HALC>_str7<HALFC>Config_t;
        /* ---------------------------------------------------------------- */ 

        /*-----------------enum for <HALC> types (if there is)--------------*/
            typedef enum{
                <Type1>,
                <Type2>
            }<HALC>_enuType_t;
        /*------------------------------------------------------------------*/

        /*-----------------enum for <HALC> Configs (if there is)--------------*/
            typedef enum{
                <Config1>,
                <Config2>
            }<HALC>_enuConfig_t;
        /*------------------------------------------------------------------*/

        /* -----Struct for the <HALC> Exotic Configuration (if there is)--- */ ?
            typedef struct
            {  
                <EXOTIC_STATE1>;
                <EXOTIC_STATE2>;                
            }<HALC>_str7<HALC>State_t;
        /* -----------------------------------------------------------------*/    

        /* -------------Struct for the <HALC> Configuration---------------- */
            typedef struct
            {  
                <HALC>_str7<HALFC>Config_t       <HALC>_strNUM_OF_<HALC>_<HALC_NATURE>Config [NUM_OF_<HALC>_<HALC NATURE>];        //Used in Config function    
                <HALC>_enumType_t                <HALC>_enumType;                                                                  //(if there is) Used in Config function 
                <HALC>_str7<HALC>State_t         <EXOTIC_STATE1>;                                                                  //(if there is) Used in Set function      
            }<HALC>_str7<HALC>Config_t;
        /* ---------------------------------------------------------------- */

        /*--------------------------<HALC> List-----------------------------*/
            #define <HALC>1     0
            #define <HALC>2     1
            #define <HALC>3     2
            #define <HALC>4     3
        /*------------------------------------------------------------------*/ 

        /*--------- <HALC_Fundamental_Element> (if there is) List-----------*/
            #define <HALC>1_<Fundmental_Component_1> 0
            #define <HALC>1_<Fundmental_Component_2> 1
            #define <HALC>1_<Fundmental_Component_3> 2
            #define <HALC>1_<Fundmental_Component_4> 3
        /*------------------------------------------------------------------*/    

    /*---------------------------------------------------------------------------------------------------------------------------------------*/

#endif 