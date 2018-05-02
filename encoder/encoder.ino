//Carrega a biblioteca do encoder
#include <RotaryEncoder.h>

//Pinos de ligacao do encoder
RotaryEncoder encoder(A2, A3);

void setup()
{
  Serial.begin(9600);//57600
  Serial.println("Gire o encoder....");

  PCICR |=(1 << PCIE1); 
  PCMSK1 |= (1 << PCINT10)|(1 << PCINT11);
}

ISR(PCINT1_vect){
  encoder.tick();
}
void loop()
{
  static int pos = 0;
  int newPos = encoder.getPosition();
  if (pos != newPos) {
    Serial.print(newPos);
    Serial.println();
    pos = newPos;
    //if(newPos == 66) delay(6600);   
  }
}
