// C++ code: buzzer com noTone()
//Pino conectado ao buzzer
int buzzer = 8;

void setup()
{
pinMode(buzzer, OUTPUT);
}

void loop()
{
tone(buzzer, 1200);//define o pino e a frequência
  delay(500);
noTone(buzzer);
  delay(500);//Desliga o buzzer
  
}