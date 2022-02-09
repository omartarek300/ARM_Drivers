/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 18 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"

/*Global Variable For Interval Mode*/
static u8 STK_u8IntervalMode;

/*Global Pointer To Function For The CallBack*/
static void (*STK_PTR_CallBack)(void);

void MSTK_voidInit(void)
{
	#if STK_CLOCK == STK_CLK_AHB_8
		/* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
		STK_PTR->STK_CTRL = 0;
	#else 
		/* Disable STK - Disable STK Interrupt - Set clock source AHB */
		STK_PTR->STK_CTRL = 0x00000004;
	#endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/*Load Number Of Ticks In Load Register*/
	STK_PTR->STK_LOAD = Copy_u32Ticks;
	
	/*Start Timer*/
	SET_BIT(STK_PTR->STK_CTRL, 0);
	
	/*Loop Till Flag is Raised*/
	while((GET_BIT(STK_PTR->STK_CTRL, 16)) == 0);
	
	/*Stop Timer*/
	SET_BIT(STK_PTR->STK_CTRL, 0);
	STK_PTR->STK_LOAD = 0;
	STK_PTR->STK_VAL  = 0;
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_PTR2FUNC)(void))
{
	/*Load Number Of Ticks In Load Register*/
	STK_PTR->STK_LOAD = Copy_u32Ticks;
	
	/*Start Timer*/
	SET_BIT(STK_PTR->STK_CTRL, 0);
	
	/*Set Interval Mode To Single*/
	STK_u8IntervalMode = STK_SINGLE_INTERVAL;
	
	/*Set The CallBack*/
	STK_PTR_CallBack = Copy_PTR2FUNC;
	
	/*Enable Interrupt*/
	SET_BIT(STK_PTR->STK_CTRL, 1);
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_PTR2FUNC)(void))
{
	/*Load Number Of Ticks In Load Register*/
	STK_PTR->STK_LOAD = Copy_u32Ticks;
	
	/*Start Timer*/
	SET_BIT(STK_PTR->STK_CTRL, 0);
	
	/*Set Interval Mode To Periodic*/
	STK_u8IntervalMode = STK_PERIODIC_INTERVAL;
	
	/*Set The CallBack*/
	STK_PTR_CallBack = Copy_PTR2FUNC;
	
	/*Enable Interrupt*/
	SET_BIT(STK_PTR->STK_CTRL, 1);
}

void MSTK_voidStopInterval(void)
{
	/*Enable Interrupt*/
	CLR_BIT(STK_PTR->STK_CTRL, 1);
	
	/*Stop Timer*/
	SET_BIT(STK_PTR->STK_CTRL, 0);
	STK_PTR->STK_LOAD = 0;
	STK_PTR->STK_VAL  = 0;
}

u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime = 0;
	Local_u32ElapsedTime = (STK_PTR->STK_LOAD -  STK_PTR->STK_VAL);
	return Local_u32ElapsedTime;
}

u32 MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainigTime = 0;
	Local_u32RemainigTime = (STK_PTR->STK_VAL);
	return Local_u32RemainigTime;
}
void SysTick_Handler(void)
{
	u8 local_u8Temp =0;
	if(STK_u8IntervalMode == STK_SINGLE_INTERVAL)
	{
		/*Disable Interrupt*/
		CLR_BIT(STK_PTR->STK_CTRL, 1);
		
		/*Stop Timer*/
		SET_BIT(STK_PTR->STK_CTRL, 0);
		STK_PTR->STK_LOAD = 0;
		STK_PTR->STK_VAL  = 0;
	}
	/*Trigger The CallBack Function*/
	STK_PTR_CallBack();
	
	/*Read Interrupt Flag*/
	local_u8Temp = GET_BIT(STK_PTR->STK_CTRL, 16);
}

