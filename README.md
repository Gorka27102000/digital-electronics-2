# Lab 7: GORKA MANZANARES

### Arduino Uno pinout

1. In the picture of the Arduino Uno board, mark the pins that can be used for the following functions/operations:
   * PWM generators from Timer0, Timer1, Timer2 : 3, 5, 6, 9, 10 and 11
   * analog channels for ADC : 14, 15, 16, 17, 18 and 19
   * UART pins : 0 and 1
   * I2C pins : 18 and 19
   * SPI pins : 10, 11, 12 and 13
   * external interrupt pins INT0, INT1 : 2 and 3

![arduino](https://user-images.githubusercontent.com/114478577/201709610-d6cf3d3a-253d-468f-8a1e-9f5b22a7c1d8.png)


  
### I2C communication

2. Draw a timing diagram of I2C signals when calling function `rtc_read_years()`. Let this function reads one byte-value from RTC DS3231 address `06h` (see RTC datasheet) in the range `00` to `99`. Specify when the SDA line is controlled by the Master device and when by the Slave device. Draw the whole request/receive process, from Start to Stop condition. The image can be drawn on a computer (by [WaveDrom](https://wavedrom.com/) for example) or by hand. Name all parts of timing diagram.

   ![your figure]()

### Meteo station

Consider an application for temperature and humidity measurements. Use sensor DHT12, real time clock DS3231, LCD, and one LED. Every minute, the temperature, humidity, and time is requested from Slave devices and values are displayed on LCD screen. When the temperature is above the threshold, turn on the LED.

3. Draw a flowchart of `TIMER1_OVF_vect` (which overflows every 1&nbsp;sec) for such Meteo station. The image can be drawn on a computer or by hand. Use clear description of individual algorithm steps.

![IMG-3471](https://user-images.githubusercontent.com/114478577/201723386-85f01824-e9de-41d1-a85b-3fda4153adbd.jpg)
