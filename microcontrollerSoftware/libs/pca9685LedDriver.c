/**
  ******************************************************************************
  * @file    pca9685LedDriver.c
  * @author  Mateusz Baczewski
  * @date    2.12.2020
  * @brief   LEDs driver PCA9685 source file.
  ******************************************************************************
**/

#include "pca9685LedDriver.h"
#include "definitions.h"
#include "delay.h"
#include "i2cCommunication.h"
#include "stm8s_gpio.h"

#define PCA9685_MODE1 0x00 /**< Mode Register 1 */
#define PCA9685_MODE2 0x01 /**< Mode Register 2 */
#define PCA9685_SUBADR1 0x02 /**< I2C-bus subaddress 1 */
#define PCA9685_SUBADR2 0x03 /**< I2C-bus subaddress 2 */
#define PCA9685_SUBADR3 0x04 /**< I2C-bus subaddress 3 */
#define PCA9685_ALLCALLADR 0x05 /**< LED All Call I2C-bus address */
#define PCA9685_LED0_ON_L 0x06 /**< LED0 on tick, low byte*/
#define PCA9685_LED0_ON_H 0x07 /**< LED0 on tick, high byte*/
#define PCA9685_LED0_OFF_L 0x08 /**< LED0 off tick, low byte */
#define PCA9685_LED0_OFF_H 0x09 /**< LED0 off tick, high byte */
// etc all 16:  LED15_OFF_H 0x45
#define PCA9685_ALLLED_ON_L 0xFA /**< load all the LEDn_ON registers, low */
#define PCA9685_ALLLED_ON_H 0xFB /**< load all the LEDn_ON registers, high */
#define PCA9685_ALLLED_OFF_L 0xFC /**< load all the LEDn_OFF registers, low */
#define PCA9685_ALLLED_OFF_H 0xFD /**< load all the LEDn_OFF registers,high */
#define PCA9685_PRESCALE 0xFE /**< Prescaler for PWM output frequency */
#define PCA9685_TESTMODE 0xFF /**< defines the test mode to be entered */

// MODE1 bits
#define MODE1_ALLCAL 0x01 /**< respond to LED All Call I2C-bus address */
#define MODE1_SUB3 0x02 /**< respond to I2C-bus subaddress 3 */
#define MODE1_SUB2 0x04 /**< respond to I2C-bus subaddress 2 */
#define MODE1_SUB1 0x08 /**< respond to I2C-bus subaddress 1 */
#define MODE1_SLEEP 0x10 /**< Low power mode. Oscillator off */
#define MODE1_AI 0x20 /**< Auto-Increment enabled */
#define MODE1_EXTCLK 0x40 /**< Use EXTCLK pin clock */
#define MODE1_RESTART 0x80 /**< Restart enabled */
// MODE2 bits
#define MODE2_OUTNE_0 0x01 /**< Active LOW output enable input */
#define MODE2_OUTNE_1 0x02 /**< Active LOW output enable input - high impedience */
#define MODE2_OUTDRV 0x04 /**< totem pole structure vs open-drain */
#define MODE2_OCH 0x08 /**< Outputs change on ACK vs STOP */
#define MODE2_INVRT 0x10 /**< Output logic state inverted */

#define FREQUENCY_OSCILLATOR 25000000 /**< Int. osc. frequency in datasheet */

#define PCA9685_PRESCALE_MIN 3 /**< minimum prescale value */
#define PCA9685_PRESCALE_MAX 255 /**< maximum prescale value */

#define PCA9685_MODE1_DEFAULT 0x30

static const uint8_t ledDriverModuleAddress = 0xAA;

static void resetDriver(void);
static void setPwmFrequency(uint16_t frequency);

void initializeLedDriverPca9685(void)
{
    initializeI2CCommunication();

    resetDriver();

    setPwmFrequency(1000);
}

void enableLedDriverPca9685(void)
{
    GPIO_WriteLow(LEDS_ENABLE_PORT, LEDS_ENABLE_PIN);
}

void disableLedDriverPca9685(void)
{
    GPIO_WriteHigh(LEDS_ENABLE_PORT, LEDS_ENABLE_PIN);
}

static void resetDriver(void)
{
    const uint8_t byteToWrite = MODE1_RESTART;

    writeI2CBytes(ledDriverModuleAddress, PCA9685_MODE1, &byteToWrite, 1);

    delayMs(10);
}

static void setPwmFrequency(uint16_t frequency)
{
    if (frequency < 1) {
        frequency = 1;
    }

    float prescalerValue = ((FREQUENCY_OSCILLATOR / (frequency * 4096.0)) + 0.5) - 1;
    if (prescalerValue < PCA9685_PRESCALE_MIN) {
        prescalerValue = PCA9685_PRESCALE_MIN;
    }
    if (prescalerValue > PCA9685_PRESCALE_MAX) {
        prescalerValue = PCA9685_PRESCALE_MAX;
    }
    const uint8_t prescaler = (uint8_t)prescalerValue;

    const uint8_t oldMode = PCA9685_MODE1_DEFAULT & ~MODE1_SLEEP;
    const uint8_t newMode = PCA9685_MODE1_DEFAULT;
    writeI2CBytes(ledDriverModuleAddress, PCA9685_MODE1, &newMode, 1);
    writeI2CBytes(ledDriverModuleAddress, PCA9685_PRESCALE, &prescaler, 1);
    writeI2CBytes(ledDriverModuleAddress, PCA9685_MODE1, &oldMode, 1);
    delayMs(5);
}
