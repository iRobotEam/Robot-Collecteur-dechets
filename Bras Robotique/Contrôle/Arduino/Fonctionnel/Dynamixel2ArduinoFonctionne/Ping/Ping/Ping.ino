#include <Dynamixel2Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
#define DXL_SERIAL   Serial
#define DEBUG_SERIAL soft_serial
const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
const uint8_t DXL_ID =1;
const uint8_t new_id=1;
const float DXL_PROTOCOL_VERSION = 2.0;

int i = 0;
int led =7; 

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);
void setup() {

  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  // put your setup code here, to run once:
   // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(57600);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);


}

void loop() {



  for (i=0; i<255; i++){
    delay(500);
    if(dxl.ping(i) == true) {
  
      digitalWrite(led,HIGH);
      delay(5000); 
      // Turn off torque when configuring items in EEPROM area
      dxl.torqueOff(i);
      
      dxl.setID(i, new_id);
  
      
      }else{
        digitalWrite(led,HIGH);
        delay(100);
        digitalWrite(led,LOW);
        delay(100);
        digitalWrite(led,HIGH);
        delay(100);
        digitalWrite(led,LOW);
        delay(100);
        digitalWrite(led,HIGH);
        delay(100);
        digitalWrite(led,LOW);
        delay(100);  
      }
   }
}
