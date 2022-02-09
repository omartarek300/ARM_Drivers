/*********************************************************/
/* Author  : Omar Tarek                                  */
/* Date    : 18 December 2021                            */
/* Version : V1.0                                        */
/*********************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H


/*******
Function Description: This Function Initialize USART
parameters:Copy_u8USRTNumber : Selects Which USART To Be Used
return: none
*/
void MUSART_voidInit(u8 Copy_u8USRTNumber);


/*******
Function Description: This Function Transmits Data Using USART
parameters: opy_u8Data: The Transmited Data
			Copy_u8USRTNumber : Selects Which USART To Be Used
return: none
*/
void MUSART_voidSendByte(u8 Copy_u8Data, u8 Copy_u8USRTNumber);



/*******
Function Description: This Function Transmits Data Using USART
parameters: arr: The Transmited Data
			Copy_u8USRTNumber : Selects Which USART To Be Used
return: none
*/
void MUSART_voidSendString(u8 arr[], u8 Copy_u8USRTNumber);

/*******
Function Description: This Function Receives Data Using USART
parameters: Copy_u8USRTNumber : Selects Which USART To Be Used
return: The Received Data
*/
u8 MUSART_voidReceiveByte(u8 Copy_u8USRTNumber);


/*******
Function Description: This Function Receives String Using USART
parameters: Copy_u8USRTNumber : Selects Which USART To Be Used
			Str : Buffer To Store Received Data
return: none
*/
void MUSART_voidReceiveString(u8 Copy_u8USRTNumber, u8* Str);


#endif
  