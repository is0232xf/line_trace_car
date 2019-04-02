#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP

#define WH_right 1
#define WH_left 2

Dynamixel Dxl(DXL_BUS_SERIAL1);

const int analogInPin_left = 1; // Analog input pin that the potentiometer
const int analogInPin_right = 3; // Analog input pin that the potentiometer
int random_num;

// These variables will change:
int sensorValue_left = 0;        // value read from the pot
int sensorValue_right = 0;        // value read from the pot

void setup() {
  //Serial.begin(9600);
  randomSeed(analogRead(0));
  Dxl.begin(3);
  Dxl.wheelMode(WH_right); //wheelMode() is to use wheel mode
  Dxl.wheelMode(WH_left); //wheelMode() is to use wheel mode
  // Configure the ADC pin
  pinMode(analogInPin_right, INPUT_ANALOG);
  pinMode(analogInPin_left, INPUT_ANALOG);
  // Configure LED pin
  pinMode(BOARD_LED_PIN, PWM);
}

void loop() {
  random_num = random(100);
  // read the analog in value:
  sensorValue_left = analogRead(analogInPin_left);
  sensorValue_right = analogRead(analogInPin_right);
  // print the results to the serial monitor:
  SerialUSB.print("left sensor = " );
  SerialUSB.print(sensorValue_left);
  SerialUSB.print("\n" );
  
  SerialUSB.print("right sensor = " );
  SerialUSB.print(sensorValue_right);
  SerialUSB.print("\n" );
  
  // When the sensor value is smaller than 200, the sensor recognizes white.
  // When the sensor value is lager than 200, the sensor recognizes black.
  if(sensorValue_left < 200 && sensorValue_right < 200) {
    SerialUSB.print("go forward\n" );
    Dxl.goalSpeed(WH_left, 1023); //forward
    Dxl.goalSpeed(WH_right, 2047); //forward
  }
  else if(sensorValue_left < 200 && sensorValue_right >= 200){
    SerialUSB.print("turn left\n" );
    Dxl.goalSpeed(WH_left, 2047); //forward
    Dxl.goalSpeed(WH_right, 2047); //backward
    delay(100);
  }
  else if(sensorValue_left >= 200 && sensorValue_right <= 200){
    SerialUSB.print("turn right\n" );
    Dxl.goalSpeed(WH_left, 1023); //backward
    Dxl.goalSpeed(WH_right, 1023); //forward
    delay(100);
  }
  else if(sensorValue_left >= 200 && sensorValue_right >= 200){
    if(random_num < 50){
      SerialUSB.print("turn right\n" );
      Dxl.goalSpeed(WH_left, 1023); //forward
      Dxl.goalSpeed(WH_right, 1023); //backward
      delay(1000);
    }
    else if(random_num >= 50){
      SerialUSB.print("turn left\n" );
      Dxl.goalSpeed(WH_left, 2047); //forward
      Dxl.goalSpeed(WH_right, 2047); //backward
      delay(1000);
    }
  }
  
}


