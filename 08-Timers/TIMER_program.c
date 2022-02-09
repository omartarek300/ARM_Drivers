/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 23 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"



static void(*Timer1_CallBack_PTR)(void);
static void(*Timer2_CallBack_PTR)(void);
static void(*Timer3_CallBack_PTR)(void);
static void(*Timer4_CallBack_PTR)(void);
void MTimer_voidInit(u8 Copy_u8TimerNum, u8 Copy_u8TimerMode, u16 Copy_u16TimerPreScaler, u16 Copy_u16TimerARRValue)
{
	/* Selecting Which Timer Will Operate*/
	if(Copy_u8TimerNum == TIMER1)
	{
		/* Select Timer 1 */
		TIMERx = (volatile TIMER_t*) TIMER1_BASE_ADDRESS;
		
		/* Select Timer Mode */
		if(Copy_u8TimerMode == UPCOUNTING_MODE)
		{
			/* SET UPCOUNTING_MODE */
			CLR_BIT(TIMERx->TIM_CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->TIM_PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->TIM_ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->TIM_CR1, 0);
		}
		else if(Copy_u8TimerMode ==  DOWNCOUNTING_MODE)
		{
			/* SET DOWNCOUNTING_MODE */
			SET_BIT(TIMERx->TIM_CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->TIM_PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->TIM_ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->TIM_CR1, 0);
		}
		else if(Copy_u8TimerMode ==  CENTER_ALIGNED_MODE)
		{
			
		}
	}
	else if(Copy_u8TimerNum == TIMER2)
	{
		/* Select Timer 2*/
		TIMERx = (volatile TIMER_t*) TIMER2_BASE_ADDRESS;
		
		/* Select Timer Mode */
		if(Copy_u8TimerMode == UPCOUNTING_MODE)
		{
			/* SET UPCOUNTING_MODE */
			CLR_BIT(TIMERx->TIM_CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->TIM_PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->TIM_ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->TIM_CR1, 0);
		}
		else if(Copy_u8TimerMode ==  DOWNCOUNTING_MODE)
		{
			/* SET DOWNCOUNTING_MODE */
			SET_BIT(TIMERx->TIM_CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->TIM_PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->TIM_ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->TIM_CR1, 0);
		}
		else if(Copy_u8TimerMode ==  CENTER_ALIGNED_MODE)
		{
			
		}
	}
	else if(Copy_u8TimerNum == TIMER3)
	{
		/* Select Timer 3*/
		TIMERx = (volatile TIMER_t*)TIMER3_BASE_ADDRESS;
		
		/* Select Timer Mode */
		if(Copy_u8TimerMode == UPCOUNTING_MODE)
		{
			/* SET UPCOUNTING_MODE */
			CLR_BIT(TIMERx->TIM_CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->TIM_PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->TIM_ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->TIM_CR1, 0);
		}
		else if(Copy_u8TimerMode ==  DOWNCOUNTING_MODE)
		{
			/* SET DOWNCOUNTING_MODE */
			SET_BIT(TIMERx->TIM_CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->TIM_PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->TIM_ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->TIM_CR1, 0);
		}
		else if(Copy_u8TimerMode ==  CENTER_ALIGNED_MODE)
		{
			
		}
	}
	else if(Copy_u8TimerNum == TIMER4)
	{
		/* Select Timer 4*/
		TIMERx = (volatile TIMER_t*)TIMER4_BASE_ADDRESS;
		
		/* Select Timer Mode */
		if(Copy_u8TimerMode == UPCOUNTING_MODE)
		{
			/* SET UPCOUNTING_MODE */
			CLR_BIT(TIMERx->TIM_CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->TIM_PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->TIM_ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->TIM_CR1, 0);
		}
		else if(Copy_u8TimerMode ==  DOWNCOUNTING_MODE)
		{
			/* SET DOWNCOUNTING_MODE */
			SET_BIT(TIMERx->TIM_CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->TIM_PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->TIM_ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->TIM_CR1, 0);
		}
		else if(Copy_u8TimerMode ==  CENTER_ALIGNED_MODE)
		{
			
		}
	}
	
}

void MTimer_voidSetCallBack(u8 Copy_u8TimerNum, void (*PTR2FUNC)(void))
{
	if(Copy_u8TimerNum == TIMER1)
	{
		Timer1_CallBack_PTR = PTR2FUNC;
	}
	else if(Copy_u8TimerNum == TIMER2)
	{
		Timer2_CallBack_PTR = PTR2FUNC;
	}
	else if(Copy_u8TimerNum == TIMER3)
	{
		Timer3_CallBack_PTR = PTR2FUNC;
	}
	else if(Copy_u8TimerNum == TIMER4)
	{
		Timer4_CallBack_PTR = PTR2FUNC;
	}		
}

