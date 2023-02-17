/*
 * @Author: MeowKJ
 * @Date: 2023-02-17 11:15:13
 * @LastEditors: MeowKJ ijink@qq.com
 * @LastEditTime: 2023-02-17 12:00:32
 * @FilePath: /MDK-ARMc:/Users/ijink/Project/PlatformIO/MiniSDVX/3.Software/mini_sdvx_rec/Lib/Src/lcd.c
 */
#include "LCD.h"
#include "spi.h"

void LCD_Init(void)
{
    LCD_CS_RESET;
    LCD_K_RESET;
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
    LCD_Reset(); // Reset before LCD Init.

    LCD_WriteCmd(0x11); // Sleep exit
    HAL_Delay(120);

    //	LCD_WriteCmd(0x20); 	//0x20:反色关; 0x21:反色开
    LCD_WriteCmd(0x21);

    LCD_WriteCmd(0xB1);
    LCD_WriteData(0x05);
    LCD_WriteData(0x3A);
    LCD_WriteData(0x3A);

    LCD_WriteCmd(0xB2);
    LCD_WriteData(0x05);
    LCD_WriteData(0x3A);
    LCD_WriteData(0x3A);

    LCD_WriteCmd(0xB3);
    LCD_WriteData(0x05);
    LCD_WriteData(0x3A);
    LCD_WriteData(0x3A);
    LCD_WriteData(0x05);
    LCD_WriteData(0x3A);
    LCD_WriteData(0x3A);

    LCD_WriteCmd(0xB4);
    LCD_WriteData(0x03);

    LCD_WriteCmd(0xC0);
    LCD_WriteData(0x62);
    LCD_WriteData(0x02);
    LCD_WriteData(0x04);

    LCD_WriteCmd(0xC1);
    LCD_WriteData(0xC0);

    LCD_WriteCmd(0xC2);
    LCD_WriteData(0x0D);
    LCD_WriteData(0x00);

    LCD_WriteCmd(0xC3);
    LCD_WriteData(0x8D);
    LCD_WriteData(0x6A);

    LCD_WriteCmd(0xC4);
    LCD_WriteData(0x8D);
    LCD_WriteData(0xEE);

    LCD_WriteCmd(0xC5); /*VCOM*/
    LCD_WriteData(0x0E);

    LCD_WriteCmd(0xE0);
    LCD_WriteData(0x10);
    LCD_WriteData(0x0E);
    LCD_WriteData(0x02);
    LCD_WriteData(0x03);
    LCD_WriteData(0x0E);
    LCD_WriteData(0x07);
    LCD_WriteData(0x02);
    LCD_WriteData(0x07);
    LCD_WriteData(0x0A);
    LCD_WriteData(0x12);
    LCD_WriteData(0x27);
    LCD_WriteData(0x37);
    LCD_WriteData(0x00);
    LCD_WriteData(0x0D);
    LCD_WriteData(0x0E);
    LCD_WriteData(0x10);

    LCD_WriteCmd(0xE1);
    LCD_WriteData(0x10);
    LCD_WriteData(0x0E);
    LCD_WriteData(0x03);
    LCD_WriteData(0x03);
    LCD_WriteData(0x0F);
    LCD_WriteData(0x06);
    LCD_WriteData(0x02);
    LCD_WriteData(0x08);
    LCD_WriteData(0x0A);
    LCD_WriteData(0x13);
    LCD_WriteData(0x26);
    LCD_WriteData(0x36);
    LCD_WriteData(0x00);
    LCD_WriteData(0x0D);
    LCD_WriteData(0x0E);
    LCD_WriteData(0x10);

    LCD_WriteCmd(0x3A); // 颜色格式 16bit
    LCD_WriteData(0x05);

    LCD_WriteCmd(0x36);
    LCD_WriteData(0xA8); // BGR格式  0xA0:RGB格式
    LCD_WriteCmd(0x28);  // Display OFF
    LCD_Clear(GREEN);
    LCD_K_SET;
    LCD_WriteCmd(0x29); // Display On
}

void LCD_Deinit(void)
{
    LCD_CS_SET;
}

void LCD_Reset(void)
{
    LCD_RST_SET;
    HAL_Delay(50);
    LCD_RST_RESET;
    HAL_Delay(100);
    LCD_RST_SET;
    HAL_Delay(50);
}

void LCD_WriteCmd(uint8_t cmd)
{
    LCD_DC_RESET;
    HAL_SPI_Transmit(&LCD_SPI_HANDLER, &cmd, 1, 1000);
}

void LCD_WriteData(uint8_t data)
{
    LCD_DC_SET;
    HAL_SPI_Transmit(&LCD_SPI_HANDLER, &data, 1, 1000);
}

void LCD_WriteData_16Bit(uint16_t data)
{
    LCD_DC_SET;
    HAL_SPI_Transmit(&LCD_SPI_HANDLER, (uint8_t *)&data, 2, 1000);
}

void LCD_Clear(uint16_t Color)
{
    unsigned int i, m;
    LCD_SetRegion(0, 0, X_MAX_PIXEL - 1, Y_MAX_PIXEL - 1);
    LCD_WriteCmd(0x2C);
    for (i = 0; i < X_MAX_PIXEL; i++)
        for (m = 0; m < Y_MAX_PIXEL; m++)
        {
            LCD_WriteData_16Bit(Color);
        }
}


/**
 * @brief 设置LCD显示区域，在此区域写点数据自动换行
*/
void LCD_SetRegion(uint16_t x_start,uint16_t y_start,uint16_t x_end,uint16_t y_end)
{	
	//根据屏幕调节偏移量
//	LCD_WriteCmd(0x2a);
//	LCD_WriteData(0x00);
//	LCD_WriteData(x_start);
//	LCD_WriteData(0x00);
//	LCD_WriteData(x_end);	
	LCD_WriteCmd(0x2a);
	LCD_WriteData(0x00);
	LCD_WriteData(x_start+1);
	LCD_WriteData(0x00);
	LCD_WriteData(x_end+1);
 
//	LCD_WriteCmd(0x2b);
//	LCD_WriteData(0x00);
//	LCD_WriteData(y_start+0x18);
//	LCD_WriteData(0x00);
//	LCD_WriteData(y_end+0x18);
	LCD_WriteCmd(0x2b);
	LCD_WriteData(0x00);
	LCD_WriteData(y_start+0x1A);
	LCD_WriteData(0x00);
	LCD_WriteData(y_end+0x1A);	
	LCD_WriteCmd(0x2c);

}