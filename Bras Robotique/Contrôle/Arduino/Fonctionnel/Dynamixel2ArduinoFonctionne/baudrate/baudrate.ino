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


const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;
uint32_t BAUDRATE = 115200;
uint32_t NEW_BAUDRATE = 57600; //1Mbsp

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

void setup() {

  int led =7;
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(BAUDRATE);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);

  if(dxl.ping(DXL_ID) == true) {
    digitalWrite(led,HIGH);
    delay(2000); 
    digitalWrite(led,LOW);
   
    // Turn off torque when configuring items in EEPROM area
    dxl.torqueOff(DXL_ID);
    
    // Set a new baudrate(1Mbps) for DYNAMIXEL
    dxl.setBaudrate(DXL_ID, NEW_BAUDRATE);
    delay(100);
        // Change to the new baudrate for communication.
    dxl.torqueOn(DXL_ID);
    dxl.begin(NEW_BAUDRATE);
    // Change back to the initial baudrate
    if (dxl.getPortBaud()==NEW_BAUDRATE){
      digitalWrite(led,HIGH);
      delay(3000);
      digitalWrite(led,LOW);
      }
      
    }

}

void loop() {
  // put your main code here, to run repeatedly:
}
