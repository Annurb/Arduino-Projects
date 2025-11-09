#include "thermistor.h"

#define ntc A0
THERMISTOR thermistor(ntc,        // Analog pin
                      10000,          // Nominal resistance at 25 ºC
                      3950,           // thermistor's beta coefficient
                      10000);         // Value of the series resistor
float temp;
void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = thermistor.read();
  Serial.println("Temperatura: ");
  Serial.print(temp/10);
  Serial.println("*C");
  delay(5000);

}
