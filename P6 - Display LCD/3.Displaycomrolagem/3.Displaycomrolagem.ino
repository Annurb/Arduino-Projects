// C++ code
#include <LiquidCrystal.h>
#define TEMPO_ATUALIZACAO 500

LiquidCrystal lcd( 12, 11, 5, 4, 3, 2);
int inicio = 0, tamanho = 1;
boolean alterar = false;

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  
  //inicia o LCD com dimensoes 16 x 2(colunas x linhas)
  lcd.begin(16, 2);
}

void loop()
{
  lcd.clear();//limpa o display do lcd
  String nome = "Fatecino-Clube de Arduino";
  if (tamanho < 16){
    //Posiciona o cursor nas coordenadas especificadas
    lcd.setCursor(16-tamanho, 0);
    
    //exibe no lcd
    lcd.print(nome.substring(inicio, tamanho));
    tamanho ++;
  }
  else{
    if (!alterar){
      alterar = !alterar;
      tamanho = 16;
      lcd.setCursor(0,0);  
	}
    lcd.print(nome.substring(inicio, inicio +tamanho));
    inicio++;
  }
  if (inicio > nome.length()){
    inicio  = 0;
    tamanho = 1;
    alterar = !alterar;
  }
  delay(TEMPO_ATUALIZACAO);
}