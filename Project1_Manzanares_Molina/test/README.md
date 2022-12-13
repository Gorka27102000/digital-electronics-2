## Team members

Alberto Molina: C code, flowchart, Readme.

Gorka Manzanares: C code, set up the code, Readme.

## Hardware description

The devices we have used are the arduino board, the board, an LED, a resistor, the encoder, the LCD and the joystick as a button. 
The joystick is synchronised with the LED, so that if it is held down, the LED will be on. Otherwise, it stays off.
As for the encoder, we use it to make a counter that is displayed on the LCD. 

<img src=https://user-images.githubusercontent.com/114478577/207440083-38875a0d-5751-4bb2-8ff7-52cf05d9aafa.png>

The joystick has five ports: GND, 5V, VRx, VRy and SW

GND is connected to ground node
5V is connected to Vcc node
VRx is an analog output that gives voltage proportional to X axis, connected to analog port PC0
VRy is an analog output that gives voltage proportional to Y axis, connected to analog port PC1
SW is the digital output of the pushbutton, connected to digital port PB4
![arduino-joystick-conexion](https://user-images.githubusercontent.com/114478577/207445385-25c1c958-ec0e-4fa3-8ddf-4306e4e7b006.png)

The rotary encoder has five ports: CLK, DT, SW, +, GND
![rotary-encoder](https://user-images.githubusercontent.com/114478577/207445605-955bde55-cbb7-41d6-ae8f-5b362c47df10.jpg)


## Software description

![Bloc de notas sin título-5](https://user-images.githubusercontent.com/114478577/207445166-b400fbd1-5b22-4cab-b617-410a0bfd8c24.jpg)

![Bloc de notas sin título-6](https://user-images.githubusercontent.com/114478577/207445171-802f5afb-97cb-4b38-92d4-ab5e7d77a100.jpg)


## Video
https://youtube.com/shorts/ZP0koT1qq0o

## References
https://www.taloselectronics.com/blogs/tutoriales/encoder-rotativo

http://www.electronicworld.com.mx/electronica/contador-asc-des-encoder-rotativo-lcd-pic18f4550-pic-c-compiler/
