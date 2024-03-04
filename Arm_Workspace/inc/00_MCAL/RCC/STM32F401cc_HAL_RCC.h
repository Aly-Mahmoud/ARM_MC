/*
 * STM32F401cc_HAL_RCC.h
 *
 *  Created on: Feb 5, 2024
 *      Author: Aly Mahmoud
 */


#ifndef MCAL_RCC_STM32F401CC_HAL_RCC_H_
	#define MCAL_RCC_STM32F401CC_HAL_RCC_H_

	/*Includes*/
		#include "Std_Types.h"
		#include "Bit_Mask.h"
	/*-------*/

	/*#defines*/

		/*
		 Here you notice that SYSCLK_<Something> so, 
			the DevUser Can Write SYSCLK_ and Press tab to AUTO COMPLETE easily
		*/

		/*---Mask for CLK_CTRL--*/
			#define CLK_HSI		 				BIT00_MASK
			#define CLK_HSE  	 				BIT16_MASK
			#define CLK_PLL 	   				BIT24_MASK
			#define CLK_PLLI2S					BIT26_MASK
		/*----------------------*/

		/* Mask for READ_CLK_STATUS*/
			#define READ_HSI_STATUS		     	BIT01_MASK
			#define READ_HSE_STATUS       	    BIT17_MASK
			#define READ_PLL_STATUS 			BIT25_MASK
			#define READ_PLLI2S_STATUS      	BIT27_MASK
		/*------------------*/

		/*Mask for PLL_SRC*/	
			#define PLLSRC_HSI 	       			BITNULL_MASK
			#define PLLSRC_HSE		 			BIT22_MASK
		/*----------------*/

		/*Mask for SYSCLK_CLK*/
			#define SYSCLK_HSI					BITNULL_MASK
			#define SYSCLK_HSE					BIT01_MASK
			#define SYSCLK_PLL					BIT02_MASK		
		/*-------------------*/

		/*Mask for READ_SYSCLK_SRC*/
			#define SYSCLK_STATUS                0x0000000C
		/*------------------------*/

		/*Mask for AHB_PREscalar*/
			#define AHB_PRE_1					0x00000000
			#define AHB_PRE_2					0x00000080
			#define AHB_PRE_4 					0x00000090
			#define AHB_PRE_8 					0x000000A0
			#define AHB_PRE_16 					0x000000B0
			#define AHB_PRE_64 					0x000000C0
			#define AHB_PRE_128 				0x000000D0
			#define AHB_PRE_256 				0x000000E0
			#define AHB_PRE_512					0x000000F0
		/*----------------------*/	

		/*Mask for AHB1ENR_PERI*/
			#define AHB1ENR_DMA2                BIT22_MASK
			#define AHB1ENR_DMA1				BIT21_MASK
			#define AHB1ENR_CRC					BIT12_MASK
			#define AHB1ENR_GPOIH               BIT07_MASK
			#define AHB1ENR_GPOIE               BIT04_MASK
			#define AHB1ENR_GPOID				BIT03_MASK
			#define AHB1ENR_GPOIC               BIT02_MASK
			#define AHB1ENR_GPOIB               BIT01_MASK
			#define AHB1ENR_GPOIA               BIT00_MASK
		/*-----------------*/

		/*Mask for AHB2ENR_PERI*/
			#define AHB2ENR_OTGFS               BIT07_MASK
		/*----------------*/

		/* Masks for PPRE1: APB Low-speed prescaler (APB1) */
			#define APB_PRE1_1   				0x00000000
			#define APB_PRE1_2   				0x00000400
			#define APB_PRE1_4   				0x00000500
			#define APB_PRE1_8   				0x00000600
			#define APB_PRE1_16  				0x00000700
		/*-------------------------------------------------*/		

		/*Mask for APB1ENR_PERI*/
			#define APB1ENR_PWR					BIT28_MASK
			#define APB1ENR_I2C3				BIT23_MASK
			#define APB1ENR_I2C2				BIT22_MASK
			#define APB1ENR_I2C1				BIT21_MASK
			#define APB1ENR_USART				BIT17_MASK
			#define APB1ENR_SPI3				BIT15_MASK
			#define APB1ENR_SPI2				BIT14_MASK
			#define APB1ENR_WWDG				BIT11_MASK
			#define APB1ENR_TIM5				BIT03_MASK
			#define APB1ENR_TIM4				BIT02_MASK
			#define APB1ENR_TIM3				BIT01_MASK
			#define APB1ENR_TIM2 				BIT00_MASK
		/*---------------*/	

		/* Masks for PPRE2: APB high-speed prescaler (APB2) */
			#define APB_PRE2_1   				0x00000000
			#define APB_PRE2_2   				0x00002000
			#define APB_PRE2_4   				0x00002800
			#define APB_PRE2_8   				0x00003000
			#define APB_PRE2_16  				0x00003800
		/*----------------------*/	

		/*Mask for APB2ENR_PERI*/
			#define APB2ENR_TIM11               BIT18_MASK
			#define APB2ENR_TIM10               BIT17_MASK
			#define APB2ENR_TIM09               BIT16_MASK
			#define APB2ENR_SYSCFG              BIT14_MASK
			#define APB2ENR_SPI4                BIT13_MASK
			#define APB2ENR_SPI1                BIT12_MASK
			#define APB2ENR_SDIO                BIT11_MASK
			#define APB2ENR_ADC1                BIT08_MASK
			#define APB2ENR_USART6              BIT05_MASK
			#define APB2ENR_USART1              BIT04_MASK
			#define APB2ENR_TIM1                BIT00_MASK
		/*---------------*/

	/*--------*/

	/*New types*/

		/*Enums*/

			/*Error Enum*/
				typedef enum 
				{
					RCC_OK,
					RCC_NOK,
					RCC_InputError,
					RCC_ClockNotON,
					RCC_ClockNotReady,
					RCC_PLLON,
				}RCC_enuErrorStatus_t;
			/*----------*/

			/*Status Enum*/
				typedef enum
				{
						NotReady,
						Ready,
						Wrong_Input
				}RCC_CLKStatus_t;
			/*-----------*/

			/*SYSCLK STATUS enum*/
				typedef enum
				{
					HSI,
					HSE,
					PLL
				}RCC_SYSCLKStatus_t;
			/*------------------*/

		/*-----*/

	/*---------*/

	/*API's*/

		/*Naming Conventions of API*/
					//    ErrorStatus_Driver_<Operation><On_What> ( Data type On_What )
			//Example ->
					//    ErrorStatus_RCC_SelectSYSCLK (uint8_t SYSCLK)
		/*-------------------------*/

		/*CLK Control functions*/	

			/*-----Function for Enable any CLK----*/
				RCC_enuErrorStatus_t RCC_EnableClock				( U32 CLK_CLK );
			/*------------------------------------*/

			/*-----Function for Disaple any CLK----*/
				RCC_enuErrorStatus_t RCC_DisableClock				( U32 CLK_CLK );
			/*-------------------------------------*/

			/*Function for Configuration of PLL SRC */
				RCC_enuErrorStatus_t RCC_PLL_SRCConfig				( U32 PLLSRC_CLK );
			/*--------------------------------------------*/

			/*Function for Configuration of PLL Pre Scalar*/
				RCC_enuErrorStatus_t RCC_PLL_PreScalarConfig		( U8 Copy_u8PLLM , U16 Copy_u16PLLN , U8 Copy_u8PLLQ , U8 Copy_u8PLLP );
			/*--------------------------------------------*/		

			/*----Function for Reading any CLK status----*/
				RCC_CLKStatus_t	RCC_ReadStatusClock					( U32 READ_CLK_STATUS );
			/*-------------------------------------------*/

			/*Function to Choose the desired system clk source*/
				RCC_enuErrorStatus_t RCC_SetSYSCLK 					( U32 Copy_u32ClockSelection );
			/*------------------------------------------------*/

			/*Function to Reading SYSCLK source*/
				RCC_enuErrorStatus_t RCC_ReadSYSCLKStatus 			( U32 Copy_u32ClockSelection );
			/*---------------------------------*/

		/*---------------------*/

		/*Peripheral Control*/
			
			/*AHB1*/

				/*AHB1_PREscalar*/
					RCC_enuErrorStatus_t RCC_AHB_PREscaler			(    U32 AHB_PREscalar    );
				/*--------------*/

				/*AHB1 Set*/
					RCC_enuErrorStatus_t RCC_SetAHB1Peripheral		(U32 Copy_u32AHB1Peripheral);
				/*--------*/

				/*AHB1 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAHB1Peripheral	(U32 Copy_u32AHB1Peripheral);
				/*----------*/

			/*----*/

			/*AHB2*/

				/*AHB2 Set*/
					RCC_enuErrorStatus_t RCC_SetAHB2Peripheral		(U32 Copy_u32AHB1Peripheral);
				/*--------*/

				/*AHB2 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAHB2Peripheral	(U32 Copy_u32AHB1Peripheral);
				/*---------*/

			/*----*/

			/*APB1*/

				/*APB1_PREscalar*/
					RCC_enuErrorStatus_t RCC_APB1_PREscaler			(    U32 APB1_PREscalar    );
				/*--------------*/			

				/*APB1 Set*/
					RCC_enuErrorStatus_t RCC_SetAPB1Peripheral		(U32 Copy_u32APB1Peripheral);
				/*--------*/

				/*APB1 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAPB1Peripheral	(U32 Copy_u32APB1Peripheral);
				/*----------*/

			/*----*/

			/*APB2*/

				/*APB2_PREscalar*/
					RCC_enuErrorStatus_t RCC_APB2_PREscaler			(    U32 APB2_PREscalar    );
				/*--------------*/	

				/*APB2 Set*/
					RCC_enuErrorStatus_t RCC_SetAPB2Peripheral		(U32 Copy_u32APB2Peripheral);
				/*--------*/

				/*APB2 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAPB2Peripheral	(U32 Copy_u32APB2Peripheral);
				/*---------*/

			/*----*/
			
		/*------------------*/

	/*-----*/
	
#endif /* MCAL_RCC_STM32F401CC_HAL_RCC_H_ */

