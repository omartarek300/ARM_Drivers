/**************************************************************/
/* Author   : Omar Tarek                                      */
/* Date     : 7 NOV 2021                                      */
/* Version  : V01                                             */
/**************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE   == RCC_HSE_CRYSTAL 
		RCC_CR  = 0x00010000; /* Enable HSE with no bypass*/
		RCC_CFGR = 0x00000001;
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR  = 0x00050000; /* Enable HSE with bypass*/
		RCC_CFR = 0x00000001;
	#elif RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR  = 0x00000081; /* Enable HSI */
		RCC_CFR = 0x00000000;
	
	#elif RCC_CLOCK_TYPE == RCC_PLL
		RCC_CR = 0x01000000;
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			RCC_CFR = 0x00000000;
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			RCC_CFR = 0x00030000;
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			RCC_CFR = 0x00010000;
		#endif
	#else
		#error("You chosed Wrong Clock type")
	#endif
}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId )
{
	if (Copy_u8BusId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB : SET_BIT(RCC_AHBENR, Copy_u8PerId) ; break;
			case RCC_APB1: SET_BIT(RCC_APB1ENR, Copy_u8PerId); break;
			case RCC_APB2: SET_BIT(RCC_APB2ENR, Copy_u8PerId); break;
			//default : /*Return Error*/                         break;
		}
	}
	else
	{
		/*Return Error*/
	}
} 

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId )
{
	if (Copy_u8BusId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB : CLR_BIT(RCC_AHBENR, Copy_u8PerId) ; break;
			case RCC_APB1: CLR_BIT(RCC_APB1ENR, Copy_u8PerId); break;
			case RCC_APB2: CLR_BIT(RCC_APB2ENR, Copy_u8PerId); break;
			//default : /*Return Error*/                         break;
		}
	}
	else
	{
		/*Return Error*/
	}
}
