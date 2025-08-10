//Controla aintensidade da luminosidade de um
//LED através de frequência determinada pelo potenciômetro
int LED = 13;
int POT = A1;
int valor = 0;

 void setup()
{
  Serial.begin(9600);
   pinMode(LED, OUTPUT);
}

void loop()
{
  valor = analogRead(POT);
  if(valor >0){
    //acende o led com intensidade proporcional
    //ao valor obtido
    analogWrite(LED, (valor/4));
    
    //Exibe no Serial monitor o valor obtido
    //do potenciômetro
    Serial.println(valor);
  }}