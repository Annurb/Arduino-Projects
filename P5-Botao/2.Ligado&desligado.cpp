//Guardar o valor de um botão pra deixar o LED aceso ou apagado
//variavel do led
int LED = 9;
//variavel do botão
int BOTAO = 7;
//criação do valor a ser guardado
int valor;
int anterior = 0;
int estado = LOW;

void setup()
{
//Modo dos pínos
pinMode(LED, OUTPUT);
pinMode(BOTAO, INPUT);
}

void loop()
{
valor = digitalRead(BOTAO);
  if (valor == HIGH && anterior == LOW){
    estado = !estado;
  }
  digitalWrite(LED, estado);
  anterior = valor;
  delay(50);
}