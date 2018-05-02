int motor4=9;
int motor3=6;
int motor2=5;
int motor1=3;
int x4=255;
int x3=191;
int x2=127;
int x1=64;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(motor1,x1);
  analogWrite(motor2,x2);
  analogWrite(motor3,x3);
  analogWrite(motor4,x4);
  delay(10000);
  
}
