#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servoMotor;

void setup() {
  // put your setup code here, to run once:
  servoMotor.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  servoMotor.write(90);

}
