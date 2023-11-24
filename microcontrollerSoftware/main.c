/**
  ******************************************************************************
  * @file    main.c
  * @author  Mateusz Baczewski
  * @date    12.11.2020
  * @brief   Tractor project main source file.
  ******************************************************************************
**/

#include "buttons.h"
#include "config.h"
#include "debugLeds.h"
#include "delay.h"
#include "pca9685LedDriver.h"
#include "stm8s_it.h"

int main(void)
{

    initializeClocks();
    initializePins();
    initializeDelays();
    delayMs(5);
    initializeLedDriverPca9685();

    enableLedDriverPca9685();

    setLedDriverPca9685PwmOutput(LED_DRIVER_PCA9685_LED0, 0);
    setLedDriverPca9685PwmOutput(LED_DRIVER_PCA9685_LED1, 25);
    setLedDriverPca9685PwmOutput(LED_DRIVER_PCA9685_LED2, 50);
    setLedDriverPca9685PwmOutput(LED_DRIVER_PCA9685_LED3, 75);
    setLedDriverPca9685PwmOutput(LED_DRIVER_PCA9685_LED4, 100);

    while (1) {
        if (GetButtonState(BUTTON_LEFT_UPPER)) {
            disableDebugLed(DBG_LED1);
            enableDebugLed(DBG_LED0);
        } else {
            disableDebugLed(DBG_LED0);
            enableDebugLed(DBG_LED1);
        }
    }
}
