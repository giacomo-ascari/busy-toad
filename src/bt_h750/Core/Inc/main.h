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
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "cs4282p.h"

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
#define X_Pin GPIO_PIN_2
#define X_GPIO_Port GPIOE
#define XE3_Pin GPIO_PIN_3
#define XE3_GPIO_Port GPIOE
#define XE4_Pin GPIO_PIN_4
#define XE4_GPIO_Port GPIOE
#define XE5_Pin GPIO_PIN_5
#define XE5_GPIO_Port GPIOE
#define XE6_Pin GPIO_PIN_6
#define XE6_GPIO_Port GPIOE
#define XC13_Pin GPIO_PIN_13
#define XC13_GPIO_Port GPIOC
#define XC14_Pin GPIO_PIN_14
#define XC14_GPIO_Port GPIOC
#define XC15_Pin GPIO_PIN_15
#define XC15_GPIO_Port GPIOC
#define XH0_Pin GPIO_PIN_0
#define XH0_GPIO_Port GPIOH
#define XH1_Pin GPIO_PIN_1
#define XH1_GPIO_Port GPIOH
#define XC0_Pin GPIO_PIN_0
#define XC0_GPIO_Port GPIOC
#define XC1_Pin GPIO_PIN_1
#define XC1_GPIO_Port GPIOC
#define XC2_Pin GPIO_PIN_2
#define XC2_GPIO_Port GPIOC
#define POT_0_Pin GPIO_PIN_3
#define POT_0_GPIO_Port GPIOC
#define EXP_0_Pin GPIO_PIN_0
#define EXP_0_GPIO_Port GPIOA
#define EXP_1_Pin GPIO_PIN_1
#define EXP_1_GPIO_Port GPIOA
#define EXP_2_Pin GPIO_PIN_2
#define EXP_2_GPIO_Port GPIOA
#define EXP_3_Pin GPIO_PIN_3
#define EXP_3_GPIO_Port GPIOA
#define CODEC_I2S_WS_Pin GPIO_PIN_4
#define CODEC_I2S_WS_GPIO_Port GPIOA
#define CODEC_I2S_CK_Pin GPIO_PIN_5
#define CODEC_I2S_CK_GPIO_Port GPIOA
#define CODEC_I2S_SDI_Pin GPIO_PIN_6
#define CODEC_I2S_SDI_GPIO_Port GPIOA
#define CODEC_I2S_SDO_Pin GPIO_PIN_7
#define CODEC_I2S_SDO_GPIO_Port GPIOA
#define CODEC_I2S_MCK_Pin GPIO_PIN_4
#define CODEC_I2S_MCK_GPIO_Port GPIOC
#define CODEC_RESET_Pin GPIO_PIN_5
#define CODEC_RESET_GPIO_Port GPIOC
#define XB0_Pin GPIO_PIN_0
#define XB0_GPIO_Port GPIOB
#define XB1_Pin GPIO_PIN_1
#define XB1_GPIO_Port GPIOB
#define XB2_Pin GPIO_PIN_2
#define XB2_GPIO_Port GPIOB
#define XE7_Pin GPIO_PIN_7
#define XE7_GPIO_Port GPIOE
#define XE8_Pin GPIO_PIN_8
#define XE8_GPIO_Port GPIOE
#define XE9_Pin GPIO_PIN_9
#define XE9_GPIO_Port GPIOE
#define XE10_Pin GPIO_PIN_10
#define XE10_GPIO_Port GPIOE
#define XE11_Pin GPIO_PIN_11
#define XE11_GPIO_Port GPIOE
#define XE12_Pin GPIO_PIN_12
#define XE12_GPIO_Port GPIOE
#define XE13_Pin GPIO_PIN_13
#define XE13_GPIO_Port GPIOE
#define XE14_Pin GPIO_PIN_14
#define XE14_GPIO_Port GPIOE
#define XE15_Pin GPIO_PIN_15
#define XE15_GPIO_Port GPIOE
#define CODEC_I2C_SCL_Pin GPIO_PIN_10
#define CODEC_I2C_SCL_GPIO_Port GPIOB
#define CODEC_I2C_SDA_Pin GPIO_PIN_11
#define CODEC_I2C_SDA_GPIO_Port GPIOB
#define HPDAC_I2S_WS_Pin GPIO_PIN_12
#define HPDAC_I2S_WS_GPIO_Port GPIOB
#define HPDAC_I2S_BCK_Pin GPIO_PIN_13
#define HPDAC_I2S_BCK_GPIO_Port GPIOB
#define HPDAC_I2S_SDI_Pin GPIO_PIN_14
#define HPDAC_I2S_SDI_GPIO_Port GPIOB
#define HPDAC_I2S_SDO_Pin GPIO_PIN_15
#define HPDAC_I2S_SDO_GPIO_Port GPIOB
#define USART_TX_Pin GPIO_PIN_8
#define USART_TX_GPIO_Port GPIOD
#define USART_RX_Pin GPIO_PIN_9
#define USART_RX_GPIO_Port GPIOD
#define AUX_OUTPUT_Pin GPIO_PIN_10
#define AUX_OUTPUT_GPIO_Port GPIOD
#define AUX_INPUT_Pin GPIO_PIN_11
#define AUX_INPUT_GPIO_Port GPIOD
#define XD12_Pin GPIO_PIN_12
#define XD12_GPIO_Port GPIOD
#define XD13_Pin GPIO_PIN_13
#define XD13_GPIO_Port GPIOD
#define XD14_Pin GPIO_PIN_14
#define XD14_GPIO_Port GPIOD
#define XD15_Pin GPIO_PIN_15
#define XD15_GPIO_Port GPIOD
#define XC6_Pin GPIO_PIN_6
#define XC6_GPIO_Port GPIOC
#define XC7_Pin GPIO_PIN_7
#define XC7_GPIO_Port GPIOC
#define SD_D0_Pin GPIO_PIN_8
#define SD_D0_GPIO_Port GPIOC
#define SD_D1_Pin GPIO_PIN_9
#define SD_D1_GPIO_Port GPIOC
#define XA8_Pin GPIO_PIN_8
#define XA8_GPIO_Port GPIOA
#define XA10_Pin GPIO_PIN_10
#define XA10_GPIO_Port GPIOA
#define XA15_Pin GPIO_PIN_15
#define XA15_GPIO_Port GPIOA
#define SD_D2_Pin GPIO_PIN_10
#define SD_D2_GPIO_Port GPIOC
#define SD_D3_Pin GPIO_PIN_11
#define SD_D3_GPIO_Port GPIOC
#define SD_CK_Pin GPIO_PIN_12
#define SD_CK_GPIO_Port GPIOC
#define XD0_Pin GPIO_PIN_0
#define XD0_GPIO_Port GPIOD
#define XD1_Pin GPIO_PIN_1
#define XD1_GPIO_Port GPIOD
#define SD_CMD_Pin GPIO_PIN_2
#define SD_CMD_GPIO_Port GPIOD
#define SD_DETECT_Pin GPIO_PIN_3
#define SD_DETECT_GPIO_Port GPIOD
#define BTN_D_Pin GPIO_PIN_4
#define BTN_D_GPIO_Port GPIOD
#define LED_D_Pin GPIO_PIN_5
#define LED_D_GPIO_Port GPIOD
#define BTN_C_Pin GPIO_PIN_6
#define BTN_C_GPIO_Port GPIOD
#define LED_C_Pin GPIO_PIN_7
#define LED_C_GPIO_Port GPIOD
#define BTN_B_Pin GPIO_PIN_3
#define BTN_B_GPIO_Port GPIOB
#define LED_B_Pin GPIO_PIN_4
#define LED_B_GPIO_Port GPIOB
#define BTN_A_Pin GPIO_PIN_5
#define BTN_A_GPIO_Port GPIOB
#define LED_A_Pin GPIO_PIN_6
#define LED_A_GPIO_Port GPIOB
#define LED_RD_Pin GPIO_PIN_7
#define LED_RD_GPIO_Port GPIOB
#define XB8_Pin GPIO_PIN_8
#define XB8_GPIO_Port GPIOB
#define XB9_Pin GPIO_PIN_9
#define XB9_GPIO_Port GPIOB
#define XE0_Pin GPIO_PIN_0
#define XE0_GPIO_Port GPIOE
#define XE1_Pin GPIO_PIN_1
#define XE1_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
