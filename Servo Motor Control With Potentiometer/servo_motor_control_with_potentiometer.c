#include <Servo.h>  // Include Servo library

Servo myServo;  // Create Servo object

int servoPin = 6;  // Pin connected to the servo
int potValue;  // Variable to store potentiometer value
int potPin = A0;  // Pin connected to the potentiometer

void setup(){
  myServo.attach(servoPin);  // Attach the servo to the specified pin
}

void loop(){
  potValue = analogRead(potPin);  // Read the potentiometer value (0-1023)
  int servoAngle = map(potValue, 0, 1023, 0, 180);  // Map potentiometer value to servo angle (0-180)
  myServo.write(servoAngle);  // Set the servo angle based on the potentiometer value
  delay(200);  // Short delay to smooth movement
}