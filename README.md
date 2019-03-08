![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# HDC1000 Click

---

- **CIC Prefix**  : HDC1000
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Sep 2018.

---

### Software Support

We provide a library for the HDC1000 Click on our [LibStock](https://libstock.mikroe.com/projects/view/1240/hdc1000-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control HDC1000 Click board. 
Library performs the communication with the device via I2C driver by writting to registers and by reading from registers.
Library set default configuration, get temperature and humidity data from register. 
Convert temperature data to degree Celsius [ °C ] and humidity value to percentage [ % ]
from the HDC1000 Click sensor [ HDC1000 ] and send results via UART.

Key functions :

- ``` uint16_t hdc1000_readData( uint8_t address ) ``` - Generic read data function from HDC1000
- ``` float hdc1000_getTemperature() ``` - Get temperature value
- ``` float hdc1000_getHumidity() ``` - Get humidity value

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures, set INT pin as input.
- Application Initialization - Initialization driver enable's - I2C,
     default configurates HDC1000 sensor and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of HDC1000 Click board.
     Measured temperature and humidity,
     calculate dewpoint value from the HDC1000 sensor.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 3 sec.


```.c

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

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1240/hdc1000-click) page.

Other mikroE Libraries used in the example:

- I2C
- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
