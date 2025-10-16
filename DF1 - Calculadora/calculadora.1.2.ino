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
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

boolean presentValue = false;
boolean next = false;
boolean final = false;
String num1, num2;
float answer;
char op;
int tamanho = 0;

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Calculadora");
  lcd.setCursor(3, 1);
  lcd.print("Eletronica");
  delay(3000);
  lcd.clear();
}

void loop()
{

  char key = myKeypad.getKey();

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
      lcd.setCursor(15 - numLength, 1);
      lcd.print(num2);
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
      answer = num1.toFloat() / num2.toFloat();
      String texto = String(answer, 6);
      while(texto.endsWith("0")){
        texto.remove(texto.length()-1);
      }
      int pos = texto.indexOf('.');
      tamanho = texto.length() - pos - 1;
    }    
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(answer, tamanho);

  }
  else if (key != NO_KEY && key == 'C'){
    lcd.clear();
    presentValue = false;
    final = false;
    num1 = "";
    num2 = "";
    answer = 0;
    op = ' ';
    tamanho = 0;
  }}
      
      