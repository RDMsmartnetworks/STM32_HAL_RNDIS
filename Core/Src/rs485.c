// ****************************************************************************
/// \file      rs485.c
///
/// \brief     rs485 uart module
///
/// \details   Module used to initialise rs485 uart peripherals completed with 
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
#include "queuex.h"

// Private defines ************************************************************

// Private types     **********************************************************

// Private variables **********************************************************
static uint8_t* rxBufferPointerExample;

// Global variables ***********************************************************
extern queue_handle_t uartQueue;
extern queue_handle_t usbQueue;

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
   rxBufferPointerExample = queue_getHeadBuffer( &uartQueue );
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
/// \brief     Uart start output/transmit function.          
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
/// \brief     Uart start receive function.          
///
/// \param     [in] uint8_t* buffer
/// \param     [in] uint16_t length
///
/// \return    0 = error, 1 = success
uint8_t rs485_receive( uint8_t* buffer, uint16_t length )
{
   return 1;
}

//------------------------------------------------------------------------------
/// \brief     Uart rx complete callback function. Called from peripheral irq
///            handler.
///
/// \param     none
///
/// \return    none
void rs485_rxCplt( void )
{
   uint16_t rxLengthExample = 500;
   queue_enqueue( rxBufferPointerExample, rxLengthExample, &uartQueue );
}

//------------------------------------------------------------------------------
/// \brief     Uart tx complete callback function. Called from peripheral irq
///            handler.
///
/// \param     none
///
/// \return    none
void rs485_txCplt( void )
{
   queue_dequeue( &usbQueue );
}

/********************** (C) COPYRIGHT Reichle & De-Massari *****END OF FILE****/