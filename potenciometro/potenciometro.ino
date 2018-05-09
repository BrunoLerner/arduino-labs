#define pot A5
#define blue 9
#define red 10
#define green 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(pot);
  x = map(x,0,1023,0,255);
  Serial.print(x);
  Serial.println(" bits ");
  int r = random(1,3);
  if(r == 1) analogWrite(blue, x);
  else if(r == 2) analogWrite(red, x);
  else if(r == 3) analogWrite(green, x);
  
  
  delay(100);
}
