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

}
