#include "cs4282p.h"

uint8_t CS4282P_Init(CS4282P_HandleTypeDef* hcs4282p, I2C_HandleTypeDef* hi2c, I2S_HandleTypeDef* hi2s, GPIO_TypeDef* resetPort, uint16_t resetPin) {
    
    hcs4282p->hi2c = hi2c;
    hcs4282p->hi2s = hi2s;
    hcs4282p->resetPort = resetPort;
    hcs4282p->resetPin = resetPin;
    hcs4282p->initialized = 1;

    CS4282P_Reset(hcs4282p);

    // read device ID or status register to verify communication
    uint8_t data[2] = {0, 0};
    HAL_StatusTypeDef status;
    
    status = HAL_I2C_IsDeviceReady(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, 3, HAL_MAX_DELAY);

    if (status != HAL_OK) {
        return 1;
    }

    status = HAL_I2C_Mem_Read(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_DEVID, I2C_MEMADD_SIZE_16BIT, data, sizeof(data), HAL_MAX_DELAY);
    
    HAL_Delay(100);
    if (status != HAL_OK) {
        return 2;
    }

    return 0;
}

void CS4282P_Reset(CS4282P_HandleTypeDef* hcs4282p) {
    HAL_GPIO_WritePin(hcs4282p->resetPort, hcs4282p->resetPin, GPIO_PIN_RESET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(hcs4282p->resetPort, hcs4282p->resetPin, GPIO_PIN_SET);
    HAL_Delay(10);
}