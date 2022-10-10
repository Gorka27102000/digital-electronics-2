# digital-electronics-2

## Lab 1: GORKA MANZANARES

### Morse code

**1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:**

```c
#define LED_GREEN PB5   // PB5 is AVR pin where green on-board LED 
                        // is connected
#define SHORT_DELAY 250 // Delay in milliseconds
#define LONG_DELAY 950
#define SHORTEST_DELAY 150
#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
#include <util/delay.h> // Functions for busy-wait delay loops

int main(void)
{
    // Set pin where on-board LED is connected as output
    
    pinMode(LED_GREEN, OUTPUT);

    // Infinite loop
    while (1)
    {
        // Generate a lettre `A` Morse code

        // WRITE YOUR CODE HERE
        digitalWrite(LED_GREEN, HIGH);
        _delay_ms(SHORT_DELAY);   // dot on;led on
        digitalWrite(LED_GREEN, LOW);
        _delay_ms(SHORTEST_DELAY);  //led off
        digitalWrite(LED_GREEN, HIGH);
        _delay_ms(LONG_DELAY); // coma on;led on
        digitalWrite(LED_GREEN, LOW);
        _delay_ms(SHORTEST_DELAY); //led off
    }

    // Will never reach this
    return 0;
}
```

**2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!**

![Captura de pantalla (57)](https://user-images.githubusercontent.com/114478577/193689278-a6c965d3-c64c-473d-a0de-2c6b606ccb45.png)


# Lab 2: GORKA MANZANARES

### GPIO control registers

1. Complete the table for DDRB and PORTB control register values.

   | **DDRB** | **PORTB** | **Direction** | **Internal pull-up resistor** | **Description** |
   | :-: | :-: | :-: | :-: | :-- |
   | 0 | 0 | input | no | Tri-state, high-impedance |
   | 0 | 1 | input | yes | Pxn will source current if ext. pulled low. |
   | 1 | 0 | output | no | Output low (sink) |
   | 1 | 1 | output | no | Output high (source) |

### GPIO library

2. Complete the table with code sizes from three versions of the blink application.

   | **Version** | **Size [B]** |
   | :-- | :-: |
   | Ver. 1: Arduino-style | 480 bytes |
   | Ver. 2: Registers | 182 bytes |
   | Ver. 3: Library functions | 182 bytes |

### Traffic light

3. Scheme of traffic light application with one red/yellow/green light for cars, one red/green light for pedestrians, and one push button. Connect AVR device, LEDs, resistors, push button (for pedestrians), and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

  ![semaforo](https://user-images.githubusercontent.com/114478577/194750635-1fdad118-0421-4963-863e-cdac05dc3dcd.png)
