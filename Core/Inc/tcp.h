// ****************************************************************************
/// \file      pcu_bus_uart_tcp.h
///
/// \brief     TCP/IP Stack Application Level C Header File
///
/// \details   Module for the handling of the freertos tcp ip stack
///
/// \author    Nico Korn
///
/// \version   1.0.0.0
///
/// \date      02072021
/// 
/// \copyright Copyright (C) 2021  by "Reichle & De-Massari AG", 
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

// Define to prevent recursive inclusion **************************************
#ifndef __TCP_H
#define __TCP_H

// Include ********************************************************************
#include "stm32f4xx_hal.h"

// Exported defines ***********************************************************
#define IP1             ( 192u )
#define IP2             ( 168u )
#define IP3             ( 2u )
#define IP4             ( 1u )
#define SUB1            ( 255u )
#define SUB2            ( 255u )
#define SUB3            ( 255u )
#define SUB4            ( 0u )
#define DHCPPOOLSIZE    ( 4u )

// Exported types *************************************************************

// Exported functions *********************************************************
void                    tcp_init                      ( void );
void                    tcp_deinit                    ( void );
uint8_t                 tcp_output                    ( uint8_t* buffer, uint16_t length );
const char*             pcApplicationHostnameHookCAP  ( void );
uint8_t                 tcp_enqueue                   ( uint8_t* data, uint16_t length );
#endif // __TCP_H