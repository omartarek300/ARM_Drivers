/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 13 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterrupt(u8 Copy_u8Interrupt_NUM)
{
	if(Copy_u8Interrupt_NUM <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8Interrupt_NUM);
	}
	else if(Copy_u8Interrupt_NUM <= 59)
	{
		NVIC_ISER1 = (1 << (Copy_u8Interrupt_NUM - 32));
	}
	else
	{
		/*Return Error*/
	}
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8Interrupt_NUM)
{
	if(Copy_u8Interrupt_NUM <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8Interrupt_NUM);
	}
	else if(Copy_u8Interrupt_NUM <= 59)
	{
		NVIC_ICER1 = (1 << (Copy_u8Interrupt_NUM - 32));
	}
	else
	{
		/*Return Error*/
	}
}
void MNVIC_voidSetPendingFlag(u8 Copy_u8Interrupt_NUM)
{
	if(Copy_u8Interrupt_NUM <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8Interrupt_NUM);
	}
	else if(Copy_u8Interrupt_NUM <= 59)
	{
		NVIC_ISPR1 = (1 << (Copy_u8Interrupt_NUM - 32));
	}
	else
	{
		/*Return Error*/
	}
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8Interrupt_NUM)
{
	if(Copy_u8Interrupt_NUM <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8Interrupt_NUM);
	}
	else if(Copy_u8Interrupt_NUM <= 59)
	{
		NVIC_ICPR1 = (1 << (Copy_u8Interrupt_NUM - 32));
	}
	else
	{
		/*Return Error*/
	}
}
u8 MNVIC_voidGetActiveFlag(u8 Copy_u8Interrupt_NUM)
{
	u8 local_u8Result;
	if(Copy_u8Interrupt_NUM <= 31)
	{
		local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8Interrupt_NUM);
	}
	else if(Copy_u8Interrupt_NUM <= 59)
	{
		local_u8Result = GET_BIT(NVIC_IABR0, (Copy_u8Interrupt_NUM - 32));
	}
	else
	{
		/*Return Error*/
	}
	return local_u8Result;
}

void MNVIC_voidSetPriority(s8 Copy_s8InterruptID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32Group)
{
	/* External Interrupt */
 	u8 Local_u8Priority = Copy_u8SubPriority|(Copy_u8GroupPriority << ((Copy_u32Group - MNVIC_GRP_4_SUB_0) / CONVERT_TO_DECIMAL));
	if(Copy_s8InterruptID >= 0)
	{
		NVIC_IPR[Copy_s8InterruptID] = (Local_u8Priority << MOST_SIGNIFICANT ); 
	}
	SCB_AIRCR = Copy_u32Group;
}
