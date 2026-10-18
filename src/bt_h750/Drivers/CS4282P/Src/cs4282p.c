#include "cs4282p.h"
#include "stm32h7xx_hal_def.h"
#include <stdint.h>

#define CLAMP(x, min, max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x))) 

typedef union {
    uint8_t bytes[2];
} CS4282P_DataTypeDef;

static inline void PrepPayload(CS4282P_DataTypeDef *data, uint16_t value)
{
    data->bytes[0] = (value >> 8) & 0xFF;
    data->bytes[1] = value & 0xFFU;
}

static inline uint16_t ReadPayload(CS4282P_DataTypeDef *data)
{
    return ((uint16_t)data->bytes[0] << 8) | (uint16_t)data->bytes[1];
}

HAL_StatusTypeDef CS4282P_Init(CS4282P_HandleTypeDef* hcs4282p, I2C_HandleTypeDef* hi2c, I2S_HandleTypeDef* hi2s, GPIO_TypeDef* resetPort, uint16_t resetPin)
{    
    hcs4282p->hi2c = hi2c;
    hcs4282p->hi2s = hi2s;
    hcs4282p->resetPort = resetPort;
    hcs4282p->resetPin = resetPin;
    hcs4282p->initialized = 0;

    CS4282P_DataTypeDef data;

    HAL_StatusTypeDef status = HAL_OK;

    CS4282P_Reset(hcs4282p);
    
    // read device ID or status register to verify communication
    status += HAL_I2C_IsDeviceReady(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, 3, HAL_MAX_DELAY);
    status += HAL_I2C_Mem_Read(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_DEVID, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
    uint16_t devid = ReadPayload(&data); // 17026 or 0x4282

    // GLOBAL_EN=0
    status += CS4282P_Disable(hcs4282p);

    // CLOCK and ASP
    PrepPayload(&data, 0x1000); // PLL, 3MHz, BLCK
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_CLK_CFG_0, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
    PrepPayload(&data, 0x0001); // default
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_CLK_CFG_1, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
    PrepPayload(&data, 0x0000); // default
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_ASP_CFG, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
    PrepPayload(&data, 0x0000); // default 0x0000
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_SIGNAL_PATH_CFG, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);

    // INPUTS and OUTPUTS
    hcs4282p->volume.inputMute[0] = 0;
    hcs4282p->volume.inputMute[1] = 0;
    hcs4282p->volume.inputVolume[0] = 0x00;
    hcs4282p->volume.inputVolume[1] = 0x00;
    hcs4282p->volume.outputMute[0] = 0;
    hcs4282p->volume.outputMute[1] = 0;
    hcs4282p->volume.outputVolume[0] = 0x01;
    hcs4282p->volume.outputVolume[1] = 0x01;
    status += CS4282P_ApplyVolume(hcs4282p);
    PrepPayload(&data, 0x0003); // enable in1 and in2 
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_IN_ENABLES, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
    PrepPayload(&data, 0x0003); // enable out1 and out2
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_OUT_ENABLES, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);

    // REFERENCE
    PrepPayload(&data, 0x000C); // default 1s
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_STARTUP_DELAY, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
    
    // GLOBAL_EN=1
    status += CS4282P_Enable(hcs4282p);


    HAL_Delay(10); // Give some time for the codec to stabilize after enabling
    uint16_t debug = 0;
    status += HAL_I2C_Mem_Read(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_OUT_VOL_CTRL1_0, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
    debug = ReadPayload(&data);
    status += HAL_I2C_Mem_Read(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_OUT_VOL_CTRL1_1, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
    debug = ReadPayload(&data);
    status += HAL_I2C_Mem_Read(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_OUT_ENABLES, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
    debug = ReadPayload(&data);
    status += HAL_I2C_Mem_Read(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_SIGNAL_PATH_CFG, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
    debug = ReadPayload(&data);

    if (status != HAL_OK) {
        return HAL_ERROR;
    }

    hcs4282p->initialized = 1;
    return HAL_OK;
}

void CS4282P_Reset(CS4282P_HandleTypeDef* hcs4282p)
{
    HAL_GPIO_WritePin(hcs4282p->resetPort, hcs4282p->resetPin, GPIO_PIN_RESET);
    HAL_Delay(5);
    HAL_GPIO_WritePin(hcs4282p->resetPort, hcs4282p->resetPin, GPIO_PIN_SET);
    HAL_Delay(10);
}

HAL_StatusTypeDef CS4282P_Enable(CS4282P_HandleTypeDef* hcs4282p)
{
    CS4282P_DataTypeDef data;
    PrepPayload(&data, 0x0001);
    return HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_CHIP_ENABLE, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
}

HAL_StatusTypeDef CS4282P_Disable(CS4282P_HandleTypeDef* hcs4282p)
{
    CS4282P_DataTypeDef data;
    PrepPayload(&data, 0x0000);
    return HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_CHIP_ENABLE, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
}

static inline uint16_t VolumeToRegister(uint8_t volume, uint8_t mute)
{
    return (mute ? 0x8000 : 0x0000) | volume;
}

HAL_StatusTypeDef CS4282P_ApplyVolume(CS4282P_HandleTypeDef* hcs4282p)
{
    CS4282P_DataTypeDef data;

    HAL_StatusTypeDef status = HAL_OK;

    PrepPayload(&data, VolumeToRegister(hcs4282p->volume.inputVolume[0], hcs4282p->volume.inputMute[0]));
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_IN_VOL_CTRL1_0, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);

    PrepPayload(&data, VolumeToRegister(hcs4282p->volume.inputVolume[1], hcs4282p->volume.inputMute[1]));
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_IN_VOL_CTRL1_1, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
    
    PrepPayload(&data, VolumeToRegister(hcs4282p->volume.outputVolume[0], hcs4282p->volume.outputMute[0]));
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_OUT_VOL_CTRL1_0, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);

    PrepPayload(&data, VolumeToRegister(hcs4282p->volume.outputVolume[1], hcs4282p->volume.outputMute[1]));
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_OUT_VOL_CTRL1_1, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);

    PrepPayload(&data, 0x0001); // apply volume change
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_IN_VOL_CTRL5, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);
    status += HAL_I2C_Mem_Write(hcs4282p->hi2c, CS4282P_I2C_ADDRESS, CS4282P_REG_OUT_VOL_CTRL5, I2C_MEMADD_SIZE_16BIT, data.bytes, sizeof(data), HAL_MAX_DELAY);

    if (status != HAL_OK) {
        return HAL_ERROR;
    }
    return status;
}

uint8_t CS4282P_CalculateVolumeFromDB(float volumeDB)
{
    // volume is a line from 0 to 0xFF from 0dB to -127.5dB in 0.5dB steps
    volumeDB = CLAMP(volumeDB, -127.5f, 0.0f);
    return (uint8_t)(-2.0f * volumeDB);
}

HAL_StatusTypeDef CS4282P_MuteAll(CS4282P_HandleTypeDef* hcs4282p)
{
    hcs4282p->volume.inputMute[0] = 1;
    hcs4282p->volume.inputMute[1] = 1;
    hcs4282p->volume.outputMute[0] = 1;
    hcs4282p->volume.outputMute[1] = 1;
    return CS4282P_ApplyVolume(hcs4282p);
}

HAL_StatusTypeDef CS4282P_UnmuteAll(CS4282P_HandleTypeDef* hcs4282p)
{
    hcs4282p->volume.inputMute[0] = 0;
    hcs4282p->volume.inputMute[1] = 0;
    hcs4282p->volume.outputMute[0] = 0;
    hcs4282p->volume.outputMute[1] = 0;
    return CS4282P_ApplyVolume(hcs4282p);
}