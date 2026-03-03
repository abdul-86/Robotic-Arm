#include <ESP32Servo.h>

Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo gripperServo;

// Servo Pins
#define BASE_PIN 13
#define SHOULDER_PIN 12
#define ELBOW_PIN 14
#define GRIPPER_PIN 27

void setup() {
  Serial.begin(115200);

  // Attach Servos
  baseServo.attach(BASE_PIN);
  shoulderServo.attach(SHOULDER_PIN);
  elbowServo.attach(ELBOW_PIN);
  gripperServo.attach(GRIPPER_PIN);

  // Initial Position
  baseServo.write(90);
  shoulderServo.write(90);
  elbowServo.write(90);
  gripperServo.write(30);

  delay(2000);
}

void loop() {

  // Move Base
  for(int pos = 90; pos <= 150; pos++) {
    baseServo.write(pos);
    delay(15);
  }

  delay(500);

  // Move Shoulder
  for(int pos = 90; pos <= 140; pos++) {
    shoulderServo.write(pos);
    delay(15);
  }

  delay(500);

  // Move Elbow
  for(int pos = 90; pos <= 130; pos++) {
    elbowServo.write(pos);
    delay(15);
  }

  delay(500);

  // Close Gripper
  for(int pos = 30; pos <= 80; pos++) {
    gripperServo.write(pos);
    delay(15);
  }

  delay(1000);

  // Return to Original Position
  baseServo.write(90);
  shoulderServo.write(90);
  elbowServo.write(90);
  gripperServo.write(30);

  delay(3000);
}