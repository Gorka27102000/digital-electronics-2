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



/***********************************************************************
 * 
 * Blink two LEDs using functions from GPIO and Timer libraries. Do not 
 * use delay library any more.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2018 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#define LED_GREEN PB5  // Arduino Uno on-board LED
#define LED_RED PB0    // External active-low LED


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle two LEDs using the internal 8- and 16-bit 
 *           Timer/Counter.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Set pins where LEDs are connected as output
    GPIO_mode_output(&DDRB, LED_GREEN);
    GPIO_mode_output(&DDRB, LED_RED);
    // Configuration of 16-bit Timer/Counter1 for LED blinking
    // Set the overflow prescaler to 262 ms and enable interrupt
    TIM1_overflow_262ms();
    TIM1_overflow_interrupt_enable();

    TIM0_overflow_16ms();
    TIM0_overflow_interrupt_enable();
    // Enables interrupts by setting the global interrupt mask
    sei();  // global enable

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Toggle on-board LED.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    PORTB = PORTB ^ (1<<LED_RED);
}

ISR(TIMER0_OVF_vect)
{
  static uint8_t no_of_overflows = 0;
  
  no_of_overflows++;
  if (no_of_overflows >=6) {
    no_of_overflows = 0;
    PORTB = PORTB ^ (1<<LED_GREEN);
}
}






#ifndef TIMER_H
# define TIMER_H

/***********************************************************************
 * 
 * Timer library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 * @file 
 * @defgroup fryza_timer Timer Library <timer.h>
 * @code #include "timer.h" @endcode
 *
 * @brief Timer library for AVR-GCC.
 *
 * The library contains macros for controlling the timer modules.
 *
 * @note Based on Microchip Atmel ATmega328P manual and no source file
 *       is needed for the library.
 * @author Tomas Fryza, Dept. of Radio Electronics, Brno University 
 *         of Technology, Czechia
 * @copyright (c) 2019 Tomas Fryza, This work is licensed under 
 *                the terms of the MIT license
 * @{
 */


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>


/* Defines -----------------------------------------------------------*/
/**
 * @name  Definitions for 16-bit Timer/Counter1
 * @note  t_OVF = 1/F_CPU * prescaler * 2^n where n = 16, F_CPU = 16 MHz
 */
/** @brief Stop timer, prescaler 000 --> STOP */
#define TIM1_stop()           TCCR1B &= ~((1<<CS12) | (1<<CS11) | (1<<CS10));
/** @brief Set overflow 4ms, prescaler 001 --> 1 */
#define TIM1_overflow_4ms()   TCCR1B &= ~((1<<CS12) | (1<<CS11)); TCCR1B |= (1<<CS10);
/** @brief Set overflow 33ms, prescaler 010 --> 8 */
#define TIM1_overflow_33ms()  TCCR1B &= ~((1<<CS12) | (1<<CS10)); TCCR1B |= (1<<CS11);
/** @brief Set overflow 262ms, prescaler 011 --> 64 */
#define TIM1_overflow_262ms() TCCR1B &= ~(1<<CS12); TCCR1B |= (1<<CS11) | (1<<CS10);
/** @brief Set overflow 1s, prescaler 100 --> 256 */
#define TIM1_overflow_1s()    TCCR1B &= ~((1<<CS11) | (1<<CS10)); TCCR1B |= (1<<CS12);
/** @brief Set overflow 4s, prescaler // 101 --> 1024 */
#define TIM1_overflow_4s()    TCCR1B &= ~(1<<CS11); TCCR1B |= (1<<CS12) | (1<<CS10);

/** @brief Enable overflow interrupt, 1 --> enable */
#define TIM1_overflow_interrupt_enable()  TIMSK1 |= (1<<TOIE1);
/** @brief Disable overflow interrupt, 0 --> disable */
#define TIM1_overflow_interrupt_disable() TIMSK1 &= ~(1<<TOIE1);


/**
 * @name  Definitions for 8-bit Timer/Counter0
 * @note  t_OVF = 1/F_CPU * prescaler * 2^n where n = 8, F_CPU = 16 MHz
 */
// WRITE YOUR CODE HERE
#define TIM0_stop()           TCCR0B &= ~((1<<CS02) | (1<<CS01) | (1<<CS00));
//#define TIM0_16us()         
//#define TIM0_128us()
//#define TIM0_1ms()
//#define TIM0_4ms()
#define TIM0_overflow_16ms()  TCCR0B &= ~(1<<CS01); TCCR0B |= (1<<CS02) | (1<<CS00);

/** @brief Enable overflow interrupt, 1 --> enable */
#define TIM0_overflow_interrupt_enable()  TIMSK0 |= (1<<TOIE0);
/** @brief Disable overflow interrupt, 0 --> disable */
#define TIM0_overflow_interrupt_disable() TIMSK0 &= ~(1<<TOIE0);
/**
 * @name  Definitions for 8-bit Timer/Counter2
 * @note  t_OVF = 1/F_CPU * prescaler * 2^n where n = 8, F_CPU = 16 MHz
 */
// WRITE YOUR CODE HERE


/** @} */

#endif
