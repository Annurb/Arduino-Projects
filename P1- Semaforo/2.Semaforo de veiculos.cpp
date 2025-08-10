// C++ code

//criação de variáveis
int green = 13;
int yellow = 12;
int red = 11;

void setup()
{//configuração do pino digital por entrada/saída
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop()
{//funcionamento high ou low
  digitalWrite(green,1);
  digitalWrite(yellow,0);
  digitalWrite(red, 0);
  
  delay(1000);
    
  digitalWrite(green,0);
  digitalWrite(yellow,1);
  digitalWrite(red,0);
  
  delay(500);
  
  digitalWrite(green,0);
  digitalWrite(yellow, 0);
  digitalWrite(red, 1);
  
  delay(1000);
}