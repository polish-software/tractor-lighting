/**
  ******************************************************************************
  * @file    pca9685LedDriver.h
  * @author  Mateusz Baczewski
  * @date    2.12.2020
  * @brief   LEDs driver PCA9685 header file.
  ******************************************************************************
**/

#ifndef __PCA9685_LED_DRIVER_H__
#define __PCA9685_LED_DRIVER_H__

#include <stdint.h>

typedef enum {
    LED_DRIVER_PCA9685_LED0,
    LED_DRIVER_PCA9685_LED1,
    LED_DRIVER_PCA9685_LED2,
    LED_DRIVER_PCA9685_LED3,
    LED_DRIVER_PCA9685_LED4,
    LED_DRIVER_PCA9685_LED5,
    LED_DRIVER_PCA9685_LED6,
    LED_DRIVER_PCA9685_LED7,
    LED_DRIVER_PCA9685_LED8,
    LED_DRIVER_PCA9685_LED9,
    LED_DRIVER_PCA9685_LED10,
    LED_DRIVER_PCA9685_LED11,
    LED_DRIVER_PCA9685_LED12,
    LED_DRIVER_PCA9685_LED13,
    LED_DRIVER_PCA9685_LED14,
    LED_DRIVER_PCA9685_LED15,
} LedDriverPca9685LedType;

void initializeLedDriverPca9685(void);

void enableLedDriverPca9685(void);

void disableLedDriverPca9685(void);

void setLedDriverPca9685PwmOutput(LedDriverPca9685LedType ledType, uint8_t pwmDutyInPercents);

#endif /* __PCA9685_LED_DRIVER_H__ */
