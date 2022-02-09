/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 14 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H
#define AFIO_BASE_ADDRESS  0x4001 0000

typedef struct{
	u32 AFIO_EVCR;
	u32 AFIO_MAPR;
	u32 AFIO_EXTICR[4];
	u32 AFIO_MAPR2;
}AFIO_t;

#define AFIO_PTR ((volatile AFIO_t*)(AFIO_BASE_ADDRESS))

 
#endif