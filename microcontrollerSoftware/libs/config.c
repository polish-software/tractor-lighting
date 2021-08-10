/**
  ******************************************************************************
  * @file    config.c
  * @author  Mateusz Baczewski
  * @date    12.11.2020
  * @brief   Tractor project config source file.
  ******************************************************************************
**/

#include "config.h"
#include "definitions.h"
#include "stm8s.h"
#include "stm8s_clk.h"
#include "stm8s_gpio.h"

static void initializePinsForI2C(void);
static void initializePinsForDebugLeds(void);
static void initializePinForLedsDriver(void);

void initializeClocks(void)
{
    /* HSI frequency = 16 MHz */
    /* HSI prescaler = 4 (HSIDIV[1:0] = 0b10) */
    /* fMASTER = 4 MHz (for peripherals) */
    /* fCPU = fMASTER = 4 MHz (CPUDIV[2:0] = 0b000) */
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV4);
}

void initializePins(void)
{
    initializePinsForDebugLeds();
    initializePinForLedsDriver();
}

static void initializePinsForDebugLeds(void)
{
    GPIO_Init(DBG_LED0_PORT, DBG_LED0_PIN, GPIO_MODE_OUT_OD_HIZ_SLOW);
    GPIO_Init(DBG_LED1_PORT, DBG_LED1_PIN, GPIO_MODE_OUT_OD_HIZ_SLOW);
}

static void initializePinForLedsDriver(void)
{
    GPIO_Init(LEDS_ENABLE_PORT, LEDS_ENABLE_PIN, GPIO_MODE_OUT_OD_HIZ_SLOW);
}
