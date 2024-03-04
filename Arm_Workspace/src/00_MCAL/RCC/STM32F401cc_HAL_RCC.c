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
					volatile U32 AHB1ENR;
					volatile U32 AHB2ENR;
					volatile U32 Reserved5;
					volatile U32 Reserved6;
					volatile U32 APB1ENR;
					volatile U32 APB2ENR;
				}RCC_Peri_t;
			/*--------------*/

		/*-------*/
/*-----*/

/*Define*/
    #define RCC_u32BASEADDRESS 		 0x40023800

    #define RCC						((RCC_Peri_t* )(RCC_u32BASEADDRESS))

    #define CLEAR_MAGIC_CFGR		0x00000003

	#define CLEAR_MAGIC_AHBRSRR	    0x000000F0

	#define CLEAR_MAGIC_APB2RSRR	0x00001C00

	#define CLEAR_MAGIC_APB1RSRR	0x0000E000
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
				RCC_CLKStatus_t	RCC_ReadStatusClock				(     U32 READ_CLK_STATUS    )
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
				RCC_enuErrorStatus_t RCC_SetSYSCLK 				 (       U32 SYSCLK_CLK      )
				{
					RCC_enuErrorStatus_t RCC_enuErrorStatus = RCC_InputError;

					if ( SYSCLK_CLK == SYSCLK_HSI | SYSCLK_CLK == SYSCLK_HSE | SYSCLK_CLK == SYSCLK_PLL) 
					{
						local_u32_SYSCLK   =  RCC->CFGR;
						local_u32_SYSCLK  &= ~CLEAR_MAGIC_CFGR;
						local_u32_SYSCLK  |=  SYSCLK_CLK;
						RCC->CFGR          =  local_u32_SYSCLK;
						RCC_enuErrorStatus =  RCC_OK;
					};

				};
			/*-------------------------------------------------------------------------------------------*/

			/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function to Reading SYSCLK source>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				RCC_SYSCLKStatus_t RCC_ReadSYSCLKStatus 		    (                          )
				{
					RCC_SYSCLKStatus_t RCC_SYSCLKStatus;
					RCC_SYSCLKStatus = RCC->CFGR & SYSCLK_STATUS;

					return RCC_SYSCLKStatus;
				};
			/*-------------------------------------------------------------------------------------------*/

		/*---------------------*/

		/*Peripheral Control*/
			
			/*AHB1*/

				/*AHB1_PREscalar*/
					RCC_enuErrorStatus_t RCC_AHB_PREscaler			(    U32 AHB_PREscalar    )
					{
						RCC_enuErrorStatus RCC_enuErrorStatus_t = RCC_NOK;
						if(AHB_PREscalar == AHB_PRE_1 || AHB_PRE_2 || AHB_PRE_4 || AHB_PRE_8 || AHB_PRE_16 || AHB_PRE_64 || AHB_PRE_128 || AHB_PRE_256 || AHB_PRE_512 )
						{
							local_u32_AHB1_PREscalar   =  RCC->CFGR;
							local_u32_AHB1_PREscalar  &= ~CLEAR_MAGIC_CFGR;
							local_u32_AHB1_PREscalar  |=  AHB_PREscalar;
							RCC->CFGR                  =  local_u32_SYSCLK;
							RCC_enuErrorStatus         =  RCC_OK;
						}
					};
				/*--------------*/

				/*AHB1 Set*/
					RCC_enuErrorStatus_t RCC_SetAHB1Peripheral		(     U32 AHB1ENR_PERI     )
					{
						RCC->AHB1RSTR |= AHB1ENR_PERI;
					};
				/*--------*/

				/*AHB1 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAHB1Peripheral	(     U32 AHB1ENR_PERI     )
					{
						RCC->AHB1RSTR &= ~AHB1ENR_PERI;
					};
				/*----------*/

			/*----*/

			/*AHB2*/

				/*AHB2 Set*/
					RCC_enuErrorStatus_t RCC_SetAHB2Peripheral		(      U32 AHB2ENR_PERI    )
					{
						RCC->AHB2RSTR |= AHB2ENR_PERI;
					};
				/*--------*/

				/*AHB2 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAHB2Peripheral	(      U32 AHB2ENR_PERI    )
					{
						RCC->AHB2RSTR &= ~AHB2ENR_PERI;
					};
				/*---------*/

			/*----*/

			/*APB1*/

				/*APB1_PREscalar*/
					RCC_enuErrorStatus_t RCC_APB1_PREscaler			(    U32 APB1_PREscalar    )
					{
						RCC_enuErrorStatus RCC_enuErrorStatus_t = RCC_NOK;
						if(APB1_PREscalar == APB_PRE1_1 || APB_PRE1_2 || APB_PRE1_4 || APB_PRE1_8 || APB_PRE1_16 )
						{
							local_u32_APB1_PREscalar   =  RCC->CFGR;
							local_u32_AHB1_PREscalar  &= ~CLEAR_MAGIC_CFGR;
							local_u32_AHB1_PREscalar  |=  APB1_PREscalar;
							RCC->CFGR                  =  local_u32_AHB1_PREscalar;
							RCC_enuErrorStatus         =  RCC_OK;
						}						
					};
				/*--------------*/	

				/*APB1 Set*/
					RCC_enuErrorStatus_t RCC_SetAPB1Peripheral		(      U32 AP1ENR_PERI     )
					{
						RCC->APB1RSTR |= AP1ENR_PERI;
					};
				/*--------*/

				/*APB1 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAPB1Peripheral	(     U32 AP1ENR_PERI      )
					{
						RCC->APB1RSTR &= ~AP1ENR_PERI;
					};
				/*----------*/

			/*----*/

			/*APB2*/

				/*APB2_PREscalar*/
					RCC_enuErrorStatus_t RCC_APB2_PREscaler			(    U32 APB2_PREscalar    )
					{
						RCC_enuErrorStatus RCC_enuErrorStatus_t = RCC_NOK;
						if(APB2_PREscalar == APB_PRE2_1 || APB_PRE2_2 || APB_PRE2_4 || APB_PRE2_8 || APB_PRE2_16 )
						{
							local_u32_APB2_PREscalar   =  RCC->CFGR;
							local_u32_APB2_PREscalar  &= ~CLEAR_MAGIC_CFGR;
							local_u32_APB2_PREscalar  |=  APB2_PREscalar;
							RCC->CFGR                  =  local_u32_APB2_PREscalar;
							RCC_enuErrorStatus         =  RCC_OK;
						}							
					};
				/*--------------*/				

				/*APB2 Set*/
					RCC_enuErrorStatus_t RCC_SetAPB2Peripheral		(      U32 AP2ENR_PERI      )
					{
						RCC->APB2RSTR |= AP2ENR_PERI;
					};
				/*--------*/

				/*APB2 Reset*/
					RCC_enuErrorStatus_t RCC_ResetAPB2Peripheral	(       U32 AP2ENR_PERI     )
					{
						RCC->APB2RSTR &= ~AP2ENR_PERI;						
					};
				/*---------*/

			/*----*/
			
		/*------------------*/

	/*-----------*/

    /*For Dev only*/
        // put your static functions here
    /*------------*/

/*--------------*/

//FIXME Try it in eclipse