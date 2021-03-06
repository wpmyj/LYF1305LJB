/*
	FileName : bsp_gpio.h
	Description : 
			GPIO 
	Created on 2013.10.11 by ZZP.

	Revision History:


*/

#ifndef __BSP_GPIO_H__
#define __BSP_GPIO_H__

#include "core_cm3.h"
#include "bsp_usart.h"

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///											连接板
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
#if defined LJB_CPU_MAIN
///////////////////////////////////////////////////
///控制信号电子开关: LJB CPU
///////////////////////////////////////////////////
///串口断电
#define USART_CTRL_DISABLE			    	{GPIOA->BSRRL = GPIO_Pin_11; GPIOB->BSRRL = GPIO_Pin_9;}
///串口供电
#define USART_CTRL_ENABLE					{GPIOA->BSRRH = GPIO_Pin_11; GPIOB->BSRRH = GPIO_Pin_9;}
///I2C写保护
#define I2C_WP_ENABLE			     		{GPIOA->BSRRL = GPIO_Pin_2;}
///I2C写保护解除
#define I2C_WP_DISABLE			     		{GPIOA->BSRRH = GPIO_Pin_2;}

#define FLASH_WP_DISABLE	{GPIOA->BSRRH = GPIO_Pin_2;}
#define FLASH_WP_ENABLE	    {GPIOA->BSRRL = GPIO_Pin_2;}


#endif

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///											记录采集板
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
#if defined JLB_CPU_SAMPLE
///////////////////////////////////////////////////
///控制信号电子开关: sample CPU
///////////////////////////////////////////////////
///ADC H/L Select:
#define SELECT_ADC_L_CH		{GPIOB->BSRRH = GPIO_Pin_2;}
#define SELECT_ADC_H_CH		{GPIOB->BSRRL = GPIO_Pin_2;}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///									记录控制板
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
#elif defined JLB_CPU_MAIN
///////////////////////////////////////////////////
///	 FLASH 写保护: main CPU
///////////////////////////////////////////////////
#define FLASH_WP_ENABLE		{GPIOA_BSRRH = GPIO_Pin_2;}
#define FLASH_WP_DISABLE	{GPIOA_BSRRL = GPIO_Pin_2;}

///////////////////////////////////////////////////
///	 复位 ULPI： main CPU
///////////////////////////////////////////////////
#define RESET_ULPI			{GPIOB_BSRRH = GPIO_Pin_14;}
#define DERESET_ULPI		{GPIOB_BSRRL = GPIO_Pin_14;}

///////////////////////////////////////////////////
///	 GPRS POW CTRL: main CPU
///////////////////////////////////////////////////
#define GPRS_POW_ON			{GPIOA_BSRRL = GPIO_Pin_12; GPIOA_BSRRH = GPIO_Pin_11;}
#define GPRS_POW_OFF		{GPIOA_BSRRH = GPIO_Pin_12; GPIOA_BSRRL = GPIO_Pin_11;}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///									解码板
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
#elif defined JMB_CPU_MAIN
#define SET_WKST			{GPIOA_BSRRL = GPIO_Pin_5;}
#define RESET_WKST			{GPIOA_BSRRH = GPIO_Pin_5;}
#define TOGGLE_WKST			{GPIOA->ODR ^= GPIO_Pin_5;}

#define SET_INCS			{GPIOA_BSRRL = GPIO_Pin_6;}
#define RESET_INCS			{GPIOA_BSRRH = GPIO_Pin_6;}
#define TOGGLE_INCS			{GPIOA->ODR ^= GPIO_Pin_6;}
#endif




void 		BSP_GPIO_Init(void);
void		BSP_FeedDog(void);
void 		BSP_EnableUsartTx(COM_TypeDef com, uint8_t enable);

///记录控制板
#if defined JLB_CPU_MAIN

uint8_t		BSP_GetSwStatus(void);
#endif

uint8_t		BSP_DetectSD(void);


#endif///EOF


