#include "Servo.h"
#include <Ultrasonic.h>

#define pino_trigger 4
#define pino_echo 5

#define motorBase 9
#define motorCotovelo 10
#define motorGarra 12

#define minimumDistance 10

Servo base;
Servo cotovelo;
Servo garra;
Ultrasonic ultrasonic(pino_trigger, pino_echo);
float distance;

void setup() {
  base.attach(motorBase);
  cotovelo.attach(motorCotovelo);
  garra.attach(motorGarra);
  
  base.write(45);
  cotovelo.write(90);
  garra.write(60);
  
  Serial.begin(9600);
}

void slowSpin(Servo servo, int initialAngle, int finalAngle){
  if (finalAngle > initialAngle){
    for (int i = initialAngle; i <= finalAngle; i++){
      servo.write(i);
      delay(50);
    }
  }else{
    for (int i = initialAngle; i >= finalAngle; i--){
      servo.write(i);
      delay(50);
    }
  }
}

void getCandy(){
  base.write(90);
  garra.write(0);
  delay(1000);
  slowSpin(cotovelo, 90, 0);
  delay(200);
  garra.write(30);
  delay(200);
  slowSpin(cotovelo, 0, 90);
  delay(100);
  base.write(0);
  delay(100);
  slowSpin(cotovelo, 90, 0);
  delay(100);
  garra.write(0);
  delay(100);
  base.write(45);
  cotovelo.write(90);
  garra.write(60);
}

float readDistance(){
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  return cmMsec;
}


void loop() {
  if (distance < minimumDistance) {
      getCandy();
  }
  delay(300);   
}
