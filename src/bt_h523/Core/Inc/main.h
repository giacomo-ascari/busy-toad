/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h5xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ENC_SW_Pin GPIO_PIN_13
#define ENC_SW_GPIO_Port GPIOC
#define ENC_A_Pin GPIO_PIN_14
#define ENC_A_GPIO_Port GPIOC
#define ENC_B_Pin GPIO_PIN_15
#define ENC_B_GPIO_Port GPIOC
#define X_Pin GPIO_PIN_0
#define X_GPIO_Port GPIOH
#define XH1_Pin GPIO_PIN_1
#define XH1_GPIO_Port GPIOH
#define AUX_OUTPUT_Pin GPIO_PIN_0
#define AUX_OUTPUT_GPIO_Port GPIOA
#define AUX_INPUT_Pin GPIO_PIN_1
#define AUX_INPUT_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define XA4_Pin GPIO_PIN_4
#define XA4_GPIO_Port GPIOA
#define XA5_Pin GPIO_PIN_5
#define XA5_GPIO_Port GPIOA
#define XA6_Pin GPIO_PIN_6
#define XA6_GPIO_Port GPIOA
#define DP_GPIO_0_Pin GPIO_PIN_7
#define DP_GPIO_0_GPIO_Port GPIOA
#define DP_GPIO_1_Pin GPIO_PIN_0
#define DP_GPIO_1_GPIO_Port GPIOB
#define DP_GPIO_2_Pin GPIO_PIN_1
#define DP_GPIO_2_GPIO_Port GPIOB
#define DP_GPIO_3_Pin GPIO_PIN_2
#define DP_GPIO_3_GPIO_Port GPIOB
#define DP_GPIO_4_Pin GPIO_PIN_10
#define DP_GPIO_4_GPIO_Port GPIOB
#define LED_RD_Pin GPIO_PIN_12
#define LED_RD_GPIO_Port GPIOB
#define DP_SPI_SCK_Pin GPIO_PIN_13
#define DP_SPI_SCK_GPIO_Port GPIOB
#define DP_SPI_MISO_Pin GPIO_PIN_14
#define DP_SPI_MISO_GPIO_Port GPIOB
#define DP_SPI_MOSI_Pin GPIO_PIN_15
#define DP_SPI_MOSI_GPIO_Port GPIOB
#define XA8_Pin GPIO_PIN_8
#define XA8_GPIO_Port GPIOA
#define XA9_Pin GPIO_PIN_9
#define XA9_GPIO_Port GPIOA
#define XA10_Pin GPIO_PIN_10
#define XA10_GPIO_Port GPIOA
#define XA11_Pin GPIO_PIN_11
#define XA11_GPIO_Port GPIOA
#define XA12_Pin GPIO_PIN_12
#define XA12_GPIO_Port GPIOA
#define BTN_F_Pin GPIO_PIN_15
#define BTN_F_GPIO_Port GPIOA
#define BTN_E_Pin GPIO_PIN_3
#define BTN_E_GPIO_Port GPIOB
#define BTN_D_Pin GPIO_PIN_4
#define BTN_D_GPIO_Port GPIOB
#define BTN_C_Pin GPIO_PIN_5
#define BTN_C_GPIO_Port GPIOB
#define BTN_B_Pin GPIO_PIN_6
#define BTN_B_GPIO_Port GPIOB
#define BTN_A_Pin GPIO_PIN_7
#define BTN_A_GPIO_Port GPIOB
#define XB8_Pin GPIO_PIN_8
#define XB8_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
