#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int temp = A0;

const int atraso = 5000;

const float celsius = 0.4887585532746823069403714565;
void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop()
{
 lcd.setCursor(0,0);
 lcd.print("Temperatura: ");
 lcd.setCursor(0, 1);
 lcd.print(lerTemperatura());
 lcd.print("*C");

 delay(atraso);
}
float lerTemperatura(){
  return(analogRead(temp)*celsius);
}