/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 23 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#define TIMER1_BASE_ADDRESS  0x40012C00
#define TIMER2_BASE_ADDRESS  0x40000000
#define TIMER3_BASE_ADDRESS  0x40000400
#define TIMER4_BASE_ADDRESS  0x40000800

typedef struct{
	volatile u32 TIM_CR1;
	volatile u32 TIM_CR2;
	volatile u32 TIM_SMCR;
	volatile u32 TIM_DIER;
	volatile u32 TIM_SR;
	volatile u32 TIM_EGR;
	volatile u32 TIM_CCMR1;
	volatile u32 TIM_CCMR2;
	volatile u32 TIM_CCER;
	volatile u32 TIM_CNT;
	volatile u32 TIM_PSC;
	volatile u32 TIM_ARR;
	volatile u32 TIM_RCR;
	volatile u32 TIM_CCR1;
	volatile u32 TIM_CCR2;
	volatile u32 TIM_CCR3;
	volatile u32 TIM_CCR4;
	volatile u32 TIM_BDTR;
	volatile u32 TIM_DCR;
	volatile u32 TIM_DMAR;
}TIMER_t;


volatile TIMER_t* TIMERx;

#define TIM1 					( ( volatile TIMER_t* ) TIMER1_BASE_ADDRESS )
#define TIM2 					( ( volatile TIMER_t* ) TIMER2_BASE_ADDRESS )
#define TIM3  					( ( volatile TIMER_t* ) TIMER3_BASE_ADDRESS )
#define TIM4  					( ( volatile TIMER_t* ) TIMER4_BASE_ADDRESS )

/* Delays Configurations*/
#define OVERFLOW_VALUE (0xFFFF-1)
#define PRESCALAR (72-1) // Tick Time is 1 Micro Second
#define ONE_MILLISECOND 1000



 

#endif
