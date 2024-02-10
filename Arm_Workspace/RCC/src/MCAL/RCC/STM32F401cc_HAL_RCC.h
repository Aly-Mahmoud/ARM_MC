/*
 * STM32F401cc_HAL_RCC.h
 *
 *  Created on: Feb 5, 2024
 *      Author: Aly Mahmoud
 */

#ifndef MCAL_RCC_STM32F401CC_HAL_RCC_H_
	#define MCAL_RCC_STM32F401CC_HAL_RCC_H_

	#include "Std_Types.h"

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

		}RCC;
	/*--------------*/



	/*Simple Reg definitions*/

		#define RCC_CR 			*((volatile uint32*)0x40023800)  
		#define RCC_PLLCFGR 	*((volatile uint32*)0x40023804)
		#define RCC_CFGR 		*((volatile uint32*)0x40023808)
		#define RCC_CIR 		*((volatile uint32*)0x4002380C)
		#define RCC_AHB1RSTR 	*((volatile uint32*)0x40023810)
		#define RCC_AHB2RSTR 	*((volatile uint32*)0x40023814)
		#define RCC_APB1RSTR 	*((volatile uint32*)0x40023820)
		#define RCC_APB2RSTR	*((volatile uint32*)0x40023824)
		#define RCC_AHB1ENR		*((volatile uint32*)0x40023830)
		#define RCC_AHB2ENR     *((volatile uint32*)0x40023834) 
		#define RCC_APB1ENR     *((volatile uint32*)0x40023840) 
		#define RCC_APB2ENR     *((volatile uint32*)0x40023844)
		#define RCC_AHB1LPENR   *((volatile uint32*)0x40023850)
		#define RCC_AHB2LPENR   *((volatile uint32*)0x40023854)
		#define RCC_APB1LPENR   *((volatile uint32*)0x40023860)
		#define RCC_APB2LPENR   *((volatile uint32*)0x40023864)
		#define RCC_BDCR        *((volatile uint32*)0x40023870)
		#define RCC_CSR			*((volatile uint32*)0x40023874)
		#define RCC_SSCGR       *((volatile uint32*)0x40023880)
		#define RCC_PLLI2SCFGR  *((volatile uint32*)0x40023884)
		#define RCC_DCKCFGR     *((volatile uint32*)0x4002388C)

	/*-----------------------*/

	/*Mask for Registers*/

		/*RCCCR*/

			#define RCCCR_RESMASK 		 	0x00000081

			#define RCCCR_INIT 	 		 	0x01090081      	 //All CLK ON but PLL

			#define RCC_CR_HSI_ON			SET_BIT(RCC_CR,0)
			#define RCC_CR_HSI_OFF			CLR_BIT(RCC_CR,0)

			#define RCC_CR_HSE_ON			SET_BIT(RCC_CR,16)
			#define RCC_CR_HSE_OFF			CLR_BIT(RCC_CR,16)

			#define RCC_CR_CSS_ON			SET_BIT(RCC_CR,19)
			#define RCC_CR_CSS_OFF			CLR_BIT(RCC_CR,19)

			#define RCC_CR_PLL_ON			SET_BIT(RCC_CR,24)
			#define RCC_CR_PLL_OFF			CLR_BIT(RCC_CR,24)

		/*-----*/

		/*RCC_PLLCFGR*/
			#define RCC_PLLCFGR_RESMASK 	0x24003010

			#define RCC_PLLCFGR_MYMASK  	0x
		/*-----------*/


	/*------------------*/

	/*Function for enabling any CLK*/
		CLK_Control( CLK_SOURCE , CLK_State );
	/*-----------------------------*/

	/*Function for Configuration of PLL*/
		
	/*---------------------------------*/

	/*Select system CLK from */
		1
	/*-----------------------*/

	/*Enable Perpherial*/
		1
	/*-----------------*/


#endif /* MCAL_RCC_STM32F401CC_HAL_RCC_H_ */
