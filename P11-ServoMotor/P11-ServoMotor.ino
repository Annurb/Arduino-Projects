// servo code base
#include <Servo.h>
Servo teste;
int pos;

void setup()
{
teste.attach(6);
  teste.write(0);
  
}

void loop()
{
  for(pos = 0; pos<90;pos++){
    teste.write(pos);
      delay(15);
}
  delay(1000);
  
  for( pos = 90; pos>=0;pos--){
    teste.write(pos);
   delay(15);             
  }
  delay(1000);

}