/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 18 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"

void MUSART_voidInit(u8 Copy_u8USRTNumber)
{
    if (Copy_u8USRTNumber == USART_ONE)
    {
		/*Set BaudRate*/
		USART1_PTR->BRR = BAUD_RATE; 
		
		/*Enable RX*/
		SET_BIT(USART1_PTR->CR1,2);
		
		/*Enable TX*/
		SET_BIT(USART1_PTR->CR1,3);
		
		/*Enable USART1*/
		SET_BIT(USART1_PTR->CR1,13);
		
		/*Clear Status Register*/
		USART1_PTR->SR = 0;
    }
	else if (USART_NUM == USART_TWO)
	{
		/*Set BaudRate*/
		USART2_PTR->BRR = BAUD_RATE; 
		
		/*Enable RX*/
		SET_BIT(USART2_PTR->CR1,2);
		
		/*Enable TX*/
		SET_BIT(USART2_PTR->CR1,3);
		
		/*Enable USART1*/
		SET_BIT(USART2_PTR->CR1,13);
		
		/*Clear Status Register*/
		USART2_PTR->SR = 0;
	}
	else if (USART_NUM == USART_THREE)
	{
		/*Set BaudRate*/
		USART3_PTR->BRR = BAUD_RATE; 
		
		/*Enable RX*/
		SET_BIT(USART3_PTR->CR1,2);
		
		/*Enable TX*/
		SET_BIT(USART3_PTR->CR1,3);
		
		/*Enable USART1*/
		SET_BIT(USART3_PTR->CR1,13);
		
		/*Clear Status Register*/
		USART3_PTR->SR = 0;
	}
	
	
}


void MUSART_voidSendByte(u8 Copy_u8Data, u8 Copy_u8USRTNumber)
{
	
		if (Copy_u8USRTNumber == USART_ONE)
		{
			/* Sending The Data  */
			USART1_PTR->DR = Copy_u8Data;
				
			/*Wait Till Transmission Is Complete*/
			while((GET_BIT(USART1_PTR->SR, 6)) ==0);	
		}
		else if (Copy_u8USRTNumber == USART_TWO)
		{
			/* Sending The Data  */
			USART2_PTR->DR = Copy_u8Data;
				
			/*Wait Till Transmission Is Complete*/
			while((GET_BIT(USART2_PTR->SR, 6)) ==0);
		}
		else if Copy_u8USRTNumber == USART_THREE
		{
			/* Sending The Data  */
			USART3_PTR->DR = Copy_u8Data;
				
			/*Wait Till Transmission Is Complete*/
			while((GET_BIT(USART3_PTR->SR, 6)) ==0);
		}
	
}


void MUSART_voidSendString(u8 arr[], u8 Copy_u8USRTNumber)
{
	u8 Local_u8Index = 0;
	while(arr[Local_u8Index] != '\0')
	{
		MUSART_voidSendByte(arr[Local_u8Index], Copy_u8USRTNumber);
		Local_u8Index++;
	}
}

u8 MUSART_voidReceiveByte(u8 Copy_u8USRTNumber)
{
	if (Copy_u8USRTNumber == USART_ONE)
	{
		/* Wait Till Receiving Is Complete */
		while((GET_BIT(USART1_PTR->SR, 5)) == 0);
		return (0xFF & (USART1_PTR->DR));
	}
	else if (Copy_u8USRTNumber == USART_TWO)
	{
		/* Wait Till Receiving Is Complete */
		while((GET_BIT(USART2_PTR->SR, 5)) == 0);
		return (0xFF & (USART2_PTR->DR));
	}
	else if (Copy_u8USRTNumber == USART_THREE)
	{
		/* Wait Till Receiving Is Complete */
		while((GET_BIT(USART3_PTR->SR, 5)) == 0);
		return (0xFF & (USART3_PTR->DR));
	}
}

void MUSART_voidReceiveString(u8 Copy_u8USRTNumber, u8* Str)
{
	u8 char_index =0;
	Str[char_index] = MUSART_voidReceiveByte(Copy_u8USRTNumber);
	while(Str[char_index] != '#')
	{
		char_index++;
		Str[char_index] = MUSART_voidReceiveByte(Copy_u8USRTNumber);
	}
	Str[char_index] = '\0';
}
