/**
  ******************************************************************************
  * @file    delay.c
  * @author  Mateusz Baczewski
  * @date    9.12.2020
  * @brief   STM8S delays source file.
  ******************************************************************************
**/

#include "delay.h"
#include "stm8s_tim4.h"

static volatile uint32_t timingDelay;

void initializeDelays(void)
{
    /* set timer overflow after 1 millisecond */
    /* 4 MHz / 32 / 125 = 1 kHz */
    const uint8_t autoreloadValue = 125 - 1;
    TIM4_TimeBaseInit(TIM4_PRESCALER_32, autoreloadValue);
    TIM4_GenerateEvent(TIM4_EVENTSOURCE_UPDATE);
    while (TIM4_GetFlagStatus(TIM4_FLAG_UPDATE) == RESET)
        ;
    TIM4_ClearFlag(TIM4_FLAG_UPDATE);

    /* enable update interrupt */
    TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);

    enableInterrupts();

    TIM4_Cmd(ENABLE);
}

void delayMs(const uint32_t milliseconds)
{
    timingDelay = milliseconds;

    while (timingDelay != 0)
        ;
}

void decrementTimingDelay(void)
{
    if (timingDelay != 0) {
        timingDelay--;
    }
}
