# digital-electronics-2

# Lab 5: GORKA MANZANARES

### Analog-to-Digital Conversion

1. Complete table with voltage divider, calculated, and measured ADC values for all five push buttons.

   | **Push button** | **PC0 voltage** | **ADC value (calculated)** | **ADC value (measured)** | **ADC value (measured, hex)** |
   | :-: | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V     | 0    | 0    | 0   |
   | Up     | 0.495&nbsp;V | 101  | 99   | 63  |
   | Down   | 1.203&nbsp;V | 246  | 257  | 101 |
   | Left   | 1.97&nbsp;V  | 403  | 409  | 199 |
   | Select | 3.18&nbsp;V  | 651  | 639  | 27F |
   | none   | 5&nbsp;V     | 1023 | 1023 | 3FF |

### Temperature meter

Consider an application for temperature measurement. Use analog temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, and a LED. Every 30 seconds, the temperature is measured and the value is displayed on LCD screen. When the temperature is too high, the LED will turn on.

2. Draw a schematic of temperature meter. The image can be drawn on a computer or by hand. Always name all components, their values and pin names!

   ![IMG-2890](https://user-images.githubusercontent.com/114478577/198678796-91c94573-a3f5-44a6-8385-6e6f0e9b5ec8.jpg)


3. Draw two flowcharts for interrupt handler `TIMER1_OVF_vect` (which overflows every 1&nbsp;sec) and `ADC_vect`. The image can be drawn on a computer or by hand. Use clear descriptions of individual algorithm steps.

   ![IMG-2915](https://user-images.githubusercontent.com/114478577/198683783-a65d0a2d-3bdb-45ef-8069-3f837d60a095.jpg)
