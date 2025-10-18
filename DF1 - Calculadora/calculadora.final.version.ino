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

//Liga e desliga
int botao = 10;
int anterior = 0;
int estado = 0;
int valor;
int variavel = 0;

void setup() {
  pinMode(botao, INPUT);
}

void loop() {
  valor = digitalRead(botao);
  if (anterior == 0 && valor == 1) {
    estado = !estado;
    variavel = 1;
  }
  anterior = valor;

  if (estado == 1) {
    if (variavel == 1) {
      variavel = 0;
      lcd.init();
      lcd.backlight();
    }

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
        // Faz o cálculo parcial
        calcular();
        // Atualiza num1 com o resultado
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
  } else {
    lcd.noDisplay();
    lcd.noBacklight();
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
