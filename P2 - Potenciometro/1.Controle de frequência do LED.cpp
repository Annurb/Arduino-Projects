//Liga e desliga de um led na frequência determinada pelo potenciômetro
// Pino ligado ao potenciômetro
int POT = A1;

//Pino conectado  ao LED
int LED = 13;

//variável que armazenará o valor obtido do potenciômetro
int valor=0;

void setup()
{
pinMode(LED, OUTPUT);
}

void loop()
{
valor = analogRead(POT);//leitura da porta analogica;
digitalWrite(LED, 1);
delay(valor);
digitalWrite(LED, 0);
delay(valor);
}