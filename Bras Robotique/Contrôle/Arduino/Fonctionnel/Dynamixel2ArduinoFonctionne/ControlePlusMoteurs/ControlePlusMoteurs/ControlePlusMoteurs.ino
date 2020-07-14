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


Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

int led =7;

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
  
  //dxl.writeControlTableItem(MAX_POSITION_LIMIT,DXL_ID2,0x839);
 // delay(100);
 // dxl.writeControlTableItem(MIN_POSITION_LIMIT,DXL_ID2,0x00);
  
  dxl.torqueOn(DXL_ID1);
  dxl.torqueOn(DXL_ID2);
  dxl.torqueOn(DXL_ID3);
  dxl.torqueOn(DXL_ID4);
  dxl.torqueOn(DXL_ID5);
  dxl.torqueOn(DXL_ID6);

  
  dxl.setGoalPosition(DXL_ID1,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID2,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID3,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID4,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID5,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID6,0,UNIT_DEGREE);
  delay(1000);


   
  
}

void loop() {
  // put your main code here, to run repeatedly:
  dxl.setGoalPosition(DXL_ID1,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID2,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID3,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID4,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID5,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID6,0,UNIT_DEGREE);
  digitalWrite(led,HIGH);
  
  delay(2000);
  digitalWrite(led,LOW);
  
  dxl.setGoalPosition(DXL_ID1,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID2,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID3,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID4,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID5,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID6,0,UNIT_DEGREE);
  delay(2000);

  dxl.setGoalPosition(DXL_ID1,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID2,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID3,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID4,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID5,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID6,0,UNIT_DEGREE);

  
  delay(1000);

 
  dxl.setGoalPosition(DXL_ID1,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID2,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID3,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID4,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID5,0,UNIT_DEGREE);
  dxl.setGoalPosition(DXL_ID6,0,UNIT_DEGREE);
  delay(1000);
 
}
