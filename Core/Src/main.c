/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void SysTick_Handler(void){

}
void GPIO_init(void){
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;                        /*  Activate clock GPIOA */

/* -------- PA0 : IR sensor input -------- */
GPIOA -> CRL &= ~(GPIO_CRL_CNF7 | GPIO_CRL_MODE7);           /*  Reset configuration PA7 (bits 31:28 in CRL) */
GPIOA -> CRL |= GPIO_CRL_MODE7_1;                            /*  MODE7 = 10 → Output 2 MHz */

/* -------- PA7 : RELAY output -------- */
GPIOA -> CRL &= ~(GPIO_CRL_CNF0 | GPIO_CRL_MODE0);          /*  Reset configuration PA0 (bits 31:28 in CRL) */
GPIOA -> CRL |= GPIO_CRL_CNF0_1;                            /*  CNF0 = 10 → Input pull-down / Input pull-up*/

}
void SysTick_Init(void){
	SysTick->LOAD = 72000 - 1;                       /* Reload value = 72000000 / 1000 - 1 */
	SysTick->VAL   = 0;                              /* Reset current value */
	SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |    /* Enable SysTick, interrupt, use processor clock */
	                 SysTick_CTRL_TICKINT_Msk   |
	                 SysTick_CTRL_ENABLE_Msk;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	 GPIO_init();
	 SysTick_Init();
  /* USER CODE END 1 */


  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
   uint8_t IRSensorState = GPIOA->IDR & 1;

   /* Polling method: the IR sensor state is continuously read.
      Note: using EXTI interrupt is more CPU-efficient. */

   if(IRSensorState){
    GPIOA ->BSRR = GPIO_BSRR_BR7;              // Reset bit7, PA7
   }
   else
	GPIOA ->BSRR = GPIO_BSRR_BS7;              // Set bit7, PA7
  /* USER CODE END 3 */
  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
