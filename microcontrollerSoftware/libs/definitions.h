/**
  ******************************************************************************
  * @file    definitions.h
  * @author  Mateusz Baczewski
  * @date    14.11.2020
  * @brief   Tractor project header file with GPIO pins definitions.
  ******************************************************************************
**/

#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

/* Debug LEDs */
#define DBG_LED0_PIN (GPIO_PIN_3)
#define DBG_LED0_PORT (GPIOA)

#define DBG_LED1_PIN (GPIO_PIN_5)
#define DBG_LED1_PORT (GPIOC)

/* I2C pins */
#define I2C_SDA_PIN (GPIO_PIN_5)
#define I2C_SDA_PORT (GPIOB)

#define I2C_SCL_PIN (GPIO_PIN_4)
#define I2C_SCL_PORT (GPIOB)

/* LEDs driver enable pin */
#define LEDS_ENABLE_PIN (GPIO_PIN_7)
#define LEDS_ENABLE_PORT (GPIOC)

/*buttons pins*/
#define BUTTON1_PIN (GPIO_PIN_3)
#define BUTTON1_PORT (GPIOC)

#define BUTTON2_PIN (GPIO_PIN_4)
#define BUTTON2_PORT (GPIOC)

#define BUTTON3_PIN (GPIO_PIN_5)
#define BUTTON3_PORT (GPIOD)

#define BUTTON4_PIN (GPIO_PIN_6)
#define BUTTON4_PORT (GPIOD)

/*battery measure pin*/
#define BAT_MEASURE_PIN (GPIO_PIN_2)
#define BAT_MEASURE_PORT (GPIOD)

/*potentiometer pin*/
#define POTENTIOMETER_PIN (GPIO_PIN_3)
#define POTENTIOMETER_PORT (GPIOD)

#endif /* __DEFINITIONS_H__ */
