//Estacionamento
//lcd
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

//leds
#define vermelho 13
#define amarelo 12
#define verde 11

//buzzer
#define buzzer 10

//sensor de distancia
#define trig 9
#define echo 8
long duracao,  distancia;

int mili;
int diferente;

void setup()
{
pinMode(vermelho, OUTPUT);
pinMode(amarelo, OUTPUT);
pinMode(verde, OUTPUT);
 
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
  
pinMode(buzzer, OUTPUT);
  
lcd.init();
lcd.backlight();
  
 Serial.begin(9600);
}

void loop()
{
  //sensor de distancia e calculo
digitalWrite(trig, 0);
delayMicroseconds(10);
digitalWrite(trig, 1);
delayMicroseconds(10);
digitalWrite(trig, 0);
  
  duracao = pulseIn(echo, 1);
  distancia = duracao/58;
  
  Serial.println(distancia);
  
  mili = distancia*100;
  
  if(distancia >10){
  digitalWrite(verde, 1);
  digitalWrite(amarelo, 0);
  digitalWrite(vermelho, 0);
   
    if (diferente != 0){
      lcd.clear();
      diferente = 0;
    }
  lcd.setCursor(0,0);
  lcd.print("SEGURO: ");
  lcd.print(distancia);
  lcd.print(" cm");
  
  }
  else if(distancia <= 10 && distancia >=5){
  digitalWrite(verde, 0);
  digitalWrite(amarelo, 1);
  digitalWrite(vermelho, 0);
  
    if (diferente != 1){
      lcd.clear();
      diferente = 1;
    }
  lcd.setCursor(0,0);
  lcd.print("ATENCAO: ");
  lcd.print(distancia);
  lcd.print(" cm");
    
  tone(buzzer, 400);
  delay(mili);
  noTone(buzzer);
  delay(mili);
  }
  else{
  digitalWrite(verde, 0);
  digitalWrite(amarelo, 0);
  digitalWrite(vermelho, 1);
    
  tone(buzzer, 400);
  delay(mili);
  noTone(buzzer);
  delay(mili);
    
    if(distancia>2){
     if (diferente != 2){
      lcd.clear();
      diferente = 2;
    }
    lcd.setCursor(0,0);
  	lcd.print("CUIDADO: ");
  	lcd.print(distancia);
  	lcd.print(" cm");
    }
    else{
    if (diferente != 3){
      lcd.clear();
      diferente = 3;
    }
    lcd.setCursor(0,0);
  	lcd.print("PARE!!! ");
    }
  }
}