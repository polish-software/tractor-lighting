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
static void initializePinsForButtons(void);
static void initializePinsForAdc(void);

void initializeClocks(void)
{
    /* HSI frequency = 16 MHz */
    /* HSI prescaler = 4 (HSIDIV[1:0] = 0b10) */
    /* fMASTER = 4 MHz (for peripherals) */
    /* fCPU = fMASTER = 4 MHz (CPUDIV[2:0] = 0b000) */
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV4);

    CLK_PeripheralClockConfig(CLK_PERIPHERAL_I2C, ENABLE);
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE);
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_ADC, ENABLE);

    CLK_PeripheralClockConfig(CLK_PERIPHERAL_SPI, DISABLE);
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_UART1, DISABLE);
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER2, DISABLE);
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1, DISABLE);
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_AWU, DISABLE);
}

void initializePins(void)
{
    initializePinsForDebugLeds();
    initializePinForLedsDriver();
    initializePinsForButtons();
    initializePinsForAdc();
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

static void initializePinsForButtons(void)
{
    GPIO_Init(BUTTON1_PORT, BUTTON1_PIN, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(BUTTON2_PORT, BUTTON2_PIN, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(BUTTON3_PORT, BUTTON3_PIN, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(BUTTON4_PORT, BUTTON4_PIN, GPIO_MODE_IN_PU_NO_IT);
}

static void initializePinsForAdc(void)
{
    GPIO_Init(BAT_MEASURE_PORT, BAT_MEASURE_PIN, GPIO_MODE_IN_FL_NO_IT);
    GPIO_Init(POTENTIOMETER_PORT, POTENTIOMETER_PIN, GPIO_MODE_IN_FL_NO_IT);
}
