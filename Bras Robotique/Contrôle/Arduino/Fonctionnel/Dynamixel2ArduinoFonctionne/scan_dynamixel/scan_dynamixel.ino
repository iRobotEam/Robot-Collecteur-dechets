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
#include "master.h"

// Please modify it to suit your hardware.
  #include <SoftwareSerial.h>
  SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
  #define DXL_SERIAL   Serial
  #define DEBUG_SERIAL soft_serial
  const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN

#define MAX_BAUD  6
const int32_t buad[MAX_BAUD] = {9600, 57600, 115200, 1000000, 2000000, 3000000};
const uint8_t new_id=1;
int led =7;
Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

 int j =0; 
 int p=0;
void setup() {
  // put your setup code here, to run once:
  int8_t index = 0;
  int8_t found_dynamixel = 0;

  int8_t new_id =1;

   
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
    
  for(int8_t protocol = 1; protocol < 3; protocol++) {
    // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
    dxl.setPortProtocolVersion((float)protocol);
    
    for(index = 0; index < MAX_BAUD; index++) {
      
      // Set Port baudrate.
      dxl.begin(buad[index]);
      for(int id = 0; id < DXL_BROADCAST_ID; id++) {
        //iterate until all ID in each buadrate is scanned.

        
 /*
         for(j=0; j<15; j++){
          if (getLastLibErrCode() == j){
            for( p=0; p<j; j++){
             digitalWrite(led,HIGH);
             delay(500);
             digitalWrite(led,LOW);
            }
          } 
         }
         */
      
        if(dxl.ping(id) == true) {
          digitalWrite(led,HIGH);
          delay(5000); 

          
          if (id == 0) {
            digitalWrite(led,LOW);
            delay(1000);
            digitalWrite(led,HIGH);
            delay(500);
            digitalWrite(led,LOW);
            delay(500);  
          }
      
         else if (id ==1){
            digitalWrite(led,LOW);
            delay(1000);
            digitalWrite(led,HIGH);
            delay(500);
            digitalWrite(led,LOW);
            delay(500);
            digitalWrite(led,HIGH);
            delay(500);
            digitalWrite(led,LOW);
            delay(500);            
          
            } 
         else if(id  == 2){
            digitalWrite(led,LOW);
            delay(1000);
            digitalWrite(led,HIGH);
            delay(500);
            digitalWrite(led,LOW);
            delay(500);
            digitalWrite(led,HIGH);
            delay(500);
            digitalWrite(led,LOW);
            delay(500);
             digitalWrite(led,HIGH);
            delay(500);
            digitalWrite(led,LOW);
            delay(500);
            
          }
        
        

         /*
          dxl.torqueOff(id);
          
          dxl.setOperatingMode(id, OP_CURRENT_BASED_POSITION);
          delay(100); 
         
          dxl.setID(id, new_id);        
          // Turn off torque when configuring items in EEPROM area
          dxl.torqueOn(id);

       */
         
         
        }
      }
      
    }
  }
}

void loop() {


}