void MTimer_voidEnablePWM(u8 Copy_u8TimerNum, u8 Copy_u8ChannelNum)
{
	
	if(Copy_u8TimerNum == TIMER1)
	{
		/* Select Timer 1 */
		TIMERx = (volatile TIMER_t*) TIMER1_BASE_ADDRESS;
		
		/* ENABLE Auto-reload preload enable */
		SET_BIT(TIMERx->TIM_CR1, 7);
		
		/* PWM Mode 1 */
		CLR_BIT(TIMERx->TIM_CCMR1, 4);
		SET_BIT(TIMERx->TIM_CCMR1, 5);
		SET_BIT(TIMERx->TIM_CCMR1, 6);
		
		/* ENABLE Preload Enable */
		SET_BIT(TIMERx->TIM_CCMR1, 3);
		
		/*Re-initialize the counter */
		SET_BIT(TIMERx->TIM_EGR, 0);
		
		SET_BIT(TIMERx->TIM_BDTR, 15);
		/* ENABLE TIMER */
		//SET_BIT(TIMERx->TIM_CR1, 0);
	}
	else if(Copy_u8TimerNum == TIMER2)
	{
		/* Select Timer 2 */
		TIMERx = (volatile TIMER_t*) TIMER2_BASE_ADDRESS;
		
		/* ENABLE Auto-reload preload enable */
		SET_BIT(TIMERx->TIM_CR1, 7);
		
		/* PWM Mode 1 */
		CLR_BIT(TIMERx->TIM_CCMR1, 12);
		SET_BIT(TIMERx->TIM_CCMR1, 13);
		SET_BIT(TIMERx->TIM_CCMR1, 14);
		
		/* ENABLE Preload Enable */
		SET_BIT(TIMERx->TIM_CCMR1, 11);
		
		/*Re-initialize the counter */
		SET_BIT(TIMERx->TIM_EGR, 0);
	}
	else if(Copy_u8TimerNum == TIMER3)
	{
		/* Select Timer 3 */
		TIMERx = (volatile TIMER_t*) TIMER3_BASE_ADDRESS;
		
		/* ENABLE Auto-reload preload enable */
		SET_BIT(TIMERx->TIM_CR1, 7);
		
		/* PWM Mode 1 */
		CLR_BIT(TIMERx->TIM_CCMR2, 4);
		SET_BIT(TIMERx->TIM_CCMR2, 5);
		SET_BIT(TIMERx->TIM_CCMR2, 6);
		
		/* ENABLE Preload Enable */
		SET_BIT(TIMERx->TIM_CCMR1, 3);
		
		/*Re-initialize the counter */
		SET_BIT(TIMERx->TIM_EGR, 0);
	}
	else if(Copy_u8TimerNum == TIMER4)
	{
		/* Select Timer 4 */
		TIMERx = (volatile TIMER_t*) TIMER4_BASE_ADDRESS;
		
		/* ENABLE Auto-reload preload enable */
		SET_BIT(TIMERx->TIM_CR1, 7);
		
		/* PWM Mode 1 */
		CLR_BIT(TIMERx->TIM_CCMR2, 12);
		SET_BIT(TIMERx->TIM_CCMR2, 13);
		SET_BIT(TIMERx->TIM_CCMR2, 14);
		
		/* ENABLE Preload Enable */
		SET_BIT(TIMERx->TIM_CCMR2, 11);
		
		/*Re-initialize the counter */
		SET_BIT(TIMERx->TIM_EGR, 0);
	}
	if(Copy_u8ChannelNum == CHANNEL1)
	{
	    SET_BIT(TIMERx->TIM_CCER, 0);
	}
	else if(Copy_u8ChannelNum == CHANNEL2)
	{
		SET_BIT(TIMERx->TIM_CCER, 4);
	}
	else if(Copy_u8ChannelNum == CHANNEL3)
	{
		SET_BIT(TIMERx->TIM_CCER, 8);
	}
	else if(Copy_u8ChannelNum == CHANNEL4)
	{
		SET_BIT(TIMERx->TIM_CCER, 11);
	}

}

void MTimer_voidSelectChannel(u8 Copy_u8TimerNum, u8 Copy_u8ChannelNum,u16 Copy_u16DutyCycle)
{
	if(Copy_u8TimerNum == TIMER1)
	{
		/* Select Timer 1 */
		TIMERx = (volatile TIMER_t*) TIMER1_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIMER2)
	{
		/* Select Timer 2 */
		TIMERx = (volatile TIMER_t*) TIMER2_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIMER3)
	{
		/* Select Timer 3 */
		TIMERx = (volatile TIMER_t*) TIMER3_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIMER4)
	{
		/* Select Timer 4 */
		TIMERx = (volatile TIMER_t*) TIMER4_BASE_ADDRESS;
	}
	if(Copy_u8ChannelNum == CHANNEL1)
			{
				TIMERx->TIM_CCR1 = Copy_u16DutyCycle;
			}
			else if(Copy_u8ChannelNum == CHANNEL2)
			{
				TIMERx->TIM_CCR2 = Copy_u16DutyCycle;
			}
			else if(Copy_u8ChannelNum == CHANNEL3)
			{
				TIMERx->TIM_CCR3 = Copy_u16DutyCycle;
			}
			else if(Copy_u8ChannelNum == CHANNEL4)
			{
				TIMERx->TIM_CCR4 = Copy_u16DutyCycle;
			}
}


void TIM1_IRQHandler(void)
{
	Timer1_CallBack_PTR();
}
void TIM2_IRQHandler(void)
{
	Timer2_CallBack_PTR();
}
void TIM3_IRQHandler(void)
{
	Timer3_CallBack_PTR();
}
void TIM4_IRQHandler(void)
{
	Timer4_CallBack_PTR();
}	
