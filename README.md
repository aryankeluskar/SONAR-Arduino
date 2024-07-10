# SONAR Module in Arduino (High School Physics Project)
SONAR (Sound Navigation and Ranging) Module built with Arduino. Utilized C++ to control the display, fetch input from the ultrasonic sensor, and perform the necessary computations.

### PIN MAP:
  - OLED GND --> ARDUINO GND
  - OLED VCC --> ARDUINO 5V
  - OLED D0  --> ARDUINO D10
  - OLED D1  --> ARDUINO D9
  - OLED RES --> ARDUINO D13
  - OLED DC  --> ARDUINO D11
  - OLED CS  --> ARDUINO D12

### Setup function: 
This function is called once at the beginning of the program. It sets up the serial communication at a baud rate of 9600, initializes the SSD1306 display, sets the trigPin as an output, and the echoPin as an input. It also displays the initial contents of the display buffer on the screen and clears the buffer.

### Loop function: 
This is the main loop function which clears the display, sets text size, color, and cursor position, reads sensor data, calculates distance, prints distance in centimeters on the display, and updates the display, with a 1-second delay between iterations.

### Demo:
![demo](https://github.com/aryankeluskar/SONAR-Arduino/blob/master/Working%20Diagram.png?raw=true)
