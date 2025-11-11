#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);//configs

#define led1 12
#define led2 11
#define botao 13

int inicio = 0, tamanho = 1;
boolean alterar = false;

int estado = LOW;
int valor;
int anterior = 0;


void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(botao, INPUT);
  
}

void loop()
{
  valor = digitalRead(botao);
  if (valor == 1 && anterior ==LOW){
  estado = !estado;
  } 
  if(estado == 1){
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
 	String nome = "Feliz Aniversario Joao";
    lcd.init();
    lcd.backlight();
    if (tamanho < 16) {
    lcd.setCursor(16 - tamanho, 0); // posiciona o cursor
    lcd.print(nome.substring(inicio, tamanho)); // mostra o texto crescendo
    tamanho++;
  } else {
    if (!alterar) {
      alterar = !alterar;
      tamanho = 16;
      lcd.setCursor(0, 0);
    }
    lcd.print(nome.substring(inicio, inicio + tamanho)); // desliza o texto
    inicio++;
  }

  if (inicio > nome.length()) {
    inicio = 0;
    tamanho = 1;
    alterar = !alterar;
  }
    lcd.setCursor(7, 1);
    lcd.print(":D");

    delay(50);
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    delay(150);
    
  }
  else{
    // --- LCD desligado ---
    lcd.noDisplay();
    lcd.noBacklight();
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  anterior =valor;


}