// Motor A
int IN1 = 5;
int IN2 = 6;

// Motor B
int IN3 = 10;
int IN4 = 11;

//sensor
int TRIG= 3;
int ECHO = 2; 

long duracao = 0; 
long distancia = 0;

void setup() {
  pinMode(TRIG, OUTPUT); // O trigger envia o sinal
  pinMode(ECHO, INPUT);  // O echo recebe o sinal

  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // velocidade dos motores
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
  Serial.println(distancia);
  // ir pro lado
  if(distancia <= 15){
  analogWrite(IN1, 100);
  analogWrite(IN2, 0);
  analogWrite(IN3, 100);
  digitalWrite(IN4, LOW);
  delay(1000);
  }else{
    // FRENTE
  analogWrite(IN1, 100);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  analogWrite(IN4, 100);
  delay(1000);
}}

