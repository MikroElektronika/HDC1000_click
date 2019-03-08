/*
    __hdc1000_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__hdc1000_driver.h"
#include "__hdc1000_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __HDC1000_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _HDC1000_ADDR                = 0x40;

const uint8_t _HDC1000_TEMP                = 0x00;
const uint8_t _HDC1000_HUMI                = 0x01;
const uint8_t _HDC1000_CONFIG              = 0x02;

const uint8_t _HDC1000_SERID_1             = 0xFB;
const uint8_t _HDC1000_SERID_2             = 0xFC;
const uint8_t _HDC1000_SERID_3             = 0xFD;
const uint8_t _HDC1000_MFID                = 0xFE;
const uint8_t _HDC1000_DEVID               = 0xFF;

const uint8_t _HDC1000_RST                 = 0x80;
const uint8_t _HDC1000_HEAT_ON             = 0x20;
const uint8_t _HDC1000_HEAT_OFF            = 0x00;
const uint8_t _HDC1000_BOTH_TEMP_HUMI      = 0x10;
const uint8_t _HDC1000_SINGLE_MEASUR       = 0x00;
const uint8_t _HDC1000_TEMP_HUMI_14BIT     = 0x00;
const uint8_t _HDC1000_TEMP_11BIT          = 0x04;
const uint8_t _HDC1000_HUMI_11BIT          = 0x01;
const uint8_t _HDC1000_HUMI_8BIT           = 0x02;

const float _HDC1000_TEMP_CONST          = 0.0025177;                                       //For 14bit resolution
const float _HDC1000_HUMI_CONST          = 0.0015259;                                       //For 14bit resolution

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __HDC1000_DRV_SPI__

void hdc1000_spiDriverInit(T_HDC1000_P gpioObj, T_HDC1000_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __HDC1000_DRV_I2C__

void hdc1000_i2cDriverInit(T_HDC1000_P gpioObj, T_HDC1000_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __HDC1000_DRV_UART__

void hdc1000_uartDriverInit(T_HDC1000_P gpioObj, T_HDC1000_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */

/* Generic write data function to HDC1000 */
void hdc1000_writeData( uint8_t address, uint16_t writeCommand )
{
    uint8_t buffer[ 3 ];
    buffer[ 0 ] = address;
    buffer[ 1 ] = ( writeCommand >> 8 ) & 0xFF;
    buffer[ 2 ] = writeCommand & 0xFF;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, buffer, 3, END_MODE_STOP );
}

/* Generic read data function from HDC1000 */
uint16_t hdc1000_readData( uint8_t address )
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 2 ];
    uint16_t result;

    writeReg[ 0 ] = address;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, writeReg, 1, END_MODE_RESTART );
    Delay_10ms();
    Delay_10ms();
    hal_i2cRead( _slaveAddress, readReg, 2, END_MODE_STOP );

    result = 0x00;
    result = readReg[ 0 ];
    result <<= 8;
    result |= readReg[ 1 ];

    return result;
}

/* Default configurates */
void hdc1000_defaultConfiguration()
{
    uint8_t buffer[ 3 ];
    buffer[ 0 ] = _HDC1000_CONFIG;
    buffer[ 1 ] = _HDC1000_BOTH_TEMP_HUMI;
    buffer[ 2 ] = _HDC1000_TEMP_HUMI_14BIT;
  
    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, buffer, 3, END_MODE_STOP );
}

/* Get temperature value */
float hdc1000_getTemperature()
{
    uint16_t buffer;
    float temperature;

    buffer = hdc1000_readData( _HDC1000_TEMP );

    temperature = ( ( float ) buffer * _HDC1000_TEMP_CONST ) - 40.00;
    
    return temperature;
}

/* Get humidity value */
float hdc1000_getHumidity()
{
    uint16_t buffer;
    float humidity;

    buffer = hdc1000_readData( _HDC1000_HUMI );

    humidity = ( float ) buffer * _HDC1000_HUMI_CONST ;

    return humidity;
}




/* -------------------------------------------------------------------------- */
/*
  __hdc1000_driver.c

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