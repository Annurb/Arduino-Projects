#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

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
int tamanho;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  char key = myKeypad.getKey();

  if (key != NO_KEY && (key >= '0' && key <= '9')) {
    if (!presentValue) {
      num1 += key;
      int numLength = num1.length();
      lcd.setCursor(15 - numLength, 0);
      lcd.print(num1);
    } else {
      num2 += key;
      int numLength = num2.length();
      lcd.setCursor(15 - numLength, 1);
      lcd.print(num2);
      final = true;
    }
  }

  else if (key != NO_KEY && (key == '/' || key == '*' || key == '-' || key == '+')) {
    if (final) {
      calcular();
      num1 = String(answer, tamanho);
      num2 = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(num1);
    }

    op = key;
    presentValue = true;
    final = false;
    lcd.setCursor(15, 0);
    lcd.print(op);
  }

  else if (key != NO_KEY && key == '=') {
    if (final) {
      calcular();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(answer, tamanho);
    }
  }

  else if (key != NO_KEY && key == 'C') {
    lcd.clear();
    presentValue = false;
    final = false;
    num1 = "";
    num2 = "";
    answer = 0;
    op = ' ';
  }
}

void calcular() {
  if (op == '+') {
    answer = num1.toFloat() + num2.toFloat();
  } else if (op == '-') {
    answer = num1.toFloat() - num2.toFloat();
  } else if (op == '*') {
    answer = num1.toFloat() * num2.toFloat();
  } else if (op == '/') {
    answer = num1.toFloat() / num2.toFloat();
    String texto = String(answer, 10);
    while (texto.endsWith("0")) {
      texto.remove(texto.length() - 1);
    }
    int pos = texto.indexOf('.');
    tamanho = texto.length() - pos - 1;
  } else {
    answer = num1.toFloat();
  }
}

