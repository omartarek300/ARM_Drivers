/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 23 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#define TIMER1 0
#define TIMER2 1
#define TIMER3 2
#define TIMER4 3

#define CHANNEL1 0
#define CHANNEL2 1
#define CHANNEL3 2
#define CHANNEL4 3


#define UPCOUNTING_MODE      0
#define DOWNCOUNTING_MODE    1
#define CENTER_ALIGNED_MODE  2




/*---------------------------------------------------------------------*/
/*******
Function Description: This Function Initialize TIMER1 2 3 4
parameters: Copy_u8TimerNum       : Selects Which Timer To Be Used
			Copy_u8TimerMode	  : Selects Which Mode The Timer Will Operate On
			Copy_u16TimerPreScaler: Specifies The Value Of Prescaler
			Copy_u16TimerARRValue : Specifies The Value Of ARR_Register The Timer Will Count Until It
return: none
*/
void MTimer_voidInit(u8 Copy_u8TimerNum, u8 Copy_u8TimerMode, u16 Copy_u16TimerPreScaler, u16 Copy_u16TimerARRValue);


/*******
	Function Description: This Is A Callback Function Excutes a Specific Function Afte Timer Interrupt
	parameter: Copy_u8TimerNum: Selects Which Timer To Be Used
			   Ptr2Func: Pointer To Function Takes The Address Of The Upper Layer Function
	return: none
*/
void MTimer_voidSetCallBack(u8 Copy_u8TimerNum, void (*PTR2FUNC)(void));


/*******
	Function Description: This Function Initialize PWM Mode
	parameter: Copy_u8TimerNum : Selects Which Timer To Be Used
			   opy_u8ChannelNum: Selects Which Channel To Operate
	return: none
*/
void MTimer_voidEnablePWM(u8 Copy_u8TimerNum, u8 Copy_u8ChannelNum);


/*******
	Function Description: This Function Initialize PWM Mode
	parameter: Copy_u8TimerNum  : Selects Which Timer To Be Used
			   opy_u8ChannelNum : Selects Which Channel To Operate
			   Copy_u16DutyCycle: Set The Duty Cycle Of PWM Signal
	return: none
*/
void MTimer_voidSelectChannel(u8 Copy_u8TimerNum, u8 Copy_u8ChannelNum,u16 Copy_u16DutyCycle);

/*******
	Function Description: This Function Delays The Controller For Microseconds
	parameter: Copy_Time_US  : Number Of Microseconds Required For Delay
	return: none
*/
void MTimer_Delay_us(u16 Copy_Time_US);

/*******
	Function Description: This Function Delays The Controller For Milliseconds
	parameter: Copy_Time_MS  : Number Of Milliseconds Required For Delay
	return: none
*/
void MTimer_Delay_ms(u16 Copy_Time_MS);

#endif
  
