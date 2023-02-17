#include "bsp_encoder.h"
#include "usb_device.h"
#include "usbd_hid_mouse.h"

uint8_t stepL = 4;
uint8_t stepR = 4;

int8_t LCount;
int8_t RCount;
uint8_t mouseReport[4] = {0};
extern USBD_HandleTypeDef hUsbDevice;


void encoderEXIT(uint16_t GPIO_Pin) {
    static uint32_t timeEncoderL;
    static uint32_t timeEncoderR;
    if (GPIO_Pin == ENC_LA_Pin) {
        if (HAL_GetTick() - timeEncoderL > 5) {
            timeEncoderL = HAL_GetTick();
            if (HAL_GPIO_ReadPin(ENC_LA_GPIO_Port, ENC_LA_Pin)) {
                if (HAL_GPIO_ReadPin(ENC_LB_GPIO_Port, ENC_LB_Pin))
                    LCount--;
                else
                    LCount++;
            } else {
                if (HAL_GPIO_ReadPin(ENC_LB_GPIO_Port, ENC_LB_Pin))
                    LCount++;
                else
                    LCount--;
            }
        }
        //return;
    } else if (GPIO_Pin == ENC_LB_Pin) {
        if (HAL_GetTick() - timeEncoderL > 5) {
            timeEncoderL = HAL_GetTick();
            if (HAL_GPIO_ReadPin(ENC_LB_GPIO_Port, ENC_LB_Pin)) {
                if (HAL_GPIO_ReadPin(ENC_LA_GPIO_Port, ENC_LA_Pin))
                    LCount++;
                else
                    LCount--;
            } else {
                if (HAL_GPIO_ReadPin(ENC_LA_GPIO_Port, ENC_LA_Pin))
                    LCount--;
                else
                    LCount++;
            }
        }
        //return;
    } else if (GPIO_Pin == ENC_RA_Pin) {
        if (HAL_GetTick() - timeEncoderR > 5) {
            timeEncoderR = HAL_GetTick();
            if (HAL_GPIO_ReadPin(ENC_RA_GPIO_Port, ENC_RA_Pin)) {
                if (HAL_GPIO_ReadPin(ENC_RB_GPIO_Port, ENC_RB_Pin))
                    RCount--;
                else
                    RCount++;
            } else {
                if (HAL_GPIO_ReadPin(ENC_RB_GPIO_Port, ENC_RB_Pin))
                    RCount++;
                else
                    RCount--;
            }
        }
        //return;
    } else if (GPIO_Pin == ENC_RB_Pin) {
        if (HAL_GetTick() - timeEncoderR > 5) {
            timeEncoderR = HAL_GetTick();
            if (HAL_GPIO_ReadPin(ENC_RB_GPIO_Port, ENC_RB_Pin)) {
                if (HAL_GPIO_ReadPin(ENC_RA_GPIO_Port, ENC_RA_Pin))
                    RCount++;
                else
                    RCount--;
            } else {
                if (HAL_GPIO_ReadPin(ENC_RA_GPIO_Port, ENC_RA_Pin))
                    RCount--;
                else
                    RCount++;
            }
        }
        //return;
    }

    RCount *= stepR;
    LCount *= stepL;
    mouseReport[1] = LCount;
    mouseReport[2] = RCount;
    LCount = 0;
    RCount = 0;
    USBD_HID_Mouse_SendReport(&hUsbDevice, mouseReport, 4);
}

//void lEncoderEXIT(){
//
//}
//
//void rEncoderEXIT(){
//
//}