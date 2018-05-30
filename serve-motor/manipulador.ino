#include "Servo.h"
#include <Ultrasonic.h>

#define pino_trigger 4
#define pino_echo 5

#define motorBase 9
#define motorCotovelo 10
#define motorPunho 13

#define minimumDistance 18

Servo base;
Servo cotovelo;
Servo punho;
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
  base.attach(motorBase);
  cotovelo.attach(motorCotovelo);
  punho.attach(motorPunho);
  
  base.write(60);
  cotovelo.write(0);
  punho.write(0);
  
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

void dropWater(){
  slowSpin(base, 60, 0);
  delay(1000);
  slowSpin(punho, 0, 70);
  delay(6000);
  slowSpin(punho, 70, 0);
  slowSpin(base, 0, 60);
}

float readDistance(){
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  //Exibe informacoes no serial monitor
  Serial.println("Distancia em cm: ");
  Serial.println(cmMsec);
  return cmMsec;
}


void loop() {
  if (readDistance() < minimumDistance) {
      dropWater();
  }
  delay(500);
}
