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
#include "stm8s_gpio.h"
#include "stm8s_clk.h"


static void initializePinsForI2C(void);
static void initializePinsForDebugLeds(void);
static void initializePinForLedsDriver(void);


void initializeClocks(void)
{
  /* HSI frequency = 16 MHz */
  /* HSI prescaler = 4 (HSIDIV[1:0] = 0b10) */
  /* fMASTER = 4 MHz (for peripherals) */
  /* fCPU = fMASTER = 4 MHz (CPUDIV[2:0] = 0b000) */
  CLK->CKDIVR = CLK_PRESCALER_HSIDIV4 | CLK_PRESCALER_CPUDIV1;
}


void initializePins(void)
{
  initializePinsForI2C();
  initializePinsForDebugLeds();
  initializePinForLedsDriver();
}


static void initializePinsForI2C(void)
{
  /* set GPIOs in output mode */
  I2C_SDA_PORT->DDR |= I2C_SDA_PIN;
  I2C_SCL_PORT->DDR |= I2C_SCL_PIN;
}


static void initializePinsForDebugLeds(void)
{
  /* set GPIOs high state */
  DBG_LED0_PORT->ODR |= DBG_LED0_PIN;
  DBG_LED1_PORT->ODR |= DBG_LED1_PIN;

  /* set GPIOs in output mode */
  DBG_LED0_PORT->DDR |= DBG_LED0_PIN;
  DBG_LED1_PORT->DDR |= DBG_LED1_PIN;
}


static void initializePinForLedsDriver(void)
{
  /* set GPIO high state */
  LEDS_ENABLE_PORT->ODR |= LEDS_ENABLE_PIN;

  /* set GPIO in output mode */
  LEDS_ENABLE_PORT->DDR |= LEDS_ENABLE_PIN;
}
