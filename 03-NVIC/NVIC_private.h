/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 13 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H
#define NVIC_BASE_ADDRESS 		0xE000E100
#define SCB_BASE_ADDRESS  		0xE000ED00 								/* System Control Block*/
#define CONVERT_TO_DECIMAL      256
#define MOST_SIGNIFICANT        4 

#define NVIC_ISER0 *((u32*)(NVIC_BASE_ADDRESS + 0x000)) 			/* Enables External interrupts from 0 to 31 */
#define NVIC_ISER1 *((u32*)(NVIC_BASE_ADDRESS + 0x004)) 			/* Enables External interrupts from 32 to 63 */

#define NVIC_ICER0 *((u32*)(NVIC_BASE_ADDRESS + 0x080)) 			/* Disables External interrupts from 0 to 31 */
#define NVIC_ICER1 *((u32*)(NVIC_BASE_ADDRESS + 0x084)) 			/* Disables External interrupts from 32 to 63 */

#define NVIC_ISPR0 *((u32*)(NVIC_BASE_ADDRESS + 0x100))  		 	/* Set Pending Flag for Interrupts from 0 to 31 */
#define NVIC_ISPR1 *((u32*)(NVIC_BASE_ADDRESS + 0x104))  		 	/* Set Pending Flag for Interrupts from 32 to 63 */

#define NVIC_ICPR0 *((u32*)(NVIC_BASE_ADDRESS + 0x180))  		 	/* Clear Pending Flag for Interrupts from 0 to 31 */
#define NVIC_ICPR1 *((u32*)(NVIC_BASE_ADDRESS + 0x184))     		/* Clear Pending Flag for Interrupts from 32 to 63 */

#define NVIC_IABR0 *((volatile u32*)(NVIC_BASE_ADDRESS + 0x200))  	/* Read The Status Of Interrupt */
#define NVIC_IABR1 *((volatile u32*)(NVIC_BASE_ADDRESS + 0x204))  	/* Read The Status Of Interrupt */

#define NVIC_IPR    ((volatile u8*)(NVIC_BASE_ADDRESS + 0x300)) 	/* Accsessing The Priority Of Interrupts */

#define SCB_AIRCR  *((volatile u32*)(SCB_BASE_ADDRESS  + 0x0C))
#endif