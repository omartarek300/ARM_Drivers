/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 24 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PWM_interface.h"
#include "PWM_config.h"
#include "PWM_private.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"


void HPWM_voidInitPWM(u8 Copy_u8TimerNum,u8 Copy_u8ChannelNum,u16 Copy_u16TimerPreScaler, u16 Copy_u16TimerARRValue)
{
	MTimer_voidInit(Copy_u8TimerNum, UPCOUNTING_MODE, Copy_u16TimerPreScaler, Copy_u16TimerARRValue);
	MTimer_voidEnablePWM(Copy_u8TimerNum, Copy_u8ChannelNum);
}

void HPWM_voidWritePWM(u8 Copy_u8TimerNum ,u8 Copy_u8ChannelNum, u16 Copy_u16DutyCycle)
{
	MTimer_voidSelectChannel(Copy_u8TimerNum, Copy_u8ChannelNum,Copy_u16DutyCycle);
	
	if(Copy_u8TimerNum ==  TIMER1)
	{
		/*Enable GPIOA Clocks*/
		RCC_voidEnableClock(RCC_APB2, 2);
		
		if(Copy_u8ChannelNum == CHANNEL1)
		{
			/*Set Pin As Alternative Function*/
			DIO_voidSetPinDirection(GPIOA, PIN8, OUTPUT_SPEED_50MHZ_AFPP);
		}
		else if(Copy_u8ChannelNum == CHANNEL2)
		{
			/*Set Pin As Alternative Function*/
			DIO_voidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_50MHZ_AFPP);
		}
		else if(Copy_u8ChannelNum == CHANNEL3)
		{
			/*Set Pin As Alternative Function*/
			DIO_voidSetPinDirection(GPIOA, PIN10, OUTPUT_SPEED_50MHZ_AFPP);
		}
		else if(Copy_u8ChannelNum == CHANNEL4)
		{
			/*Set Pin As Alternative Function*/
			DIO_voidSetPinDirection(GPIOA, PIN11, OUTPUT_SPEED_50MHZ_AFPP);
		}
		
	}
	else if(Copy_u8TimerNum ==  TIMER2)
	{
		/*Enable GPIOA Clocks*/
		RCC_voidEnableClock(RCC_APB2, 2);

		if(Copy_u8ChannelNum == CHANNEL1)
		{
			/*Set Pin As Alternative Function*/
			DIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_50MHZ_AFPP);
		}
		else if(Copy_u8ChannelNum == CHANNEL2)
		{
			/*Set Pin As Alternative Function*/
			DIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_50MHZ_AFPP);
		}
	    else if(Copy_u8ChannelNum == CHANNEL3)
		{
			/*Set Pin As Alternative Function*/
			DIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_50MHZ_AFPP);
		}
	    else if(Copy_u8ChannelNum == CHANNEL4)
		{
			/*Set Pin As Alternative Function*/
			DIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_50MHZ_AFPP);
		}

	}
	else if(Copy_u8TimerNum ==  TIMER3)
		{
			/*Enable GPIOA Clocks*/
			RCC_voidEnableClock(RCC_APB2, 2);

			/*Enable GPIOB Clocks*/
			RCC_voidEnableClock(RCC_APB2, 3);

			if(Copy_u8ChannelNum == CHANNEL1)
			{
				/*Set Pin As Alternative Function*/
				DIO_voidSetPinDirection(GPIOA, PIN6, OUTPUT_SPEED_50MHZ_AFPP);
			}
			else if(Copy_u8ChannelNum == CHANNEL2)
			{
				/*Set Pin As Alternative Function*/
				DIO_voidSetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_50MHZ_AFPP);
			}
		    else if(Copy_u8ChannelNum == CHANNEL3)
			{
				/*Set Pin As Alternative Function*/
				DIO_voidSetPinDirection(GPIOB, PIN0, OUTPUT_SPEED_50MHZ_AFPP);
			}
		    else if(Copy_u8ChannelNum == CHANNEL4)
			{
				/*Set Pin As Alternative Function*/
				DIO_voidSetPinDirection(GPIOB, PIN1, OUTPUT_SPEED_50MHZ_AFPP);
			}

		}
	else if(Copy_u8TimerNum ==  TIMER4)
			{
				/*Enable GPIOB Clocks*/
				RCC_voidEnableClock(RCC_APB2, 3);

				if(Copy_u8ChannelNum == CHANNEL1)
				{
					/*Set Pin As Alternative Function*/
					DIO_voidSetPinDirection(GPIOB, PIN6, OUTPUT_SPEED_50MHZ_AFPP);
				}
				else if(Copy_u8ChannelNum == CHANNEL2)
				{
					/*Set Pin As Alternative Function*/
					DIO_voidSetPinDirection(GPIOB, PIN7, OUTPUT_SPEED_50MHZ_AFPP);
				}
			    else if(Copy_u8ChannelNum == CHANNEL3)
				{
					/*Set Pin As Alternative Function*/
					DIO_voidSetPinDirection(GPIOB, PIN8, OUTPUT_SPEED_50MHZ_AFPP);
				}
			    else if(Copy_u8ChannelNum == CHANNEL4)
				{
					/*Set Pin As Alternative Function*/
					DIO_voidSetPinDirection(GPIOB, PIN9, OUTPUT_SPEED_50MHZ_AFPP);
				}

			}
	
}
