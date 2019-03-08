/*
Example for HDC1000 Click

    Date          : Sep 2018.
    Author        : Nenad Filipovic

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures, set INT pin as input.
- Application Initialization - Initialization driver enable's - I2C,
     default configurates HDC1000 sensor and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of HDC1000 Click board.
     Measured temperature and humidity,
     calculate dewpoint value from the HDC1000 sensor.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 3 sec.

Additional Functions :

- UART
- Conversions

*/

#include "Click_HDC1000_types.h"
#include "Click_HDC1000_config.h"


float humidity;
float temperature;
char logText[50];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_HDC1000_I2C_CFG[0] );
    mikrobus_logInit( _MIKROBUS2, 9600 );

    Delay_100ms();
}

void applicationInit()
{
    hdc1000_i2cDriverInit( (T_HDC1000_P)&_MIKROBUS1_GPIO, (T_HDC1000_P)&_MIKROBUS1_I2C, _HDC1000_ADDR );

    hdc1000_defaultConfiguration();

    mikrobus_logWrite( "------------------------", _LOG_LINE );
    mikrobus_logWrite( "     Initialization", _LOG_LINE );
    mikrobus_logWrite( "------------------------", _LOG_LINE );

    Delay_100ms();
}

void applicationTask()
{
    temperature = hdc1000_getTemperature();
    humidity = hdc1000_getHumidity();

    mikrobus_logWrite( " Temperature :", _LOG_TEXT );
    FloatToStr( temperature, logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( " ?C", _LOG_LINE );

    mikrobus_logWrite( " Humidity    :", _LOG_TEXT );
    FloatToStr( humidity, logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( " %", _LOG_LINE );

    mikrobus_logWrite( "------------------------", _LOG_LINE );

    Delay_1sec();
    Delay_1sec();
    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}