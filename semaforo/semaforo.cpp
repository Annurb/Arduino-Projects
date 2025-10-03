// first css code
int led = 13;//criação de uma variável para o pino 13 do led

void setup()
{
  pinMode(led,OUTPUT);//define o modo do pino digital como saída
}
void loop()
{
digitalWrite(led,1);//coloca nível 1 no pino(liga o led)
  
  delay(2000);//aguarda 2 segundos
  digitalWrite(led, 0);//coloca nivel 0 no pino(apaga o led)
  
    delay(2000);
}