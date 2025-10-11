#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//controle de estufa
int botao = 4;
int valor;
int anterior = 0;
int c ;
int i ;
 
int verde = 10;
int amarelo = 9;
int vermelho = 8;
int ultimoEstado = -1;//-1 nada 0 verde 1 amarelo 2 vermelho

int buzzer = 6;
int estado = LOW;
int ldr = A0;
int entrada = 0;

void setup()
{
 Serial.begin(9600);
 pinMode(botao, INPUT);
 pinMode(verde, OUTPUT);
 pinMode(amarelo, OUTPUT);
 pinMode(vermelho, OUTPUT);
  
 lcd.init();
 lcd.backlight();
  
}

void loop()
{
  lcd.setCursor(0,0);
  valor = digitalRead(botao);
  if(valor == HIGH && anterior == LOW){
    estado = !estado;
  }
  anterior = valor;
  if(estado == HIGH){
    entrada = analogRead(ldr);
    if(entrada> 0.8*835){
      digitalWrite(vermelho, 1);
      digitalWrite(amarelo, 0);
      digitalWrite(verde, 0);
      if(ultimoEstado != 2){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Valor mto acima");
        lcd.setCursor(0,1);
        lcd.print(entrada);
        Serial.println("Valor mto acima");
        for( c = 0; c<3; c++){
          tone(buzzer, 400);
          delay(500);
          noTone(buzzer);}
        ultimoEstado = 2;
      }
    }
    else if(entrada>0.5*835){ 
      digitalWrite(vermelho, 0);
      digitalWrite(amarelo, 1);
      digitalWrite(verde, 0);
      if(ultimoEstado != 1){
       lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Valor acima");
        lcd.setCursor(0,1);
        lcd.print(entrada);
        Serial.println("Valor acima");
        
      for(i=0;i<2;i++){
        tone(buzzer,400);
        delay(500);
        noTone(buzzer);}
        ultimoEstado = 1;
      }
    }
    else{
      digitalWrite(vermelho, 0);
      digitalWrite(amarelo, 0);
      digitalWrite(verde, 1);
      if(ultimoEstado != 0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Valor ideal");
        lcd.setCursor(0,1);
        lcd.print(entrada);
        Serial.println("Valor ideal");
        
      tone(buzzer, 400);
      delay(500);
      noTone(buzzer);
      }
      ultimoEstado = 0;
      
    }
    
  //digitalWrite(led, 1);
  }
  else{
    lcd.clear();
    ultimoEstado = -1;
      digitalWrite(vermelho, 0);
      digitalWrite(amarelo, 0);
      digitalWrite(verde, 0);
  }
  
}