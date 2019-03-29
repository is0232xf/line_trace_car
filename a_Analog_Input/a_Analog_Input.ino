/* Analog input
 
 Reads an analog input pin, maps the result to a range from 0 to
 65535 and uses the result to set the pulse width modulation (PWM) of
 an output pin.  Also prints the results to the serial monitor.

 The circuit:
 * Potentiometer connected to analog pin 1.
 Center pin of the potentiometer goes to the analog pin.
 Side pins of the potentiometer go to +3.3V and ground.
 * LED connected from digital pin 14 to 3.3V( defined as BOARD_LED_PIN )
 If you have CM-900, you have to connect LED to any PWM enable pin.
 
                  Compatibility
 CM900                  O
 OpenCM9.04             O

 created 16 Nov 2012
 by ROBOTIS CO,.LTD.
 */

const int analogInPin_left = 1; // Analog input pin that the potentiometer
const int analogInPin_right = 3; // Analog input pin that the potentiometer

// These variables will change:
float sensorValue_left = 0;        // value read from the pot
float sensorValue_right = 0;        // value read from the pot
float outputValue_left = 0;        // value output to the PWM
float outputValue_right = 0;        // value output to the PWM

void setup() {
  // Configure the ADC pin
  pinMode(analogInPin_right, INPUT_ANALOG);
  pinMode(analogInPin_left, INPUT_ANALOG);
  // Configure LED pin
  pinMode(BOARD_LED_PIN, PWM);
}

void loop() {
  // read the analog in value:
  sensorValue_left = analogRead(analogInPin_left);
  sensorValue_right = analogRead(analogInPin_right);
  // map it to the range of the analog out:
  outputValue_left = map(sensorValue_left, 0, 4095, 0, 100);
  outputValue_right = map(sensorValue_right, 0, 4095, 0, 100);

  // print the results to the serial monitor:
  SerialUSB.print("left sensor = " );
  SerialUSB.print(sensorValue_left);
  SerialUSB.print("\t output = ");
  SerialUSB.println(outputValue_left);
  
  SerialUSB.print("right sensor = " );
  SerialUSB.print(sensorValue_right);
  SerialUSB.print("\t output = ");
  SerialUSB.println(outputValue_right);
  delay(10);
}


