// buzzer sem notone
//Pino ao qual o buzzer esta conectado
int buzzer = 8;

void setup()
{
pinMode(buzzer, OUTPUT);	
}
void loop()
{
//Define, a frequencia e duração
  tone(buzzer, 1200, 500);
  delay(1000);
}