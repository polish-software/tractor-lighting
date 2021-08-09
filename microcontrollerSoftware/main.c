/**
  ******************************************************************************
  * @file    main.c
  * @author  Mateusz Baczewski
  * @date    12.11.2020
  * @brief   Tractor project main source file.
  ******************************************************************************
**/

#include "config.h"
#include "delay.h"
#include "debugLeds.h"
#include "stm8s_it.h"
#include "pca9685LedDriver.h"

int main(void)
{

  initializeClocks();
  initializePins();
  initializeDelays();
  delayMs(5);
  initializeLedDriverPca9685();

  while(1) {
    disableDebugLed(DBG_LED1);
    enableDebugLed(DBG_LED0);

    delayMs(1000);

    disableDebugLed(DBG_LED0);
    enableDebugLed(DBG_LED1);

    delayMs(1000);
  }
}
