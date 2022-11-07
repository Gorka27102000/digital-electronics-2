# Lab 6: GORKA MANZANARES

### ASCII

1. Complete the table with selected ASCII codes.

   | **Char** | **Decimal** | **Hexadecimal** | **Binary** |
   | :-: | :-: | :-: | :-: |
   | `a` | 97 | 0x61 | `0b0110_0001` |
   | `b` | 98 | 0x62 | `0b0110_0010` |
   | `c` | 99 | 0x63 | `0b0110_0011` |
   | `0` | 48 | 0x30 | `0b0011_0000` |
   | `1` | 49 | 0x31 | `0b0011_0001` |
   | `2` | 50 | 0x32 | `0b0011_0010` |
   | `Esc` | 27 | 0x1B | `0b0001_1011` |
   | `Space` | 32 | 0x20 | `0b0001_0000` |
   | `Tab` | 9 | 0x09 | `0b0000_1001` |
   | `Backspace` | 8 | 0x08 | `0b0000_1000` |
   | `Enter` | 10 | 0x0A | `0b0000_1010` |

### UART communication

2. Draw a timing diagram of the output from UART/USART when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd). The image can be drawn on a computer (by [WaveDrom](https://wavedrom.com/) for example) or by hand. Name all parts of timing diagram.

  ![IMG-3259](https://user-images.githubusercontent.com/114478577/200403350-3a13b7c5-7228-47fa-adf4-8f2517969fb2.jpg)


3. Draw a flowchart for function `uint8_t get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear description of individual algorithm steps.

   ![your figure]()
