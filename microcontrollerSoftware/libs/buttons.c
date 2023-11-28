/**
  ******************************************************************************
  * @file    buttons.c
  * @author  Mateusz Baczewski
  * @date    14.08.2021
  * @brief   Tractor project buttons control source file.
  ******************************************************************************
**/

#include "buttons.h"
#include "definitions.h"
#include "stm8s.h"
#include "stm8s_gpio.h"

static GPIO_TypeDef* const buttonPorts[NUMBER_OF_BUTTONS] = { BUTTON1_PORT, BUTTON4_PORT, BUTTON3_PORT, BUTTON2_PORT };
static const GPIO_Pin_TypeDef buttonPins[NUMBER_OF_BUTTONS] = { BUTTON1_PIN, BUTTON4_PIN, BUTTON3_PIN, BUTTON2_PIN };

static uint8_t buttonPressTimers[NUMBER_OF_BUTTONS];
static uint8_t buttonReleaseTimers[NUMBER_OF_BUTTONS];

static const uint8_t buttonChangeStateTimeMs = 30;

static ButtonState buttonStates[NUMBER_OF_BUTTONS];

static uint8_t isButtonPressed(const ButtonType buttonType);

ButtonState GetButtonState(ButtonType buttonType)
{
    return buttonStates[(int)buttonType];
}

void processButtonsInterrupt(void)
{
    for (uint8_t i = 0; i < NUMBER_OF_BUTTONS; ++i) {
        if (buttonStates[i] == BUTTON_STATE_RELEASED) {
            if (isButtonPressed((ButtonType)i)) {
                buttonPressTimers[i]++;
                if (buttonPressTimers[i] >= buttonChangeStateTimeMs) {
                    buttonStates[i] = BUTTON_STATE_PRESSED;
                }
            } else {
                buttonPressTimers[i] = 0;
            }
        } else {
            if (!isButtonPressed((ButtonType)i)) {
                buttonReleaseTimers[i]++;
                if (buttonReleaseTimers[i] >= buttonChangeStateTimeMs) {
                    buttonStates[i] = BUTTON_STATE_RELEASED;
                }
            } else {
                buttonReleaseTimers[i] = 0;
            }
        }
    }
}

static uint8_t isButtonPressed(const ButtonType buttonType)
{
    if (GPIO_ReadInputPin(buttonPorts[buttonType], buttonPins[buttonType]) == RESET) {
        return 1;
    } else {
        return 0;
    }
}
