/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <Dynamixel2Arduino.h>


  #include <SoftwareSerial.h>
  SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
  #define DXL_SERIAL   Serial
  #define DEBUG_SERIAL soft_serial
  const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN

 

const uint8_t DEFAULT_DXL_ID = 3;
const float DXL_PROTOCOL_VERSION = 2.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);
uint8_t present_id = DEFAULT_DXL_ID;
uint8_t new_id =2; //Change this New ID 
uint32_t BAUDRATE = 57600;

void setup() {
  // put your setup code here, to run once 
  int led =7;
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(BAUDRATE);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  
  if(dxl.ping(present_id) == true) {
    digitalWrite(led,HIGH);
    delay(2000); 
    digitalWrite(led,LOW);
    
    // Turn off torque when configuring items in EEPROM area
    dxl.torqueOff(present_id);
    dxl.setID(present_id, new_id);
 }
 dxl.ping(new_id);
 dxl.torqueOff(new_id);
 dxl.setOperatingMode(new_id, OP_POSITION);
 dxl.torqueOn(new_id);
 
}
void loop() {
  
  

  delay(500);
   // Set Goal Current using RAW value
  dxl.setGoalPosition(new_id, 300.0, UNIT_DEGREE);
  delay(3000); 
  dxl.setGoalPosition(new_id, 30);

  delay(3000);
  
}
