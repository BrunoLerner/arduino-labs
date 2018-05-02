const int led1 = 13; //saída
const int botao = 2; // entrada

int estadoBotao = 0; // armazena o valor da entrada porta2
void setup() {
  // put your setup code here, to run once:
  pinMode (led1, OUTPUT);
  pinMode (botao, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  estadoBotao = digitalRead(botao);
  if (estadoBotao == HIGH){
    digitalWrite(led1,HIGH);
  }else{
    digitalWrite(led1,LOW);
  }
}
