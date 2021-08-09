/**
  ******************************************************************************
  * @file    debugLeds.h
  * @author  Mateusz Baczewski
  * @date    17.11.2020
  * @brief   Tractor project debug LEDs control header file.
  ******************************************************************************
**/

#ifndef __DEBUG_LEDS_H__
#define __DEBUG_LEDS_H__

#include <stdint.h>

typedef enum
{
  DBG_LED0,
  DBG_LED1,
  NUMBER_OF_DEBUG_LEDS
}DebugLedType;


void enableDebugLed(const DebugLedType debugLedType);

void disableDebugLed(const DebugLedType debugLedType);

void toggleDebugLed(const DebugLedType debugLedType);

#endif /* __DEBUG_LEDS_H__ */
