// ****************************************************************************
/// \file      main.c
///
/// \brief     main C source file
///
/// \details   Main c file as the applications entry point.
///
/// \author    Nico Korn
///
/// \version   0.2.0.0
///
/// \date      29102021
/// 
/// \copyright Copyright (C) 2020 by "Reichle & De-Massari AG", 
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
     
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "usb_device.h"
#include "usb_device.h"
#include "queuex.h"
#include "rs485.h"

// Private typedef *************************************************************

// Private define *************************************************************

// Private variables **********************************************************
/* Definitions for defaultTask */
osThreadId_t rndisTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};

/* Definitions for myEvent01 */
osEventFlagsId_t myEvent01Handle;
const osEventFlagsAttr_t myEvent01_attributes = {
  .name = "myEvent01"
};

// queue declerations
queue_handle_t uartQueue;
queue_handle_t usbQueue;
   

// Private function prototypes ************************************************
void SystemClock_Config   ( void );
void startRndisTask       ( void *argument );

// Private functions **********************************************************

// ----------------------------------------------------------------------------
/// \brief     Main function, app entry point.
///
/// \param     none
///
/// \return    none
int main( void )
{
   // Reset of all peripherals, Initializes the Flash interface and the Systick.
   HAL_Init();
   
   // Configure the system clock
   SystemClock_Config();
   
   // Init scheduler
   osKernelInitialize();
   
   // create rndis task
   rndisTaskHandle = osThreadNew( startRndisTask, NULL, &defaultTask_attributes );
   
   // create event ??
   myEvent01Handle = osEventFlagsNew(&myEvent01_attributes);
   
   // Start scheduler
   osKernelStart();
   
   // infinite loop
   while (1)
   {
   }
}

// ----------------------------------------------------------------------------
/// \brief     System clock configuration.
///
/// \param     none
///
/// \return    none
void SystemClock_Config( void )
{
   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
   
   /** Configure the main internal regulator output voltage
   */
   __HAL_RCC_PWR_CLK_ENABLE();
   __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
   /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
   RCC_OscInitStruct.HSEState = RCC_HSE_ON;
   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
   RCC_OscInitStruct.PLL.PLLM = 25;
   RCC_OscInitStruct.PLL.PLLN = 192;
   RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
   RCC_OscInitStruct.PLL.PLLQ = 4;
   if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
   {
      Error_Handler();
   }
   /** Initializes the CPU, AHB and APB buses clocks
   */
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
   
   if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
   {
      Error_Handler();
   }
}

// ----------------------------------------------------------------------------
/// \brief     RNDIS task.
///
/// \param     [in]  void *argument
///
/// \return    none
void startRndisTask( void *argument )
{
   // init peripherals
   rs485_init();
   usb_init();
   
   // set the queue on the uart io
   uartQueue.messageDirection  = UART_TO_USB;
   uartQueue.output            = usb_output;
   queue_init(&uartQueue);
   
   // set the queue on the usb io
   usbQueue.messageDirection   = USB_TO_UART;
   usbQueue.output             = rs485_output;  
   queue_init(&usbQueue);
   
   // loop forever and check for messages to be ready to send from the queues
   for(;;)
   {
      queue_manager( &uartQueue );
      queue_manager( &usbQueue );
   }
}

// ----------------------------------------------------------------------------
/// \brief     Period elapsed callback in non blocking mode. This function is 
///            called  when TIM1 interrupt took place, inside 
///            HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to 
///            incrementa global variable "uwTick" used as application time 
///            base.
///
/// \param     [in]  TIM_HandleTypeDef *htim
///
/// \return    none
void HAL_TIM_PeriodElapsedCallback( TIM_HandleTypeDef *htim )
{
   if (htim->Instance == TIM1)
   {
      HAL_IncTick();
   }
}

// ----------------------------------------------------------------------------
/// \brief     Error handler.
///
/// \param     [in]  TIM_HandleTypeDef *htim
///
/// \return    none
void Error_Handler(void)
{
   // User can add his own implementation to report the HAL error return state
   __disable_irq();
   while (1)
   {
   }
}

#ifdef  USE_FULL_ASSERT
// ----------------------------------------------------------------------------
/// \brief     Reports the name of the source file and the source line number
///            where the assert_param error has occurred.
///
/// \param     [in]  uint8_t *file
/// \param     [in]  uint32_t line
///
/// \return    none
void assert_failed( uint8_t *file, uint32_t line )
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}
#endif /* USE_FULL_ASSERT */

/********************** (C) COPYRIGHT Reichle & De-Massari *****END OF FILE****/