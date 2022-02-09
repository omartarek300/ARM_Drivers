/*****************************************************************/
/* Author      : Omar Tarek                                      */
/* Date        : 21 NOV 2021                                     */
/* Version     : 1.0 V                                           */
/* Description : GPIO Functions Implimentation                   */
/*****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_voidSetPinDirection(u8 copy_u8PortName, u8 copy_u8PinNumber, u8 copy_u8PinMode)
{
	switch(copy_u8PortName)
	{
		case GPIOA :
					  if(copy_u8PinNumber <= 7) // If The Pin In CRL Register
					  {
						  GPIOA_CRL &= ~((0b1111)<< (copy_u8PinNumber * 4));           // Reset Register Bits
						  GPIOA_CRL |= ((copy_u8PinMode)<< (copy_u8PinNumber * 4));    // Set Pin Mode
					  }
					  else if (copy_u8PinNumber >= 8 && copy_u8PinNumber <= 15 )
					  {
						  copy_u8PinNumber = copy_u8PinNumber - 8;                     // Subtract 8 From Pin Number To Match The Register Bits
						  GPIOA_CRH &= ~((0b1111)<< (copy_u8PinNumber * 4));           // Reset Register Bits
						  GPIOA_CRH |= ((copy_u8PinMode)<< (copy_u8PinNumber * 4));    // Set Pin Mode
					  }
					  break;
		case GPIOB :
					  if(copy_u8PinNumber <= 7) // If The Pin In CRL Register
					  {
						  GPIOB_CRL &= ~((0b1111)<< (copy_u8PinNumber * 4));           // Reset Register Bits
						  GPIOB_CRL |= ((copy_u8PinMode)<< (copy_u8PinNumber * 4));    // Set Pin Mode
					  }
					  else if (copy_u8PinNumber >= 8 && copy_u8PinNumber <= 15 )
					  {
						  copy_u8PinNumber = copy_u8PinNumber - 8;                     // Subtract 8 From Pin Number To Match The Register Bits
						  GPIOB_CRH &= ~((0b1111)<< (copy_u8PinNumber * 4));           // Reset Register Bits
						  GPIOB_CRH |= ((copy_u8PinMode)<< (copy_u8PinNumber * 4));    // Set Pin Mode
					  }
					  break;
		case GPIOC :     
					  if(copy_u8PinNumber <= 7) // If The Pin In CRL Register
					  {
						  GPIOC_CRL &= ~((0b1111)<< (copy_u8PinNumber * 4));           // Reset Register Bits
						  GPIOC_CRL |= ((copy_u8PinMode)<< (copy_u8PinNumber * 4));    // Set Pin Mode
					  }
					  else if (copy_u8PinNumber >= 8 && copy_u8PinNumber <= 15 )
					  {
						  copy_u8PinNumber = copy_u8PinNumber - 8;                     // Subtract 8 From Pin Number To Match The Register Bits
						  GPIOC_CRH &= ~((0b1111)<< (copy_u8PinNumber * 4));           // Reset Register Bits
						  GPIOC_CRH |= ((copy_u8PinMode)<< (copy_u8PinNumber * 4));    // Set Pin Mode
					  }
					  break;
		default : break;			  
	}
}

void DIO_voidSetPinValue(u8 copy_u8PortName, u8 copy_u8PinNumber, u8 copy_u8Value)
{
	switch(copy_u8PortName)
	{
		case GPIOA :
					  if(copy_u8Value == DIO_HIGH)
					  {
						  SET_BIT(GPIOA_ODR, copy_u8PinNumber);
					  }
					  else if(copy_u8Value == DIO_LOW)
					  {
						  CLR_BIT(GPIOA_ODR, copy_u8PinNumber);
					  }
					  break;
		case GPIOB :
					  if(copy_u8Value == DIO_HIGH)
					  {
						  SET_BIT(GPIOB_ODR, copy_u8PinNumber);
					  }
					  else if(copy_u8Value == DIO_LOW)
					  {
						  CLR_BIT(GPIOB_ODR, copy_u8PinNumber);
					  }
					  break;
		case GPIOC :     
					  if(copy_u8Value == DIO_HIGH)
					  {
						  SET_BIT(GPIOC_ODR, copy_u8PinNumber);
					  }
					  else if(copy_u8Value == DIO_LOW)
					  {
						  CLR_BIT(GPIOC_ODR, copy_u8PinNumber);
					  }
					  break;
		default : break;			  
	}
}

u8 DIO_voidGetPinValue(u8 copy_u8PortName, u8 copy_u8PinNumber)
{
	u8 local_u8Result = 0;
	switch(copy_u8PortName)
	{
		case GPIOA :
					  local_u8Result = GET_BIT(GPIOA_IDR, copy_u8PinNumber);
					  break;
		case GPIOB :
					  local_u8Result = GET_BIT(GPIOB_IDR, copy_u8PinNumber);
					  break;
		case GPIOC :     
					  local_u8Result = GET_BIT(GPIOC_IDR, copy_u8PinNumber);
					  break;
		default : break;			  
	}
	return local_u8Result;
}
