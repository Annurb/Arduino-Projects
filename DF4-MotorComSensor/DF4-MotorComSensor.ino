// Motor A
int ENA = 5;
int IN1 = 8;
int IN2 = 9;

// Motor B
int ENB = 6;
int IN3 = 10;
int IN4 = 11;

//sensor
int TRIG= 3;
int ECHO = 2; 

long duracao = 0; 
long distancia = 0;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // velocidade dos motores
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);

  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

void loop() {
  //Pino trigger com um pulso baixo LOW(desligado)
  digitalWrite(TRIG, LOW);
  
 //Delay de 10 microssegundos
  delayMicroseconds(2);
  
  //Pino trigger com pulso HIGH (ligado)
  digitalWrite(TRIG, HIGH);
  
  //Delay de 10 microssegundos
  delayMicroseconds(10);
  
  //Pino trigger com pulso baixo LOW
  digitalWrite(TRIG, LOW);
  
  //A funcao verifica o tempo que o pino ECHO ficou HIGH
  //calculando assim a duracao do trafego do sinal
  duracao = pulseIn(ECHO, HIGH);
  
  //Calculo da distancia (centimetros):distancia= duracao/58
	distancia =duracao/58;

  // FRENTE
  if(distancia > 10){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);
  }
  else{

  // PARAR
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);;
  }
}