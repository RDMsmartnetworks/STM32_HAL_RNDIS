// ****************************************************************************
/// \file      rs485.c
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
/// \copyright Copyright (C) 2021 by "Reichle & De-Massari AG", 
///            all rights reserved.
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

// Include ********************************************************************
#include "rs485.h"

// Private defines ************************************************************


// Private types     **********************************************************

// Private variables **********************************************************

// Global variables ***********************************************************

// Private function prototypes ************************************************

// Functions ******************************************************************

//------------------------------------------------------------------------------
/// \brief     USART2 Initialization Function          
///
/// \param     none
///
/// \return    none
void rs485_init( void )
{
}

//------------------------------------------------------------------------------
/// \brief     USART2 Deinitialization Function          
///
/// \param     none
///
/// \return    none
void rs485_deinit( void )
{
}

//------------------------------------------------------------------------------
/// \brief     Uart output function.          
///
/// \param     [in] uint8_t* buffer
/// \param     [in] uint16_t length
///
/// \return    0 = not send, 1 = send
uint8_t rs485_output( uint8_t* buffer, uint16_t length )
{
   return 1;
}

//------------------------------------------------------------------------------
/// \brief     Uart receive function.          
///
/// \param     [in] uint8_t* buffer
/// \param     [in] uint16_t length
///
/// \return    0 = error, 1 = success
uint8_t rs485_receive( uint8_t* buffer, uint16_t length )
{
   return 1;
}

/********************** (C) COPYRIGHT Reichle & De-Massari *****END OF FILE****/