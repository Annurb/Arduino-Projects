//sensor de distancia
int ECHO = 7; //Pino 7 recebe o pulso
int TRIG = 8; //Pino 8 envia o pulso

long duracao = 0;
long distancia = 0;

void setup() {
  Serial.begin(9600);//Inicia a porta serial
  pinMode(ECHO, INPUT);//Pino 12 é entrada(receber)
  pinMode(TRIG, OUTPUT);//Pino 13 é saída (enviar)
  }

void loop() {
  //Pino trigger com um pulso baixo LOW(desligado)
  digitalWrite(TRIG, LOW);

  //Delay de 10 microssegundos
  delayMicroseconds(10);

  //Pino trigger com pulso alto HIGH(ligado);
  digitalWrite(TRIG, HIGH);

  //Delay de 10 microssegundos
  delayMicroseconds(10);

  //Pino trigger com um pulso baico LOW(desligado) novamente
  digitalWrite(TRIG, LOW);

  //A funcao pulseIn verifica o tempo que o pino ECHO ficou HIGH
  //Calculando assim a duracao do trafego de sinal
  duracao = pulseIn(ECHO, HIGH);

  //Calculo da distacia (centimetros): distancia = duracao/58
  distancia = duracao/58;

  Serial.print("Distancia em cm: ");
  Serial.println(distancia);
  delay(100);
}
