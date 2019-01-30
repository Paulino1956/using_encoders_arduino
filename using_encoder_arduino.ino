#include <SoftwareSerial.h>
#include "RoboClaw.h"

#define address 0x80

SoftwareSerial serial(10,11);
RoboClaw roboclaw(&serial,10000);

void setup() {
  roboclaw.begin(38400);
  Serial.begin(38400);
}

void loop() {

    // Read encoder channel 1
    int motor_1_count = roboclaw.ReadEncM1(address);
    Serial.print("Original:");
    Serial.print(motor_1_count);
    Serial.print("\n");
    
    delay(2000);

    // Set encoder and then print the value set for confimation
    roboclaw.SetEncM1(address, 10000);
    motor_1_count = roboclaw.ReadEncM1(address);
    Serial.print("After setting count:");
    Serial.print(motor_1_count);
    Serial.print("\n");
    

    delay(2000);

    // Start motor 1 and read the speed value
    roboclaw.ForwardM1(address, 64);
    delay(500);
    int motor_1_speed = roboclaw.ReadSpeedM1(address);
    delay(500);
    Serial.print("Motor speed:");
    Serial.print(motor_1_speed);
    Serial.print("\n");
    roboclaw.ForwardM1(address,0);

    delay(2000);

    // Reset encoders, read value and print to test
    roboclaw.ResetEncoders(address);
    motor_1_count = roboclaw.ReadEncM1(address);
    Serial.print("After reset:");
    Serial.print(motor_1_count);
    Serial.print("\n");

    delay(2000);

    // Position the motor
    roboclaw.SpeedAccelDeccelPositionM1(address,10000,2000,10000,15000,1);

    delay(2000);
}
