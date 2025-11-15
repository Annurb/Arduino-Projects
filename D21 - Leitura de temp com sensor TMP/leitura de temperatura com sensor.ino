#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int temp = A0;

#define botao 13
int valor;
int anterior = 0;
int estado = LOW;

const float celsius = 0.20;
void setup()
{
  lcd.init();
  Serial.begin(9600);
}

void loop()
{
 valor = digitalRead(botao);
  Serial.println(valor);
  if(valor == 1 && anterior ==LOW){
  estado = estado +1;
  lcd.init();
  }
  anterior = valor;
  if (estado > 0){
    lcd.backlight();
  }
if(estado == 1){
  lcd.setCursor(0,0);
  lcd.print("Temp em Celsius:");
  lcd.setCursor(0,1);
  lcd.print(lerTemperatura());
  lcd.print("*C");
  
}
  else if (estado == 2){
    lcd.setCursor(0, 0);
    lcd.print("Temp em Kevin:");
    lcd.setCursor(0, 1);
    lcd.print(lerTemperatura()+273);
    lcd.print("*K");
  }
  else if (estado == 3){
    lcd.setCursor(0,0);
    lcd.print("Temp em Farenh:");
    float farenheit = (lerTemperatura()*9)/5;
    lcd.setCursor(0, 1);
    lcd.print(farenheit);
    lcd.print("*F");
    
  }
  else if(estado == 4){
    estado = 0;
    lcd.noBacklight();
  }}
float lerTemperatura(){
  return(analogRead(temp)*celsius);
}