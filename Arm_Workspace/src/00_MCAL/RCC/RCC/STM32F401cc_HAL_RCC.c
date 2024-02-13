/*
 * STM32F401cc_HAL_RCC.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Aly Mahmoud
 */


/*Includes*/
    #include "STM32F401cc_HAL_RCC.h"
/*--------*/

/*Types*/
		/*Structs*/

			/*RCC Peripheral*/ 
				typedef struct
				{
					volatile U32 CR;
					volatile U32 PLLCFGR;
					volatile U32 CFGR;
					volatile U32 CIR;
					volatile U32 AHB1RSTR;
					volatile U32 AHB2RSTR;
					volatile U32 Reserved1;
					volatile U32 Reserved2;
					volatile U32 APB1RSTR;
					volatile U32 APB2RSTR;
					volatile U32 Reserved3;
					volatile U32 Reserved4;
					volatile U32 APB1ENR;
					volatile U32 APB2ENR;

				}RCC_Peri_t;
			/*--------------*/

		/*-------*/
/*-----*/

/*Define*/
   #define RCC_u32BASEADDRESS 		 0x40023800

   #define RCC						((RCC_Peri_t* )(RCC_u32BASEADDRESS))

   #define CLEAR_MAGIC_CFGR			0x

	#define CLEAR_MAGIC_AHB1RSRR	0x

	#define CLEAR_MAGIC_APB2RSRR	0x

	#define CLEAR_MAGIC_APB1RSRR	0x
/*------*/

/*Var*/
 //
/*---*/

/*Static function Prototypes*/ 
 //
/*---------------------------*/

