#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>
#include <gpio.h>
#include <lcd.h>      //LCD library
#include <stdlib.h>   //for conversion of variable number to string
 
//Led define pin13
#define LED_GREEN PB5
#define PB5 13
 
#define SHORT_DELAY 250 // Delay in milliseconds
#ifndef F_CPU
#define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif
 
//Button define Pin7
#define BUTTON PD7
#define PD7 7
 
//Encoder define
#define encoderCLK PB2  //A
#define PB2 10
#define encoderDT PB3  //B
#define PB3 11
int encoderPos = 0;
int encoderPinALast = LOW;
int n = LOW;
 
 
int main(void)
{
    // Set pin where on-board LED is connected as output, set encoderCLK and encoderDT as imputs
    pinMode(LED_GREEN, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
    pinMode(encoderCLK, INPUT);
    pinMode(encoderDT, INPUT);
    int val=0;
    int contador=0;
    char lcd_string[8];
    lcd_init(LCD_DISP_ON_CURSOR);
 
    //Put string(s) on LCD screen
    lcd_clrscr();
    lcd_gotoxy(1, 0);
    lcd_puts("Counter:");
    int encoderPos = 0;
  while (encoderPos<=15)
  {
    val=digitalRead(BUTTON);
   
    if  (val==HIGH)
    {
      digitalWrite(LED_GREEN,LOW);
    }
    else
    {
      digitalWrite(LED_GREEN,HIGH);
    }
    _delay_ms(SHORT_DELAY);
     n = digitalRead(encoderCLK);
    if ((encoderPinALast == LOW) && (n == HIGH))
    {
      if (digitalRead(encoderDT) == LOW)
      {
        encoderPos--;
        contador--;
        itoa(contador, lcd_string, 10);
        lcd_gotoxy(8, 0);
        lcd_puts(lcd_string);
      }
      else
      {
        encoderPos++;
        contador++;
        itoa(contador, lcd_string, 10);
        lcd_gotoxy(8, 0);
        lcd_puts(lcd_string);
      }
    }
    encoderPinALast = n;
    digitalWrite(LED_GREEN,HIGH);
  }
  return 0;
}
