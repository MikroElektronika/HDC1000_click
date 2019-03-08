/*
    __hdc1000_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __hdc1000_driver.h
@brief    HDC1000 Driver
@mainpage HDC1000 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   HDC1000
@brief      HDC1000 Click Driver
@{

| Global Library Prefix | **HDC1000** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Sep 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _HDC1000_H_
#define _HDC1000_H_

/** 
 * @macro T_HDC1000_P
 * @brief Driver Abstract type 
 */
#define T_HDC1000_P    const uint8_t*

/** @defgroup HDC1000_COMPILE Compilation Config */              /** @{ */

//  #define   __HDC1000_DRV_SPI__                            /**<     @macro __HDC1000_DRV_SPI__  @brief SPI driver selector */
   #define   __HDC1000_DRV_I2C__                            /**<     @macro __HDC1000_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __HDC1000_DRV_UART__                           /**<     @macro __HDC1000_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup HDC1000_VAR Variables */                           /** @{ */

extern const uint8_t _HDC1000_ADDR;

extern const uint8_t _HDC1000_TEMP;
extern const uint8_t _HDC1000_HUMI;
extern const uint8_t _HDC1000_CONFIG;

extern const uint8_t _HDC1000_SERID_1;
extern const uint8_t _HDC1000_SERID_2;
extern const uint8_t _HDC1000_SERID_3;
extern const uint8_t _HDC1000_MFID;
extern const uint8_t _HDC1000_DEVID;

extern const uint8_t _HDC1000_RST;
extern const uint8_t _HDC1000_HEAT_ON;
extern const uint8_t _HDC1000_HEAT_OFF;
extern const uint8_t _HDC1000_BOTH_TEMP_HUMI;
extern const uint8_t _HDC1000_SINGLE_MEASUR;
extern const uint8_t _HDC1000_TEMP_HUMI_14BIT;
extern const uint8_t _HDC1000_TEMP_11BIT;
extern const uint8_t _HDC1000_HUMI_11BIT;
extern const uint8_t _HDC1000_HUMI_8BIT;


                                                                       /** @} */
/** @defgroup HDC1000_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup HDC1000_INIT Driver Initialization */              /** @{ */

#ifdef   __HDC1000_DRV_SPI__
void hdc1000_spiDriverInit(T_HDC1000_P gpioObj, T_HDC1000_P spiObj);
#endif
#ifdef   __HDC1000_DRV_I2C__
void hdc1000_i2cDriverInit(T_HDC1000_P gpioObj, T_HDC1000_P i2cObj, uint8_t slave);
#endif
#ifdef   __HDC1000_DRV_UART__
void hdc1000_uartDriverInit(T_HDC1000_P gpioObj, T_HDC1000_P uartObj);
#endif


/** @defgroup HDC1000_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic write 16-bit data function
 *
 * @param[in] address         8-bit data register address
 *
 * @param[in] writeCommand    16-bit data command to write
 *
 * Function write 16-bit data to 8-bit data register address
 * on the HDC1000 sensor.
 */
void hdc1000_writeData( uint8_t address, uint16_t writeCommand );

/**
 * @brief Generic read 16-bit data function
 *
 * @param[in] address         Register address
 *
 * @return
 * 16-bit data from addressed register on the HDC1000
 *
 * @note
 * delay is 20 ms (  6,5 ms + 6,35 ms ),
 * conversion time for 14-bit values of temperature and humidity.
 *
 * Function read 16-bit data from 8-bit data register address
 * on the HDC1000 sensor.
 */
uint16_t hdc1000_readData( uint8_t address );

/**
 * @brief Default configurates
 *
 * Function set HDC1000 sensor to default configurates.
 */
void hdc1000_defaultConfiguration();

/**
 * @brief Get temperature value
 *
 * @return
 * float temperature data degrees Celsius [ ºC ]
 *
 * Function gets temperature data from the HDC1000 sensor.
 */
float hdc1000_getTemperature();

/**
 * @brief Get humidity value
 *
 * @return
 * float humidity data percent [ % ]
 *
 * Function gets humidity data from the HDC1000 sensor.
 */
float hdc1000_getHumidity();






                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_HDC1000_STM.c
    @example Click_HDC1000_TIVA.c
    @example Click_HDC1000_CEC.c
    @example Click_HDC1000_KINETIS.c
    @example Click_HDC1000_MSP.c
    @example Click_HDC1000_PIC.c
    @example Click_HDC1000_PIC32.c
    @example Click_HDC1000_DSPIC.c
    @example Click_HDC1000_AVR.c
    @example Click_HDC1000_FT90x.c
    @example Click_HDC1000_STM.mbas
    @example Click_HDC1000_TIVA.mbas
    @example Click_HDC1000_CEC.mbas
    @example Click_HDC1000_KINETIS.mbas
    @example Click_HDC1000_MSP.mbas
    @example Click_HDC1000_PIC.mbas
    @example Click_HDC1000_PIC32.mbas
    @example Click_HDC1000_DSPIC.mbas
    @example Click_HDC1000_AVR.mbas
    @example Click_HDC1000_FT90x.mbas
    @example Click_HDC1000_STM.mpas
    @example Click_HDC1000_TIVA.mpas
    @example Click_HDC1000_CEC.mpas
    @example Click_HDC1000_KINETIS.mpas
    @example Click_HDC1000_MSP.mpas
    @example Click_HDC1000_PIC.mpas
    @example Click_HDC1000_PIC32.mpas
    @example Click_HDC1000_DSPIC.mpas
    @example Click_HDC1000_AVR.mpas
    @example Click_HDC1000_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __hdc1000_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */