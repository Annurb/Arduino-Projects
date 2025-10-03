// C++ code
//
int botao = 7;
int buzzer = 8;
int estado = LOW;
int valor;
int anterior = 0;
int led = 6;
void setup()
{
  pinMode(botao, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  
}

void loop()
{
  valor = digitalRead(botao);
    if (valor == HIGH && anterior == LOW){
    estado = !estado;
  }
  anterior = valor;
  if (estado == HIGH){
      tone(buzzer, 2000);
    digitalWrite(led, 1);
    }
  else{
    noTone(buzzer);
    digitalWrite(led, 0);
  }
}