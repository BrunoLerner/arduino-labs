#define pot A5
#define motor 5
#include "Servo.h"

Servo servo;
void setup() {
  // put your setup code here, to run once:
  servo.attach(motor);
}

void loop() {
  // put your main code here, to run repeatedly:
  int angle = analogRead(pot);
  angle = map(angle,0,1023,0,255);
  servo.write(angle);
  delay(40);
}
