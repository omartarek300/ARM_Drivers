/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 13 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#define MNVIC_GRP_4_SUB_0  0X05FA0300 // 4 Bits For Group (IPR)
#define MNVIC_GRP_3_SUB_1  0X05FA0400 // 3 Bits For Group (IPR)
#define MNVIC_GRP_2_SUB_2  0X05FA0500 // 2 Bits For Group (IPR)
#define MNVIC_GRP_1_SUB_3  0X05FA0600 // 1 Bits For Group (IPR)
#define MNVIC_GRP_0_SUB_4  0X05FA0700 // 0 Group 4 Bits For Sub Priority

/*******
Function Description:    This Function Enables External Interrupts
parameters:  			 Copy_u8Interrupt_NUM: The Number Of Interrupt To Be Enabled
return: none
*/
void MNVIC_voidEnableInterrupt  (u8 Copy_u8Interrupt_NUM);

/*******
Function Description:    This Function Disables External Interrupts
parameters:  			 Copy_u8Interrupt_NUM: The Number Of Interrupt To Be Disabled
return: none
*/
void MNVIC_voidDisableInterrupt (u8 Copy_u8Interrupt_NUM);

/*******
Function Description:    This Function Sets The Pending Flag For Interrupt (For Debuging)
parameters:  			 Copy_u8Interrupt_NUM: The Number Of Interrupt To Be in Pending Status
return: none
*/
void MNVIC_voidSetPendingFlag   (u8 Copy_u8Interrupt_NUM);

/*******
Function Description:    This Function Clears The Pending Flag For Interrupt (For Debuging)
parameters:  			 Copy_u8Interrupt_NUM: The Number Of Interrupt To Cancel Its Pending Status
return: none
*/
void MNVIC_voidClearPendingFlag (u8 Copy_u8Interrupt_NUM);

/*******
Function Description:    This Function Gets The Status Of Active Flag
parameters:  			 Copy_u8Interrupt_NUM: The Number Of Interrupt To Check Its Status
return: u8 Active Interrupt Flag Status
*/
u8 MNVIC_voidGetActiveFlag      (u8 Copy_u8Interrupt_NUM);

/*******
Function Description:    This Function Sets Interrupts Priority
parameters:  			 Copy_s8InterruptID  : The ID Of The Interrupt From ST DataSheet
						 Copy_u8GroupPriority: The Specified Group ID
						 Copy_u8SubPriority  : The Specified SubGroup ID
						 Copy_u32Group       : Spicifies How Many Bites For Group and SubGroup ID In SCB_AIRCR Register
return: none
*/
void MNVIC_voidSetPriority(s8 Copy_s8InterruptID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32Group);
#endif
