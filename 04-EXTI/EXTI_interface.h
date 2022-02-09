/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 14 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
/* Set Line and Mode*/
void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSWTrigger(u8 Copy_u8Line);
void MEXTI_voidSetMode(u8 Copy_u8Line, u8 Copy_u8Mode);
#endif
  