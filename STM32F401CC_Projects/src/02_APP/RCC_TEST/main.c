#include "00_MCAL/RCC/STM32F401cc_HAL_RCC.h"

#include "00_MCAL/GPIO/GPIO.h"


int main ()
{
    RCC_EnableClock				( CLK_HSI );
    RCC_EnableClock				( CLK_HSE );
    RCC_EnableClock				( CLK_PLL );
    RCC_DisableClock            ( CLK_PLL );
    RCC_EnableClock             ( CLK_PLLI2S );

    RCC_DisableClock            ( CLK_PLLI2S );

    RCC_PLL_SRCConfig		    ( PLLSRC_HSE );
    RCC_PLL_PreScalarConfig     ( 25 , 336 , 7 , 4 );

    RCC_ReadStatusClock			( READ_HSI_STATUS );
    RCC_ReadStatusClock			( READ_HSE_STATUS );
    RCC_ReadStatusClock			( READ_PLL_STATUS );
    RCC_ReadStatusClock			( READ_PLLI2S_STATUS );

    RCC_SetSYSCLK 				( SYSCLK_HSE );

    RCC_AHB_PREscaler			( AHB_PRE_2 );

    RCC_SetAHB1Peripheral		( AHB1ENR_GPOIA);

    RCC_ResetAHB1Peripheral	    ( AHB1ENR_GPOIA	);

    RCC_SetAHB1Peripheral		( AHB1ENR_GPOIA);

    RCC_SetAHB2Peripheral		( AHB2ENR_OTGFS );

    RCC_ResetAHB2Peripheral      ( AHB2ENR_OTGFS );

    RCC_SetAHB2Peripheral		( AHB2ENR_OTGFS );

    RCC_APB1_PREscaler			( APB_PRE1_2 );

    RCC_SetAPB1Peripheral		( APB1ENR_PWR );

    RCC_ResetAPB1Peripheral		( APB1ENR_PWR );

    RCC_APB2_PREscaler			( APB_PRE2_2 );

    RCC_SetAPB2Peripheral		( APB2ENR_ADC1);

    RCC_ResetAPB2Peripheral		( APB2ENR_ADC1);

    RCC_SetAPB2Peripheral		( APB2ENR_ADC1);


    while (1)
    {

    };

    return 0;
}




/*
int main ()
{
    GPIO_Pin_t Led;

    Led.Port = GPIO_PORT_A;
    Led.Pin_num = GPIO_PIN_0;
    Led.Pin_Mode = GPIO_MODE_OP_PP;
    Led.Pin_Speed = GPIO_SPEED_MED;

    GPIO_Init( &Led );
 
}

 */