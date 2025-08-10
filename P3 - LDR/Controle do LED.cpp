//Pino no qual o LED está conectado
int LED = 13;

//Pino no qual o LDR está conectado
int LDR = A0;

//Variável que receberá o valor lido do LDR;
int entrada = 0;

void setup()
{
//Iniciar e definir a velocidade de comunicação da porta serial
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}
void loop()
{
  entrada = analogRead(LDR);
  
  //Valor que será exibido no Serial Monitor do ambiente de 
  //desenvolvimento do arduino
  Serial.println(entrada);
  
  if(entrada < 500)
    digitalWrite(LED, 1);//Acender o LED
  else
    digitalWrite(LED, 0);//Apagar o LED
  delay(100);
}