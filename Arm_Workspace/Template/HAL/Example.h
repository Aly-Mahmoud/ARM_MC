#include config.HALC

#define led


    /*------------------------------Enum for error of <HALC> Driver-------------------------*/
        typedef enum{
            <HALC>_enuOK,
            <HALC>_enuNOK,
            <HALC>_NullPointer,
            <HALC>_enuWrong_PortNo,
            <HALC>_enuWrong_PinNo,
            <HALC>_enu<Erro1>,
            <HALC>_enu<Error2>,
            <HALC>_enu<Error3>
        }<HALC>_enuErrorStatus_t;
    /*--------------------------------------------------------------------------------------*/

    /*---------------------------------------Function API's---------------------------------*/

        /*Init Function*/
            void <HALC>_Init(void);
        /*-------------*/

        /*Function 1 API*/
            <HALC>_enuErrorStatus_t <HALC>_Fnc1(<Argument_1>, Argument_2);
        /*--------------*/

        /*Function 2 API*/
            <HALC>_enuErrorStatus_t <HALC>_Fnc2(<Argument_1>);
        /*-------------*/
        
    /*--------------------------------------------------------------------------------------*/