/*Implementation*/

    /*For UserDev*/

		/*CLK Control functions*/	

			/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function for Enable any CLK>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				RCC_enuErrorStatus_t RCC_EnableClock			( U32 CLK_CLK )
                {
					RCC_enuErrorStatus_t RCC_enuErrorStatus = RCC_NOK;

					if ( CLK_CLK == CLK_HSI | CLK_CLK == CLK_HSE | CLK_CLK == CLK_PLL | CLK_CLK == CLK_PLLI2S )
					{
						RCC->CR |= ENABLE_CLK;
						RCC_enuErrorStatus = RCC_OK;
					}
					return RCC_enuErrorStatus;
                };
			/*-----------------------------------------------------------------------------------------*/

			/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function for Disaple any CLK>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				RCC_enuErrorStatus_t RCC_DisableClock			( U32 CLK_CLK )
				{
					RCC_enuErrorStatus_t RCC_enuErrorStatus = RCC_NOK;

					if ( CLK_CLK == CLK_HSI | CLK_CLK == CLK_HSE | CLK_CLK == CLK_PLL | CLK_CLK == CLK_PLLI2S )
					{
						RCC->CR &= ~CLK_CLK;
						RCC_enuErrorStatus = RCC_OK;
					}
					return RCC_enuErrorStatus;
				};
			/*------------------------------------------------------------------------------------------*/

			/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function for Configuration of PLL Prescalar>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				RCC_enuErrorStatus_t	RCC_PLL_SRCConfig	( U8 Copy_u8PLLM , U16 Copy_u16PLLN , U8 Copy_u8PLLQ , U8 Copy_u8PLLP )
				{
					U32 local_u32_PLLStatus;
					u32 local_u32_PLLStatus = RCC->CR & Bit22_Mask; // Is PLL Enabled?

					RCC_enuErrorStatus_t RCC_enuErrorStatus = RCC_NOK

						if (local_u32_PLLStatus)
						{
							RCC_enuErrorStatus = RCC_PLLON;
						}
						else 
						{

							if (Copy_u8PllM < 2 || Copy_u8PllM > 63)
							{
								RCC_enuErrorStatus = RCC_InputError;
							}

							else if (Copy_u16PLLN < 192 || Copy_u16PLLN > 432)
							{
								RCC_enuErrorStatus = RCC_InputError;
							}

							else if (Copy_u8PllQ < 2 || Copy_u8PllQ > 15)
							{
								RCC_enuErrorStatus = RCC_InputError;
							}

							else if (Copy_u8PLLP != 2 | Copy_u8PLLP != 4 | Copy_u8PLLP != 6 | Copy_u8PLLP != 8 )
							{
								RCC_enuErrorStatus = RCC_InputError;
							}

							else
							{
								Copy_u8PLLP = ( Copy_u8PLLP / 2 ) - 1;   // Coverting from 3 bit represetation to 2 bit representation to match data sheet specs
								
								local_u32_PLLStatus = Copy_u8PLLQ<<24 | Copy_u8PLLP<<16 | Copy_u16PLLN<<6 | Copy_u8PLLM<<0 ;
								RCC->PLLCFGR |= local_u32_PLLStatus;
								RCC_enuErrorStatus = RCC_OK;
							}

						}
						return RCC_enuErrorStatus;

				};
			/*-------------------------------------------------------------------------------------------*/		

			/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function for Reading any CLK Status>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				RCC_CLKStatus_t	RCC_ReadStatusClock				( U32 READ_CLK_STATUS )
				{
					RCC_CLKStatus_t RCC_CLKStatus = Wrong_Input;

					if ( READ_CLK_STATUS == READ_HSI_STATUS | READ_CLK_STATUS == READ_HSE_STATUS | READ_CLK_STATUS == READ_PLL_STATUS | READ_CLK_STATUS == READ_PLLI2S_STATUS )
					{
						local_u32_CLKStatus = RCC->CR & READ_CLK_STATUS;

						if (local_u32_CLKStatus)
						{
							RCC_CLKStatus = Ready;
						}

						else
						{
							RCC_CLKStatus = NotReady;
						}

					}
				};
			/*-------------------------------------------------------------------------------------------*/

			/*<<<<<<<<<<<<<<<<<<<<<Function to Choose the desired system clk source>>>>>>>>>>>>>>>>>>>>>*/
				RCC_enuErrorStatus_t RCC_SetSYSCLK 				( U32 SYSCLK_CLK )
				{
					RCC_enuErrorStatus_t RCC_enuErrorStatus = RCC_InputError;

					if ( SYSCLK_CLK == SYSCLK_HSI | SYSCLK_CLK == SYSCLK_HSE | SYSCLK_CLK == SYSCLK_PLL) 
					{
						RCC->CFGR |= SYSCLK_CLK;
						RCC_enuErrorStatus = RCC_OK;
					};
					
				};
			/*-------------------------------------------------------------------------------------------*/

			/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function to Reading SYSCLK source>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				RCC_enuErrorStatus_t RCC_ReadSYSCLKStatus 		( U32 SYSCLK_CLK )
				{
					
				};
			/*-------------------------------------------------------------------------------------------*/

		/*---------------------*/

		/*Peripheral Control*/
			
			/*AHB1*/

				/*AHB1 Set*/
					RCC_enuErrorStatus_t RCC_SetAHB1Peripheral		(U32 Copy_u32AHB1Peripheral)
					{

					};
				/*--------*/

				/*AHB1 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAHB1Peripheral	(U32 Copy_u32AHB1Peripheral)
					{

					};
				/*----------*/

			/*----*/

			/*AHB2*/

				/*AHB2 Set*/
					RCC_enuErrorStatus_t RCC_SetAHB2Peripheral		(U32 Copy_u32AHB1Peripheral)
					{

					};
				/*--------*/

				/*AHB2 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAHB2Peripheral	(U32 Copy_u32AHB1Peripheral)
					{

					};
				/*---------*/

			/*----*/

			/*APB1*/

				/*APB1 Set*/
					RCC_enuErrorStatus_t RCC_SetAPB1Peripheral		(U32 Copy_u32APB1Peripheral)
					{

					};
				/*--------*/

				/*APB1 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAPB1Peripheral	(U32 Copy_u32APB1Peripheral)
					{

					};
				/*----------*/

			/*----*/

			/*APB2*/

				/*APB2 Set*/
					RCC_enuErrorStatus_t RCC_SetAPB2Peripheral		(U32 Copy_u32APB2Peripheral)
					{

					};
				/*--------*/

				/*APB2 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAPB2Peripheral	(U32 Copy_u32APB2Peripheral)
					{
						
					};
				/*---------*/

			/*----*/
			
		/*------------------*/

	/*-----*/
    /*-----------*/

    /*For Dev only*/
        //
    /*------------*/

/*--------------*/

//FIXME Try it in eclipse