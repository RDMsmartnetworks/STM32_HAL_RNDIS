// ****************************************************************************
/// \file      main.c
///
/// \brief     main C source file
///
/// \details   Main c file as the applications entry point and for high level
///            setup for the RTOS and the peripherals.
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* Private defines -----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/********************** (C) COPYRIGHT Reichle & De-Massari *****END OF FILE****/
