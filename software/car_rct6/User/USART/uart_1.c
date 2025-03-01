/*
 * @Author: DuRuofu duruofu@qq.com
 * @Date: 2023-07-13 17-13-53
 * @LastEditors: DuRuofu
 * @LastEditTime: 2024-04-07 11-43-01
 * @FilePath: \STM32F103_Demo\02.UART\03.USART_IDLE_DMA\Users\Components\Usart\uart_1.c
 * @Description: 串口1逻辑(用于debug)
 * Copyright (c) 2023 by duruofu@foxmail.com All Rights Reserved.
 */

#include "uart_1.h"

#define RXBUFFERSIZE_1 256 // 最大接收字节数
extern char HC_05[64];
// 定义串口句柄,使用串口3
#define UART_HANDLE huart3
// 定义数据缓冲区
uint8_t RxBuffer_1[RXBUFFERSIZE_1];
uint8_t Uart_RxBuffer_1;   // 接收中断缓冲
uint8_t Uart_Rx_Cnt_1 = 0; // 接收缓冲计数

extern int32_t car_speed_1 ; // 电机1速度
extern int32_t car_speed_2 ; // 电机2速度
extern int flag;
char message[32];
uint16_t data[8]={0};
extern float Kp_Speed ;      // 速度环比例系数  
extern float Ki_Speed ;        // 速度环积分系数  
extern float Kd_Speed ;  

extern float Kp_Angle ;      // 转向环比例系数  
extern float Ki_Angle ;        // 转向环积分系数  
extern float Kd_Angle ; 
// 发送缓冲区
uint8_t TxBuffer_1[RXBUFFERSIZE_1];

extern DMA_HandleTypeDef hdma_usart3_rx;

void UART3_Init(void)
{
  /*串口硬件配置代码(使用cudeMX则不需要此部分)
  Init the GPIO of USART3
  */
  // 使能 USART3 的接收中断
  __HAL_UART_ENABLE_IT(&UART_HANDLE, UART_IT_RXNE);
  // 开启 USART3 的连续接收中断，并指定接收缓冲区的地址和长度
  HAL_UARTEx_ReceiveToIdle_DMA(&UART_HANDLE, &Uart_RxBuffer_1, 1);
  // 关闭DMA的传输过半中断
  __HAL_DMA_DISABLE_IT(&hdma_usart3_rx, DMA_IT_HT);
}

// 串口接收完成回调函数
void UARTE3_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  UNUSED(Size);
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_UART_TxCpltCallback could be implemented in the user file
   */
	
//串口助手以\rxx,x\r比较好
	if(Uart_Rx_Cnt_1 >= 255)  //溢出判断
	{
		Uart_Rx_Cnt_1 = 0;
		memset(RxBuffer_1,0x00,sizeof(RxBuffer_1));
		HAL_UART_Transmit(&UART_HANDLE, (uint8_t *)"数据溢出", 10,0xFFFF); 
	}
	else
	{
		RxBuffer_1[Uart_Rx_Cnt_1++] = Uart_RxBuffer_1;
	
    // 处理数据
		strcpy(message, (const char *)RxBuffer_1);
//		sscanf((const char *)RxBuffer_1, "%f,%f,%f", &Kp_Speed,&Ki_Speed,&Kd_Speed);
		sscanf((const char *)RxBuffer_1, "%f,%f,%f", &Kp_Angle,&Ki_Angle,&Kd_Angle);
//		DEBUG_printf("pid","%f,%f,%f",Kp_Speed,Ki_Speed,Kd_Speed);
		//复位
		Uart_Rx_Cnt_1 = 0;
		memset(RxBuffer_1,0x00,sizeof(RxBuffer_1)); //清空数组

	}

	  // 将数据发送回去
//  HAL_UART_Transmit_DMA(&UART_HANDLE, RxBuffer_1, Size);
  HAL_UARTEx_ReceiveToIdle_DMA(&UART_HANDLE, RxBuffer_1, RXBUFFERSIZE_1);
}

// 串口3错误回调函数(主要用来清除溢出中断)
void UART3_ErrorCallback(UART_HandleTypeDef *huart)
{
  if (HAL_UART_ERROR_ORE)
  {
    uint32_t temp = huart->Instance->SR;
    temp = huart->Instance->DR;
  }
}

// 实现printf函数
void Usart3DmaPrintf(const char *format, ...)
{
  uint16_t len;
  va_list args;
  va_start(args, format);
  len = vsnprintf((char *)TxBuffer_1, sizeof(TxBuffer_1) + 1, (char *)format, args);
  va_end(args);
  HAL_UART_Transmit_DMA(&UART_HANDLE, TxBuffer_1, len);
}
