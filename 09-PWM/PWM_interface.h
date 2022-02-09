/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 24 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H


/*******
	Function Description: This Function Writes PWM on A Specific Pin
	parameter: Copy_u8TimerNum   : Selects Which Timer To Be Used
			   opy_u8ChannelNum  : Selects Which Channel To Operate
			   Copy_u16DutyCycle : Set The Duty Cycle Of PWM Signal
			   u8 Copy_u8PortName: Specify Which Port
			   u8 Copy_u8PinNum  : Specify Which Pin
	return: none
*/
void HPWM_voidWritePWM(u8 Copy_u8TimerNum ,u8 Copy_u8ChannelNum, u16 Copy_u16DutyCycle);


void HPWM_voidInitPWM(u8 Copy_u8TimerNum,u8 Copy_u8ChannelNum,u16 Copy_u16TimerPreScaler, u16 Copy_u16TimerARRValue);

#endif
  
