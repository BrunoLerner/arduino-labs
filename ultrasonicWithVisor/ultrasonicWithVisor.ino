//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

//Define os pinos para o trigger e echo
#define pino_trigger 8
#define pino_echo 9

int dict[16][8] = {
    {0,1,1,1,0,1,1,1},
    {0,0,0,0,0,1,1,0},
    {1,0,1,1,0,0,1,1},
    {1,0,0,1,0,1,1,1},
    {1,1,0,0,0,1,1,0},
    {1,1,0,1,0,1,0,1},
    {1,1,1,1,0,1,0,1},
    {0,0,0,0,0,1,1,1},
    {1,1,1,1,0,1,1,1},
    {1,1,0,1,0,1,1,1},
    {1,1,1,0,0,1,1,1},
    {1,1,1,1,0,1,0,0},
    {0,1,1,1,0,0,0,1},
    {1,0,1,1,0,1,1,0},
    {1,1,1,1,0,0,0,1},
    {1,1,1,0,0,0,0,1}
  };

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
//  cmMsec /= 20;
  if(cmMsec  < 16){
    for(int j = 0; j< 8; j++){
      if(j <= 3){
        digitalWrite(j+2, dict[cmMsec][j]);   
      }else{
        digitalWrite(j+6, dict[cmMsec][j]);   
      }
  }   
  delay(100);
  }
}

