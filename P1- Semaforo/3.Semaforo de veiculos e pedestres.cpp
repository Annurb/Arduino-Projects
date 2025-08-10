//criação de variáveis
//Carros
int greenC = 13;
int yellowC = 12;
int redC = 11;

//Pedestres
int redP = 10;
int greenP = 9;

void setup()
{
//Colocar todas as portas como sinais de saída:
//Carros
  pinMode(greenC,OUTPUT);
  pinMode(yellowC, OUTPUT);
  pinMode(redC, OUTPUT);
  
 //Pedestres
  pinMode(redP, OUTPUT);
  pinMode(greenP, OUTPUT);
}

void loop()
{
  //Sinal verde para carros
  digitalWrite(greenC, 1);
  digitalWrite(yellowC, 0);
  digitalWrite(redC, 0);
  
  digitalWrite(redP, 1);
  digitalWrite(greenP, 0);
  
  delay(10000);
  
  //sinal amarelo para carros
  digitalWrite(greenC, 0);
  digitalWrite(yellowC, 1);
  digitalWrite(redC, 0);
  
  delay(2000);
  
  //Sinal vermelho para carros
  digitalWrite(greenC,0);
  digitalWrite(yellowC, 0);
  digitalWrite(redC, 1);
  
  digitalWrite(redP, 0);
  digitalWrite(greenP, 1);
  
  delay(8000);
  
  digitalWrite(greenP, 0);
  
  delay(500);
  
  digitalWrite(greenP, 1);
  
  delay(500);
  
  digitalWrite(greenP, 0);
  
  delay(500);
    
  digitalWrite(greenP, 1);
  
  delay(500);
}
