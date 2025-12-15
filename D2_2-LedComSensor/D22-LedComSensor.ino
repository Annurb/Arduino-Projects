//Projeto lm
const int LM35 = A0;
const int ATRASO = 5000;

const float baseCelsius = 0.163;
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  float temperaturaAtual = lerTemperatura();
  Serial.println(temperaturaAtual);
  if (temperaturaAtual<= 20){
    digitalWrite(10, HIGH);
    digitalWrite(9,0);
    digitalWrite(8,0);
  }
  else if(temperaturaAtual <= 30){
    digitalWrite(10, 1);
    digitalWrite(9,1);
    digitalWrite(8,0);
}
  else{
    digitalWrite(10, 1);
    digitalWrite(9,1);
    digitalWrite(8,1);
  }
  delay(ATRASO);
}
float lerTemperatura(){
  return(analogRead(LM35)*baseCelsius);
}