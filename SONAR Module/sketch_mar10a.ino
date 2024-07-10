/*
  PIN MAP:
  OLED GND --> ARDUINO GND
  OLED VCC --> ARDUINO 5V
  OLED D0  --> ARDUINO D10
  OLED D1  --> ARDUINO D9
  OLED RES --> ARDUINO D13
  OLED DC  --> ARDUINO D11
  OLED CS  --> ARDUINO D12
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// defines pins numbers
const int trigPin = 5;
const int echoPin = 6;
// defines variables
long duration;
int distance;
// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

/**
 * Initializes the setup of the Arduino.
 *
 * This function is called once at the beginning of the program. It sets up the serial communication
 * at a baud rate of 9600, initializes the SSD1306 display, sets the trigPin as an output, and the
 * echoPin as an input. It also displays the initial contents of the display buffer on the screen
 * and clears the buffer.
 *
 * @return void
 * 
 */
void setup(){
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds
  // Clear the buffer
  display.clearDisplay();
}


/**
 * Main loop function that clears the display, sets text size, color, and cursor position,
 * reads sensor data, calculates distance, prints distance in centimeters on the display,
 * and updates the display, with a 1-second delay between iterations.
 *
 * The formula to compute distance from duration is: distance = duration * 0.034 / 2.
 * This formula is used because the ultrasonic sensor is emitting a sound wave
 * and measuring the time it takes for the sound wave to bounce off an object and return. By
 * multiplying the time by the speed of sound, we can calculate the distance the sound wave
 * traveled. The 2 is used to convert the time to centimeters because the speed of sound is
 * typically given in meters per second, and there are 100 centimeters in a meter.
 * 
 * @return void
 */
void loop()
{
  display.clearDisplay();
  
  display.setTextSize(3); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(5, 0);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  display.print(distance);
  display.println(" cm");
  display.display();
  delay(1000);
}
