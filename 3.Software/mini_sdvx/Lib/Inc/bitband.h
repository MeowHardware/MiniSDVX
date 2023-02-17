/*
 * @Author: MeowKJ
 * @Date: 2023-02-17 18:52:52
 * @LastEditors: MeowKJ ijink@qq.com
 * @LastEditTime: 2023-02-17 18:53:13
 * @FilePath: /MDK-ARMc:/Users/ijink/Project/PlatformIO/MiniSDVX/3.Software/mini_sdvx/Lib/Inc/bitband.h
 */
#ifndef __BITBAND_H_
#define __BITBAND_H_

#include "stm32f4xx.h"


/* 位带别名区计算公式 */
#define BITBAND(addr, bit)	(*(volatile unsigned long*)((addr & 0xF0000000U) + 0x2000000U + ((addr & 0xFFFFFFU) << 5U) + (bit << 2U)))


/* 输出寄存器 */
#define GPIOA_ODR_ADDR	(GPIOA_BASE + 0x0CU)
#define GPIOB_ODR_ADDR	(GPIOB_BASE + 0x0CU)
#define GPIOC_ODR_ADDR	(GPIOC_BASE + 0x0CU)
#define GPIOD_ODR_ADDR	(GPIOD_BASE + 0x0CU)
#define GPIOE_ODR_ADDR	(GPIOE_BASE + 0x0CU)


/* 输入寄存器 */
#define GPIOA_IDR_ADDR		(GPIOA_BASE + 0x08U)
#define GPIOB_IDR_ADDR		(GPIOB_BASE + 0x08U)
#define GPIOC_IDR_ADDR		(GPIOC_BASE + 0x08U)
#define GPIOD_IDR_ADDR		(GPIOD_BASE + 0x08U)
#define GPIOE_IDR_ADDR		(GPIOE_BASE + 0x08U)


/* GPIO输出 */
#define PAout(n)		BITBAND(GPIOA_ODR_ADDR, n)
#define PBout(n)		BITBAND(GPIOB_ODR_ADDR, n)
#define PCout(n)		BITBAND(GPIOC_ODR_ADDR, n)
#define PDout(n)		BITBAND(GPIOD_ODR_ADDR, n)
#define PEout(n)		BITBAND(GPIOE_ODR_ADDR, n)


/* GPIO输入 */
#define PAin(n)		BITBAND(GPIOA_IDR_ADDR, n)
#define PBin(n)		BITBAND(GPIOB_IDR_ADDR, n)
#define PCin(n)		BITBAND(GPIOC_IDR_ADDR, n)
#define PDin(n)		BITBAND(GPIOD_IDR_ADDR, n)
#define PEin(n)		BITBAND(GPIOE_IDR_ADDR, n)

#endif /* __BITBAND_H_ */
