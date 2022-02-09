/*****************************************************************/
/* Author      : Omar Tarek                                      */
/* Date        : 21 NOV 2021                                     */
/* Version     : 1.0 V                                           */
/* Description : GPIO Interfacing                                */
/*****************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* Define GPIO Ports */
#define GPIOA     0
#define GPIOB     1
#define GPIOC     2

/* Define Port Pins */
#define PIN0      0
#define PIN1      1
#define PIN2      2
#define PIN3      3
#define PIN4      4
#define PIN5      5
#define PIN6      6
#define PIN7      7
#define PIN8      8
#define PIN9      9
#define PIN10      10
#define PIN11      11
#define PIN12      12
#define PIN13      13
#define PIN14      14
#define PIN15      

/* Define Pin OutPuts */
#define DIO_HIGH                   1
#define DIO_LOW                    0

/* Define Pin Modes */
/* OutPut */
#define OUTPUT_SPEED_10MHZ_PP      0b0001
#define OUTPUT_SPEED_10MHZ_OD      0b0101
#define OUTPUT_SPEED_10MHZ_AFPP    0b1001
#define OUTPUT_SPEED_10MHZ_AFOD    0b1101

#define OUTPUT_SPEED_2MHZ_PP       0b0010
#define OUTPUT_SPEED_2MHZ_OD       0b0110
#define OUTPUT_SPEED_2MHZ_AFPP     0b1010
#define OUTPUT_SPEED_2MHZ_AFOD     0b1110

#define OUTPUT_SPEED_50MHZ_PP      0b0011
#define OUTPUT_SPEED_50MHZ_OD      0b0111
#define OUTPUT_SPEED_50MHZ_AFPP    0b1011
#define OUTPUT_SPEED_50MHZ_AFOD    0b1111

/* InPut */
#define INPUT_ANALOG      	       0b0000
#define INPUT_FLOATING             0b0100
#define INPUT_PULL_UP_DOWN    	   0b1000

void DIO_voidSetPinDirection(u8 copy_u8PortName, u8 copy_u8PinNumber, u8 copy_u8PinMode);

void DIO_voidSetPinValue(u8 copy_u8PortName, u8 copy_u8PinNumber, u8 copy_u8Value);

u8 DIO_voidGetPinValue(u8 copy_u8PortName, u8 copy_u8PinNumber);


#endif
