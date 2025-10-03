// C++ code
//
int botao = 7;
int buzzer = 8;
int estado = LOW;
int valor;
int anterior = 0; 
void setup()
{
  pinMode(botao, INPUT);
  pinMode(buzzer, OUTPUT);
  
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
    }
  else{
    noTone(buzzer);
  }
  delay(50);
}