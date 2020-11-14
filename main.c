/**
  ******************************************************************************
  * @file    main.c
  * @author  Mateusz Baczewski
  * @date    12.11.2020
  * @brief   Tractor project main source file.
  ******************************************************************************
**/

//#include "stm8s.h"
//#include "stm8s_gpio.h"
#include "config.h"

int main(void)
{

  initializeClocks();
  initializePins();

  while(1) {

  }
}