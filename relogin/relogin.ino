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
  for(int i = 0; i < 16; i++){
    for(int j = 0; j< 8; j++){
      if(j <= 3){
        digitalWrite(j+2, dict[i][j]);   
      }else{
        digitalWrite(j+6, dict[i][j]);   
      }
    }
    delay(250);
  }
}

