/**
  ******************************************************************************
  * @file    i2cCommunication.h
  * @author  Mateusz Baczewski
  * @date    17.11.2020
  * @brief   STM8S I2C communication header file.
  ******************************************************************************
**/

#ifndef __I2C_COMMUNICATION_H__
#define __I2C_COMMUNICATION_H__

#include <stdint.h>


uint8_t initializeI2CCommunication(void);


uint8_t writeI2CBytes(const uint8_t moduleAddress, const uint8_t bytesAddress,
                      const uint8_t* const bytes, const uint8_t numberOfBytes);

#endif /* __I2C_COMMUNICATION_H__ */
