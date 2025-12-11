#include <LiquidCrystal_I2C.h>
#define TEMPO_ATUALIZACAO 1000
#define ECHO 7
#define TRIG 8

int maximo = 200;//Distancia maxima:200 cm
int minimo = 0;//Distancia minima 0 cm
long duracao, distCm, distPol;
  
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
lcd.init();
lcd.backlight();
  
pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);
}

void loop()
{
//Enviar o pulso
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  //Obter o tempo que o pulso levou pra retornar
  duracao = pulseIn(ECHO, HIGH);
  
  //Calcular a distancia em centimetros
  distCm = duracao/58;
  
  //Calcular a distancia em polegadas
  distPol = duracao/ 37;
  
  lcd.clear();
  lcd.setCursor(0,0);
  if (distCm >=maximo || distCm <= minimo){
	lcd.print("Fora da faixa! ");
  }
  else{
    lcd.print("Distancia: ");
    lcd.setCursor(0, 1);//linha, coluna
    lcd.print(distCm);
    lcd.print(" cm / ");
    lcd.print(distPol);
    lcd.print(" pol");
  }
  delay(TEMPO_ATUALIZACAO);
}