/**
  ******************************************************************************
  * @file    delay.h
  * @author  Mateusz Baczewski
  * @date    9.12.2020
  * @brief   STM8S delays header file.
  ******************************************************************************
**/

#ifndef __DELAY_H__
#define __DELAY_H__

#include <stdint.h>

void initializeDelays(void);

void delayMs(const uint32_t milliseconds);

void decrementTimingDelay(void);

#endif /* __DELAY_H__ */
