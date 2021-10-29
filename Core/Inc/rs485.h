// ****************************************************************************
/// \file      rs485.h
///
/// \brief     bus uart module
///
/// \details   Module used to initialise bus uart peripherals completed with 
///            functions for receiving and transmitting data.
///
/// \author    Nico Korn
///
/// \version   0.2.0.0
///
/// \date      29102021
/// 
/// \copyright Copyright 20210 Reichle & De-Massari AG
///            
///            Permission is hereby granted, free of charge, to any person 
///            obtaining a copy of this software and associated documentation 
///            files (the "Software"), to deal in the Software without 
///            restriction, including without limitation the rights to use, 
///            copy, modify, merge, publish, distribute, sublicense, and/or sell
///            copies of the Software, and to permit persons to whom the 
///            Software is furnished to do so, subject to the following 
///            conditions:
///            
///            The above copyright notice and this permission notice shall be 
///            included in all copies or substantial portions of the Software.
///            
///            THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
///            EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
///            OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
///            NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
///            HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
///            WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
///            FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR 
///            OTHER DEALINGS IN THE SOFTWARE.
///
/// \pre       
///
/// \bug       
///
/// \warning   
///
/// \todo      
///
// ****************************************************************************

// Define to prevent recursive inclusion **************************************
#ifndef __RS485_H
#define __RS485_H

// Include ********************************************************************
#include "stm32f4xx.h"

// Exported defines ***********************************************************

// Exported types *************************************************************

// Exported functions *********************************************************
void     rs485_init              ( void );
void     rs485_deinit            ( void );
uint8_t  rs485_output            ( uint8_t* buffer, uint16_t length );
uint8_t  rs485_receive           ( uint8_t* buffer, uint16_t length );

#endif // __RS485_H

/********************** (C) COPYRIGHT Reichle & De-Massari *****END OF FILE****/