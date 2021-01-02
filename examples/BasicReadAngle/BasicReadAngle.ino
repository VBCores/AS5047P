/*
  BasicReadAngle.ino

  This is a basic example program to read the angle position from a AS5047 rotary encoder.

  The angle postion gets updated and printed to the serial consol once a second. 

  More Information can be found here:
  https://github.com/jonas-merkle/AS5047P
*/

// include the library for the AS5047P sensor.
#include "AS5047P.h"

// define a led pin.
#define LED_PIN 13

// define the chip select port.
#define AS5047P_CHIP_SELECT_PORT 12 

// define the spi bus speed 
#define AS5047P_CUSTOM_SPI_BUS_SPEED 100000

// initialize a new AS5047P sensor object.
AS5047P as5047p(AS5047P_CHIP_SELECT_PORT, AS5047P_CUSTOM_SPI_BUS_SPEED);

// arduino setup routine
void setup() {

  // set the pinmode of the led pin to output.
  pinMode(LED_PIN, OUTPUT);

  // initialize the serial bus for the communication with your pc.
  Serial.begin(115200);

}

// arduino loop routine
void loop() {

  // read the sensor
  digitalWrite(LED_PIN, HIGH);                    // activate the led.
  Serial.print("Angle: ");                        // print some text to the serial consol.
  Serial.println(as5047p.readAngleDegree());      // read the angle value from the AS5047P sensor an print it to the serial consol.
  delay(500);                                     // wait for 500 milli seconds.

  // wait
  digitalWrite(LED_PIN, LOW);                     // deactivate the led.
  delay(500);                                     // wait for 500 milli seconds.

}