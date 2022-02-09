/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 18 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#ifndef STK_INTERFACE_H
#define SRK_INTERFACE_H


/*******
Function Description: This Function Apply Clock Choice From Configuration File
                      Disables Interrupt And Sys_Tick
parameters:none
return: none
*/
void MSTK_voidInit(void);

/*******
Function Description: This Function Provides Busy Wait Utility(Delay / Synchronous Function)
parameters: Copy_u8Ticks: Number Of Ticks Or Counts
return: none
*/
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

/*******
Function Description: This Function Let Sys_Tick Counts For One Intervel Asynchrounsly Then Give An Interrupt Using CallBack
parameters:  Copy_u32Ticks    : Number Of Ticks Or Counts
			*Copy_PTR2FUNC   : Pointer To Void Function To Be Executed After Finishing Counting 
return: none
*/
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_PTR2FUNC)(void));

/*******
Function Description: This Function Let Sys_Tick Counts For Many Intervels Asynchrounsly Then Give An Interrupt Using CallBack
parameters:  Copy_u32Ticks    : Number Of Ticks Or Counts
			*Copy_PTR2FUNC   : Pointer To Void Function To Be Executed After Finishing Counting 
return: none
*/
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_PTR2FUNC)(void));

/*******
Function Description: This Function Stops Sys_Tick From Periodic Counting
parameters: none
return: none
*/
void MSTK_voidStopInterval(void);

/*******
Function Description: This Function Gets Elapsed Time From Counting
parameters: none
return: none
*/
u32 MSTK_u32GetElapsedTime(void);

/*******
Function Description: This Function Gets Remainig Time From Counting
parameters: none
return: none
*/
u32 MSTK_u32GetRemainingTime(void);
#endif
  