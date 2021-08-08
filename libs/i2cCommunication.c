/**
  ******************************************************************************
  * @file    i2cCommunication.c
  * @author  Mateusz Baczewski
  * @date    17.11.2020
  * @brief   STM8S I2C communication source file.
  ******************************************************************************
**/

#include "i2cCommunication.h"
#include "stm8s_i2c.h"
#include "stm8s_clk.h"

#define I2C_OUTPUT_FREQUENCY           (333000)

#define I2C_TIMEOUT                    ((uint32_t)0x1000)
#define I2C_LONG_TIMEOUT               ((uint32_t)(10 * I2C_TIMEOUT))

volatile uint32_t i2cTimeout = I2C_LONG_TIMEOUT;


uint8_t initializeI2CCommunication(void)
{
  static uint8_t isI2CInitialized = 0;

  if (isI2CInitialized == 0) {
    const uint8_t i2cInputFrequency = CLK_GetClockFreq() / 1000000;

    I2C_Init(I2C_OUTPUT_FREQUENCY, 0, I2C_DUTYCYCLE_2, I2C_ACK_CURR, I2C_ADDMODE_7BIT,
             i2cInputFrequency);

    isI2CInitialized = 1;
    return 1;
  }

  return 0;
}


uint8_t writeI2CBytes(const uint8_t moduleAddress, const uint8_t bytesAddress,
                      const uint8_t* const bytes, const uint8_t numberOfBytes)
{
  /* While the bus is busy */
  i2cTimeout = I2C_LONG_TIMEOUT;
  while (I2C_GetFlagStatus(I2C_FLAG_BUSBUSY)) {
    if ((i2cTimeout--) == 0) return 1; /* error */
  }

  /* Send START condition */
  I2C_GenerateSTART(ENABLE);

  /* Test on EV5 and clear it */
  i2cTimeout = I2C_TIMEOUT;
  while (!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT)) {
    if ((i2cTimeout--) == 0) return 1; /* error */
  }

  /* Send module address for write */
  i2cTimeout = I2C_TIMEOUT;
  I2C_Send7bitAddress(moduleAddress, I2C_DIRECTION_TX);

  /* Test on EV6 and clear it */
  i2cTimeout = I2C_TIMEOUT;
  while (!I2C_CheckEvent(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)) {
    if ((i2cTimeout--) == 0) return 1; /* error */
  }

  /* Send the module internal address to write to : only one byte Address */
  I2C_SendData(bytesAddress);

  /* Test on EV8 and clear it */
  i2cTimeout = I2C_TIMEOUT;
  while (!I2C_CheckEvent(I2C_EVENT_MASTER_BYTE_TRANSMITTED)) {
    if ((i2cTimeout--) == 0) return 1; /* error */
  }

  for (uint8_t i = 0; i < numberOfBytes; i++) {
    /* Send the byte to be written */
    I2C_SendData(bytes[i]);

    /* Test on EV8 and clear it */
    /* Wait till all data have been physically transferred on the bus */
    i2cTimeout = I2C_LONG_TIMEOUT;
    while (!I2C_GetFlagStatus(I2C_FLAG_TRANSFERFINISHED)) {
      if ((i2cTimeout--) == 0) return 1; /* error */
    }
  }

   /* Send STOP condition */
    I2C_GenerateSTOP(ENABLE);

    /* Perform a read on SR1 and SR3 register to clear eventually pending flags */
    (void)I2C->SR1;
    (void)I2C->SR3;

  /* If all operations OK, return (0) */
  return 0; /* OK */
}
