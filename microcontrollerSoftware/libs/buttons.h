/**
  ******************************************************************************
  * @file    buttons.h
  * @author  Mateusz Baczewski
  * @date    14.08.2021
  * @brief   Tractor project buttons control header file.
  ******************************************************************************
**/

#ifndef __BUTTONS_H__
#define __BUTTONS_H__

#include <stdint.h>

typedef enum {
    BUTTON_LEFT_UPPER,
    BUTTON_LEFT_LOWER,
    BUTTON_RIGHT_UPPER,
    BUTTON_RIGHT_LOWER,
    NUMBER_OF_BUTTONS,
} ButtonType;

typedef enum {
    BUTTON_STATE_RELEASED,
    BUTTON_STATE_PRESSED,
} ButtonState;

ButtonState GetButtonState(ButtonType buttonType);

void processButtonsInterrupt(void);

#endif /* __BUTTONS_H__ */