/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define EIGHT_6_Pin GPIO_PIN_13
#define EIGHT_6_GPIO_Port GPIOC
#define EIGHT_7_Pin GPIO_PIN_15
#define EIGHT_7_GPIO_Port GPIOC
#define EIGHT_2_Pin GPIO_PIN_0
#define EIGHT_2_GPIO_Port GPIOC
#define EIGHT_3_Pin GPIO_PIN_2
#define EIGHT_3_GPIO_Port GPIOC
#define CAR_EN1_Pin GPIO_PIN_4
#define CAR_EN1_GPIO_Port GPIOA
#define CAR_EN2_Pin GPIO_PIN_5
#define CAR_EN2_GPIO_Port GPIOA
#define EIGHT_4_Pin GPIO_PIN_4
#define EIGHT_4_GPIO_Port GPIOC
#define EIGHT_1_Pin GPIO_PIN_2
#define EIGHT_1_GPIO_Port GPIOB
#define Buzzer_Pin_Pin GPIO_PIN_12
#define Buzzer_Pin_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_14
#define LED2_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_15
#define LED3_GPIO_Port GPIOB
#define EIGHT_5_Pin GPIO_PIN_8
#define EIGHT_5_GPIO_Port GPIOC
#define KEY1_Pin GPIO_PIN_10
#define KEY1_GPIO_Port GPIOA
#define KEY1_EXTI_IRQn EXTI15_10_IRQn
#define KEY2_Pin GPIO_PIN_11
#define KEY2_GPIO_Port GPIOA
#define KEY2_EXTI_IRQn EXTI15_10_IRQn
#define KEY3_Pin GPIO_PIN_12
#define KEY3_GPIO_Port GPIOA
#define KEY3_EXTI_IRQn EXTI15_10_IRQn
#define KEY4_Pin GPIO_PIN_15
#define KEY4_GPIO_Port GPIOA
#define KEY4_EXTI_IRQn EXTI15_10_IRQn
#define EIGHT_8_Pin GPIO_PIN_3
#define EIGHT_8_GPIO_Port GPIOB
#define MPU_SCL_Pin GPIO_PIN_4
#define MPU_SCL_GPIO_Port GPIOB
#define MPU_SDA_Pin GPIO_PIN_5
#define MPU_SDA_GPIO_Port GPIOB
#define I2C_SDA_Pin GPIO_PIN_8
#define I2C_SDA_GPIO_Port GPIOB
#define I2C_SCL_Pin GPIO_PIN_9
#define I2C_SCL_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
