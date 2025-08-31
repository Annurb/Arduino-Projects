//pino conectado ao led
int LED = 9;
//pino conectado ao botão
int BOTAO = 7;
int valor;
  
void setup()
{
//Definir o pino como saída
pinMode(LED, OUTPUT);
 //Definir o pino do botão como entrada
 pinMode(BOTAO, INPUT);
}

void loop()
{
//Obtèm LOW(botão não pressionado)
//HIGH (botão pressionado)
valor = digitalRead(BOTAO);

digitalWrite(LED, valor);
delay(500);  
}