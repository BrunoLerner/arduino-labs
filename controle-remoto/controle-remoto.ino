
#include "IRremote.h"                    //Biblioteca para recepçao IR
  
float valor;                             // Variável Valor onde será armazenado o código hexa recebido do controle remoto
int pino_receiver = 10;                  // Definição do Pino onde está ligado o receptor IR
IRrecv irrecv(pino_receiver);            // Atribuição do pino receptor
decode_results results;                  // Variável results 
  
void setup()  
{  
  Serial.begin(9600);                    // Inicia comunicação Serial com o monitor
  irrecv.enableIRIn();                   // Inicia o receiver;
}  
   
void loop()  
{  
  if (irrecv.decode(&results))           // Verifica se algum valor foi recebido
  {  
    Serial.print("Valor lido : ");       // Mostra no monitor o texto "Valor lido: "
    Serial.println(results.value, HEX);  // Mostra no monitor o valor enviado pelo controle remoto
    irrecv.resume();                     // Recebe o próximo valor
  }  
}
