/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 14 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"


void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap)
{
	u8 Local_u8RegIndex = 0;
	if(Copy_u8Line <= 3)
	{
		Local_u8RegIndex = 0;
	}
	else if(Copy_u8Line <= 7)
	{
		Local_u8RegIndex = 1;
		Copy_u8Line = Copy_u8Line - 4;
	}
	else if(Copy_u8Line <= 11)
	{
		Local_u8RegIndex = 2;
		Copy_u8Line = Copy_u8Line - 8;
	}
	else if(Copy_u8Line <= 15)
	{
		Local_u8RegIndex = 3;
		Copy_u8Line = Copy_u8Line - 12;
	}
	/* Clearing Bits Before Writing On it */
	AFIO_PTR->AFIO_EXTICR[Local_u8RegIndex] &~ = ((0b1111)<<(Copy_u8Line * 4));
	/* Selecting Which Pin For EXTI */
	AFIO_PTR->AFIO_EXTICR[Local_u8RegIndex] |  = ((Copy_u8PortMap)<<(Copy_u8Line * 4));
}