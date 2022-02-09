/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 18 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_BASE_ADDRESS  0xE000E010

typedef struct{
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;
}STK_t;

#define STK_PTR  ((volatile STK_t*)(STK_BASE_ADDRESS)) 
 
#define STK_CLK_AHB_8         0
#define STK_CLK_AHB           1

#define STK_SINGLE_INTERVAL   0
#define STK_PERIODIC_INTERVAL 1
#endif
