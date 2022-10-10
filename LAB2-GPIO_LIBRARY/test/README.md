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