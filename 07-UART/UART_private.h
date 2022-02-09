/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 18 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define UART1_BASE_ADDRESS  0x40013800
#define UART2_BASE_ADDRESS  0x40004400
#define UART3_BASE_ADDRESS  0x40004800

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GRPR;
}UART1_t;

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GRPR;
}UART2_t;

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GRPR;
}UART3_t;

#define USART1_PTR  ((volatile UART1_t*)(UART1_BASE_ADDRESS)) 
#define USART2_PTR  ((volatile UART2_t*)(UART2_BASE_ADDRESS))
#define USART3_PTR  ((volatile UART3_t*)(UART3_BASE_ADDRESS))
 
#define BAUD_9600    0x341
#define BAUD_115200  0x045

#define USART_ONE   0
#define USART_TWO   1
#define USART_THREE 2

#endif
