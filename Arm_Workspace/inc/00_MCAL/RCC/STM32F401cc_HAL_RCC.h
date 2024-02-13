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
			#define CLK_HSI		 				BIT0_MASK
			#define CLK_HSE  	 				BIT16_MASK
			#define CLK_PLL 	   				BIT24_MASK
			#define CLK_PLLI2S					BIT26_MASK
		/*----------------------*/

		/* Mask for READ_CLK_STATUS*/
			#define READ_HSI_STATUS		     	BIT1_MASK
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
			#define SYSCLK_HSE					BIT1_MASK
			#define SYSCLK_PLL					BIT2_MASK		
		/*-------------------*/

		/*Mask for READ_SYSCLK_SRC*/
			#define READ_SYSCLK_HSI				BITNULL_MASK
			#define READ_SYSCLK_HSE				BIT1_MASK
			#define READ_SYSCLK_PLL				BIT2_MASK		
		/*------------------------*/		

		/*Mask for */
		/*-----------------*/
		

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

			/*System CLKs*/
				typedef
				{
					HSI,
					HSE,
					PLL,
					PLLI2S
				}RCC_SYSCLKs_t
			/*-----------*/

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
				RCC_enuErrorStatus_t RCC_EnableClock			( U32 CLK_CLK );
			/*------------------------------------*/

			/*-----Function for Disaple any CLK----*/
				RCC_enuErrorStatus_t RCC_DisableClock			( U32 CLK_CLK );
			/*-------------------------------------*/

			/*Function for Configuration of PLL SRC */
				RCC_enuErrorStatus_t RCC_PLL_SRCConfig			( U32 PLLSRC_CLK );
			/*--------------------------------------------*/

			/*Function for Configuration of PLL Pre Scalar*/
				RCC_enuErrorStatus_t RCC_PLL_PreScalarConfig	( U8 Copy_u8PLLM , U16 Copy_u16PLLN , U8 Copy_u8PLLQ , U8 Copy_u8PLLP );
			/*--------------------------------------------*/		

			/*----Function for Reading any CLK status----*/
				RCC_CLKStatus_t	RCC_ReadStatusClock				( U32 READ_CLK_STATUS );
			/*-------------------------------------------*/

			/*Function to Choose the desired system clk source*/
				RCC_enuErrorStatus_t RCC_SetSYSCLK 				( U32 Copy_u32ClockSelection );
			/*------------------------------------------------*/

			/*Function to Reading SYSCLK source*/
				RCC_enuErrorStatus_t RCC_ReadSYSCLKStatus 		( U32 Copy_u32ClockSelection );
			/*---------------------------------*/

		/*---------------------*/

		/*Peripheral Control*/
			
			/*AHB1*/

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

				/*APB1 Set*/
					RCC_enuErrorStatus_t RCC_SetAPB1Peripheral		(U32 Copy_u32APB1Peripheral);
				/*--------*/

				/*APB1 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAPB1Peripheral	(U32 Copy_u32APB1Peripheral);
				/*----------*/

			/*----*/

			/*APB2*/

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

