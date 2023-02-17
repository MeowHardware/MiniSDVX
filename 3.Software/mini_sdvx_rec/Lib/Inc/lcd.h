/*
 * @Author: MeowKJ
 * @Date: 2023-02-17 11:15:35
 * @LastEditors: MeowKJ ijink@qq.com
 * @LastEditTime: 2023-02-17 11:46:44
 * @FilePath: /MDK-ARMc:/Users/ijink/Project/PlatformIO/MiniSDVX/3.Software/mini_sdvx_rec/Lib/Inc/lcd.h
 */

#ifndef __LCE_H__
#define __LCE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "gpio.h"
#include "spi.h"

#define LCD_CS_PORT   GPIOB
#define LCD_CS_PIN  GPIO_PIN_4

#define LCD_DC_PORT  GPIOA
#define LCD_DC_PIN GPIO_PIN_15

#define LCD_RST_PORT GPIOB
#define LCD_RST_PIN GPIO_PIN_6

#define LCD_K_PORT  GPIOB
#define LCD_K_PIN   GPIO_PIN_7

#define LCD_SPI_HANDLER hspi3

#define LCD_CS_SET HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_SET)
#define LCD_CS_RESET HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_RESET)


#define LCD_DC_SET HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_SET)
#define LCD_DC_RESET HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_RESET)

#define LCD_RST_SET HAL_GPIO_WritePin(LCD_RST_PORT, LCD_RST_PIN, GPIO_PIN_SET)
#define LCD_RST_RESET HAL_GPIO_WritePin(LCD_RST_PORT, LCD_RST_PIN, GPIO_PIN_RESET)


#define LCD_K_SET HAL_GPIO_WritePin(LCD_K_PORT, LCD_K_PIN, GPIO_PIN_SET)
#define LCD_K_RESET HAL_GPIO_WritePin(LCD_K_PORT, LCD_K_PIN, GPIO_PIN_RESET)

#define X_MAX_PIXEL 160
#define Y_MAX_PIXEL 80


#define BLACK		0x0000
#define WHITE		0xffff
#define GRAY50  	0x8430	//灰色50%
#define RED  		0xf800
#define GREEN		0x07e0
#define BLUE 		0x001f
#define YELLOW  	0xFFE0	


void LCD_Init(void);
void LCD_DeInit(void);
void LCD_Reset(void);
void LCD_WriteCmd(uint8_t cmd);
void LCD_WriteData(uint8_t data);
void LCD_WriteData_16Bit(uint16_t data);
void LCD_SetRegion(uint16_t x_start,uint16_t y_start,uint16_t x_end,uint16_t y_end);
void LCD_Clear(uint16_t color);


#ifdef __cplusplus
}
#endif // DEBUG
#endif