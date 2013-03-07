/**
  ******************************************************************************
  * @file    printf.h 
  * @author  Xu Mingfeng
  * @version V1.0.0
  * @date    2013-03-07
  * @brief   This file contains the headers of the printf.
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F10x_SDK_PRINTF_H
#define __STM32F10x_SDK_PRINTF_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>

/* Exported types ------------------------------------------------------------*/
/*
 * ��������ɫ
 * 30: ��
 * 31: ��
 * 32: ��
 * 33: ��
 * 34: ��
 * 35: ��
 * 36: ����
 * 37: ��ɫ
*/
#define COLOR_RESET                              "\033[1;m"
#define COLOR_RED                                "\033[1;31m"
#define COLOR_GREEN                              "\033[1;32m"
#define COLOR_YELLOW                             "\033[1;33m"
#define COLOR_BLUE                               "\033[1;34m"
#define COLOR_PURPLE                             "\033[1;35m"
#define COLOR_CYAN                               "\033[1;36m"
#define COLOR_WHITE                              "\033[1;37m"

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define STM32_TRACE(level, fmt, args...) \
	printf##level(COLOR_GREEN "%d[%s:%d] %s():" COLOR_RESET fmt, level, __FILE__, __LINE__, __func__, ##args)

/*!
 * @def printf_0
 * ��ӡ����0���ƣ���app�����ú�PRINTF_LEVEL��
 * @def printf_1
 * ��ӡ����1���ƣ���app�����ú�PRINTF_LEVEL��
 * @def printf_2
 * ��ӡ����2���ƣ���app�����ú�PRINTF_LEVEL��
 * @def printf_3
 * ��ӡ����3���ƣ���app.h�����ú�PRINTF_LEVEL��
 */
#ifdef PRINTF_LEVEL
	#if   (PRINTF_LEVEL == 0)
		#define printf0 printf
		#define printf1(fmt, args...)
		#define printf2(fmt, args...)
		#define printf3(fmt, args...)
	#elif (PRINTF_LEVEL == 1)
		#define printf0 printf
		#define printf1 printf
		#define printf2(fmt, args...)
		#define printf3(fmt, args...)
	#elif (PRINTF_LEVEL == 2)
		#define printf0 printf
		#define printf1 printf
		#define printf2 printf
		#define printf3(fmt, args...)
	#elif (PRINTF_LEVEL >= 3)
		#define printf0 printf
		#define printf1 printf
		#define printf2 printf
		#define printf3 printf
	#else
		#define printf0(fmt, args...)
		#define printf1(fmt, args...)
		#define printf2(fmt, args...)
		#define printf3(fmt, args...)
	#endif
#else
	#define printf0(fmt, args...)
	#define printf1(fmt, args...)
	#define printf2(fmt, args...)
	#define printf3(fmt, args...)
#endif

/*
 * ����ƶ�����
 */
#define CURSOR_MV_UP(level, n)                   printf##level("\033[%dA", n)
#define CURSOR_MV_DOWN(level, n)                 printf##level("\033[%dB", n)
#define CURSOR_MV_R(level, n)                    printf##level("\033[%dC", n)
#define CURSOR_MV_F(level, n)                    printf##level("\033[%dD", n)
#define CURSOR_CLR_LINE(level)                   printf##level("\r\033[K")
#define CURSOR_CLR_ALL(level)                    printf##level("\033[2J")

/* Exported functions ------------------------------------------------------- */

#endif /* __STM32F10x_SDK_PRINTF_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
