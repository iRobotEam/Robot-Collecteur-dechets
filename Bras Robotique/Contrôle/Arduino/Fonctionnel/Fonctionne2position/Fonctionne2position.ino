
// ========================================
// Dynamixel XL-320 Arduino library example
// ========================================

// Read more:
// https://github.com/hackerspace-adelaide/XL320

#include "XL430.h"

// Name your robot!
XL320 robot;

// If you want to use Software Serial, uncomment this line
#include <SoftwareSerial.h>

// Set the SoftwareSerial RX & TX pins
SoftwareSerial mySerial(10, 11); // (RX, TX)

// Set some variables for incrementing position & LED colour
char rgb[] = "rgbypcwo";
int servoPosition = 0;
int ledColour = 0;

int inPin = 5; 
int val = 0; 
// Set the default servoID to talk to
int servoID =5;

void setup() {

  // Talking standard serial, so connect servo data line to Digital TX 1
  // Comment out this line to talk software serial
  Serial.begin(9600);
 

  // Setup Software Serial
  mySerial.begin(9600);

  // Initialise your robot
  robot.begin(Serial); // Hand in the serial object you're using
  
  // I like fast moving servos, so set the joint speed to max!
  robot.setJointSpeed(servoID, 1023);

  pinMode(inPin, INPUT);      // configure la broche 7 en ENTREE

}

void loop() {

     robot.moveJoint(servoID,30);
     //print(robot.moveJoint(servoID,30), BIN); 
     delay(1000);
     robot.moveJoint(servoID,0);
     //print(robot.moveJoint(servoID,30), BIN); 
     delay(1000);
  
   
}
