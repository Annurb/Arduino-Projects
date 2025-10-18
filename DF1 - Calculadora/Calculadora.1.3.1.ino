//Código da calculadora
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);//configs

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};
byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

boolean presentValue = false;
boolean next = false;
boolean final = false;
String num1, num2;
int answer;
char op;

//Liga e desliga
int botao = 5;
int anterior = 0;
int estado = 0;
int valor;
int variavel = 0;

void setup()
{
  pinMode(botao, INPUT);
  

}

void loop()
{
  valor = digitalRead(botao);
  if (anterior == 0 && valor == 1){
  estado = !estado;
  variavel = 1;
  }
  anterior = valor ;
  if (estado == 1){
    if (variavel == 1){
      variavel = 0;
      lcd.init();
      lcd.backlight();
    }

  
  char key = myKeypad.getKey();
    static char ultimaTecla = NO_KEY;

if (key != NO_KEY && key != ultimaTecla) {
  // nova tecla pressionada
  ultimaTecla = key;

  // (teu código normal de tratamento da tecla aqui)
  
} else if (key == NO_KEY) {
  // nenhuma tecla pressionada -> libera pra próxima vez
  ultimaTecla = NO_KEY;
}

  if (key != NO_KEY && (key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='0'))
  {
    if (presentValue != true)
    {
      num1 = num1 + key;
      int numLength = num1.length();
      lcd.setCursor(15 - numLength, 0); //to adjust one whitespace for operator
      lcd.print(num1);
    }
    else 
    {
      num2 = num2 + key;
      int numLength = num2.length();
      lcd.autoscroll();
      lcd.print(num2);
      lcd.noAutoscroll();
      final = true;
    }
  }

  else if (presentValue == false && key != NO_KEY && (key == '/' || key == '*' || key == '-' || key == '+'))
  {
    if (presentValue == false)
    {
      presentValue = true;
      op = key;
      lcd.setCursor(15,0);
      lcd.print(op);
    }
  }

  else if (final == true && key != NO_KEY && key == '='){
    if (op == '+'){
      answer = num1.toInt() + num2.toInt();
    }
    else if (op == '-'){
      answer = num1.toInt() - num2.toInt();
    }
    else if (op == '*'){
      answer = num1.toInt() * num2.toInt();
    }
    else if (op == '/'){
      answer = num1.toInt() / num2.toInt();
    }   
    lcd.clear();
    lcd.setCursor(0, 0);
	lcd.print(num1 + op + num2);
	lcd.setCursor(0, 1);
	lcd.print("= " + String(answer));
  }
  else if (key != NO_KEY && key == 'C'){
    lcd.clear();
    presentValue = false;
    final = false;
    num1 = "";
    num2 = "";
    answer = 0;
    op = ' ';
  }}
  else{
    lcd.noDisplay();
    lcd.noBacklight();
  }
}
      
      
