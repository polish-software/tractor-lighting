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

void initializeLedDriverPca9685(void);

void enableLedDriverPca9685(void);

void disableLedDriverPca9685(void);

#endif /* __PCA9685_LED_DRIVER_H__ */
