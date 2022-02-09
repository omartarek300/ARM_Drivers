/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 14 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void MEXTI_voidInit()
{
	#if   EXTI_MODE == RISING
		SET_BIT(EXTI_PTR ->EXTI_RTSR, EXTI_LINE);
	#elif EXTI_MODE == FALLING	
		SET_BIT(EXTI_PTR ->EXTI_FTSR, EXTI_LINE);
	#elif EXTI_MODE == ON_CHANGE
		SET_BIT(EXTI_PTR ->EXTI_RTSR, EXTI_LINE);
		SET_BIT(EXTI_PTR ->EXTI_FTSR, EXTI_LINE);
	#else #error "Wrong Mode and Line Choice"
	#endif
	/* Disable Interrupt */
	MEXTI_voidDisableEXTI(EXTI_LINE);
}
void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI_PTR ->EXTI_IMR, Copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI_PTR ->EXTI_IMR, Copy_u8Line);
}
void MEXTI_voidSWTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI_PTR ->EXTI_SWIER, Copy_u8Line);
}
void MEXTI_voidSetMode(u8 Copy_u8Line, u8 Copy_u8Mode)
{
  switch(Copy_u8Mode)
  {
	 case RISING:
		SET_BIT(EXTI_PTR ->EXTI_RTSR, Copy_u8Line);
		break;
	 case FALLING:
		SET_BIT(EXTI_PTR ->EXTI_FTSR, Copy_u8Line);
		break;
	 case ON_CHANGE:
		SET_BIT(EXTI_PTR ->EXTI_RTSR, Copy_u8Line);
		SET_BIT(EXTI_PTR ->EXTI_FTSR, Copy_u8Line);
		break;
  }	  
}