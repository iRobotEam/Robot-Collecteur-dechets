#include <Dynamixel2Arduino.h>
// Please modify it to suit your hardware.
//#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560) // When using DynamixelShield
#include <SoftwareSerial.h>
SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
#define DXL_SERIAL   Serial
#define DEBUG_SERIAL soft_serial
const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN

const uint8_t DXL_ID1 = 1;
const uint8_t DXL_ID2 = 2;
const uint8_t DXL_ID3 = 3;
const uint8_t DXL_ID4 = 4;
const uint8_t DXL_ID5 = 5;
const uint8_t DXL_ID6 = 6;
const float DXL_PROTOCOL_VERSION = 2.0;

uint32_t BAUDRATE = 57600;
const int analogInPin = A0; // Analog input pin that the Linear Pot is attached to
int degree=0;
int sensorValue = 0; // value read from the Linear pot
int outputValue = 0; 
Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

int led=7;
void setup() {
  
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(BAUDRATE);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  if (dxl.ping(DXL_ID1)== true){
    digitalWrite(led,HIGH);
    delay(500); 
    digitalWrite(led,LOW);
    }
   else if (dxl.ping(DXL_ID2)== true){
    digitalWrite(led,HIGH);
    delay(500); 
    digitalWrite(led,LOW);
    }
    else if (dxl.ping(DXL_ID3)== true){
      digitalWrite(led,HIGH);
      delay(500); 
      digitalWrite(led,LOW);
    }
    else if (dxl.ping(DXL_ID4)== true){
    digitalWrite(led,HIGH);
    delay(500); 
    digitalWrite(led,LOW);
    }
    else if (dxl.ping(DXL_ID5)== true){
    digitalWrite(led,HIGH);
    delay(500); 
    digitalWrite(led,LOW);
    }
    else if (dxl.ping(DXL_ID6)== true){
    digitalWrite(led,HIGH);
    delay(500); 
    digitalWrite(led,LOW);
    }


  dxl.torqueOff(DXL_ID1);
  dxl.torqueOff(DXL_ID2);
  dxl.torqueOff(DXL_ID3);
  dxl.torqueOff(DXL_ID4);
  dxl.torqueOff(DXL_ID5);
  dxl.torqueOff(DXL_ID6);
  dxl.setOperatingMode(DXL_ID1, OP_POSITION);
  dxl.setOperatingMode(DXL_ID2, OP_POSITION);
  dxl.setOperatingMode(DXL_ID3, OP_POSITION);
  dxl.setOperatingMode(DXL_ID4, OP_POSITION);
  dxl.setOperatingMode(DXL_ID5, OP_POSITION);
  dxl.setOperatingMode(DXL_ID6, OP_POSITION); 
  dxl.torqueOn(DXL_ID1);
  dxl.torqueOn(DXL_ID2);
  dxl.torqueOn(DXL_ID3);
  dxl.torqueOn(DXL_ID4);
  dxl.torqueOn(DXL_ID5);
  dxl.torqueOn(DXL_ID6);
}

void loop() {
  // put your main code here, to run repeatedly:

  sensorValue = analogRead(analogInPin); // read the analog in value: 0 to 1023
  
  degree = sensorValue/2.84; 
  delay(50);
  dxl.setGoalPosition(DXL_ID2, degree, UNIT_DEGREE);

  //outputValue = map(sensorValue, 0, 1023, 0, 255);
// change the analog out value:
  
  delay(100);
}
