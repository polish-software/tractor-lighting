/**
  ******************************************************************************
  * @file    definitions.h
  * @author  Mateusz Baczewski
  * @date    14.11.2020
  * @brief   Tractor project header file with GPIO pins definitions.
  ******************************************************************************
**/

/* Debug LEDs */
#define DBG_LED0_PIN                   (GPIO_PIN_3)
#define DBG_LED0_PORT                  (GPIOA)

#define DBG_LED1_PIN                   (GPIO_PIN_5)
#define DBG_LED1_PORT                  (GPIOC)


/* LEDs driver enable pin */
#define LEDS_ENABLE_PIN                (GPIO_PIN_7)
#define LEDS_ENABLE_PORT               (GPIOC)
