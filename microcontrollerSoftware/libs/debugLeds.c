/**
  ******************************************************************************
  * @file    debugLeds.c
  * @author  Mateusz Baczewski
  * @date    17.11.2020
  * @brief   Tractor project debug LEDs control source file.
  ******************************************************************************
**/

#include "debugLeds.h"
#include "definitions.h"
#include "stm8s.h"
#include "stm8s_gpio.h"

static GPIO_TypeDef* const debugLedPorts[NUMBER_OF_DEBUG_LEDS] = { DBG_LED0_PORT, DBG_LED1_PORT };

static const GPIO_Pin_TypeDef debugLedPins[NUMBER_OF_DEBUG_LEDS] = { DBG_LED0_PIN, DBG_LED1_PIN };

void enableDebugLed(const DebugLedType debugLedType)
{
    if (debugLedType < NUMBER_OF_DEBUG_LEDS) {
        GPIO_WriteLow(debugLedPorts[debugLedType], debugLedPins[debugLedType]);
    }
}

void disableDebugLed(const DebugLedType debugLedType)
{
    if (debugLedType < NUMBER_OF_DEBUG_LEDS) {
        GPIO_WriteHigh(debugLedPorts[debugLedType], debugLedPins[debugLedType]);
    }
}

void toggleDebugLed(const DebugLedType debugLedType)
{
    if (debugLedType < NUMBER_OF_DEBUG_LEDS) {
        GPIO_WriteReverse(debugLedPorts[debugLedType], debugLedPins[debugLedType]);
    }
}
